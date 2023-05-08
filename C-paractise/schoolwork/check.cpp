#include <Windows.h>
#include <string>

// 視窗名稱和視窗尺寸
const std::string WINDOW_NAME = "Math Quiz";
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 400;

// 問題和答案
const int NUM_QUESTIONS = 10;
const int MAX_NUMBER = 100;
int questions[NUM_QUESTIONS][2];
int answers[NUM_QUESTIONS];

// 目前的問題和分數
int currentQuestion = 0;
int score = 0;

// 畫面更新函式
void update(HWND hwnd) {
    // 畫面清空
    HDC hdc = GetDC(hwnd);
    RECT rect;
    GetClientRect(hwnd, &rect);
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);

    // 顯示目前的問題和分數
    std::string questionStr = "Question " + std::to_string(currentQuestion + 1) + ": " +
        std::to_string(questions[currentQuestion][0]) + " + " + std::to_string(questions[currentQuestion][1]) + " = ?";
    TextOutA(hdc, 50, 50, questionStr.c_str(), questionStr.length());

    std::string scoreStr = "Score: " + std::to_string(score);
    TextOutA(hdc, 50, 100, scoreStr.c_str(), scoreStr.length());

    // 釋放裝置內容
    ReleaseDC(hwnd, hdc);
}

// 確認答案函式
void checkAnswer(HWND hwnd) {
    // 讀取使用者輸入的答案
    char answerStr[10];
    GetWindowTextA(GetDlgItem(hwnd, 1), answerStr, 10);
    int userAnswer = atoi(answerStr);

    // 比對答案並更新分數
    if (userAnswer == answers[currentQuestion]) {
        score++;
    }

    // 準備下一個問題
    currentQuestion++;

    // 如果還有問題，更新畫面，否則顯示成績
    if (currentQuestion < NUM_QUESTIONS) {
        update(hwnd);
    }
    else {
        MessageBoxA(hwnd, ("Your score is " + std::to_string(score)).c_str(), "Math Quiz", MB_OK);
        PostQuitMessage(0);
    }
}

// 視窗處理函式
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            // 初始化問題和答案
            for (int i = 0; i < NUM_QUESTIONS; i++) {
                questions[i][0] = rand() % MAX_NUMBER;
                questions[i][1] = rand() % MAX_NUMBER;
                answers[i] = questions[i][0] + questions[i][1];
            }

            // 建立問題和答案的文字框和確認按鈕
CreateWindowA("STATIC", "Answer:", WS_VISIBLE | WS_CHILD, 50, 150, 100, 20, hwnd, NULL, NULL, NULL);
CreateWindowA("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 150, 50, 20, hwnd, (HMENU)1, NULL, NULL);
CreateWindowA("BUTTON", "OK", WS_VISIBLE | WS_CHILD, 220, 150, 50, 20, hwnd, (HMENU)2, NULL, NULL);
update(hwnd);
break;
case WM_COMMAND:
if (LOWORD(wParam) == 2) {
checkAnswer(hwnd);
}
break;
case WM_DESTROY:
PostQuitMessage(0);
break;
default:
return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
return 0;
}

// 程式進入點
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
// 註冊視窗類別
WNDCLASS wc = {};
wc.lpfnWndProc = WindowProc;
wc.hInstance = hInstance;
wc.lpszClassName = WINDOW_NAME.c_str();
RegisterClass(&wc);

// 建立視窗
HWND hwnd = CreateWindowEx(0, WINDOW_NAME.c_str(), WINDOW_NAME.c_str(),
    WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
    WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

// 訊息迴圈
MSG msg;
while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}

return 0;

}
// #include <Windows.h>
// #include <string>

// // 窗口控件 ID
// #define IDC_EDIT_A 1
// #define IDC_EDIT_B 2
// #define IDC_BUTTON_CALCULATE 3
// #define IDC_STATIC_RESULT 4

// // 處理窗口消息的回調函數
// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
// {
//     static HWND hwndEditA, hwndEditB, hwndButton, hwndStatic;
//     static int a = 0, b = 0;

//     switch (uMsg)
//     {
//         case WM_CREATE:
//             // 創建 A、B 兩個編輯框
//             hwndEditA = CreateWindow(
//                 "EDIT",
//                 "",
//                 WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER,
//                 10,
//                 10,
//                 100,
//                 25,
//                 hwnd,
//                 (HMENU)IDC_EDIT_A,
//                 NULL,
//                 NULL
//             );
//             hwndEditB = CreateWindow(
//                 "EDIT",
//                 "",
//                 WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER,
//                 10,
//                 40,
//                 100,
//                 25,
//                 hwnd,
//                 (HMENU)IDC_EDIT_B,
//                 NULL,
//                 NULL
//             );

//             // 創建「計算」按鈕
//             hwndButton = CreateWindow(
//                 "BUTTON",
//                 "確認",
//                 WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
//                 10,
//                 70,
//                 100,
//                 25,
//                 hwnd,
//                 (HMENU)IDC_BUTTON_CALCULATE,
//                 NULL,
//                 NULL
//             );

//             // 創建結果靜態文字框
//             hwndStatic = CreateWindow(
//                 "STATIC",
//                 "",
//                 WS_CHILD | WS_VISIBLE | SS_CENTER,
//                 10,
//                 100,
//                 150,
//                 25,
//                 hwnd,
//                 (HMENU)IDC_STATIC_RESULT,
//                 NULL,
//                 NULL
//             );
//             return 0;

//         case WM_COMMAND:
//             if (LOWORD(wParam) == IDC_BUTTON_CALCULATE)
//             {
//                 // 讀取 A、B 兩個數字
//                 char buf[16];
//                 GetWindowText(hwndEditA, buf, sizeof(buf));
//                 a = std::stoi(buf);
//                 GetWindowText(hwndEditB, buf, sizeof(buf));
//                 b = std::stoi(buf);

//                 // 計算並顯示結果
//                 int result = a + b;
//                 std::string resultStr = std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(result);
//                 SetWindowText(hwndStatic, resultStr.c_str());
//             }
//             return 0;

//         case WM_DESTROY:
//             PostQuitMessage(0);
//             return 0;
//     }

//     return DefWindowProc(hwnd, uMsg, wParam, lParam);
// }

// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
// {
//     // 註冊窗口類別
//     WNDCLASS wc = {};
//     wc.lpfnWndProc = WindowProc;
//     wc.hInstance = hInstance;
//     wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//     wc.lpszClassName = "MyWindowClass";
//     RegisterClass(&wc);

//     // 創建窗口
//     HWND hwnd = CreateWindow(
//         "MyWindowClass",
//         "計算 A+B",
//         WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//         CW_USEDEFAULT,
//         CW_USEDEFAULT,
//         300,
//         200,
//         NULL,
//         NULL,
//         hInstance,
//         NULL
//     );

//     // 處理窗口消息
//     MSG msg = {};
//     while (GetMessage(&msg, NULL, 0, 0))
//     {
//         TranslateMessage(&msg);
//         DispatchMessage(&msg);
//     }

//     return 0;
// }