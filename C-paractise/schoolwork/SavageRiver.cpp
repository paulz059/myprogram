#include <stdio.h>
#include<iostream>
#define MAX 100
  using namespace std;
  
  /*
  A�� �G A
  B�� �G B
  ���H�G S
  �Фh�G M
  ��  �G BOAT
  */

//????�w?
struct status  //�إ� struct �s�W ���e 
{
	int left_c;     //���ǳ��H   
	int right_c;    //�k�ǳ��H 
	int left_y;		//���ǱФh 
	int right_y;	//�k�ǱФh 
	int boat_location;   //��  1�� ����  -1���k�� 
};
struct status arr[MAX];
int index=0;   // index �x�s�g�L�h�p�� �B�� �C���L�e index �[�@ 
int count=0;  // count �����X�h �L�e��k 
int y_num=3,c_num=3;  //cum�� ���H�Фh�ƶq  

int judge(status t);


int main()
{
	printf("\n...........�˯�..............\n");
	arr[index].left_c = y_num;
	arr[index].left_y = c_num;
	arr[index].right_c = 0;
	arr[index].right_y = 0;
	arr[index].boat_location = 1;
	judge(arr[index]);
	printf("�w���z���%d���L�e���|�I�åB�w�����[�������I\n",count);
	    return 0;

}


int judge(status t)
{	
	if(	t.right_c == y_num && t.right_y == c_num)  //���L�X �L�e�B�J  �Ҧ��H�h�F�k��  
	{
		count++;
		printf("\n����%d�����|�I",count); printf("�ݭn�L�e%d����\n�G",index) ;
		printf("�����ǱФh�ƶq\t�������H�ƶq\t�k���ǱФh�ƶq\t�k�����H�ƶq\t���m\n");
		for(int i = 0; i <= index ; i++)
		{
			printf("\t%3d\t",arr[i].left_c);
			printf("\t%3d\t",arr[i].left_y);
			printf("\t%3d\t",arr[i].right_c);
			printf("\t%3d\t",arr[i].right_y);
			
			switch(arr[i].boat_location){
				case -1:{
					printf("\t������\t");	break;
				}	
				case 1:{
					printf("\���k��\t");
					break;
				}
			}
		//	printf("%2d\t",arr[i].boat_location);
			printf("\n");
		}
		return 0;
	}

	//�P�_���O�_���`�ާ@
	for(int i = 0; i < index; i++)
	{
		if(t.left_c == arr[i].left_c && t.left_y == arr[i].left_y)
		{
			if(t.boat_location == arr[i].boat_location)
			{
				return 0;
			}
			
		}
	}
	//�H�ƬO�_�X�z��
	if(t.left_c < 0 || t.left_y < 0 || t.right_c < 0 || t.right_y < 0  )
	{
		return 0;
	}
	//�ǱФh�O�_�Q�Y
	if((t.left_c < t.left_y && t.left_c != 0) || (t.right_c < t.right_y && t.right_c != 0) )
	{
		return 0;
	}

	//�w�q�@���{�ɸ`�I
	struct status tt;

	//�@�ӶǱФh�L�e
	tt.left_c = t.left_c - 1 * t.boat_location;
	tt.left_y = t.left_y;
	tt.right_c = t.right_c + 1 * t.boat_location;
	tt.right_y = t.right_y;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	arr[index] = tt;
	judge(arr[index]);
	index = index-1;

	//�@�ӳ��H�L�e
	tt.left_c = t.left_c;
	tt.left_y = t.left_y - 1 * t.boat_location;
	tt.right_c = t.right_c;
	tt.right_y = t.right_y + 1 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	arr[index] = tt;
	judge(arr[index]);
	index = index-1;


	//�@���H �@�Фh 
	tt.left_c = t.left_c - 1 * t.boat_location;
	tt.left_y = t.left_y - 1 * t.boat_location;
	tt.right_c = t.right_c + 1 * t.boat_location;
	tt.right_y = t.right_y + 1 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	arr[index] = tt;
	judge(arr[index]);
	index = index-1;
	
	//��ӶǱФh�L�e
	tt.left_c = t.left_c - 2 * t.boat_location;
	tt.left_y = t.left_y;
	tt.right_c = t.right_c + 2 * t.boat_location;
	tt.right_y = t.right_y;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	arr[index] = tt;
	judge(arr[index]);
	index = index - 1;
	
	//�⳥�H 
	tt.left_c = t.left_c;
	tt.left_y = t.left_y - 2 * t.boat_location;
	tt.right_c = t.right_c ;
	tt.right_y = t.right_y + 2 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	arr[index] = tt;
	judge(arr[index]);
	index = index-1;	

	return 0;
}



