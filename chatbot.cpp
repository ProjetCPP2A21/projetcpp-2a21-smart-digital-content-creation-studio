#include "chatbot.h"
#include <QScrollBar>
#include <QDateTime>
#include <QDebug>
#include <QRegularExpression>

ChatBot::ChatBot(QWidget *parent) : QWidget(parent)
{
    setupUI();
    setupKnowledgeBase();
}

ChatBot::~ChatBot()
{
}

void ChatBot::setupUI()
{
    mainLayout = new QVBoxLayout(this);

    // Titre
    QLabel *titleLabel = new QLabel("🤖 Assistant de Gestion de Projets");
    titleLabel->setStyleSheet("QLabel { font-weight: bold; font-size: 14px; color: #2c3e50; padding: 10px; background-color: #e3f2fd; border-radius: 5px; }");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // Zone d'affichage des messages
    chatDisplay = new QTextEdit();
    chatDisplay->setReadOnly(true);
    chatDisplay->setStyleSheet("QTextEdit { background-color: #f8f9fa; border: 1px solid #ddd; border-radius: 5px; padding: 10px; }");
    mainLayout->addWidget(chatDisplay);

    // Zone de saisie et bouton
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputField = new QLineEdit();
    inputField->setPlaceholderText("Posez votre question ou décrivez votre problème...");
    inputField->setStyleSheet("QLineEdit { padding: 8px; border: 1px solid #ccc; border-radius: 5px; }");

    sendButton = new QPushButton("Envoyer");
    sendButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; padding: 8px 15px; border: none; border-radius: 5px; font-weight: bold; }");

    inputLayout->addWidget(inputField);
    inputLayout->addWidget(sendButton);
    mainLayout->addLayout(inputLayout);

    // Connexions
    connect(sendButton, &QPushButton::clicked, this, &ChatBot::onSendMessage);
    connect(inputField, &QLineEdit::returnPressed, this, &ChatBot::onSendMessage);

    // Message de bienvenue
    addMessage("👋 Bonjour ! Je suis votre assistant pour la gestion de projets. Je peux vous aider avec :\n\n"
               "• **Gestion des projets** : ajouter, modifier, supprimer\n"
               "• **Recherche et tri** : trouver et organiser les projets\n"
               "• **Calendrier** : voir les périodes des projets\n"
               "• **Calcul des délais** : jours restants\n"
               "• **Statistiques** : analyse des budgets\n"
               "• **Export** : générer des PDF\n\n"
               "N'hésitez pas à me poser vos questions !", false);
}

