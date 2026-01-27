#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
Node*head=NULL;
void insertBegin(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if(head == NULL){
        head = newNode;
    }
    else{
    head->prev = newNode;
    head =  newNode;
    }
}

void insertEnd(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void insertAfterNode(Node* pre, int value){
    if(pre == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    newNode->prev = pre;
    newNode->next = pre->next;

    if(pre->next != NULL){
        pre->next->prev = newNode;
    }

    pre->next = newNode;
}

void deleteBegin(){
    if(head == NULL) return;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);

}

void deleteEnd(){
    if(head == NULL) return;

    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);
}

void display(){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
 insertBegin(15);
    insertEnd(15);
    insertAfterNode(head, 20);
    deleteBegin();
    deleteEnd();
    display();
}