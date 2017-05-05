#include "gui/activitywindow.h"
#include "ui_activitywindow.h"
#include "gui/checkinwindow.h"
#include "gui/listactivities.h"
#include <QString>
#include "database/checkin.h"
#include "QRCapture.h"
#include "database/user.h"
#include <vector>
#include <iostream>

ActivityWindow::ActivityWindow(QWidget *parent, Activity* act) :
    QDialog(parent),
    ui(new Ui::ActivityWindow)
{
    ui->setupUi(this);
    activity=act;
    QString name = QString::fromStdString(activity->getActivityName());
    ui->label_2->setText(name);

    std::vector<Checkin*> listCheckIn = activity->getCheckins();
    for(unsigned int i = 0; i<listCheckIn.size();i++)
   {

      User* user = User::loadUserById(listCheckIn.at(i)->getUserId());
        QString name = QString::fromStdString(user->getUserFname());
       ui->listWidget->addItem(name);
   }

}

ActivityWindow::~ActivityWindow()
{
    delete ui;
}

void ActivityWindow::on_QR_released()
{
    Camera* scanner = new Camera(this, activity, this);
    scanner->show();
}

void ActivityWindow::updateList()
{
    ui->listWidget->clear();
    std::vector<Checkin*> listCheckIn = activity->getCheckins();
   for(unsigned int i = 0; i<listCheckIn.size();i++)
   {

      User* user = User::loadUserById(listCheckIn.at(i)->getUserId());
      QString name = QString::fromStdString(user->getUserFname());
       ui->listWidget->addItem(name);
       ui->listWidget->update();
   }
}

void ActivityWindow::on_back_released()
{
    this->close();
}
