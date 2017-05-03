#include "gui/activitysearch.h"
#include "ui_activitysearch.h"
#include "gui/activitywindow.h"
#include "gui/listactivities.h"
#include "database/activity.h"
ActivitySearch::ActivitySearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivitySearch)
{
    ui->setupUi(this);
    /*std::vector<Activity*> eventActivity;
     eventActivity=Activity::getAllActivities();
     for (int t = 0; t<eventActivity.size();t++)
     {
         ui->listWidget->addItem(eventActivity.at(t).getActivityName());
     }
     */
}

ActivitySearch::~ActivitySearch()
{
    delete ui;
}

void ActivitySearch::on_listWidget_itemClicked(QListWidgetItem *item)
{

    ActivityWindow la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}

void ActivitySearch::on_back_released()
{
    this->close();
}

void ActivitySearch::on_searchButton_released()
{
    ui->listWidget->clear();
    ui->listWidget->addItem(ui->lineEdit->text());
}
