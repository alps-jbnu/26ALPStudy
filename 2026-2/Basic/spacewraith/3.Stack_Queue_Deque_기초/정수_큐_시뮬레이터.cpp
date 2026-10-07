#include <iostream>
#include <string>

using namespace std;

const int MAX_QUEUE_SIZE = 10005;

class MyQueue {
private:
	int queue[MAX_QUEUE_SIZE];
	int head = 0;
	int tail = 0;

public:
	void push(int num) {
		queue[tail++] = num;
	}

	int pop() {
		return head == tail ? -1 : queue[head++];
	}

	int size() const {
		return tail - head;
	}

	int empty() const {
		return head == tail ? 1 : 0;
	}

	int front() const {
		return head == tail ? -1 : queue[head];
	}

	int back() const {
		return head == tail ? -1 : queue[tail - 1];
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	MyQueue q;

	cin >> n;

	while(n--) {
		string cmd;

		cin >> cmd;

		if(cmd == "push") {
			int num;
			
			cin >> num;
			q.push(num);
		} else if(cmd == "pop") {
			cout << q.pop() << '\n';
		} else if(cmd == "size") {
			cout << q.size() << '\n';
		} else if(cmd == "empty") {
			cout << q.empty() << '\n';
		} else if(cmd == "front") {
			cout << q.front() << '\n';
		} else if(cmd == "back") {
			cout << q.back() << '\n';
		}
	}

}
