#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right,*next,*p;
    char dir;
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
void print_path(node *root,node *target){
    if(root->left==NULL && root->right==NULL)
    return;
    if(root==NULL)
    return ;
    while(root->data!=target->data){
        if(root->data>target->data){
        printf("%c",'L');
        root=root->left;
        }
        if(root->data<target->data){
            printf("%c",'R');
            root=root->right;
        }

    }
    
}
void leaf_get(node *temp,int *sum_max_ref,int curr_sum,node **target){
    if(temp==NULL)
    return;
    curr_sum=curr_sum+temp->data;
    if(temp->left==NULL && temp->right==NULL){
        if(curr_sum>=*sum_max_ref){
            *sum_max_ref=curr_sum;
            *target=temp;
        }
    }
    leaf_get(temp->left,sum_max_ref,curr_sum,target);
    leaf_get(temp->right,sum_max_ref,curr_sum,target);
}
int sum_path( node *temp){
    if(temp==NULL)
    return 0;
    node * target;
    int sum_max=0;
    leaf_get(temp,&sum_max,0,&target);
    print_path(temp,target);
    return sum_max;
}
int main(){
    char *str=(char *)malloc(1000*sizeof(char));
    scanf("%[^\n]s",str);
    node *root=string_bt(str);
    int sum=sum_path(root);
    printf(" %d",sum);
}