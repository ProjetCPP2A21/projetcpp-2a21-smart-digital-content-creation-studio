#ifndef CHATBOT_H
#define CHATBOT_H

#include <QDialog>  // Changé de QWidget à QDialog
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QString>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTimer>

class ChatBot : public QDialog  // Changé de QWidget à QDialog
{
    Q_OBJECT

public:
    explicit ChatBot(QWidget *parent = nullptr);
    ~ChatBot();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onSendMessage();
    void processMessage(const QString &message);
    void onAiResponseReceived(QNetworkReply *reply);
    void onTypingTimeout();

private:
    void setupUI();
    void setupKnowledgeBase();
    QString findAnswer(const QString &question);
    QString findSolution(const QString &problem);
    void addMessage(const QString &message, bool isUser = true);
    void showTypingIndicator();
    void hideTypingIndicator();
    void callOpenAI(const QString &message);
    QString processWithAI(const QString &message);
    void setupAIConfig();

    QTextEdit *chatDisplay;
    QLineEdit *inputField;
    QPushButton *sendButton;
    QVBoxLayout *mainLayout;
    QNetworkAccessManager *networkManager;

    // Indicateur de frappe
    QLabel *typingLabel;
    QTimer *typingTimer;

    // Configuration AI
    QString aiApiKey;
    QString aiEndpoint;
    bool useOpenAI;

    QMap<QString, QString> knowledgeBase;
    QMap<QString, QString> problemSolutions;
};

#endif // CHATBOT_H
