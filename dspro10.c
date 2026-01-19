#include<stdio.h>
#include<stdlib.h>
struct bst{
     int data;
     struct bst *left;
     struct bst *right;
};

struct bst *createnode(int data){
     struct bst *temp=(struct bst*)malloc(sizeof(struct bst));
     temp->data=data;
     temp->left=NULL;
     temp->right=NULL;
     return temp;
}
struct bst *insert(struct bst *root,int data){
     if(root==NULL){
          return createnode(data);
     }
     if(data<root->data) root->left=insert(root->left,data);
     if(data>root->data) root->right=insert(root->right,data);
     return root;
}

void preorder(struct bst *root){
     if(root!=NULL){
     printf("%d\t",root->data);
     preorder(root->left);
     preorder(root->right);
}
}


void postorder(struct bst *root){
    if(root!=NULL){
     postorder(root->left);
     postorder(root->right);
     printf("%d\t",root->data);
    }
}

void inorder(struct bst *root){
     if(root!=NULL){
          inorder(root->left);
          printf("%d\t",root->data);
          inorder(root->right);
     }
}

void search(struct bst *root,int key){
     if(root==NULL){
          printf("key %d is not found\n");
          return;
     }
     if(key==root->data){
          printf("key %d found!!",key);
          return;
     }
     else if(key<root->data){
          search(root->left,key);
     }
     else{
          search(root->right,key);
     }
}


int main(){
     struct bst *root=NULL;
     int choice ,i,key;
     int data[]={6,9,5,2,8,15,24,14,7,8,5,2};
     int n=12;

     while(1){
          printf("---------menu----------");
          printf("1.create bst\n");
          printf("2.inordertraversal\n");
          printf("3.preordrtraversal\n");
          printf("4.postorder traversal\n");
          printf("5.search element\n");
          printf("6.exit\n");

          printf("enter your choice\n");
          scanf("%d",&choice);
          switch(choice){
               case 1:
               root=NULL;
               for(i=0;i<n;i++) root=insert(root,data[i]);
               printf("bst successful\n");
               break;

               case 2:
               printf("inordr traversal\n");
               inorder(root);
               printf("\n");
               break;

               case 3:
               printf("preorder traversal\n");
               preorder(root);
               printf("\n");
               break;

               case 4:
               printf("postorder traversal\n");
               postorder(root);
               printf("\n");
               break;
               case 5:
               printf("enter the key to search\n");
               scanf("%d",&key);
               search(root,key);
               break;
               case 6:
               exit(0);
               default:
               printf("invalid choice\n");

          }
     }

}
