#include "main.h"
#include "ui_main.h"

main::main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::main)
{
    ui->setupUi(this);
}

main::~main()
{
    delete ui;
}
