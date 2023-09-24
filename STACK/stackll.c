#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *top=NULL;
void push();
void pop();
void peek();
void display();
void main(){
int ch;
while(ch != 4){
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
            default:
            printf("Enter the valid number");
        }
    }
}
void push(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&x);
    newnode->data=x;
    newnode->link=top;
    top=newnode;
    printf("%d is inserted\n",x);
}
void display(){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}
void peek(){
     if(top==NULL){
        printf("stack is empty");
    }
    else{
      printf("The top element is %d\n",top->data);  
    }
}
void pop(){
    struct node *temp;
    temp=top;
     if(top==NULL){
        printf("stack is empty");
    }
    else{
        printf("the removed element is %d\n",top->data);
        top=top->link;
        free(temp);
    }
}