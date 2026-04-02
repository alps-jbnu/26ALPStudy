#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct NODE {
    struct NODE *prev, *next;
    int data;
} NODE;

NODE* dequeue(NODE *node){
    node -> prev -> next = node -> next;
    // 노드의 이전 노드의 다음 포인터는, 지금의 다음 노드
    node -> next -> prev = node -> prev;
    // 다음노드의 포인터를, 현재노드의 이전을 가르킴

    NODE *nextNode = node -> next;
    // 다음 노드

    return nextNode; // 다음노드 반환 
}

int main(){
    int N, K;
    cin >> N >> K;

    NODE *head = NULL;
    NODE *tail = NULL;

    for(int i = 1; i <= N; i++){
        NODE *newNODE = (NODE*) malloc (sizeof(NODE));
        newNODE -> data = i;
        
        if(head == NULL){ // 신규 생성 시
            head = newNODE;
            tail = newNODE;

            newNODE -> prev = newNODE;
            newNODE -> next = newNODE;
        } else { // 연결부 
            tail -> next = newNODE; // 추가
            newNODE -> prev = tail;
            tail = newNODE;

            newNODE -> next = head; // 다음 연결
            head -> prev = newNODE;
        }
    } // 원형 리스트 생성

    cout << "<";
    NODE *now = head;
    for(int i = 1; i <= N; i++){
        for (int j = 0; j < K-1; j++){
            now = now -> next;
        } // K번

        cout << now -> data;
        if(i < N){
            cout << ", ";
        }

        now = dequeue(now);
    }
    cout << ">\n";
}