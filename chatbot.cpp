#include "chatbot.h"
#include <QScrollBar>
#include <QDateTime>
#include <QDebug>
#include <QRegularExpression>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QApplication>
#include <QMessageBox>
#include <QCloseEvent>

ChatBot::ChatBot(QWidget *parent) : QDialog(parent)
{
    // Configuration de la fenêtre
    setWindowTitle("🤖 Assistant de Gestion de Projets - ARTEMIA");
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setMinimumSize(500, 600);
    setMaximumSize(700, 800);
    setAttribute(Qt::WA_DeleteOnClose, false); // Ne pas se détruire automatiquement

    networkManager = new QNetworkAccessManager(this);
    typingTimer = new QTimer(this);

    setupUI();
    setupKnowledgeBase();
    setupAIConfig();

    connect(networkManager, &QNetworkAccessManager::finished,
            this, &ChatBot::onAiResponseReceived);
    connect(typingTimer, &QTimer::timeout,
            this, &ChatBot::onTypingTimeout);
}

ChatBot::~ChatBot()
{
    qDebug() << "🔴 ChatBot détruit";
    if (networkManager) {
        networkManager->deleteLater();
    }
}

void ChatBot::closeEvent(QCloseEvent *event)
{
    qDebug() << "🔴 ChatBot fermé par l'utilisateur";
    hide(); // Cacher au lieu de détruire
    event->accept();
}

void ChatBot::setupAIConfig()
{
    // Configuration de l'IA - À adapter selon vos besoins
    useOpenAI = false; // Changez à true pour utiliser OpenAI
    aiApiKey = "votre_cle_api_openai_ici"; // Remplacez par votre clé API
    aiEndpoint = "https://api.openai.com/v1/chat/completions";
}

void ChatBot::setupUI()
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(10);

    // Titre amélioré
    QLabel *titleLabel = new QLabel("🤖 Assistant IA de Gestion de Projets");
    titleLabel->setStyleSheet("QLabel { "
                              "font-weight: bold; "
                              "font-size: 14px; "
                              "color: #2c3e50; "
                              "padding: 10px; "
                              "background: linear-gradient(90deg, #e3f2fd, #bbdefb); "
                              "border-radius: 5px; "
                              "border: 1px solid #90caf9;"
                              "}");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // Zone d'affichage des messages
    chatDisplay = new QTextEdit();
    chatDisplay->setReadOnly(true);
    chatDisplay->setStyleSheet("QTextEdit { "
                               "background-color: #fafafa; "
                               "border: 2px solid #e0e0e0; "
                               "border-radius: 10px; "
                               "padding: 15px; "
                               "font-size: 12px; "
                               "line-height: 1.4; "
                               "}");
    chatDisplay->setMinimumHeight(300);
    mainLayout->addWidget(chatDisplay, 1); // Facteur d'expansion 1

    // Indicateur de frappe
    typingLabel = new QLabel();
    typingLabel->setText("🤖 Assistant réfléchit...");
    typingLabel->setStyleSheet("QLabel { "
                               "color: #666; "
                               "font-style: italic; "
                               "padding: 5px; "
                               "background-color: #fff3e0; "
                               "border-radius: 5px; "
                               "margin: 5px; "
                               "border: 1px solid #ffb74d;"
                               "}");
    typingLabel->setAlignment(Qt::AlignCenter);
    typingLabel->setVisible(false);
    mainLayout->addWidget(typingLabel);

    // Zone de saisie et bouton
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->setSpacing(10);

    inputField = new QLineEdit();
    inputField->setPlaceholderText("Posez votre question ou décrivez votre problème...");
    inputField->setStyleSheet("QLineEdit { "
                              "padding: 12px; "
                              "border: 2px solid #ccc; "
                              "border-radius: 8px; "
                              "font-size: 12px; "
                              "background-color: white;"
                              "}");
    inputField->setMinimumHeight(40);

    sendButton = new QPushButton("Envoyer");
    sendButton->setStyleSheet("QPushButton { "
                              "background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); "
                              "color: white; "
                              "padding: 12px 20px; "
                              "border: none; "
                              "border-radius: 8px; "
                              "font-weight: bold; "
                              "font-size: 12px; "
                              "min-width: 80px;"
                              "}"
                              "QPushButton:hover { "
                              "background: linear-gradient(135deg, #764ba2 0%, #667eea 100%);"
                              "}"
                              "QPushButton:disabled { "
                              "background: #cccccc;"
                              "}");

    inputLayout->addWidget(inputField, 1); // Facteur d'expansion 1
    inputLayout->addWidget(sendButton);
    mainLayout->addLayout(inputLayout);

    // Connexions
    connect(sendButton, &QPushButton::clicked, this, &ChatBot::onSendMessage);
    connect(inputField, &QLineEdit::returnPressed, this, &ChatBot::onSendMessage);

    // Message de bienvenue amélioré
    addMessage("👋 Bonjour ! Je suis votre assistant IA pour la gestion de projets ARTEMIA. "
               "Je peux vous aider avec l'analyse de données, la génération de rapports, "
               "et bien plus encore !\n\n"
               "**Fonctionnalités IA :**\n"
               "• Analyse intelligente des projets\n"
               "• Suggestions d'optimisation\n"
               "• Génération de rapports détaillés\n"
               "• Résolution de problèmes complexes\n\n"
               "N'hésitez pas à me poser vos questions les plus complexes !", false);
}

