#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    char data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* create(char data){
    Node* keylogger = (Node *)malloc(sizeof(Node));
    keylogger->data = data;
    keylogger->next = NULL;
    keylogger->prev = NULL;
    return keylogger;
}

void Foward(Node* keylogger){
    if(keylogger->next == NULL){
        printf("Error can't move to next character");
    }
    keylogger->next = keylogger->next->next;
    keylogger->prev = keylogger->next->prev;
}

void main(){
    create('a');
    create('p');

}
