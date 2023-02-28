#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *right,*left,*next;
    int data;
};
typedef struct node node;
struct stack{
    node *top;
};
typedef struct stack stack;
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

void push(stack *st,node *temp){
    if(temp==NULL)
    return;
    temp->next=st->top;
    st->top=temp;
}
void print_stack(stack *st){
    node *temp=st->top;
    if(temp==NULL)
    printf("-1\n");
    else{
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    }
}
void inorder_x(node *root,node *cur){
    stack *st=(stack *)malloc(1000*sizeof(stack));
    int x=cur->data;
    st->top=NULL;
    node *temp=root;
    while(temp->data!=x){
        if(temp->data>x)
        {
            push(st,temp);
            temp=temp->left;
        }
        else
        {
            push(st,temp);
            temp=temp->right;
        }
    }
    print_stack(st);
}
node * searchNode( node *root, int value){  
    if(root==NULL) return NULL;
    if(root->data==value) return root;
    node *found=searchNode(root->left,value);
    if(found!=NULL) return found;
    return searchNode(root->right,value);
} 
int main(){
    char *str=(char *)malloc(1000*sizeof(char));
    scanf("%[^\n]s",str);
    node *root=string_bt(str);
    int k;
    scanf("%d",&k);
    node *cur=searchNode(root,k);
    if(cur==NULL)
    printf("-1\n");
    else{
    inorder_x(root,cur);
    }
}