void ChatBot::showTypingIndicator()
{
    typingLabel->setVisible(true);
    typingTimer->start(30000); // Timeout après 30 secondes
    sendButton->setEnabled(false);
    inputField->setEnabled(false);
}

void ChatBot::hideTypingIndicator()
{
    typingLabel->setVisible(false);
    typingTimer->stop();
    sendButton->setEnabled(true);
    inputField->setEnabled(true);
}

void ChatBot::onTypingTimeout()
{
    hideTypingIndicator();
    addMessage("⏰ Désolé, le temps de réponse a expiré. Veuillez réessayer.", false);
}

void ChatBot::onSendMessage()
{
    QString message = inputField->text().trimmed();
    if (message.isEmpty()) {
        inputField->setFocus();
        return;
    }

    addMessage(message, true);
    inputField->clear();

    // Traiter le message
    QApplication::processEvents(); // Permet l'affichage immédiat du message
    processMessage(message);
}

void ChatBot::processMessage(const QString &message)
{
    QString lowerMessage = message.toLower().trimmed();

    qDebug() << "📨 Message reçu:" << lowerMessage;

    // Réponses spéciales pour les salutations
    if (lowerMessage.contains("bonjour") || lowerMessage.contains("salut") ||
        lowerMessage.contains("coucou") || lowerMessage.contains("hello") || lowerMessage.contains("hi")) {
        QString response = "👋 Bonjour ! Je suis votre assistant IA pour la gestion de projets ARTEMIA.\n\n"
                           "Je peux vous aider avec :\n"
                           "• L'analyse intelligente de vos projets\n"
                           "• La génération de rapports détaillés\n"
                           "• L'optimisation des budgets et délais\n"
                           "• La résolution de problèmes complexes\n\n"
                           "Que souhaitez-vous savoir aujourd'hui ?";
        addMessage(response, false);
        return;
    }

    // Réponses pour "merci"
    else if (lowerMessage.contains("merci")) {
        QString response = "😊 Je vous en prie ! N'hésitez pas si vous avez d'autres questions.\n"
                           "Je suis là pour vous aider à optimiser la gestion de vos projets.";
        addMessage(response, false);
        return;
    }

    // Réponses pour "au revoir"
    else if (lowerMessage.contains("au revoir") || lowerMessage.contains("bye") || lowerMessage.contains("à bientôt")) {
        QString response = "👋 À bientôt ! N'hésitez pas à revenir si vous avez besoin d'aide.\n"
                           "Bonne journée de gestion de projets !";
        addMessage(response, false);
        return;
    }

    // Vérifier d'abord la base de connaissances locale
    QString localResponse = findAnswer(lowerMessage);
    if (!localResponse.isEmpty()) {
        addMessage(localResponse, false);
        return;
    }

    // Si pas de réponse locale, utiliser l'IA
    showTypingIndicator();

    if (useOpenAI && !aiApiKey.isEmpty() && aiApiKey != "votre_cle_api_openai_ici") {
        callOpenAI(message);
    } else {
        // Fallback vers le traitement local amélioré
        QTimer::singleShot(1500, this, [this, message]() {
            QString aiResponse = processWithAI(message);
            hideTypingIndicator();
            addMessage(aiResponse, false);
        });
    }
}

