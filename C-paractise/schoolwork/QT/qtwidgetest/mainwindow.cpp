#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <random>
#include <ctime>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // 創建小部件
    QLabel *questionLabel = new QLabel("請求和:");
    QLineEdit *answerEdit = new QLineEdit;
    QPushButton *confirmButton = new QPushButton("確認");

    // 創建布局並添加小部件
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(questionLabel);
    mainLayout->addWidget(answerEdit);
    mainLayout->addWidget(confirmButton);

    // 創建窗口部件並設置布局
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // 隨機生成問題
    std::srand(std::time(nullptr));
    int num1 = std::rand() % 100;
    int num2 = std::rand() % 100;
    int answer = num1 + num2;

    // 設置問題標籤的文本
    questionLabel->setText(QString("請求和: %1 + %2 =").arg(num1).arg(num2));

    // 設置按鈕的單擊事件處理程序
    connect(confirmButton, &QPushButton::clicked, [=]() {
        // 獲取用戶
    QString answerText = answerEdit->text();
    bool ok;
    int userAnswer = answerText.toInt(&ok);
    if (ok && userAnswer == answer) {
        QMessageBox::information(this, "正確", "答案正確!");
    } else {
        QMessageBox::warning(this, "錯誤", "答案錯誤!");
    }
});