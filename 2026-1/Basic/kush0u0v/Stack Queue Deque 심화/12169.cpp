#include <iostream>
#include <stack>
using namespace std;

//stack.empty()
//swap(stack1 , stack2)
//stack.top()
//stack.pop()
//stack.push(element)

int main() {
    int n;
    cin >> n;

    stack<int> ST; // 출력용

    stack<int> st; // 계산용

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        st.push(temp);
    }

    stack<int> temp = st;
    for(int i = n; i != 0; i--) { // 4
        bool flag = 1;

        int A = temp.top();// 4
        temp.pop();
        
        stack<int> temp2 = temp;
        for(int j = i-1; j != 0; j--) { 

            if(temp2.empty()) {
                break;
            }

            int compare = temp2.top();
            temp2.pop(); //1~2 stack

            if (compare < A) { 
                flag = 1;
            } else if (compare >= A) { 
                // cout << j << endl; // 4
                ST.push(j);
                flag = 0;
                break;
            }

        }

        if(flag) {
            //cout << "0" << endl;
            ST.push(0);
        }
    }


    for (int i = 0; i < n; i++) {
        cout << ST.top() << " ";
        ST.pop();
    }

	return 0;
}