void ChatBot::callOpenAI(const QString &message)
{
    QNetworkRequest request;
    request.setUrl(QUrl(aiEndpoint));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(aiApiKey).toUtf8());

    // Préparer le contexte pour l'IA
    QString systemPrompt = "Tu es un expert en gestion de projets spécialisé dans l'analyse de données de projets, "
                           "l'optimisation des budgets, et la planification stratégique. Tu aides les gestionnaires "
                           "à prendre de meilleures décisions. Sois concis, précis et orienté solutions. "
                           "Réponds en français.";

    QJsonArray messagesArray;
    messagesArray.append(QJsonObject{{"role", "system"}, {"content", systemPrompt}});
    messagesArray.append(QJsonObject{{"role", "user"}, {"content", message}});

    QJsonObject data;
    data["model"] = "gpt-3.5-turbo";
    data["messages"] = messagesArray;
    data["max_tokens"] = 500;
    data["temperature"] = 0.7;

    QJsonDocument doc(data);
    QByteArray postData = doc.toJson();

    networkManager->post(request, postData);
}

void ChatBot::onAiResponseReceived(QNetworkReply *reply)
{
    hideTypingIndicator();

    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response);
        QJsonObject json = doc.object();

        QString aiResponse;

        if (json.contains("choices") && json["choices"].isArray()) {
            QJsonArray choices = json["choices"].toArray();
            if (!choices.isEmpty()) {
                QJsonObject choice = choices[0].toObject();
                if (choice.contains("message") && choice["message"].isObject()) {
                    QJsonObject message = choice["message"].toObject();
                    aiResponse = message["content"].toString();
                }
            }
        }

        if (aiResponse.isEmpty()) {
            aiResponse = "Je n'ai pas pu générer de réponse. Pouvez-vous reformuler votre question ?";
        }

        addMessage(aiResponse, false);
    } else {
        QString errorResponse = "⚠️ Désolé, je rencontre des difficultés techniques. ";
        errorResponse += "Voici ce que je peux vous dire :\n\n";

        // Fallback vers la base de connaissances
        QString fallback = processWithAI("problème technique");
        errorResponse += fallback;

        addMessage(errorResponse, false);

        qDebug() << "❌ Erreur réseau:" << reply->errorString();
    }

    reply->deleteLater();
}