void ChatBot::setupKnowledgeBase()
{
    // Base de connaissances - Questions générales avec variations
    knowledgeBase["ajouter projet"] = "Pour ajouter un projet :\n"
                                      "1. Remplissez l'ID client (nombre positif)\n"
                                      "2. Saisissez le budget prévu et réalisé (optionnel)\n"
                                      "3. Entrez les dates au format JJ/MM/AAAA\n"
                                      "4. Cliquez sur 'Ajouter Projet'";

    knowledgeBase["comment ajouter"] = "Pour ajouter un projet :\n"
                                       "1. Remplissez l'ID client (nombre positif)\n"
                                       "2. Saisissez le budget prévu et réalisé (optionnel)\n"
                                       "3. Entrez les dates au format JJ/MM/AAAA\n"
                                       "4. Cliquez sur 'Ajouter Projet'";

    knowledgeBase["nouveau projet"] = "Pour ajouter un projet :\n"
                                      "1. Remplissez l'ID client (nombre positif)\n"
                                      "2. Saisissez le budget prévu et réalisé (optionnel)\n"
                                      "3. Entrez les dates au format JJ/MM/AAAA\n"
                                      "4. Cliquez sur 'Ajouter Projet'";

    knowledgeBase["créer projet"] = "Pour ajouter un projet :\n"
                                    "1. Remplissez l'ID client (nombre positif)\n"
                                    "2. Saisissez le budget prévu et réalisé (optionnel)\n"
                                    "3. Entrez les dates au format JJ/MM/AAAA\n"
                                    "4. Cliquez sur 'Ajouter Projet'";

    knowledgeBase["ajout projet"] = "Pour ajouter un projet :\n"
                                    "1. Remplissez l'ID client (nombre positif)\n"
                                    "2. Saisissez le budget prévu et réalisé (optionnel)\n"
                                    "3. Entrez les dates au format JJ/MM/AAAA\n"
                                    "4. Cliquez sur 'Ajouter Projet'";

    knowledgeBase["comment modifier"] = "Pour modifier un projet :\n"
                                        "1. Sélectionnez le projet dans le tableau\n"
                                        "2. Cliquez sur 'Modifier Projet'\n"
                                        "3. Modifiez les champs nécessaires\n"
                                        "4. Cliquez sur 'Confirmer Modification'";

    knowledgeBase["modifier projet"] = "Pour modifier un projet :\n"
                                       "1. Sélectionnez le projet dans le tableau\n"
                                       "2. Cliquez sur 'Modifier Projet'\n"
                                       "3. Modifiez les champs nécessaires\n"
                                       "4. Cliquez sur 'Confirmer Modification'";

    knowledgeBase["editer projet"] = "Pour modifier un projet :\n"
                                     "1. Sélectionnez le projet dans le tableau\n"
                                     "2. Cliquez sur 'Modifier Projet'\n"
                                     "3. Modifiez les champs nécessaires\n"
                                     "4. Cliquez sur 'Confirmer Modification'";

    knowledgeBase["supprimer projet"] = "Pour supprimer un projet :\n"
                                        "1. Sélectionnez le projet dans le tableau\n"
                                        "2. Cliquez sur 'Supprimer Projet'\n"
                                        "3. Confirmez la suppression";

    knowledgeBase["effacer projet"] = "Pour supprimer un projet :\n"
                                      "1. Sélectionnez le projet dans le tableau\n"
                                      "2. Cliquez sur 'Supprimer Projet'\n"
                                      "3. Confirmez la suppression";

    knowledgeBase["delete projet"] = "Pour supprimer un projet :\n"
                                     "1. Sélectionnez le projet dans le tableau\n"
                                     "2. Cliquez sur 'Supprimer Projet'\n"
                                     "3. Confirmez la suppression";

    knowledgeBase["recherche projet"] = "Pour rechercher un projet :\n"
                                        "1. Utilisez la barre de recherche en haut\n"
                                        "2. Tapez un mot-clé (ID, budget, date, statut)\n"
                                        "3. Les résultats s'affichent automatiquement";

    knowledgeBase["chercher projet"] = "Pour rechercher un projet :\n"
                                       "1. Utilisez la barre de recherche en haut\n"
                                       "2. Tapez un mot-clé (ID, budget, date, statut)\n"
                                       "3. Les résultats s'affichent automatiquement";

    knowledgeBase["find projet"] = "Pour rechercher un projet :\n"
                                   "1. Utilisez la barre de recherche en haut\n"
                                   "2. Tapez un mot-clé (ID, budget, date, statut)\n"
                                   "3. Les résultats s'affichent automatiquement";

    knowledgeBase["calcul jours restants"] = "Pour calculer les jours restants :\n"
                                             "1. Sélectionnez un projet dans le tableau\n"
                                             "2. Cliquez sur 'Calcul Jours'\n"
                                             "3. Le système calcule automatiquement";

    knowledgeBase["jours restants"] = "Pour calculer les jours restants :\n"
                                      "1. Sélectionnez un projet dans le tableau\n"
                                      "2. Cliquez sur 'Calcul Jours'\n"
                                      "3. Le système calcule automatiquement";

    knowledgeBase["délai projet"] = "Pour calculer les jours restants :\n"
                                    "1. Sélectionnez un projet dans le tableau\n"
                                    "2. Cliquez sur 'Calcul Jours'\n"
                                    "3. Le système calcule automatiquement";

    knowledgeBase["statistiques"] = "Pour voir les statistiques :\n"
                                    "1. Cliquez sur 'Statistiques Budget'\n"
                                    "2. Un diagramme circulaire s'affiche\n"
                                    "3. Analyse par plage de budget";

    knowledgeBase["stats"] = "Pour voir les statistiques :\n"
                             "1. Cliquez sur 'Statistiques Budget'\n"
                             "2. Un diagramme circulaire s'affiche\n"
                             "3. Analyse par plage de budget";

    knowledgeBase["analyse budget"] = "Pour voir les statistiques :\n"
                                      "1. Cliquez sur 'Statistiques Budget'\n"
                                      "2. Un diagramme circulaire s'affiche\n"
                                      "3. Analyse par plage de budget";

    knowledgeBase["calendrier"] = "Pour voir le calendrier :\n"
                                  "1. Cliquez sur 'Calendrier'\n"
                                  "2. Les périodes de projet sont en rouge\n"
                                  "3. Sélectionnez un projet pour calculer les jours";

    knowledgeBase["calendar"] = "Pour voir le calendrier :\n"
                                "1. Cliquez sur 'Calendrier'\n"
                                "2. Les périodes de projet sont en rouge\n"
                                "3. Sélectionnez un projet pour calculer les jours";

    knowledgeBase["exporter pdf"] = "Pour exporter en PDF :\n"
                                    "1. Cliquez sur 'Exporter PDF'\n"
                                    "2. Choisissez l'emplacement de sauvegarde\n"
                                    "3. Le PDF contiendra le tableau complet avec statistiques\n"
                                    "4. Format professionnel avec mise en forme";

    knowledgeBase["export pdf"] = "Pour exporter en PDF :\n"
                                  "1. Cliquez sur 'Exporter PDF'\n"
                                  "2. Choisissez l'emplacement de sauvegarde\n"
                                  "3. Le PDF contiendra le tableau complet avec statistiques\n"
                                  "4. Format professionnel avec mise en forme";

    knowledgeBase["générer pdf"] = "Pour exporter en PDF :\n"
                                   "1. Cliquez sur 'Exporter PDF'\n"
                                   "2. Choisissez l'emplacement de sauvegarde\n"
                                   "3. Le PDF contiendra le tableau complet avec statistiques\n"
                                   "4. Format professionnel avec mise en forme";

    // Ajoutez des variations pour "aide"
    knowledgeBase["aide"] = "Je peux vous aider avec :\n\n"
                            "• **Ajout de projets** : Comment créer un nouveau projet\n"
                            "• **Modification** : Comment modifier un projet existant\n"
                            "• **Suppression** : Comment supprimer un projet\n"
                            "• **Recherche** : Comment trouver des projets\n"
                            "• **Tri** : Comment organiser les projets\n"
                            "• **Calendrier** : Voir les périodes de projet\n"
                            "• **Calcul jours** : Voir les délais restants\n"
                            "• **Statistiques** : Analyser les budgets\n"
                            "• **Export PDF** : Exporter les données\n\n"
                            "Dites-moi sur quoi vous avez besoin d'aide !";

    knowledgeBase["help"] = "Je peux vous aider avec :\n\n"
                            "• **Ajout de projets** : Comment créer un nouveau projet\n"
                            "• **Modification** : Comment modifier un projet existant\n"
                            "• **Suppression** : Comment supprimer un projet\n"
                            "• **Recherche** : Comment trouver des projets\n"
                            "• **Tri** : Comment organiser les projets\n"
                            "• **Calendrier** : Voir les périodes de projet\n"
                            "• **Calcul jours** : Voir les délais restants\n"
                            "• **Statistiques** : Analyser les budgets\n"
                            "• **Export PDF** : Exporter les données\n\n"
                            "Dites-moi sur quoi vous avez besoin d'aide !";

    knowledgeBase["aider"] = "Je peux vous aider avec :\n\n"
                             "• **Ajout de projets** : Comment créer un nouveau projet\n"
                             "• **Modification** : Comment modifier un projet existant\n"
                             "• **Suppression** : Comment supprimer un projet\n"
                             "• **Recherche** : Comment trouver des projets\n"
                             "• **Tri** : Comment organiser les projets\n"
                             "• **Calendrier** : Voir les périodes de projet\n"
                             "• **Calcul jours** : Voir les délais restants\n"
                             "• **Statistiques** : Analyser les budgets\n"
                             "• **Export PDF** : Exporter les données\n\n"
                             "Dites-moi sur quoi vous avez besoin d'aide !";

    knowledgeBase["aider moi"] = "Je peux vous aider avec :\n\n"
                                 "• **Ajout de projets** : Comment créer un nouveau projet\n"
                                 "• **Modification** : Comment modifier un projet existant\n"
                                 "• **Suppression** : Comment supprimer un projet\n"
                                 "• **Recherche** : Comment trouver des projets\n"
                                 "• **Tri** : Comment organiser les projets\n"
                                 "• **Calendrier** : Voir les périodes de projet\n"
                                 "• **Calcul jours** : Voir les délais restants\n"
                                 "• **Statistiques** : Analyser les budgets\n"
                                 "• **Export PDF** : Exporter les données\n\n"
                                 "Dites-moi sur quoi vous avez besoin d'aide !";

    // Solutions aux problèmes
    problemSolutions["id client existe déjà"] = "Solution : L'ID client doit être unique.\n"
                                                "• Vérifiez que l'ID n'existe pas déjà\n"
                                                "• Utilisez un numéro différent\n"
                                                "• Consultez la liste des projets existants";

    problemSolutions["id existe"] = "Solution : L'ID client doit être unique.\n"
                                    "• Vérifiez que l'ID n'existe pas déjà\n"
                                    "• Utilisez un numéro différent\n"
                                    "• Consultez la liste des projets existants";

    problemSolutions["format date invalide"] = "Solution : Utilisez le format JJ/MM/AAAA\n"
                                               "• Exemples : 01/01/2025, 15/12/2025\n"
                                               "• Évitez les séparateurs différents\n"
                                               "• Vérifiez que la date est valide";

    problemSolutions["date invalide"] = "Solution : Utilisez le format JJ/MM/AAAA\n"
                                        "• Exemples : 01/01/2025, 15/12/2025\n"
                                        "• Évitez les séparateurs différents\n"
                                        "• Vérifiez que la date est valide";

    problemSolutions["date fin avant début"] = "Solution : La date de fin doit être après la date de début\n"
                                               "• Vérifiez l'ordre des dates\n"
                                               "• Corrigez la date de début ou de fin\n"
                                               "• Assurez-vous du format correct";

    problemSolutions["date fin"] = "Solution : La date de fin doit être après la date de début\n"
                                   "• Vérifiez l'ordre des dates\n"
                                   "• Corrigez la date de début ou de fin\n"
                                   "• Assurez-vous du format correct";

    problemSolutions["budget négatif"] = "Solution : Le budget doit être positif\n"
                                         "• Entrez un nombre positif\n"
                                         "• Utilisez le point pour les décimales\n"
                                         "• Exemple : 1500.50";

    problemSolutions["budget invalide"] = "Solution : Le budget doit être un nombre valide\n"
                                          "• Utilisez uniquement des chiffres\n"
                                          "• Point pour les décimales\n"
                                          "• Pas de caractères spéciaux";

    problemSolutions["projet non sélectionné"] = "Solution : Sélectionnez d'abord un projet\n"
                                                 "• Cliquez sur une ligne du tableau\n"
                                                 "• La ligne doit être surlignée\n"
                                                 "• Puis effectuez l'action";

    problemSolutions["sélectionner projet"] = "Solution : Sélectionnez d'abord un projet\n"
                                              "• Cliquez sur une ligne du tableau\n"
                                              "• La ligne doit être surlignée\n"
                                              "• Puis effectuez l'action";

    problemSolutions["connexion base données"] = "Solution : Problème de connexion\n"
                                                 "• Vérifiez que la base est accessible\n"
                                                 "• Vérifiez les paramètres ODBC\n"
                                                 "• Redémarrez l'application";

    problemSolutions["connexion base"] = "Solution : Problème de connexion\n"
                                         "• Vérifiez que la base est accessible\n"
                                         "• Vérifiez les paramètres ODBC\n"
                                         "• Redémarrez l'application";

    problemSolutions["export pdf"] = "Solution pour l'export PDF :\n"
                                     "• Vérifiez qu'il y a des données dans le tableau\n"
                                     "• Assurez-vous d'avoir les droits d'écriture\n"
                                     "• Choisissez un emplacement accessible";

    qDebug() << "📚 Base de connaissances chargée avec" << knowledgeBase.size() << "entrées";
    for (auto it = knowledgeBase.begin(); it != knowledgeBase.end(); ++it) {
        qDebug() << "   📖 Clé:" << it.key();
    }
}

