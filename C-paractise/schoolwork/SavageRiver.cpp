#include <stdio.h>
#include<iostream>
#define MAX 100
  using namespace std;
  
  /*
  A岸 ： A
  B岸 ： B
  野人： S
  教士： M
  船  ： BOAT
  */

//????定?
struct status  //建立 struct 新增 內容 
{
	int left_c;     //左傳野人   
	int right_c;    //右傳野人 
	int left_y;		//左傳教士 
	int right_y;	//右傳教士 
	int boat_location;   //船  1為 左邊  -1為右邊 
};
struct status arr[MAX];
int index=0;   // index 儲存經過多小次 運輸 每次過河 index 加一 
int count=0;  // count 為有幾多 過河方法 
int y_num=3,c_num=3;  //cum為 野人教士數量  

int judge(status t);


int main()
{
	printf("\n...........檢索..............\n");
	arr[index].left_c = y_num;
	arr[index].left_y = c_num;
	arr[index].right_c = 0;
	arr[index].right_y = 0;
	arr[index].boat_location = 1;
	judge(arr[index]);
	printf("已為您找到%d條過河路徑！並且已全部加載完畢！\n",count);
	    return 0;

}


int judge(status t)
{	
	if(	t.right_c == y_num && t.right_y == c_num)  //打印出 過河步驟  所有人去了右邊  
	{
		count++;
		printf("\n找到第%d條路徑！",count); printf("需要過河%d次數\n：",index) ;
		printf("左岸傳教士數量\t左岸野人數量\t右岸傳教士數量\t右岸野人數量\t船位置\n");
		for(int i = 0; i <= index ; i++)
		{
			printf("\t%3d\t",arr[i].left_c);
			printf("\t%3d\t",arr[i].left_y);
			printf("\t%3d\t",arr[i].right_c);
			printf("\t%3d\t",arr[i].right_y);
			
			switch(arr[i].boat_location){
				case -1:{
					printf("\t往左岸\t");	break;
				}	
				case 1:{
					printf("\往右岸\t");
					break;
				}
			}
		//	printf("%2d\t",arr[i].boat_location);
			printf("\n");
		}
		return 0;
	}

	//判斷有是否重复操作
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
	//人數是否合理嗎
	if(t.left_c < 0 || t.left_y < 0 || t.right_c < 0 || t.right_y < 0  )
	{
		return 0;
	}
	//傳教士是否被吃
	if((t.left_c < t.left_y && t.left_c != 0) || (t.right_c < t.right_y && t.right_c != 0) )
	{
		return 0;
	}

	//定義一個臨時節點
	struct status tt;

	//一個傳教士過河
	tt.left_c = t.left_c - 1 * t.boat_location;
	tt.left_y = t.left_y;
	tt.right_c = t.right_c + 1 * t.boat_location;
	tt.right_y = t.right_y;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	arr[index] = tt;
	judge(arr[index]);
	index = index-1;

	//一個野人過河
	tt.left_c = t.left_c;
	tt.left_y = t.left_y - 1 * t.boat_location;
	tt.right_c = t.right_c;
	tt.right_y = t.right_y + 1 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	arr[index] = tt;
	judge(arr[index]);
	index = index-1;


	//一野人 一教士 
	tt.left_c = t.left_c - 1 * t.boat_location;
	tt.left_y = t.left_y - 1 * t.boat_location;
	tt.right_c = t.right_c + 1 * t.boat_location;
	tt.right_y = t.right_y + 1 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	arr[index] = tt;
	judge(arr[index]);
	index = index-1;
	
	//兩個傳教士過河
	tt.left_c = t.left_c - 2 * t.boat_location;
	tt.left_y = t.left_y;
	tt.right_c = t.right_c + 2 * t.boat_location;
	tt.right_y = t.right_y;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	arr[index] = tt;
	judge(arr[index]);
	index = index - 1;
	
	//兩野人 
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



