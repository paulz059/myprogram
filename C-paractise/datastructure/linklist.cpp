#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select,student_no=0,num=0;
    float Msum=0,Esum=0;

    struct student
    {
        /* data */
        char name[20];
        int Math;
        int Eng;
        char no[10];
        struct student *next;

    };
    
    typedef struct student S_data;
    S_data *ptr;
    S_data *head;
    S_data *new_data;

    head = (S_data*) malloc(sizeof(S_data));
    head->next=NULL;
    ptr = head;  
    do{
        printf(" 1 new 2 leave =>");
        scanf("%d", &select);
        if ( select !=2 )
        {
            printf("name number math english:");
            new_data = (S_data*) malloc(sizeof(S_data));
            scanf("%s %s %d %d", new_data->name,new_data->no,&new_data->Math,&new_data->Eng);
            ptr -> next =new_data;
            new_data ->next =NULL;
            ptr = ptr->next;
            num++;
        }
    }while (select !=2);
}