QString ChatBot::processWithAI(const QString &message)
{
    // IA locale améliorée avec plus d'intelligence
    QString lowerMessage = message.toLower();

    // Détection de l'intention
    if (lowerMessage.contains("analys") || lowerMessage.contains("statistiqu") || lowerMessage.contains("rapport")) {
        return "📊 **Analyse IA des Projets**\n\n"
               "Basé sur les patterns de gestion de projets, je recommande :\n\n"
               "• **Optimisation budget** : Analysez les écarts entre budget prévu et réalisé\n"
               "• **Gestion des délais** : Surveillez les projets approchant de leur date limite\n"
               "• **Ressources** : Considérez une redistribution des ressources sur les projets prioritaires\n"
               "• **Risques** : Identifiez les projets avec le plus grand écart budgétaire\n\n"
               "**Action conseillée** : Utilisez la fonction d'export PDF pour un rapport détaillé.";
    }

    if (lowerMessage.contains("optimis") || lowerMessage.contains("amélior") || lowerMessage.contains("suggestion")) {
        return "💡 **Suggestions d'Amélioration**\n\n"
               "**Recommandations stratégiques :**\n"
               "1. **Automatisation** : Implémentez des rappels automatiques pour les échéances\n"
               "2. **Budgétisation** : Utilisez l'historique pour mieux estimer les futurs budgets\n"
               "3. **Reporting** : Génerez des rapports hebdomadaires pour suivre l'avancement\n"
               "4. **Alertes** : Configurez des alertes pour les dépassements de budget\n\n"
               "**Impact estimé** : Ces améliorations pourraient augmenter votre efficacité de 25-30%";
    }

    if (lowerMessage.contains("problème") || lowerMessage.contains("erreur") || lowerMessage.contains("difficulté")) {
        return "🔧 **Diagnostic Intelligent**\n\n"
               "**Étapes de résolution recommandées :**\n"
               "1. **Identification** : Déterminez la source exacte du problème\n"
               "2. **Priorisation** : Classez par ordre d'impact sur vos projets\n"
               "3. **Action** : Appliquez les correctifs en commençant par les plus critiques\n"
               "4. **Vérification** : Contrôlez l'efficacité des solutions\n\n"
               "**Outils disponibles** :\n"
               "• Calendrier des projets pour visualiser les conflits\n"
               "• Statistiques pour identifier les tendances problématiques\n"
               "• Export PDF pour documenter les problèmes et solutions";
    }

    if (lowerMessage.contains("budget") || lowerMessage.contains("coût") || lowerMessage.contains("prix")) {
        return "💰 **Expertise Budgétaire**\n\n"
               "**Conseils de gestion budgétaire :**\n"
               "• **Suivi régulier** : Comparez budget prévu vs réalisé mensuellement\n"
               "• **Contingence** : Prévoir 10-15% de budget pour imprévus\n"
               "• **Optimisation** : Identifiez les postes de dépenses les plus variables\n"
               "• **Négociation** : Renégociez les contrats avec les fournisseurs réguliers\n\n"
               "**Astuce** : Utilisez le tri par budget pour identifier les projets les plus coûteux.";
    }

    if (lowerMessage.contains("délai") || lowerMessage.contains("temps") || lowerMessage.contains("calendrier")) {
        return "⏰ **Gestion des Délais**\n\n"
               "**Stratégies de gestion du temps :**\n"
               "• **Buffer temporel** : Ajoutez 20% de marge aux estimations initiales\n"
               "• **Critical Path** : Identifiez les tâches critiques qui impactent le délai global\n"
               "• **Revue hebdomadaire** : Faites le point sur l'avancement chaque vendredi\n"
               "• **Alertes précoces** : Configurez des rappels 15 jours avant les échéances\n\n"
               "**Outil** : Le calendrier intégré montre visuellement les périodes de projet.";
    }

    // Réponse par défaut intelligente
    return "🤔 **Assistant IA Réponse**\n\n"
           "Je comprends que vous cherchez des informations sur : \"" + message + "\"\n\n"
                       "**Pour une assistance optimale :**\n"
                       "• Fournissez plus de détails sur votre demande\n"
                       "• Précisez le type d'analyse souhaité\n"
                       "• Partagez des données spécifiques si possible\n\n"
                       "**Je peux vous aider avec :**\n"
                       "• L'analyse de vos données projets\n"
                       "• L'optimisation des processus\n"
                       "• La génération de rapports\n"
                       "• La résolution de problèmes complexes\n\n"
                       "*Je suis ici pour vous aider à transformer vos données en insights actionnables !*";
}

