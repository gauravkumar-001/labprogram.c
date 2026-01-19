#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[max];
int top=-1;

int  push(int value){
     if(top==max-1){
          printf("stack overflow\n");
     }
     else{
          top++;
          stack[top]=value;
          printf("pushed %d\n",value);
     }
}

void pop(){
     if(top==-1){
          printf("underflow\n");
          return;
     }
     else{
          printf("pop element is :%d\n",stack[top]);
          top--;
     }
}

void display(){
     if(top==-1){
          printf("stack is empty\n");
          return;
     }
     else{
          printf("so the element are :--");
          for(int i=top;i>=0;i--){
               printf("%d\t",stack[i]);
          }
     }
}

void checkpallindrome(){
     if(top==-1){
          printf("empty\n");
          return;
     }
     int flag=1;
     for(int i=0;i<=top/2;i++){
          if(stack[i] !=stack[top-i]){
               flag=0;
               break;
          }
     }
     if(flag) printf("pallindrome");
     else printf("not pallindrome");
}

int main(){
     push(10);
     push(12);
     push(15);
     display();
     pop();
     display();
     checkpallindrome();
}