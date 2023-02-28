#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right,*next;
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
node *inorder(node *root,int m,int n){
    if(root!=NULL){
        inorder(root->left,m,n);
        if(root->data>=m && root->data<=n)
        printf("%d ",root->data);
        inorder(root->right,m,n);
    }
}
int main(){
    char *str=(char *)malloc(1000*sizeof(char));
    scanf("%[^\n]s",str);
    node *root=string_bt(str);
    int m,n;
    scanf("%d %d",&m,&n);
    inorder(root,m,n);
}