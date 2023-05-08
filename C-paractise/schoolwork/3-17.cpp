#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
using namespace std;

struct userinfo{
	string name,gender;
	int age;
};

void placeCursor(HANDLE,int,int);
void displayprompts(HANDLE);
void getuserInput(HANDLE,userinfo&);
void displayData(HANDLE,userinfo);

int main(void) {
   //coding here
	userinfo input;
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	displayprompts(screen);
	getuserInput(screen,input);
	displayData(screen,input);
	return 0;
   
  
   }
void placeCursor(HANDLE screen,int row,int col){
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen,position);
}
void displayprompts(HANDLE screen){
	placeCursor(screen,2,35);
	cout << "****input data *****";
	placeCursor(screen,5,25);
	cout << "name"<<endl;
	placeCursor(screen,7,25);
	cout<< "age :                    sex:m/f"<<endl;
	
	
}
void getuserInput(HANDLE screen,userinfo &input){
	placeCursor(screen,5,33);
	getline(cin,input.name);
	placeCursor(screen,7,33);
	cin >>input.age;
	placeCursor(screen,7,55);
	cin >> input.gender;
}
void displayData(HANDLE screen,userinfo input){
	system("cls");  // eb
	placeCursor(screen,5,20);
	cout << " your input \n";
	cout <<"name :"<< input.name<<endl;
	cout <<"age :"<< input.age<<endl;
	cout <<"sex :"<< input.gender<<endl;
	system("pause");
}
