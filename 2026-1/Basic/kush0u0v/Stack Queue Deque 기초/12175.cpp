#include <iostream>
#include <cstring>
using namespace std;

typedef struct NODE {
    int data;
    struct NODE* next;
} NODE;

typedef struct {
    NODE* front;
    NODE* rear;
    int count;
} Queue;

//OP
void initq(Queue* q) {
    q -> front = NULL;
    q -> rear = NULL;
    q -> count = 0;
}

int isEmpty(Queue* q){
    return (q -> count == 0);
}

void enq(Queue* q, int data) {
    NODE* newN = (NODE*) malloc (sizeof(NODE));

    newN -> data = data;
    newN -> next = NULL;

    if(isEmpty(q)) {
        q -> front = newN;
        q -> rear = newN;
    } else {
        q -> rear -> next = newN;
        q -> rear = newN;
    }
    q -> count++;
}

int deq(Queue *q) {
    if(isEmpty(q) == 1) 
        return -1;
    NODE* temp = q -> front;
    q -> front = temp -> next; 
    int A = temp -> data;
    free (temp);
    q -> count--;

    return A;
}


int main() {
    Queue q;
    initq(&q);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        enq(&q, i);
    }

    while(!isEmpty(&q)) {
        int temp;
        // 선두제거
        temp = deq(&q);
        if(q.count == 0) {
            cout << temp << endl;
            break;
        }

        // 말단
        temp = deq(&q);
        enq(&q, temp);

        if(q.rear == q.front) {
            cout << deq(&q) << endl;
            break;
        }
    }
}
