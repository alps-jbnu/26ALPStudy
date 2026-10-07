#include <bits/stdc++.h>
using namespace std;

class Deque {
  private:
    int data[100000];
    int head = 50000;
    int tail = 50001;

  public:
    void push_front(int value) {
      data[head] = value;

      head--;
    }

    void push_back(int value) {
      data[tail] = value;

      tail++;
    }
    
    int pop_front() {
      if (empty()) {
        return -1;
      }
      int tmp = data[head + 1];

      head++;

      return tmp;
    }

    int pop_back() {
      if (empty()) {
        return -1;
      }
      int tmp = data[tail - 1];

      tail--;

      return tmp;
    }

    int size() {
      return tail - head - 1;
    }

    int empty() {
      return (tail - head) == 1;
    }

    int front() {
      if (empty()) {
        return -1;
      }
      return data[head + 1];
    }

    int back() {
      if (empty()) {
        return -1;
      }
      return data[tail - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Deque dq;
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
      string cmd;

      cin >> cmd;

      if (cmd == "push_front") {
        int input_val;

        cin >> input_val;

        dq.push_front(input_val);
      } else if (cmd == "push_back") {
        int input_val;

        cin >> input_val;

        dq.push_back(input_val);
      } else if (cmd == "pop_front") {
        cout << dq.pop_front() << "\n";
      } else if (cmd == "pop_back") {
        cout << dq.pop_back() << "\n";
      } else if (cmd == "size") {
        cout << dq.size() << "\n";
      } else if (cmd == "empty") {
        cout << dq.empty() << "\n";
      } else if (cmd == "front") {
        cout << dq.front() << "\n";
      } else if (cmd == "back") {
        cout << dq.back() << "\n";
      }
    }
    
    return 0;
}
