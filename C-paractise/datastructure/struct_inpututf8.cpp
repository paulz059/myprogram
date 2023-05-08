#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
void show();
void insert();
void del ();
void search();
  struct status  
{
//隨機輸入10商品(品名、價格、商家)，利用鏈結串列結構存資料，利用排序方法處理鏈結串列結構資料，按照價格由小到大排序並輸出結果。
	char name[30];
	int pirce;
	char st[30];
	status *link;                     // status 結構 : NAME - PIRCE - ST -   LINK(指向一個status) 
};
status *head, *current, *previous, *prt;

int main()
{
	head = new status;  //建立動態 head
	head->link = NULL;   // head的LINK 指向0 
	
	char choice;
	cout << "i : [INSERT]" << endl;
	cout << "S : [SHOW]" << endl;
	cout << "Q : [QUIET]" << endl;
	cout <<endl;
	while (1){
	
	cout << "請輸入選項 ";
	cin >>choice ;
	switch (choice) {
	case 'i':
		insert();
		break;
	case 'd':
		del();
		break;
	case's':
		show();
		break;
	case 'q': cout << "\n BYR BYR ! \n";
		exit(1); 
	default : cout << " choice錯誤\n\n";
	}
} 
}
void insert(){
	prt = new status;
	cout << "input name ";
	cin >> prt->name;
	cout << "input pirce ";
	cin >> prt->pirce;
	cout << "input store name  ";
	cin >> prt->st;
	
	previous = head;       //  將head 儲左 previous 
	current = head->link;  // head.link放入current           
	while(current != NULL && current->pirce < prt->pirce){   //當前pirce 小於輸入 pirce 
		previous = current;				// 上一格 = 當前格 
		current = current->link;    //當前格 等於  當前格LINK 
		
	}
	prt->link = current;  //  prt->link 指向current
	previous->link = prt;  // pre->link 指向 prt 
	cout << "insert ok " << endl <<endl;
	
}


void del()
{
	char delName[15];
	cout << "input del name ";
	cin >> delName;
	
	previous = head;      //將定位返回第一格  
	current = previous->link;     // current 定位至 pre.link 
	while(current != NULL && strcmp(current->name, delName) != 0){     //strcmp 作字串比較 。 delname =current  
	//如果返回值<0，則表明str1小於str2 如果返回值，如果> 0，則表明str2 小於 str1如果返回值= 0，則表明str1 等於str2




		previous = current;             // 複製 current 到 上一格 
		current = current->link; 		//  用意為向下走一格  
	}
	if (current != NULL){    // 上述while 完成時代表 current 到達指定 位置 如 current不為 為空 
		previous->link = current->link;
		delete current;                
		cout <<delName << "deleted" <<endl << endl; 
	} 
	else{
		cout << delName << "no exist\n\n";  //找不到delname 
	}
}

void show()
{
	current = head->link;
	cout << fixed << setprecision(2);
	cout << "\nName" << "            score" <<"  store name"<< endl;
	while (current != NULL) { //當current 不為空 
		cout << setw(15) <<left << current->name << setw(6) <<current->pirce << current->st ; // 輸出 
		current = current->link;     // current 跳下一格 
		cout <<endl;
	}
	cout <<endl;
}

