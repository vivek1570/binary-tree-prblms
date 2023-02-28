#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
typedef struct node node;
node *string_bt(char *str){
    int key1,temp1,j;
    char ka[1000];
    str+=2;
    if(*str==')')
    return NULL;
    j=0;
    while((*str>='0' && *str<='9') || *str=='-')
    {
        ka[j++]=*str;
        str++;
    }
    ka[j]='\0';
    key1=atoi(ka);
    node *nod=(node*)malloc(sizeof(node));
    nod->data=key1;
    str++;
    nod->left=string_bt(str);
    str++;
    temp1=1;
    while(temp1!=0){
        if(*str=='(')
        temp1++;
        if(*str==')')
        temp1--;
        str++;
    }
    str++;
    nod->right=string_bt(str);
    return nod;
}

void print(node *root, int k)
{
    if (root == NULL || k < 0){
   return;
    }
    if (k==0)
    {
        printf("%d ",root->data);
        return;
    }
    print(root->left, k-1);
    print(root->right, k-1);
}
node * searchNode( node *root, int value){  
    if(root==NULL) return NULL;
    if(root->data==value) return root;
    node *found=searchNode(root->left,value);
    if(found!=NULL) return found;
    return searchNode(root->right,value);
} 
int height(node *root){
    if(root==NULL)
    return 0;
    else
    {
        int hl=height(root->left);
        int hr=height(root->right);
       if(hl>hr)
       return hl+1;
       else 
       return hr+1;
    }
}
int main(){
    char *str=(char *)malloc(1000*sizeof(char));
    scanf("%[^\n]s",str);
    node *root=string_bt(str);
    int m,k;
    scanf("%d %d",&m,&k);
    node *temp=searchNode(root,m);
  if(temp==NULL)
  printf("-1\n");
  else if (k>=height(temp)){
  printf("-1");
  }
  else
  print(temp,k);
}