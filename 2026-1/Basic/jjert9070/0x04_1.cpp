#include <iostream>

using namespace std;

struct NODE {
    struct NODE *prev, *next;
    int data;
};


int main()
{
    struct NODE nd = {NULL, NULL, 0};

}