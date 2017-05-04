#ifndef CHECKINWINDOW_H
#define CHECKINWINDOW_H
#include <QDialog>
#include "database/activity.h"
#include "database/checkin.h"

namespace Ui {
class CheckInWindow;
}

class CheckInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CheckInWindow(QWidget *parent, Activity*);
    ~CheckInWindow();

private slots:
    void on_Back_released();

    void on_Scan_released();

private:
    Ui::CheckInWindow *ui;
    Activity* currentActivity;
    Checkin* checkIn;
};
#endif // CHECKINWINDOW_H
