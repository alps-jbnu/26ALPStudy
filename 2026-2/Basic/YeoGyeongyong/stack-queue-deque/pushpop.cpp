#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int push_val = 1;
  vector<int> seq;
  stack<int> s;
  vector<char> result;
  bool flag = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    seq.push_back(temp);
  }

  for (int i = 0; i < n; i++) {
    if (s.empty()) {
      s.push(push_val);
      result.push_back('+');
      push_val++;
    }
    while (s.top() < seq[i]) {
      s.push(push_val);
      result.push_back('+');
      push_val++;
    }
    if (s.top() == seq[i]) {
      s.pop();
      result.push_back('-');
      continue;
    } else if (s.top() > seq[i]) {
      cout << "NO";
      flag = 1;
      break;
    }
  }

  if (flag) {
    return 0;
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }

  return 0;
}
