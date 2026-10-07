#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    Node* next;
    int value;

    Node(Node* next, int value) {
      this->next = next;
      this->value = value;
    }
};

class LinkedList {
  private:
    Node* head;
    int size = 0;

  public:
    LinkedList() {
      head = nullptr;
    }

    void insert(int idx, int value) {
      if (idx > size || idx < 0) {
        cout << "Invalid index";
        return;
      }
      if (idx == 0) {
        Node* newNode = new Node(head, value);
        head = newNode;
        size++;
        return;
      }
      Node* pos = head;
      for (int i = 0; i < idx - 1; i++) {
        pos = pos->next;
      }
      Node* newNode = new Node(pos->next, value);
      pos->next = newNode;
      size++;
    }

    void erase(int idx) {
      if (idx >= size || idx < 0) {
        cout << "Invalid index";
        return;
      }
      if (idx == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
      }
      Node* pos = head;
      for (int i = 0; i < idx - 1; i++) {
        pos = pos->next;
      }
      Node* temp = pos->next;
      pos->next = pos->next->next;
      delete  temp;
      size--;
    }

    ~LinkedList() {
      while (head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
      }
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