void ChatBot::setupKnowledgeBase()
{
    // Base de connaissances - Questions générales avec variations
    knowledgeBase["ajouter projet"] = "🚀 **Pour ajouter un projet :**\n\n"
                                      "1. **ID Client** : Nombre unique et positif\n"
                                      "2. **Budget** : Prévu et réalisé (optionnel)\n"
                                      "3. **Dates** : Format JJ/MM/AAAA\n"
                                      "4. **Statut** : 'En cours' par défaut\n\n"
                                      "💡 *Conseil : Vérifiez que l'ID client n'existe pas déjà*";

    knowledgeBase["modifier projet"] = "✏️ **Pour modifier un projet :**\n\n"
                                       "1. **Sélection** : Cliquez sur le projet dans le tableau\n"
                                       "2. **Modification** : Cliquez sur 'Modifier Projet'\n"
                                       "3. **Édition** : Modifiez les champs nécessaires\n"
                                       "4. **Validation** : Cliquez sur 'Confirmer Modification'\n\n"
                                       "⚠️ *Attention : L'ID client doit rester unique*";

    knowledgeBase["supprimer projet"] = "🗑️ **Pour supprimer un projet :**\n\n"
                                        "1. **Sélection** : Choisissez le projet dans le tableau\n"
                                        "2. **Suppression** : Cliquez sur 'Supprimer Projet'\n"
                                        "3. **Confirmation** : Validez la suppression\n\n"
                                        "❌ *Action irréversible - Soyez certain de votre choix*";

    knowledgeBase["rechercher projet"] = "🔍 **Pour rechercher un projet :**\n\n"
                                         "1. **Barre de recherche** : En haut de l'interface\n"
                                         "2. **Critères** : ID, budget, date, statut\n"
                                         "3. **Résultats** : Affichage automatique\n\n"
                                         "💡 *Astuce : La recherche est insensible à la casse*";

    knowledgeBase["calendrier"] = "📅 **Fonction calendrier :**\n\n"
                                  "1. **Visualisation** : Périodes de projet en rouge\n"
                                  "2. **Sélection** : Choisissez un projet pour calcul des jours\n"
                                  "3. **Calcul** : Jours restants automatiquement déterminés\n\n"
                                  "👁️ *Visualisez les chevauchements et les périodes critiques*";

    knowledgeBase["statistiques"] = "📊 **Statistiques budgétaires :**\n\n"
                                    "1. **Analyse** : Répartition par plages de budget\n"
                                    "2. **Visualisation** : Diagramme circulaire et barres\n"
                                    "3. **Insights** : Tendances et patterns identifiés\n\n"
                                    "📈 *Prenez des décisions basées sur les données*";

    knowledgeBase["export pdf"] = "📄 **Export PDF :**\n\n"
                                  "1. **Génération** : Cliquez sur 'Exporter PDF'\n"
                                  "2. **Sauvegarde** : Choisissez l'emplacement\n"
                                  "3. **Contenu** : Tableau complet + statistiques\n"
                                  "4. **Format** : Professionnel avec mise en forme\n\n"
                                  "💼 *Idéal pour les rapports et présentations*";

    knowledgeBase["aide"] = "ℹ️ **Centre d'Aide Complet**\n\n"
                            "**Fonctionnalités principales :**\n"
                            "• 📋 Gestion des projets (CRUD complet)\n"
                            "• 🔍 Recherche et tri avancés\n"
                            "• 📅 Calendrier visuel interactif\n"
                            "• ⏰ Calcul intelligent des délais\n"
                            "• 📊 Statistiques et analyses\n"
                            "• 📄 Export professionnel PDF\n"
                            "• 🤖 Assistant IA intégré\n\n"
                            "**Pour une aide spécifique, demandez-moi :**\n"
                            "\"Comment ajouter un projet ?\"\n"
                            "\"Problème avec les dates\"\n"
                            "\"Voir les statistiques\"\n"
                            "\"Aide pour l'export PDF\"";
}

QString ChatBot::findAnswer(const QString& question)
{
    QString lowerQuestion = question.toLower().trimmed();

    // Nettoyer la question des caractères spéciaux
    QString cleanedQuestion = lowerQuestion;
    cleanedQuestion = cleanedQuestion.replace("?", "")
                          .replace("!", "")
                          .replace(".", "")
                          .replace(",", "")
                          .replace(";", "")
                          .trimmed();

    qDebug() << "🔍 Recherche réponse pour:" << cleanedQuestion;

    // Recherche par mots-clés avec priorité
    QMap<int, QString> matches; // score -> réponse

    for (auto it = knowledgeBase.begin(); it != knowledgeBase.end(); ++it) {
        QString key = it.key();
        QString lowerKey = key.toLower();

        int score = 0;

        // Recherche exacte
        if (cleanedQuestion.contains(lowerKey)) {
            score += 100;
        }

        // Recherche par mots individuels
        QStringList questionWords = cleanedQuestion.split(" ", Qt::SkipEmptyParts);
        QStringList keyWords = lowerKey.split(" ", Qt::SkipEmptyParts);

        for (const QString& qWord : questionWords) {
            for (const QString& kWord : keyWords) {
                if (qWord == kWord) {
                    score += 10;
                } else if (kWord.contains(qWord) || qWord.contains(kWord)) {
                    score += 5;
                }
            }
        }

        if (score > 0) {
            matches[score] = it.value();
        }
    }

    // Retourner la meilleure correspondance
    if (!matches.isEmpty()) {
        return matches.last();
    }

    return "";
}

