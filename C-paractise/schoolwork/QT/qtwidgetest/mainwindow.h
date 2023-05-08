#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *questionLabel;
    QLineEdit *answerEdit;
    QPushButton *confirmButton;

    int num1;
    int num2;
    int answer;

    void generateQuestion();

private slots:
    void confirmButtonClicked();
};
#endif // MAINWINDOW_H
