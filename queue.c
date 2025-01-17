#include <stdio.h>
#include <stdlib.h>
#define maxVol 16
/*
this is queue done by c and used array to implement
typedef struct queue{
    int rear;
    int front;
    int data[maxVol];
}queue;
void enqueue(queue *q , int n){
    if(q->front<maxVol-1)q->data[++q->front]=n;
    else printf("fail");
    //if(q->rear==-1)q->rear=0;
    
}
int dequeue(queue *q){
    if(q->rear<q->front)return q->data[++q->rear];
    else return -1;
}

int main(void){
    queue q;
    q.front = -1;
    q.rear = -1;
    enqueue(&q,4);
    enqueue(&q,3);
    enqueue(&q,2);
    enqueue(&q,1);
    for(int i=0;i<4;i++){
        int pop = dequeue(&q); 
    }
    /*  front now is -1 , rear is -1
        front now is 0 , rear is -1
        front now is 1 , rear is -1
        front now is 2 , rear is -1
        front now is 3 , rear is -1
        pop 4
        after pop front now is 3 , rear is 0
        pop 3
        after pop front now is 3 , rear is 1
        pop 2
        after pop front now is 3 , rear is 2
        pop 1
        after pop front now is 3 , rear is 3*/

/*this is queue done by c and used array to implement*/

typedef struct node{
    int value;
    struct node *next;
}node;
typedef struct queue{
    node *front ;
    node *rear;
}queue;
void init_queue(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue *q, int value){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->value = value;
    newnode->next = NULL;

   if(q->front == NULL&& q->rear==NULL){
        q->front = newnode;
        q->rear = newnode;
   }else{
        q->rear->next = newnode;
        q->rear=newnode;
   }
    
}
int dequeue(queue *q){
    if(q->front==NULL){
        return -1;
    }
    int res = q->front->value;
    node *tmp = q->front;
    q->front = q->front->next;
    if(q->front==NULL){
        q->rear = NULL;
    }
    free(tmp);
    return res;
}


int main(void){
    queue q1, q2, q3;
    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 15);
    enqueue(&q1, 16);
    enqueue(&q1, 29);
    
    enqueue(&q2, 46);
    enqueue(&q2, 23);
    enqueue(&q2, 49);

    enqueue(&q3, 23);
    enqueue(&q3, 21);
    enqueue(&q3, 27);

    int t;
    while((t=dequeue(&q1))!=-1){
        printf("q1 t = %d\n", t);
    }
    while((t=dequeue(&q2))!=-1){
        printf("q2 t = %d\n", t);
    }
    while((t=dequeue(&q3))!=-1){
        printf("q3 t = %d\n", t);
    }
    return 0;
}