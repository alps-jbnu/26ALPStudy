#include <iostream>
#include <string>

using namespace std;

const int MAX_DEQUE_SIZE = 20000;

class MyDeque {
private:
	int deque[MAX_DEQUE_SIZE];
	int head = MAX_DEQUE_SIZE / 2, tail = MAX_DEQUE_SIZE / 2;

public:
	void push_front(int num) {
		deque[--head] = num;
	}

	void push_back(int num) {
		deque[tail++] = num;
	}

	int pop_front() {
		return head == tail ? -1 : deque[head++];
	}

	int pop_back() {
		return head == tail ? -1 : deque[--tail];
	}

	int size() const {
		return tail - head;
	}

	int empty() const {
		return head == tail ? 1 : 0;
	}

	int front() const {
		return head == tail ? -1 : deque[head];
	}

	int back() const {
		return head == tail ? -1 : deque[tail-1];
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	MyDeque dq;

	cin >> N;

	while(N--) {
		string cmd;

		cin >> cmd;

		if(cmd == "push_front") {
			int num;

			cin >> num;
			dq.push_front(num);
		} else if(cmd == "push_back") {
			int num;

			cin >> num;
			dq.push_back(num);
		} else if(cmd == "pop_front") {
			cout << dq.pop_front() << '\n';
		}else if(cmd == "pop_back") {
			cout << dq.pop_back() << '\n';
		}else if(cmd == "size") {
			cout << dq.size() << '\n';
		}else if(cmd == "empty") {
			cout << dq.empty() << '\n';
		}else if(cmd == "front") {
			cout << dq.front() << '\n';
		}else if(cmd == "back") {
			cout << dq.back() << '\n';
		}
	}

}
