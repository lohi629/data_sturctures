#include <stdio.h>
#include<stdlib.h>
struct avl
{
    int data,ht;
    struct avl *left,*right;
};
typedef struct avl node;
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int height(node *p)
{
    if(p==NULL)
    {
        return -1;
    }
    else
    {
        return p -> ht;
    }
}
node *single_ll(node *k2)
{
    node *k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    return k1;
}
node *single_rr(node *k1)
{
    node *k2=k1->right;
    k1->right=k2->left;
    k2->left=k1;
    return k2;
}
node *double_lr(node *k3)
{
    k3->left=single_rr(k3->left);
    return (single_ll(k3));
}
node *double_rl(node *k3)
{
    k3->right=single_ll(k3->right);
    return (single_rr(k3));
}
node *insert(node *p,int x)
{
    if(p==NULL)
    {
        p=(node*)malloc(sizeof(node));
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        p->ht=0;
       
    }
    else if(x<p->data)
    {
        p->left=insert(p->left,x);
        if(abs(height(p->left)-height(p->right))==2)
        {
            if(x<p->left->data)
            {
                p=single_ll(p);
            }
            else
            {
                p=double_lr(p);
            }
        }
    }
    else if(x>p->data)
    {
        p->right=insert(p->right,x);
        if(abs(height(p->left)-height(p->right))==2)
        {
            if(x>p->right->data)
            {
                p=single_rr(p);
            }
            else
            {
                p=double_rl(p);
            }
        }
    }
    p->ht=max(height(p->left),height(p->right));
    return p;
}
void inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d\t",p->data);
        inorder(p->right);
    }
}
void preorder(node *p)
{
    if(p!=NULL)
    {
        printf("%d\t",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d\t",p->data);
    }
}
node *findmin(node *p)
{
    if(p!=NULL)
    {
        while(p->left!=NULL)
        {
            p=p->left;
        }
    }
    return p;
}
node *findmax(node *p)
{
    if(p!=NULL)
    {
        while(p->right!=NULL)
        {
            p=p->right;
        }
    }
    return p;
}
node *search(node *p,int x)
{
    if(p==NULL)
    {
        return p;
    }
    else if(x<p->data)
    {
        return(search(p->left,x));
    }
    else if(x>p->data)
    {
        return(search(p->right,x));
    }
    else
    {
        return p;
    }
}
node *delete(node *p,int x)
{
        node *temp;
        if(p==NULL)
        {
                return p;
        }
        else if(x<p->data)
        {
                p->left=delete(p->left,x);
        }
        else if(x>p->data)
        {
                p->right=delete(p->right,x);
        }
        else if(p->left!=NULL &&p->right!=NULL)
        {
                x=p->data=findmin(p->right)->data;
                p->right=delete(p->right,x);
        }
        else
        {
                temp=p;
                if(p->right==NULL)
                {
                        p=p->left;
                }
                else if(p->left==NULL)
                {
                        p=p->right;
                }
                free(temp);
        }
        return p;
}
void main()
{
    int x,ch,max;
    node *root=NULL,*temp;
    printf("\n1-insertion \n2-inorder \n3-preorder \n4-postorder \n5-minvalue \n6-maxvalue \n7-search \n8-delete \n9-exit\n");
    while(1)
    {
        
        printf("enter choice :\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter element to insert :\n");
                   scanf("%d",&x);
                   root=insert(root,x);
                   break;
            case 2:printf("inorder traversal is :\n");
                   inorder(root);
                   break;
            case 3:printf("preorder traversal is :\n");
                   preorder(root);
                   break;
            case 4:printf("postorder traversal is :\n");
                   postorder(root);
                   break;
            case 5:temp=findmin(root);
                   if(temp==NULL)
                   {
                       printf("no tree is created \n");
                   }
                   else
                   {
                       printf("minimum value is %d \n",temp->data);
                   }
                   break;
             case 6:temp=findmax(root);
                   if(temp==NULL)
                   {
                       printf("no tree is created \n");
                   }
                   else
                   {
                       printf("maximum value is %d\n",temp->data);
                   }    
                   break;
            case 7:printf("enter an element to search :\n");
                   scanf("%d",&x);
                   temp=search(root,x);
                   if(temp==NULL)
                   {
                       printf("element %d is not found",x);
                   }
                   else
                   {
                       printf("element %d is found",x);
                   }
                   break;
            case 8:printf("enter an element to delete :\n");
                   scanf("%d",&x);
                   root=delete(root,x);
                    break;
            case 9:exit(0);
            default :printf("enter correct choice\n");
                     break;
        }
    }
}

-insertion 
2-inorder 
3-preorder 
4-postorder 
5-minvalue 
6-maxvalue 
7-search 
8-delete 
9-exit
enter choice :
1
enter element to insert :
56
enter choice :
1
enter element to insert :
67
enter choice :
1
enter element to insert :
23
enter choice :
1
enter element to insert :
45
enter choice :
2
inorder traversal is :
23      45      56      67      enter choice :
3
preorder traversal is :
56      23      45      67      enter choice :
4
postorder traversal is :
45      23      67      56      enter choice :
5
minimum value is 23 
enter choice :
6
maximum value is 67
enter choice :
7
enter an element to search :
23
element 23 is foundenter choice :
8
