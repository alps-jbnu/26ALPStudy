#include <iostream>
#include <string>

using namespace std;

const int MAX_STACK_SIZE = 100000;

class Stack {
private:
	int stack_size = 0;
	int stack[MAX_STACK_SIZE];

public:
	void push(int num) {
		stack[stack_size++] = num;
	}

	int pop() {
		return stack_size == 0 ? -1 : stack[--stack_size];
	}

	int size() const {
		return stack_size;
	}

	int empty() const {
		return stack_size == 0 ? 1 : 0;
	}

	int top() const {
		return stack_size == 0 ? -1 : stack[stack_size - 1];
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 0;
	Stack stack;

	cin >> n;

	while(n--) {
		string cmd;

		cin >> cmd;

		if(cmd == "push") {
			int num;
			cin >> num;

			stack.push(num);
		} else if(cmd == "pop") {
			cout << stack.pop() << '\n';
		} else if(cmd == "size") {
			cout << stack.size() << '\n';
		} else if(cmd == "empty") {
			cout << stack.empty() << '\n';
		} else if(cmd == "top") {
			cout << stack.top() << '\n';
		}
	}
}
