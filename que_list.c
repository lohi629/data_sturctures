#include<stdio.h>
#include<stdlib.h>
struct queue
{
        int data;
        struct queue *next;
};
typedef struct queue node;
node *front=NULL;
node *rear=NULL;
void enqueue(int x)
{
node *new;
new=(node *)malloc(sizeof(node));
new->data=x;
new->next=NULL;
if(front==NULL)
{
        front=rear=new;
}
else
{
        rear->next=new;
        rear=new;
}
}
int dequeue()
{
        int x;
        node *temp=front;
        x=front->data;
        if(front==NULL)
        {
                return -1;
        }
        else
        {
                front=front->next;
                free(temp);
        }
        return x;
}
void display()
{
   node  *temp=front;
        if(front==NULL)
        {
                printf("no list to print");
        }
        else
        {
                while(temp!=NULL)
                {
                        printf("|%d|->",temp->data);
                        temp=temp->next;
                }
        }
        printf("NULL");
}
void main()
{
        int x,ch;
        printf("1:enqueue\n 2:dequeue\n 3:display\n 4:exit\n");
        while(1)
        {
                printf("enter choice");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:printf("enter ele to be inserted:");
                               scanf("%d",&x);
                               enqueue(x);
                               break;
                        case 2:x=dequeue();
                               if(x==-1)
                               {
                                       printf("queue underflow");
                               }
                               else
                               {
                                       printf("%d ele is deleted:",x);
                               }
                               break;
                        case 3:display();
                     break;
                        case 4:exit(0);
                               break;
                }
        }
}
output:
1:enqueue
 2:dequeue
 3:display
 4:exit
enter choice1
enter ele to be inserted:56
enter choice1
enter ele to be inserted:78
enter choice1
enter ele to be inserted:90
enter choice1
enter ele to be inserted:45
enter choice2
56 ele is deleted:enter choice2
78 ele is deleted:enter choice3
|90|->|45|->NULLenter choice4
