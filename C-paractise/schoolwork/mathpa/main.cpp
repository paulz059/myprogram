
#include"matgpaV4.cpp"


int main() {

    
    placeCursor(screen,2,35);
    cout << "數學練習程式" ;
     while (true) {
    srand(time(0));  //隨機數 函數
    placeCursor(screen,5,35);
    cout << "請選擇難度 (1: 初級, 2: 中級, 3: 高級): ";
    cin >> difficulty;
    randquestion (difficulty); // 產生問題
    mathPractice( qusention );
    showans();
    if (askPlayAgain()) {
                score = 0;
                system("cls");
            } else {
                break;
            }
     }
    return 0;
}