void ChatBot::onSendMessage()
{
    QString message = inputField->text().trimmed();
    if (message.isEmpty()) return;

    addMessage(message, true);
    inputField->clear();

    processMessage(message);
}

void ChatBot::processMessage(const QString &message)
{
    QString lowerMessage = message.toLower().trimmed();
    QString response;

    qDebug() << "📨 Message reçu:" << lowerMessage;

    // Réponses spéciales pour les salutations
    if (lowerMessage.contains("bonjour") ||
        lowerMessage.contains("salut") ||
        lowerMessage.contains("coucou") ||
        lowerMessage.contains("hello") ||
        lowerMessage.contains("hi")) {
        response = "👋 Bonjour ! Je suis votre assistant pour la gestion de projets.\n\n"
                   "Je peux vous aider avec :\n"
                   "• L'ajout, modification et suppression de projets\n"
                   "• La recherche et le tri des données\n"
                   "• Le calcul des jours restants\n"
                   "• Les statistiques de budget\n"
                   "• L'export en PDF\n\n"
                   "Que souhaitez-vous faire ?";
    }
    // Réponses pour "merci"
    else if (lowerMessage.contains("merci")) {
        response = "😊 Je vous en prie ! N'hésitez pas si vous avez d'autres questions.\n"
                   "Je suis là pour vous aider avec la gestion de vos projets.";
    }
    // Réponses pour "au revoir"
    else if (lowerMessage.contains("au revoir") ||
             lowerMessage.contains("bye") ||
             lowerMessage.contains("à bientôt")) {
        response = "👋 À bientôt ! N'hésitez pas à revenir si vous avez besoin d'aide.\n"
                   "Bonne journée !";
    }
    // Recherche dans la base de connaissances
    else {
        response = findAnswer(lowerMessage);

        // Si pas trouvé, recherche de problèmes
        if (response.isEmpty()) {
            response = findSolution(lowerMessage);
        }
    }

    // Réponse par défaut
    if (response.isEmpty()) {
        response = "Je n'ai pas bien compris votre demande. 🤔\n\n"
                   "Voici ce que je peux faire :\n\n"
                   "• **Gestion des projets** : ajouter, modifier, supprimer\n"
                   "• **Recherche et tri** : trouver et organiser les projets\n"
                   "• **Calendrier** : voir les périodes des projets\n"
                   "• **Calcul des délais** : jours restants\n"
                   "• **Statistiques** : analyse des budgets\n"
                   "• **Export** : générer des PDF\n\n"
                   "Essayez de formuler votre question autrement, par exemple :\n"
                   "• \"Comment ajouter un projet ?\"\n"
                   "• \"Problème avec les dates\"\n"
                   "• \"Voir les statistiques\"\n"
                   "• \"Aide pour l'export PDF\"";
    }

    addMessage(response, false);
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
            qDebug() << "   ✅ Correspondance exacte avec:" << key;
        }

        // Recherche par mots individuels
        QStringList questionWords = cleanedQuestion.split(" ", Qt::SkipEmptyParts);
        QStringList keyWords = lowerKey.split(" ", Qt::SkipEmptyParts);

        int wordMatches = 0;
        for (const QString& qWord : questionWords) {
            for (const QString& kWord : keyWords) {
                if (qWord == kWord) {
                    wordMatches++;
                    score += 10;
                } else if (kWord.contains(qWord) || qWord.contains(kWord)) {
                    wordMatches++;
                    score += 5;
                }
            }
        }

        // Bonus si tous les mots du keyword sont trouvés
        if (wordMatches >= keyWords.size()) {
            score += 50;
        }

        if (score > 0) {
            matches[score] = it.value();
            qDebug() << "   ✅ Match trouvé - Clé:" << key << "Score:" << score;
        }
    }

    // Retourner la meilleure correspondance
    if (!matches.isEmpty()) {
        qDebug() << "🎯 Meilleure réponse sélectionnée avec score:" << matches.lastKey();
        return matches.last(); // La plus haute score
    }

    qDebug() << "❌ Aucune réponse trouvée";
    return "";
}

