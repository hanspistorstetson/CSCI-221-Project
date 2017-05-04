#include "gui/activitywindow.h"
#include "ui_activitywindow.h"
#include "gui/checkinwindow.h"
#include "gui/listactivities.h"

/*
 * TODO this will need an activity passed to the constructor
 */
ActivityWindow::ActivityWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityWindow)
{
    ui->setupUi(this);
}

ActivityWindow::~ActivityWindow()
{
    delete ui;
}

void ActivityWindow::on_QR_released()
{
    /*
     * TODO
     * This will need the activity from the constructor
     */

//    CheckInWindow la;
//    this->hide();
//    la.setModal(true);
//    la.exec();
//    this->show();
}


void ActivityWindow::on_back_released()
{
    this->close();
}
