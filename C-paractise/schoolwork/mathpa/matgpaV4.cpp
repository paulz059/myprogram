#include"matgpaV4.h"
int genNum(int low, int high) {       //刷出隨機整數
    return rand() % (high - low + 1) + low;
}

char genOp() {  //刷出隨機OP
    char operators[] = {'+', '-', '*', '/'};
    return operators[rand() % 4];
}

int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return x / y; }
int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }

int calculate(int a, int b, int (*func)(int, int)) {
    return func(a, b);
}

int checkop( char op){
    int codeop;
    if (op == '*' ){
       return 1;
    }else if  (op == '/' ){
        return 2;
    }else if  (op == '-' ){
        return 3;
    }else if  (op == '+' ){
        return 3;
    }
    return 0;
}
int calculatsetp2 (int num2,int num3, char codeop){
    int tempans;
    int (*func)(int, int);  // 定義一個指向函數的指針
    switch (codeop) {
        case '*':
            func = multiply;
            break;
        case '/':
            func = divide;
            break;
        case '+':
            func = add;
            break;
        case '-':
            func = subtract;
            break;
    }
    tempans = calculate(num2, num3, func);
    return tempans;
}
int calculateans(int num1,int num2,int num3,char op1,char op2){
    int answer;
    int codeop1 = checkop(op1);
    int codeop2=  checkop(op2);

    if (codeop1 > codeop2) {       //判斷誰執行先  較小者先行 
        answer =calculatsetp2(num2,num3,op2);
        
        answer = calculatsetp2(num1,answer,op1);
        
    }else {
        answer = calculatsetp2(num1,num2,op1);
        
        answer = calculatsetp2(answer,num3,op2);
        
    }
    return answer;
}

int calculateans(int num1,int num2,char op1){
    int answer;
    int codeop1 = checkop(op1);
    answer =calculatsetp2(num1,num2,op1);
    return answer;
}

void randquestion (int difficulty){
    string tempques;
    
     for (int i = 1; i <= NUM_QUESTIONS; i++){ // 10題
        stringstream ss; // 型別 
    
        if( difficulty == 1){
            int num1 = genNum(1, 10);     
            int num2 = genNum(1, 10);
            char op1 = genOp();
            ss << num1 << op1  << num2 ;
            ans[i-1] = calculateans(num1,num2,op1);     
            tempques = ss.str();

        }else if ( difficulty == 2){
            int num1 = genNum(10, 100);     
            int num2 = genNum(10, 100);
            char op1 = genOp();
            ss << num1 << op1  << num2 ; 
            tempques = ss.str();   
            ans[i-1] = calculateans(num1,num2,op1);    
        }else if ( difficulty == 3){
            int num1 = genNum(10, 100);     
            int num2 = genNum(10, 100);
            int num3 = genNum(10, 100);
            char op1 = genOp();
            char op2 = genOp();
            
            ss << num1 << op1  << num2 << op2 << num3;            
            tempques = ss.str();            
            ans[i-1] = calculateans(num1,num2,num3,op1,op2); //計數答案 
            
        }

        qusention[i-1] = tempques; // 10題隨機問題 
        


    }
    

}

void placeCursor(HANDLE screen,int row,int col){
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen,position);
}

void mathPractice(string (&arr)[10]){
    
    
    int userans;
    
    
    for (int i = 1; i <= NUM_QUESTIONS; i++){
        system("cls");
        placeCursor(screen,2,35);
        cout << "練習開始" <<endl;
        placeCursor(screen,5,35);
        cout <<  "第" << i << "題" <<endl ;
        placeCursor(screen,8,35);
        cout << qusention[i-1]<<" = " << endl; 
        placeCursor(screen,8,qusention[i-1].length()+39);
        cin >> userans ;
        if ( userans == ans[i-1]){
            placeCursor(screen,10,35);
            cout << "答案正確" <<endl;
            score += 1;
            
            //cin.get();   // 等待使用者按下 Enter 鍵
        }else{
            placeCursor(screen,10,35);
            cout << "答案錯誤" <<endl;
            
             // 等待使用者按下 Enter 鍵
        }
        placeCursor(screen,13,35);
        cout << "按下enter 繼續";
        fflush(stdin);  // 清空輸入緩衝區
        cin.ignore();   // 等待使用者按下 Enter 鍵

        

    }
    return ;

}
void showans(){
    system("cls");
    placeCursor(screen,5,35);
    cout << " 正確答案" <<endl;
    for (int i = 1; i <= NUM_QUESTIONS; i++){
    placeCursor(screen,5+i,35);
    cout << qusention[i-1] << " = "<< ans[i-1] << endl;

    }
        placeCursor(screen,20,35);
        cout << "你的成績 "<< score <<endl;
}

bool askPlayAgain(){
    bool again;
    char input;
    
    placeCursor(screen,21,35);
    cout << "再試一次 Y / N " <<endl;
    placeCursor(screen,22,35);
     cin >> input;
    return input == 'y' || input == 'Y';
}
