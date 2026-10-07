#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Stack {
  public:
    int top = -1;
    int data[100000];
    
    void push(int value) {
      top++;

      data[top] = value;
    }
    int pop() {
      if (top == -1) {
        return -1;
      }
      int pop_data = data[top];

      top--;

      return pop_data;
    }
    int top_value() {
      if (top == -1) {
        return -1; 
      } else{
        return data[top];
      }
    }
    int empty() {
      if (top == -1) {
        return 1;
      } else {
        return 0;
      }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    Stack s;

    cin >> n;

    for (int i = 0; i < n; i++) {
      string cmd;
      
      cin >> cmd;

      if (cmd == "push") {
        int input_val;

        cin >> input_val;

        s.push(input_val);
      } else if (cmd == "pop") {
        cout << s.pop() << "\n";
      } else if (cmd == "size") {
        cout << s.top + 1 << "\n";
      } else if (cmd == "empty") {
        cout << s.empty() << "\n";
      } else if (cmd == "top") {
        cout << s.top_value() << "\n";
      }
    }
    
    return 0;
}
