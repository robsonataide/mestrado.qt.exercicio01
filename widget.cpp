#include "widget.h"
#include "ui_widget.h"
#include <QInputDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->listWidget->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this,
            SLOT(updateDeleteEnabled()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addButton_clicked()
{
    QString newText = QInputDialog::getText(this,"Enter text","Text:");
    if(!newText.isEmpty()){
        ui->listWidget->addItem(newText);
    }
}



void Widget::on_deleteButton_clicked()
{
    foreach (QListWidgetItem *item, ui->listWidget->selectedItems()) {
        delete item;
    }
}

void Widget::updateDeleteEnabled(){
    ui->deleteButton->setEnabled(ui->listWidget->selectedItems().count()>0);
}
