//
// Created by 손민균 on 26. 10. 5.
//
#include <iostream>
#include <string>
using namespace std;

/*
 * -가 나오기 전까지는 괄호로 숫자를 줄일 방법이 없으니 더하다가
 * -가 나오고 나서 부터는 - 부터 다음 - 전 혹은 -부터 식 끝까지를 괄호로 묶어서 빼면 - 뒤에 있는 모든 수를 뺄 수 있다.
 */

int main () {
    string expression;
    cin >> expression;

    string number;
    int total = 0;
    int number_buffer = 0;
    int buffer_mode = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            number.append(expression.substr (i, 1));
        }
        else {
            if (buffer_mode == 0) {
                number_buffer = stoi (number);
                total += number_buffer;
                number_buffer = 0;
                if (expression[i] == '-') buffer_mode = 1;
            }
            else {
                if (expression[i] == '+') {
                    number_buffer += stoi (number);
                }
                else {
                    number_buffer += stoi (number);
                    total -= number_buffer;
                    number_buffer = 0;
                }
            }
            number = "";
        }
    }
    if (buffer_mode == 0) {
        number_buffer = stoi (number);
        total += number_buffer;
    }
    else {
        number_buffer += stoi (number);
        total -= number_buffer;
    }

    cout << total << endl;
    return 0;
}