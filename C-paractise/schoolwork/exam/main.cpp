#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <conio.h>
#include <Windows.h>
#include <cmath>
//1101262001-歐永康
using namespace std;


using namespace std;

#pragma warning(disable: 4996)
int main()
{
    COORD point;
    COORD point2; //遊標 座標
    HANDLE hconsole; // 紀錄console handle
    CONSOLE_CURSOR_INFO curinfo;// 遊標資訊
    SMALL_RECT rect;
    int move ,move2 ; 
    char ch = ' ';
    int cwidth, cheight;//CONSOLE SIZE
    bool fg;
    move = -1;  // Y 軸控制
    move2 = 1; // X 控制
    cout << "input start point ";
    cout << "input point  X  :"<<endl;
    cin >> point.X;
    // point.X = 30; 
     point2.X = 10; 
    cout << "input point 1 Y :" << endl;
    cin>>point.Y ;
    point2.Y = 10; 
    hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

    curinfo.bVisible = false;

    curinfo.dwSize = 1; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);

    cwidth = 60;
    cheight =20;
    rect.Top =0;
    rect.Left=0;
    rect.Bottom =cheight-1;
    rect.Right = cwidth-1;
    fg = SetConsoleWindowInfo(GetStdHandle (STD_OUTPUT_HANDLE), TRUE, &rect);

if(!fg)
{
cout << "請重新調整 cWidth 與 cHeight的大小";
exit(0);

}

while(true)
{
    if(point.X == point2.X && point.Y == point2.Y){
        break;
    }
    if(kbhit())
        break;

    if (point.Y <=0 || point.Y >= rect.Bottom) 
            move = - move;
    if (point2.X <= 0 || point2.X >= rect.Right - 1)
            move2 = -move2;
    SetConsoleTextAttribute(hconsole, 3+ (3 << 6)); 
    SetConsoleCursorPosition(hconsole, point);

    cout << ch;
        
    Sleep(50);
    SetConsoleTextAttribute(hconsole, 0); 
    SetConsoleCursorPosition(hconsole, point);

    cout << ch;
    //Sleep(50);
    SetConsoleTextAttribute(hconsole, 3+(9 << 4));
    SetConsoleCursorPosition(hconsole, point2);
        cout << ch;
    Sleep(50);
    SetConsoleTextAttribute(hconsole, 0); 
    SetConsoleCursorPosition(hconsole, point2);

    cout << ch;

    point.Y +=move;
    point2.X += move2;
}
exit(0);
}
