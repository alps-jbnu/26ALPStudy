#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

void create(node **head, int N){
    node *temp, *rear;
    for(int i = 0; i < N; i++){
        temp = (node *)malloc(sizeof(node));
        temp->data = i+1;
        temp->next = NULL;
        if(*head == NULL) *head = temp;
        else rear->next = temp;
        rear = temp;
    }
}

void display(node *head){
    node *temp;
    temp = head;
    printf("%d ", temp->data);
    temp = temp->next;
    while(head != temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(node **head, int K){
    node *temp, *current;
    
    temp = current = *head;
    while( current->next != current){
        for(int i = 0; i < K -1; i++){
            temp = current;
            current = current->next;
        }
        temp->next = current->next;
        printf("%d, ", current->data);
        free(current);
        current = temp->next;
    }
    *head = current;
}

void main(){
    int N = 0, K = 0;
    node *head = NULL;
    scanf("%d %d", &N, &K);

    create(&head, N);
    printf("<");
    delete(&head, K);
    printf(">");
}
