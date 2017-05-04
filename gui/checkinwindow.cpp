#include "gui/checkinwindow.h"
#include "ui_checkinwindow.h"
#include "gui/activitywindow.h"

/*
 * Window takes activity in the constructor so that it can create a check in for that specific activity
 */
CheckInWindow::CheckInWindow(QWidget *parent, Activity* act) :
    QDialog(parent),
    ui(new Ui::CheckInWindow)
{
    currentActivity = act;

    ui->setupUi(this);
}

CheckInWindow::~CheckInWindow()
{
    delete ui;
}

void CheckInWindow::on_Back_released()
{
    this->close();
}
/*
 * Need to check if the QRcode is found or not found, and then reflect the event in a label
 *
 * if qr code is found, get the user object from the QR code, which will be used to create a checkin object
 * the checking object will then be passed to the activity->createActivity
 *
 */
void CheckInWindow::on_Scan_released()
{
    //if statement to check if UUID is found or not

    /*if(UUID is found)
    {
        checkIn = new Checkin(**get the user associated with the UUID**, currentActivity);
        currentActivity->addCheckins(checkin);
        delete checkIn;
        ui->foundLabel->setText("User found");
    }

    */
    /*else
        {
            ui->foundLabel->setText("User not found");
        }
    */
}
