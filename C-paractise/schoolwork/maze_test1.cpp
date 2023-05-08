#include <stdio.h>
#include <stdlib.h>
#define SIZE 11
//地圖 maze[][]
//起點 : start.x=1 start.y=1 
//終點:  end.x=7 end.y=7
void visit(int, int);
void print(int[][SIZE]);

void print(int maze[][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) { 
        for(j = 0; j < SIZE; j++) 
		switch(maze[i][j]) {
            case 0 : printf("  "); break;
            case 1 : printf("◇"); break;
            case 2 : printf("HH"); 
        }
        printf("\n"); 
    }printf("\n");      
}
int maze[SIZE][SIZE] =
   
   						    {{2, 2, 2, 2, 2, 2, 2, 2, 2},
                            {2, 0, 0, 0, 0, 0, 0, 0, 2},
                            {2, 0, 2, 2, 0, 2, 2, 0, 2},
                            {2, 0, 2, 0, 0, 2, 0, 0, 2},
                            {2, 0, 2, 0, 2, 0, 2, 0, 2},
                            {2, 0, 0, 0, 0, 0, 2, 0, 2},
                            {2, 2, 0, 2, 2, 0, 2, 2, 2},
                            {2, 0, 0, 0, 0, 0, 0, 0, 2},
                            {2, 2, 2, 2, 2, 2, 2, 2, 2}}; 
int startY = 1, startX = 1;
// 入口
int endI = 8, endJ = 8;
// 出口
int main(void) {
   
	int X, Y;
	printf("顯示迷宮：\n");
	print(maze);

	visit(startY, startX);
	return 0;
}
void visit(int i, int j) {
   
   
	int m, n;
	maze[i][j] = 1;
	if(i == endI && j == endJ) {
   
   
		printf("\n顯示答案路徑：\n");
		print(maze);
	}
	if(maze[i][j+1] == 0) visit(i, j+1);
	if(maze[i+1][j] == 0) visit(i+1, j);
	if(maze[i][j-1] == 0) visit(i, j-1);
	if(maze[i-1][j] == 0) visit(i-1, j);
	maze[i][j] = 0;
}
