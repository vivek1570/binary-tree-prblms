#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right,*next;
};
typedef struct node node;
struct stack{
    node *top;
};
typedef struct stack stack;
void push(stack *st,node *temp){
     temp->next=st->top;
     st->top=temp;
}
node *pop(stack *st){
    node *temp=st->top;
    st->top=temp->next;
    return temp;
}
int isempty(stack *st){
    if(st->top==NULL)
    return -1;
    else 
    return 1; 
}
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
int check(node *temp){
    if(temp->left==NULL && temp->right==NULL)
    return 0;
    else 
    return 1;
}
int check2(node *temp){
    if(temp->left==NULL || temp->right==NULL)
    return 0;
    else
    return 1;
}
int count(node *temp){
    node *sub1=temp->left;
    node *sub2=temp->right;
    if(check(sub1)&& !check(sub2))
    {
        if(sub1->left!=NULL && sub1->right!=NULL)
        return 2;
        if(sub1->left==NULL || sub1->right==NULL)
        return 1;
    }
    else if(check(sub2)&& !check(sub1)){
        if(sub2->left!=NULL && sub2->right!=NULL)
        return 2;
        if(sub2->left==NULL || sub2->right==NULL)
        return 1;
    }
    else 
    return 0;
}
void traverse(node *root){
    node *temp=root;
    int k=0;
    stack *st=(stack *)malloc(1000*sizeof(stack));
    st->top=NULL;
     while(temp!=NULL || isempty(st)==1){
        if (temp!=NULL){
            push(st,temp);
            if(check2(temp) ){
            k+=count(temp);
            }
            temp=temp->left;
        }
        else{
            temp=pop(st);
            temp=temp->right;
        }
    }
    printf("%d",k);
}
int main(){
    char *str=(char *)malloc(1000*sizeof(char));
    scanf("%[^\n]s",str);
    node *root=string_bt(str);
    int k=0;
    traverse(root);
}