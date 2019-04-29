#ifndef MAIN_H
#define MAIN_H

#include <QWidget>

namespace Ui {
class main;
}

class main : public QWidget
{
    Q_OBJECT

public:
    explicit main(QWidget *parent = 0);
    ~main();

private:
    Ui::main *ui;
};

#endif // MAIN_H
