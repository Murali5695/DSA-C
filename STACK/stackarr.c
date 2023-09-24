#include<stdio.h>
#include<stdlib.h>
int N=10;
int stack[10];
int top=-1;
void push();
void pop();
void peek();
void display();
void main(){
    int ch;
    while(ch!=5){
        printf("Enter choice:\n1.push\n2.pop\n3.peek\n4.display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peek();
            break;
            case 4:display();
            break;
            case 5:exit(0);
            break;
            default:
            printf("Enter the valid number");
        }
    }
}
void push(){
    int x;
    printf("Enter the element to push:");
    scanf("%d",&x);
    if(top==N-1){
        printf("overflow");
    }
    else{
        top++;
        stack[top]=x;
        printf("%d is inserted\n",x);
    }
}
void pop(){
    int item;
    if(top==-1){
        printf("underflow");
    }
    else{
        item=stack[top];
        top--;
        printf("pop item is %d\n",item);
    }
}
void peek(){
    if(top==-1){
        printf("EMpty\n");
    }
    else{
        printf("the top most element is %d\n",stack[top]);
    }
}
void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}