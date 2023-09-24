#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue();
void dequeue();
void display();
void peek();
int main(){
    int choice;
    while(choice!=5){
    printf("\n*************MAINMENU*************\n");
    printf("\n1.insertion\n2,deletion\n3.display\n4.peek");
    printf("\nEnter the choice:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:enqueue();
        break;
        case 2:dequeue();
        break;
        case 3:display();
        break;
        case 4:peek();
        break;
        case 5:exit(0);
        break;
        default:
        printf("Enter the valid number");
        }
    }
}
void enqueue(){
    struct node *newnode;
    int num;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert ");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=NULL;
    if(front==0&&rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    printf("\nNode is inserted\n");
}
void dequeue(){
    struct node *temp;
    temp=front;
    if(front==0&&rear==0){
        printf("\nqueue is Empty\n");
    }
    else{
        printf("\n%d  is deleted\n",front->data);
       front=front->next; 
       free(temp);
    }
}
void display(){
    struct node *temp;
    temp=front;
    if(front==0&&rear==0){
        printf("\nQUEUE is Empty\n");
    }
    else{
        while(temp!=NULL){
            printf("\n%d-->",temp->data);
            temp=temp->next;
        }
    }
}
void peek(){
    if(front==0&&rear==0){
        printf("Queue is Empty");
    }
    else{
        printf("\nthe top element is %d\n",front->data);
    }
}
