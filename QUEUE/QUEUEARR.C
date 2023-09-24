#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[5];
int front=-1;
int rear =-1;
void enqueue();
void dequeue();
void display();
void peek();

int main(){
    int choice;
    while(choice!=5){
        printf("\nEnter the choice:\n1.insertion\n2.deletion\n3.display\n4.peek\n");
        printf("\nEnter the choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4:  peek();
            break;
            case 5: exit(0);
            break;
            default:
            printf("Enter the valid number");
        }
    }
}
void enqueue(){
    int x;
    printf("Enter the element:\n");
    scanf("%d",&x);
    if(rear==N-1){
        printf("Overflow");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
    printf("the data is inserted\n");
    printf("\n--------------------------------------------------------------------------------\n");
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("overflow\n");
    }
    else if(front==rear){
         front=rear=-1;
         printf("%d is deleted\n",queue[front]);
    }
    else{
        printf("the num deleted is %d\n",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1&&rear==-1){
        printf("underflow");
    }
    else{
        for(int i=front;i<rear+1;i++){
            printf("%d->\t\n",queue[i]);
        }
    }
}
void peek(){
    if(front==-1&&rear==-1){
        printf("overflow");
    }
    else{
        printf("The peek element is %d\n",queue[front]);
    }
}