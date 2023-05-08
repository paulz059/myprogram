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
//�H����J10�ӫ~(�~�W�B����B�Ӯa)�A�Q���쵲��C���c�s��ơA�Q�αƧǤ�k�B�z�쵲��C���c��ơA���ӻ���Ѥp��j�ƧǨÿ�X���G�C
	char name[30];
	int score;
	char st[30];
	status *link;                     // status ���c : NAME - score - ST -   LINK(���V�@��status) 
};
status *head, *current, *previous, *prt;

int main()
{
	head = new status;  //�إ߰ʺA head
	head->link = NULL;   // head��LINK ���V0 
	
	char choice;
	cout << "i : [INSERT]" << endl;
	cout << "S : [SHOW]" << endl;
	cout << "Q : [QUIET]" << endl;
	cout <<endl;
	while (1){
	
	cout << "�п�J�ﶵ ";
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
	default : cout << " choice���~\n\n";
	}
} 
}
void insert(){
	prt = new status;
	cout << "input name ";
	cin >> prt->name;
	cout << "input score ";
	cin >> prt->score;
	//cout << "input store name  ";
	//cin >> prt->st;
	
	previous = head;       //  �Nhead �x�� previous 
	current = head->link;  // head.link��Jcurrent           
	while(current != NULL && current->score < prt->score){   //��escore �p���J score 
		previous = current;				// �W�@�� = ��e�� 
		current = current->link;    //��e�� ����  ��e��LINK 
		
	}
	prt->link = current;  //  prt->link ���Vcurrent
	previous->link = prt;  // pre->link ���V prt 
	cout << "insert ok " << endl <<endl;
	
}


void del()
{
	char delName[15];
	cout << "input del name ";
	cin >> delName;
	
	previous = head;      //�N�w���^�Ĥ@��  
	current = previous->link;     // current �w��� pre.link 
	while(current != NULL && strcmp(current->name, delName) != 0){     //strcmp �@�r���� �C delname =current  
	//�p�G��^��<0�A�h���str1�p��str2 �p�G��^�ȡA�p�G> 0�A�h���str2 �p�� str1�p�G��^��= 0�A�h���str1 ����str2




		previous = current;             // �ƻs current �� �W�@�� 
		current = current->link; 		//  �ηN���V�U���@��  
	}
	if (current != NULL){    // �W�zwhile �����ɥN�� current ��F���w ��m �p current���� ���� 
		previous->link = current->link;
		delete current;                
		cout <<delName << "deleted" <<endl << endl; 
	} 
	else{
		cout << delName << "no exist\n\n";  //�䤣��delname 
	}
}

void show()
{
	current = head->link;
	cout << fixed << setprecision(2);
	cout << "\nName" << "            score" << endl;
	while (current != NULL) { //��current ������ 
		cout << setw(15) <<left << current->name << setw(6) <<current->score  ; // ��X 
		current = current->link;     // current ���U�@�� 
		cout <<endl;
	}
	cout <<endl;
}


