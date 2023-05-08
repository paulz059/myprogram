#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void matrixinputA (int*,int,int);
void matrixinputB (int*,int,int);
void matrixmultiply(int*,int*,int*,int,int,int);
void matrixput(int*,int,int);

int main()
{
    int *A,*B,*C; // matrix
    int m,n,p; // size of matrix

    int i,j;

    printf(" intput matrix A (M,N): \n");
    printf("M= ");
    scanf("%d" , &m);
    printf("N= ");
    scanf("%d" , &n);

    A= (int*)malloc(m*n*sizeof(int));   //A[m,n]
    matrixinputA(A,m,n);

    printf(" intput matrix B (M,N): \n");
    printf("N= ");
    scanf("%d" , &n);
    printf("P= ");
    scanf("%d" , &p);

    B= (int*)malloc(n*p*sizeof(int));    //B[n,p]
    matrixinputB(B,n,p);

    C= (int*)malloc(m*p*sizeof(int));   //C[m,p]

    matrixmultiply(A,B,C,m,n,p);

    matrixput(C,m,p);

	system("pause");
}
void matrixinputA(int* arrA,int M,int N){
    int i,j;
    printf("intput matrix A");
    for(i=0; i<M;i++){
        for (j = 0; j < N; j++)
        {
            printf("a%d%d=" ,i,j);
            scanf("%d",&arrA[i*N+j]);
        }
        
    }
}
void matrixinputB(int* arrA,int M,int N){
    int i,j;
    printf("intput matrix B");
    for(i=0; i<M;i++){
        for (j = 0; j < N; j++)
        {
            printf("b%d%d=" ,i,j);
            scanf("%d",&arrA[i*N+j]);
        }
        
    }
}

void matrixmultiply(int* arrA,int* arrB,int* arrC,int M,int N,int P){
    int i,j,k,Temp;
    if(M<=0 || N<=0||P<=0){
        printf("error M,N,P size mute longer the 0");
        return;
    }
    for ( i = 0; i < M; i++)
    {
        /* code */
        for ( j = 0; j < P; j++)
        {
            Temp = 0;
            for(k=0; k<N; k++){
                Temp += arrA[i*N+k]*arrB[k*P+j];  // i =0 k=0 j a[0*3+0](a[0,0]) * b[0*2+]
                
            }
            arrC[i*P+j] = Temp;
            /* code */
        }
        
    }
    
}

void matrixput(int* arrC, int M,int P){
    int i,j;
    printf("result AXB= \n");
    for(i=0; i<M; i++){
        for ( j = 0; j < P; j++)
        {
            printf("%d\t",arrC[i*P+j]);
        }
        printf("\n");
    }
}