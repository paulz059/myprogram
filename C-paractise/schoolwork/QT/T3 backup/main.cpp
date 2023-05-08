// #include <QtWidgets/QApplication>
// #include <QtWidgets/QLabel>
// #include <QtWidgets/QLineEdit>
// #include <QtWidgets/QPushButton>
// #include <QtWidgets/QVBoxLayout>
// #include <QtWidgets/QWidget>
// #include <QRandomGenerator> // 新增的標頭文件

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv); // 初始化QT應用程式

//     QWidget *window = new QWidget; // 創建一個QWidget窗口
//     window->setWindowTitle("Calculator"); // 設置窗口標題

//     QLabel *label1 = new QLabel("1 + 1 = "); // 創建一個QLabel標籤，顯示"1 + 1 = "
//     QLineEdit *lineEdit = new QLineEdit; // 創建一個QLineEdit文本框
//     QPushButton *button = new QPushButton("Calculate"); // 創建一個QPushButton按鈕，顯示"Calculate"
//     QLabel *label2 = new QLabel(); // 創建一個QLabel標籤，用於顯示隨機數

//     QVBoxLayout *layout = new QVBoxLayout; // 創建一個QVBoxLayout佈局
//     layout->addWidget(label1); // 把標籤1添加到佈局中
//     layout->addWidget(lineEdit); // 把文本框添加到佈局中
//     layout->addWidget(button); // 把按鈕添加到佈局中
//     layout->addWidget(label2); // 把標籤2添加到佈局中

//     window->setLayout(layout); // 設置窗口的佈局為剛剛建立的佈局

//     QObject::connect(button, &QPushButton::clicked, [=]() {
//         QString text = lineEdit->text(); // 讀取文本框中的內容
//         int num = text.toInt(); // 把文本轉換為整數
//         label1->setText(QString("1 + 1 = %1").arg(num + 1)); // 更新標籤1的內容
//         int randNum = QRandomGenerator::global()->bounded(100); // 生成一個0-99的隨機數
//         label2->setText(QString("Random Number: %1").arg(randNum)); // 更新標籤2的內容
//     });

//     window->show(); // 顯示窗口

//     return app.exec(); // 進入QT應用程式的事件循環
// }
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QRandomGenerator>
#include <QtWidgets/QLineEdit>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 創建開始窗口
    QWidget *startWindow = new QWidget;
    startWindow->setWindowTitle("Math Practice");

    // 添加標籤和按鈕
    QLabel *titleLabel = new QLabel("Math Practice", startWindow);
    titleLabel->setAlignment(Qt::AlignCenter);
    QPushButton *enterButton = new QPushButton("Enter", startWindow);

    // 設置標籤和按鈕的大小和位置
    titleLabel->setGeometry(50, 50, 200, 50);
    enterButton->setGeometry(100, 150, 100, 50);

    // 顯示開始窗口
    startWindow->show();

    // 創建練習窗口
    QWidget *exerciseWindow = new QWidget;
    exerciseWindow->setWindowTitle("Exercise");

    // 添加標籤、編輯框和按鈕
    QLabel *questionLabel = new QLabel("1 + 1 = ", exerciseWindow);
    QLineEdit *answerEdit = new QLineEdit(exerciseWindow);
    QPushButton *calculateButton = new QPushButton("Calculate", exerciseWindow);
    QLabel *resultLabel = new QLabel(exerciseWindow);

    // 設置標籤、編輯框和按鈕的大小和位置
    questionLabel->setGeometry(50, 50, 100, 50);
    answerEdit->setGeometry(150, 50, 100, 50);
    calculateButton->setGeometry(100, 150, 100, 50);
    resultLabel->setGeometry(50, 250, 200, 50);

    // 初始化問題數組和問題指標
    int questions[] = { 2, 3, 5, 6 };
    

    // 顯示練習窗口
    exerciseWindow->hide();

    // 連接按鈕的clicked信號到槽函數
    QObject::connect(enterButton, &QPushButton::clicked, [=]() {
        // 關閉開始窗口，顯示練習窗口
        startWindow->hide();
        exerciseWindow->show();
    });

    QObject::connect(calculateButton, &QPushButton::clicked, [=]() {
        // 讀取用戶輸入的數字
        int questionIndex = 0;
        QString answerText = answerEdit->text();
        bool ok;
        int answer = answerText.toInt(&ok);

        // 計算結果
        if (ok) {
            int result = 1 + 1 + answer;
            resultLabel->setText(QString::number(result));

            // 切換問題
            questionIndex += 1;
            if (questionIndex >= 4) {
                questionIndex = 0;
            }
            questionLabel->setText(QString::number(questions[questionIndex]) + " + 1 = ");
        }
    });

    return app.exec();
}


// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     QWidget *startWindow = new QWidget; // 創建一個QWidget開始窗口
//     startWindow->setWindowTitle("Welcome"); // 設置窗口標題

//     QLabel *label = new QLabel("Math Practice"); // 創建一個QLabel標籤，顯示"Math Practice"
//     QPushButton *button = new QPushButton("Enter"); // 創建一個QPushButton按鈕，顯示"Enter"

//     QVBoxLayout *layout = new QVBoxLayout; // 創建一個QVBoxLayout佈局
//     layout->addWidget(label); // 把標籤添加到佈局中
//     layout->addWidget(button); // 把按鈕添加到佈局中

//     startWindow->setLayout(layout); // 設置窗口的佈局為剛剛建立的佈局

//     // 在按下進入按鈕時，切換到練習窗口
//     QObject::connect(button, &QPushButton::clicked, [=]() {
//         QWidget *practiceWindow = new QWidget; // 創建一個QWidget練習窗口
//         practiceWindow->setWindowTitle("Math Practice"); // 設置窗口標題

//         QLabel *label1 = new QLabel("1 + 1 = ");
//         QLineEdit *lineEdit = new QLineEdit;
//         QPushButton *calculateButton = new QPushButton("Calculate");
//         QLabel *label2 = new QLabel();

//         QVBoxLayout *layout1 = new QVBoxLayout;
//         layout1->addWidget(label1);
//         layout1->addWidget(lineEdit);
//         layout1->addWidget(calculateButton);
//         layout1->addWidget(label2);

//         practiceWindow->setLayout(layout1);

//         // 在按下計算按鈕時，計算結果和隨機數並更新標籤
//         QObject::connect(calculateButton, &QPushButton::clicked, [=]() {
//             QString text = lineEdit->text();
//             int num = text.toInt();
//             label1->setText(QString("1 + 1 = %1").arg(num + 1));
//             int randNum = QRandomGenerator::global()->bounded(100);
//             label2->setText(QString("Random Number: %1").arg(randNum));
//         });

//         practiceWindow->show(); // 顯示練習窗口
//         startWindow->close(); // 關閉開始窗口
//     });

//     startWindow->show(); // 顯示開始窗口

//     return app.exec();
// }
