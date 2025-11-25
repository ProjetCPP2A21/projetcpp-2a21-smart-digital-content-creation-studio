#ifndef CHATBOT_H
#define CHATBOT_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QString>
#include <QMap>

class ChatBot : public QWidget
{
    Q_OBJECT

public:
    explicit ChatBot(QWidget *parent = nullptr);
    ~ChatBot();

private slots:
    void onSendMessage();
    void processMessage(const QString &message);

private:
    void setupUI();
    void setupKnowledgeBase();
    QString findAnswer(const QString &question);
    QString findSolution(const QString &problem);
    void addMessage(const QString &message, bool isUser = true);

    QTextEdit *chatDisplay;
    QLineEdit *inputField;
    QPushButton *sendButton;
    QVBoxLayout *mainLayout;

    QMap<QString, QString> knowledgeBase;
    QMap<QString, QString> problemSolutions;
};

#endif // CHATBOT_H
