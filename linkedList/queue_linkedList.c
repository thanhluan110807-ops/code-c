#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node ;

struct queue{
    node *head;
    node *tail;
};


node *makeNode (int x){
    node *newNode = malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

typedef struct queue queue;

void push (queue *q, int x){
    node *newNode = makeNode(x);
    if (q->head==NULL){
        q->head=newNode;
        q->tail=newNode;
        return;
    }
    q->tail->next=newNode;
    q->tail=newNode;
}

void pop (queue *q){
   if (q->head==NULL){
    return;
   }

   node *temp=q->head;
   q->head=q->head->next;

   if (q->head==NULL){
    q->tail=NULL;
   }
   free(temp);
}

int size (queue q){
    int count=0;
    while (q.head!=NULL){
        count++;
        q.head=q.head->next;
    }
    return count;
}

int front(queue q){
    return q.head->data;
}


int main(){
    queue q;
    q.head=NULL;
    q.tail=NULL;
    while (1){
       printf ("---------------------------------\n");
       printf ("1. push\n");
       printf ("2. pop\n");
       printf ("3. front\n");
       printf ("4. size\n");
       printf ("0. thoat\n");
       printf ("nhap lua chon cua ban: \n");
        printf ("---------------------------------\n");
       int lc, x;
       scanf ("%d", &lc);

       if (lc==1){
        printf ("nhap x: \n");
        scanf ("%d", &x );
        push(&q, x);
       }

       if (lc==2){
        if (q.head==NULL){
            printf ("EMPTY\n");
        }
        pop(&q);
       }

       if (lc==3){
        if (q.head==NULL){
            printf ("EMPTY\n");
        }
        printf ("%d\n", front (q));
       }

       if (lc==4){
        printf ("%d\n", size(q));
       }

       if (lc==0){
            break;
       }
    }
    return 0;

}
