#include "prereqselectwindow.h"
#include "ui_prereqselectwindow.h"
#include "database/activity.h"
#include <iostream>

/* TODO
 *
 *
 */

PrereqSelectWindow::PrereqSelectWindow(QWidget *parent, std::vector<Activity*> totalActs) :
    QDialog(parent),
    ui(new Ui::PrereqSelectWindow)
{
    ui->setupUi(this);
    for(int i = 0; i<totalActs.size();i++)
    {
        Qstring name = Qstring::fromStdString(totalActs.at(i)->getName());
        ui->prereqSelectList->addItem(name);
    }

}

PrereqSelectWindow::~PrereqSelectWindow()
{
    delete ui;
}

void PrereqSelectWindow::on_cancelButton_released()
{
    this->close();
}

void PrereqSelectWindow::on_prereqSelectList_itemDoubleClicked(QListWidgetItem *item)
{
    ui->prereqAddedList->addItem(item);
}

void PrereqSelectWindow::on_chooseButton_released()
{
    for(i = 0; i< ui->prereqAddedList->size(); i++)
    {
        ui->prereqAddedList->item(i)->
    }
}
