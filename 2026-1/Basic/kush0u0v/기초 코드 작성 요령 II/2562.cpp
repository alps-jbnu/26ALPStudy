#include <iostream>

int main(){
    int arr [9];
    int high = 0;
    
    for(int i =0; i < 9;i++){
        std::cin >> arr[i];
        high = arr[high] > arr[i] ? high : i;
    }

    std::cout << arr[high] << std::endl << high+1;
}