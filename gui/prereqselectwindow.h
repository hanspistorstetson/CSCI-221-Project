#ifndef PREREQSELECTWINDOW_H
#define PREREQSELECTWINDOW_H

#include <QDialog>

namespace Ui {
class PrereqSelectWindow;
}

class PrereqSelectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PrereqSelectWindow(QWidget *parent, std::vector<Activity*>);
    ~PrereqSelectWindow();

private slots:
    void on_cancelButton_released();

    void on_prereqSelectList_itemDoubleClicked(QListWidgetItem *item);

    void on_chooseButton_released();

private:
    Ui::PrereqSelectWindow *ui;
};

#endif // PREREQSELECTWINDOW_H
