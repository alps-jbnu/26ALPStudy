#include <iostream>
#include <vector>
class Stack {
private:
	int arr[10000];
	int top_i;

public:
	Stack() {
		top_i = -1;
	}
	bool isEmpty() {
		return top_i == -1;
	}
	void push(int data) {
		arr[++top_i] = data;
	}
	void pop() {
		if (!isEmpty()) {
			top_i--;
		}
	}
	int top() {
		if (!isEmpty()) {
			return arr[top_i];
		}
		return -1;
	}
	};
	int main() {
		int n;
		std::cin >> n;
		Stack s;
		std::vector <char>result;
		int current = 1;
		bool possible = true;
		for (int i = 0; i < n; i++) {
			int target;
			std::cin >> target;
			while (current <= target) {
				s.push(current);
				result.push_back('+');
				current++;
			}
			if (s.top() == target) {
				s.pop();
				result.push_back('-');
			}
			else {
				possible = false;
			}
		}
		if (possible) {
			for (char op : result) {
				std::cout << op << "\n";
			}
			return 0;
		}
	}
