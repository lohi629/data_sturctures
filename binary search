#include<stdio.h>
int i,a[20],n,x,flag=0;
void bs();
void main()
{
    printf("enter array size");
    scanf("%d",&n);
    printf("enter array ele");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter ele to be searched");
    scanf("%d",&x);
    bs();
    if(flag==1)
    {
        printf("ele is found");
    }
    else
    {
        printf("ele is not found");
    }
}
void bs()
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==x)
        {
            flag=1;
            break;
        }
        else if(x<a[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
}
