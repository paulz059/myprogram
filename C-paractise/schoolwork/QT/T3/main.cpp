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

#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.resize(512, 512);
    window.setWindowTitle("Mathematical Practice Game");
    QLabel *label2 = new QLabel("Mathematical Practice Game", &window);
    
    label2->setGeometry(20, 2, 0, 0);
    label2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label2->adjustSize();
    QMenuBar *menuBar = new QMenuBar(&window);
    
    QMenu *difficultyMenu = new QMenu("chosee", menuBar);
    difficultyMenu->addAction("High");
    difficultyMenu->addAction("Medium");
    difficultyMenu->addAction("Low");
    // 添加标签
    QLabel *label = new QLabel("choose :");
    difficultyMenu->setTitle("");
    difficultyMenu->menuAction()->setIconText(label->text() + " ");
    difficultyMenu->setContentsMargins(20, 5, 0, 0);

    
    QObject::connect(difficultyMenu, &QMenu::triggered, [&](QAction *action){
        QString diff = action->text();
        difficultyMenu->menuAction()->setIconText("your Difficulty :"+ diff);

    });

    menuBar->addMenu(difficultyMenu);
    
    menuBar->setGeometry(20, 40, 200, menuBar->height());
    QPushButton *startButton = new QPushButton("Start", &window);
    
    startButton->setGeometry(50, 100, 200, 50);
    // QString diff;
    // QObject::connect(startButton, &QPushButton::clicked, [&](){
    //     diff = difficultyMenu->actions().at(0)->text();
    //     qDebug() << diff;
    // });
    window.show();
    return app.exec();
}

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);

//     // create main window
//     QWidget *window = new QWidget;
//     window->setWindowTitle("My Application");

//     // add label and line edit
//     QLabel *label = new QLabel("How are you?", window);
//     QLineEdit *lineEdit = new QLineEdit(window);

//     // add button
//     QPushButton *button = new QPushButton("Submit", window);

//     // connect button's clicked signal to lambda function
//     QObject::connect(button, &QPushButton::clicked, [=]() {
//         QString ans = lineEdit->text();
//         // do something with the answer, e.g. display it in a label
//         QLabel *answerLabel = new QLabel("You said: " + ans, window);
//         answerLabel->setGeometry(50, 100, 200, 50);
//         answerLabel->show();
//     });

//     // set positions of label, line edit, and button
//     label->setGeometry(50, 50, 100, 50);
//     lineEdit->setGeometry(150, 50, 100, 50);
//     button->setGeometry(100, 150, 100, 50);

//     // show window
//     window->show();

//     return app.exec();
// }


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
