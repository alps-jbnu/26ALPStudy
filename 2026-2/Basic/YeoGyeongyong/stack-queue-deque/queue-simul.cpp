#include <bits/stdc++.h>
using namespace std;

class Queue {
  private:
    int data[100000];
    int head = 0;
    int tail = 0;

  public:
    void push(int value) {
      data[tail] = value;

      tail++;
    }
    
    int pop() {
      if (head == tail) {
        return -1;
      }
      int tmp = data[head];

      head++;

      return tmp;
    }

    int size() {
      return tail - head;
    }

    int empty() {
      if (head == tail) {
        return 1;
      }
      return 0;
    }

    int front() {
      if (head == tail) {
        return -1;
      }
      return data[head];
    }

    int back() {
      if (head == tail) {
        return -1;
      }
      return data[tail - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    Queue q;

    cin >> n;

    for (int i = 0; i < n; i++) {
      string cmd;

      cin >> cmd;

      if (cmd == "push") {
        int input_val;

        cin >> input_val;

        q.push(input_val);
      } else if (cmd == "pop") {
        cout << q.pop() << "\n";
      } else if (cmd == "size") {
        cout << q.size() << "\n";
      } else if (cmd == "empty") {
        cout << q.empty() << "\n";
      } else if (cmd == "front") {
        cout << q.front() << "\n";
      } else if (cmd == "back") {
        cout << q.back() << "\n";
      }
    }
    
    return 0;
}
