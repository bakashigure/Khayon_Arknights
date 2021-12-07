//
// Created by bakashigure on 12/7/2021.
//

#ifndef KHAYON_ARKNIGHTS_MAINWINDOW_H
#define KHAYON_ARKNIGHTS_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    int cornerRadius = 20;
    void Init();
    QWidget *border = nullptr;

    Ui::MainWindow *ui;
};


#endif //KHAYON_ARKNIGHTS_MAINWINDOW_H