QString ChatBot::findSolution(const QString& problem)
{
    QString lowerProblem = problem.toLower().trimmed();

    // Solutions aux problèmes courants
    if (lowerProblem.contains("id client existe") || lowerProblem.contains("id existe")) {
        return "🔧 **Solution : ID Client Existe Déjà**\n\n"
               "**Actions recommandées :**\n"
               "1. Vérifiez que l'ID n'existe pas déjà\n"
               "2. Utilisez un numéro différent\n"
               "3. Consultez la liste des projets existants\n\n"
               "💡 *Conseil : Utilisez des IDs séquentiels pour éviter les conflits*";
    }

    if (lowerProblem.contains("format date") || lowerProblem.contains("date invalide")) {
        return "🔧 **Solution : Format de Date Invalide**\n\n"
               "**Format accepté :** JJ/MM/AAAA\n"
               "**Exemples valides :**\n"
               "• 01/01/2025\n"
               "• 15/12/2025\n"
               "• 1/1/2025 (format simplifié)\n\n"
               "❌ **À éviter :** 01-01-2025, 2025/01/01";
    }

    if (lowerProblem.contains("date fin avant") || lowerProblem.contains("date fin")) {
        return "🔧 **Solution : Incohérence des Dates**\n\n"
               "**Problème :** La date de fin est avant la date de début\n"
               "**Solution :**\n"
               "1. Vérifiez l'ordre des dates\n"
               "2. Corrigez la date de début ou de fin\n"
               "3. Assurez-vous du format correct\n\n"
               "📅 *La date de fin doit toujours être après la date de début*";
    }

    if (lowerProblem.contains("budget négatif") || lowerProblem.contains("budget invalide")) {
        return "🔧 **Solution : Budget Invalide**\n\n"
               "**Règles de validation :**\n"
               "• Budget doit être positif ou zéro\n"
               "• Utilisez le point pour les décimales\n"
               "• Exemple valide : 1500.50\n\n"
               "❌ **Invalide :** -100, 1,500.50, 1500,50";
    }

    return "";
}

void ChatBot::addMessage(const QString &message, bool isUser)
{
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm");
    QString formattedMessage;
    QString style;

    if (isUser) {
        style = "background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: white;";
    } else {
        style = "background-color: white; color: #333; border-left: 4px solid #4CAF50;";
    }

    formattedMessage = QString(
                           "<div style='margin: 10px; padding: 12px; border-radius: 12px; %4 max-width: 85%%; "
                           "box-shadow: 0 2px 5px rgba(0,0,0,0.1); float: %1;'>"
                           "<div style='font-size: 10px; opacity: 0.7; margin-bottom: 5px;'>%2</div>"
                           "<div style='font-size: 12px; line-height: 1.4;'>%3</div>"
                           "</div><div style='clear: both;'></div>")
                           .arg(isUser ? "right" : "left")
                           .arg(isUser ? "Vous (" + timestamp + ")" : "🤖 Assistant (" + timestamp + ")")
                           .arg(message.toHtmlEscaped().replace("\n", "<br>"))
                           .arg(style);

    chatDisplay->append(formattedMessage);

    // Défilement automatique vers le bas
    QScrollBar *scrollbar = chatDisplay->verticalScrollBar();
    scrollbar->setValue(scrollbar->maximum());
}
