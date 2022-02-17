#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int a[MAX],f=-1,r=-1;
void cenqueue(int x)
{
        if((f==0 && r==MAX-1)||(f==r+1))
        {
                printf("que overflow");
        }
        else
        {
                if(f==-1)
                {
                        f=r=0;
                }
                else if(r==MAX-1)
                {
                        r=0;
                }
                else
                {
                        ++r;
                }
        a[r]=x;
        }
}
int denqueue()
{
        int x;
        if(f==-1)
        {
                return -1;
        }
        else
        {
                x=a[f];
                if(f==r)
                {
                        f=r=-1;
                }
                else if(f==MAX-1)
                {
                        f=0;
                }
                else
                {
                        ++f;
                }
        }
        return x;
}
void display()
{
        int i;
        if(f==-1)
        {
                printf("queue is empty");
        }
        if(f<=r)
        {
                for(i=f;i<=r;i++)
                {
                        printf("%d\n",a[i]);
                }
        }
        else
        {
                for(i=f;i<=MAX-1;i++)
                {
                        printf("%d\n",a[i]);
                }
                for(i=0;i<=r;i++)
                {
                        printf("%d\n",a[i]);
                }
        }
}
void main()
{
        int x,ch;
        printf("1:cenqueue\n 2:dequeue\n 3:display\n 4:exit\n");
  while(1)
        {
                printf("enter choice");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:printf("enter ele");
                               scanf("%d",&x);
                                cenqueue(x);
                                break;
                        case 2:x=denqueue();
                               if(x==-1)
                               {
                                       printf("underflow");
                               }
                               else
                               {
                                       printf("ele deleted is %d\n",x);
                               }
                               break;
                       case 3:display();
                              break;
                        case 4:exit(0);
                               break;
                }
        }
}
                  
1:cenqueue
 2:dequeue
 3:display
 4:exit
enter choice1
enter ele23
enter choice1
enter ele56
enter choice1
enter ele78
enter choice1
enter ele90
enter choice2
ele deleted is 23
enter choice3
56
78
90
enter choice1
enter ele67
enter choice1
enter ele89
enter choice3
56
78
90
67
89
enter choice4
