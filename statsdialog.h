#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>

class StatsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StatsDialog(int images, int videos, int audios, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int nbImages;
    int nbVideos;
    int nbAudios;
};

#endif // STATSDIALOG_H
