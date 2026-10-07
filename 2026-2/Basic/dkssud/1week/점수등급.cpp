#include <iostream>
int main() {
	int t;
	char grade;
	std::cin >> t;
	if (t >= 90) {
		grade = 'A';
	}
	else if (t >= 80) {
		grade = 'B';
	}
	else if (t >= 70) {
		grade = 'C';
	}
	else if (t >= 60) {
		grade = 'D';
	}
	else {
		grade = 'F';
	}
	std::cout << grade << "\n";	
}
