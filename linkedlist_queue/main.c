//
//  main.c
//  linkedlist_queue
//
//  Created by 楊博名 on 2016/11/15.
//  Copyright © 2016年 楊博名. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void createq();
void addq(int);
void delq();
void showqueue();

Node *front, *rear;

int main(void) {
    int input, select;
    
    createq();
    
    while(1) {
        printf("\n\nenter option(-1 to quit)°G");
        printf("\n(1)add");
        printf("\n(2)delete");
        printf("\n(3)display\n\n");
        scanf("%d", &select);
        
        if(select == -1)
            break;
        
        switch(select) {
            case 1:
                printf("\nenter data\n");
                scanf("%d", &input);
                addq(input);
                break;
            case 2:
                delq();
                break;
            case 3:
                showqueue();
                break;
            default:
                printf("\nWRONG option°I\n");
        }
    }
    
    printf("\n");
    
    return 0;
}

void createq() {
    front = rear = (Node*) malloc(sizeof(Node));
    front->next = rear->next = NULL;
}


void addq(int data) {
    Node *newnode;
    
    newnode = (Node*) malloc(sizeof(Node));
    
    if(front->next == NULL)
        front->next = newnode;
    
    newnode->data = data;
    newnode->next = NULL;
    rear->next = newnode;
    rear = newnode;
}

void delq() {
    Node* tmpnode;
    
    if(front->next == NULL) { //ßR∞£∏`¬I¨∞≤ƒ§@≠”§]¨O≥Ã´·§@≠”∏`¬I
        printf("\nqueue empty°I\n");
        return;
    }
    
    tmpnode = front->next;
    front->next = tmpnode->next; //front->next=front->next->next
    free(tmpnode);
}

void showqueue() {
    Node* tmpnode;
    
    tmpnode = front->next;
    
    printf("\nqueue°G");
    while(tmpnode != NULL) {
        printf("%d ", tmpnode->data);
        tmpnode = tmpnode->next; 
    } 
} 