QString ChatBot::findSolution(const QString& problem)
{
    QString lowerProblem = problem.toLower().trimmed();

    // Nettoyer le problème des caractères spéciaux
    QString cleanedProblem = lowerProblem;
    cleanedProblem = cleanedProblem.replace("?", "")
                         .replace("!", "")
                         .replace(".", "")
                         .replace(",", "")
                         .replace(";", "")
                         .trimmed();

    qDebug() << "🔧 Recherche solution pour:" << cleanedProblem;

    QMap<int, QString> matches; // score -> solution

    for (auto it = problemSolutions.begin(); it != problemSolutions.end(); ++it) {
        QString key = it.key();
        QString lowerKey = key.toLower();

        int score = 0;

        // Recherche exacte
        if (cleanedProblem.contains(lowerKey)) {
            score += 100;
            qDebug() << "   ✅ Correspondance exacte avec problème:" << key;
        }

        // Recherche par mots
        QStringList problemWords = cleanedProblem.split(" ", Qt::SkipEmptyParts);
        QStringList keyWords = lowerKey.split(" ", Qt::SkipEmptyParts);

        for (const QString& pWord : problemWords) {
            for (const QString& kWord : keyWords) {
                if (pWord == kWord) {
                    score += 10;
                } else if (kWord.contains(pWord) || pWord.contains(kWord)) {
                    score += 5;
                }
            }
        }

        if (score > 0) {
            matches[score] = "🔧 **Problème détecté : " + it.key() + "**\n\n" + it.value();
            qDebug() << "   ✅ Solution trouvée - Problème:" << key << "Score:" << score;
        }
    }

    if (!matches.isEmpty()) {
        qDebug() << "🎯 Meilleure solution sélectionnée avec score:" << matches.lastKey();
        return matches.last();
    }

    qDebug() << "❌ Aucune solution trouvée";
    return "";
}

void ChatBot::addMessage(const QString &message, bool isUser)
{
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm");
    QString formattedMessage;

    if (isUser) {
        formattedMessage = QString("<div style='margin: 5px; padding: 10px; background-color: #e3f2fd; border-radius: 10px; float: right; max-width: 80%;'>"
                                   "<b>Vous (%1):</b><br>%2</div><div style='clear: both;'></div>")
                               .arg(timestamp, message);
    } else {
        formattedMessage = QString("<div style='margin: 5px; padding: 10px; background-color: #f1f1f1; border-radius: 10px; float: left; max-width: 80%;'>"
                                   "<b>Assistant (%1):</b><br>%2</div><div style='clear: both;'></div>")
                               .arg(timestamp, message);
    }

    chatDisplay->append(formattedMessage);

    // Défilement automatique vers le bas
    QScrollBar *scrollbar = chatDisplay->verticalScrollBar();
    scrollbar->setValue(scrollbar->maximum());
}
