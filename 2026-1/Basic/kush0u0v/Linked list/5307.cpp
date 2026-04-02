#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

typedef struct NODE {
    struct NODE *prev, *next;
    char data;
} NODE;


int main(){
    int C;
    cin >> C;

    for(int i = 0; i < C; i++) {
        char str[1000001];
        cin >> str;
        
        // init head
        NODE *head = (NODE*) malloc (sizeof(NODE));
        head->prev = NULL;
        head->next = NULL;
        head->data = '\0';

        // pointer
        NODE *point = head;

        int len = strlen(str);
        for(int j = 0; j < len; j++){
            char ch = str[j];

                if (ch == '<') {
                    if(point -> prev != NULL){ //이전이 비어 있지 않은지?
                        point = point -> prev;
                    }
                } else if (ch == '>') {
                    if (point -> next != NULL) { // 다음이 비어 있지 않은지?
                        point = point -> next;
                    }
                } else if (ch == '-') { // 지우기

                    if (point->prev != NULL) {
                        NODE *delTemp = point;

                        delTemp -> prev -> next = delTemp -> next;
                        if(delTemp -> next != NULL) {
                            delTemp -> next -> prev = delTemp -> prev;
                        } // Temp의 다음 노드 Set

                        // point 재조정
                        point = delTemp -> prev;
                        free(delTemp); 
                    }
                } else { // 일반 문자
                    NODE *newNODE = (NODE*) malloc(sizeof(NODE)); // 추가
                    newNODE->data = ch;

                    // 새 노드, 앞뒤 연결
                    newNODE->prev = point;
                    newNODE->next = point->next;

                    if (point->next != NULL) {
                        point->next->prev = newNODE;
                    }
                    point->next = newNODE;

                    // point 재조정
                    point = newNODE;
                }
 
        } // 생성

        NODE *now = head->next;
        while (now != NULL){
            cout << now->data;
            
            NODE *temp = now;
            now = now->next;
            free(temp);
        }

        cout << "\n";
        free(head);

    }
}