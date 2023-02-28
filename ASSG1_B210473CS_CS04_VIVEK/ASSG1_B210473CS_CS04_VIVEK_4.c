#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right,*p;
};
typedef struct node node ;
struct tree{
    node *root;
};
typedef struct tree tree;
node *create_node(int k){
    node *temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    exit(0);
    temp->left=temp->p=temp->right=NULL;
    temp->data=k;
}
void INSERT(tree *T,node *x){
    int key=x->data;
    node *p1=T->root,*p2=NULL;
    while(p1!=NULL){
        p2=p1;
        if(key<p1->data)
        p1=p1->left;
        else 
        p1=p1->right;
    }
    x->p=p2;
    if(T->root==NULL)
    T->root=x;
    else if(p2->data>key)
    p2->left=x;
    else
    p2->right=x;
}
node * INORDER(node *root){
    if(root!=NULL){
        INORDER(root->left);
        printf("%d ",root->data);
        INORDER(root->right);
    }
}

node * PREORDER(node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        PREORDER(root->left);
        PREORDER(root->right);
    }
}
node * POSTORDER(node *root){
    if(root!=NULL){
        POSTORDER(root->left);
      POSTORDER(root->right);
        printf("%d ",root->data);
    }
}
node *SEARCH(node *root,int key){
   if (root == NULL || root->data == key)
       return root;
    if (root->data < key)
       return SEARCH(root->right, key);
    return SEARCH(root->left, key);
}
node * MINIMUM(node *temp){
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node * MAXIMUM(node *temp){
    while(temp->right!=NULL){
        temp=temp->right;
    }
   return temp;
}
node * SUCCESSOR(tree *T,int k){
    node *n=SEARCH(T->root,k);
   if(n==NULL)
    return NULL;
    if(n->right!=NULL)
     return MINIMUM(n->right);
    node *para=n->p;
    while(para!=NULL && para->right==n){
        n=para;
        para=para->p;
    }
    return para;
}
node *PREDECESSOR(tree *T,int k){
    node *n=SEARCH(T->root,k);
    if(n==NULL)
    return NULL;
    if(n->left!=NULL)
     return MAXIMUM(n->left);
    node *para=n->p;
    while(para!=NULL && para->left==n)
    {
        n=para;
        para=para->p;
    }
    return para;
}
void transplant(tree *T,node *u,node *v){
    if(u->p==NULL)
    T->root=v;
    else if (u==u->p->left)
    u->p->left=v;
    else u->p->right=v;
    if (v!=NULL){
        v->p=u->p;
    }
}
node *DELETE(tree * T,node *z){
    if(z->left==NULL){
        transplant(T,z,z->right);
    }
    else if(z->right==NULL){
        transplant(T,z,z->left);
    }
    else {
        node *y=MINIMUM(z->right);
        if(y->p!=z){
            transplant(T,y,y->right);
            y->right=z->right;
            y->right->p=y;
        }
        transplant(T,z,y);
        y->left=z->left;
        y->left->p=y;
    }
    return z;
}
void level(node *root,int k)
{
    int n;
    node *temp=SEARCH(root,k);
    if(temp==NULL)
    printf("-1\n");
    else{
        while(temp!=root){
            temp=temp->p;
            n++;
        }
        printf("%d\n",n+1);
    }
    
}
int main(){
    tree *T=(tree *)malloc(sizeof(tree));
    T->root=NULL;
    node *cur=NULL;
    char ch;
    int k;
    while(1){
        scanf("%c",&ch);
        switch(ch){
            case 'a':scanf("%d",&k);
            node *x=create_node(k);
            INSERT(T,x);
            break;
            case 's':scanf("%d",&k);
            cur=SEARCH(T->root,k);
            if(cur==NULL)
            printf("-1\n");
            else printf("1\n");
            break;
            case 'i':INORDER(T->root);
            printf("\n");
            break;
            case 'p':PREORDER(T->root);
            printf("\n");
            break;
            case 't':POSTORDER(T->root);
            printf("\n");
            break;
            case 'e':return -1;
            break;
            case 'm':cur=MINIMUM(T->root);
            printf("%d\n",cur->data);
            break;
            case 'x':cur=MAXIMUM(T->root);
            printf("%d\n",cur->data);
            break;
            case 'r':scanf("%d",&k);
            cur=PREDECESSOR(T,k);
            if(cur)
            printf("%d\n",cur->data);
            else
            printf("-1\n");
            break;
            case 'u':scanf("%d",&k);
            cur=SUCCESSOR(T,k);
            if(cur)
            printf("%d\n",cur->data);
            else printf("-1\n");
            break;
            case 'd':scanf("%d",&k);
            cur=SEARCH(T->root,k);
            if(!cur)
            printf("-1\n");
            else{
            node *temp=DELETE(T,cur);
            }
            break;
            case 'l':scanf("%d",&k);
            level(T->root,k);
            break;
    }
}
}