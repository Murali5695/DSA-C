#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void peek();
void display();
void enqueue(){
    int x;
    printf("\nEnter the number to insert:\n");
    scanf("%d",&x);
    if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front){
        printf("\nQueue is empty\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
    printf("\nNOde is inserted\n");
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue is Empty\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("the deleted element is %d",queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    if(front==-1&&rear==-1){
        printf("Queue is Empty");
    }
    else{
        int i=front;
        while(i!=rear){
            printf("%d-->",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[rear]);
    }
}
void peek(){
    if(front==-1&&rear==-1){
        printf("Queue is empty");
    }
    else{
        printf("The top most element is %d",queue[front]);
    }
}
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