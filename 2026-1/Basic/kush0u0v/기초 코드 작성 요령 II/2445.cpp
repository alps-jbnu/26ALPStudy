#include <iostream>

int main() {
    int N;
    std::cin >> N;

    char temp[200] = { };

    for (int i = 0; i < 2 * N - 1; i++){
        // 1. Init
        for(int k = 0; k < 200; k++){
            temp[k] = 0x20;
        }

        // 2. Set
        if(i < N){ // Upper
            for(int j = 0; j <= i; j++){
                temp[j] = '*';
            } // Left

            for(int j = 0; j <= i; j++){
                temp[N * 2 - 1 - j] = '*';
            } // Right
        } else { // Lower
            int last = 2 * N - 1 - i;
            // 2 * 5 - 1 - 6 = 3
            // 9 - 7 = 2
            // 9 - 8 = 1

            for(int j = 0; j < last; j++){
                temp[j] = '*';
            } // Left

            for(int j = 0; j < last; j++){
                temp[N * 2 - 1 - j] = '*';
            } // Right
        }

        // 3. Arry OUT
        for(int j = 0; j < N*2; j++){
            std::cout << temp[j];
        } std::cout << '\n';
    }
}