#include <bits/stdc++.h>
using namespace std;

class ArrayList {
  private:
    int* data;
    int size = 0;
    int capacity;

  public:
    ArrayList(int capacity) {
      this->capacity = capacity;
      data = new int[capacity];
    }

    void Insert(int idx, int value) {
      if (size < idx || idx < 0) {
        cout << "invalid index";
        return;
      }

      size++;

      if (size > capacity) {
        capacity *= 2;

        int* temp = new int[capacity];

        for(int i = 0; i < size -1; i++){
          temp[i] = data[i];
        }

        delete [] data;

        data = temp;
      }

      for (int i = size - 1; i > idx; i--) {
        data[i] = data[i-1];
      }

      data[idx] = value;
    }

    void Erase(int idx) {
      if (size <= idx || idx < 0) {
        cout << "invalid index";
        return;
      }

      for (int i = idx; i < size - 1; i++) {
        data[i] = data[i + 1];
      }

      size -= 1;
    }

    ~ArrayList() {
      delete[] data;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
