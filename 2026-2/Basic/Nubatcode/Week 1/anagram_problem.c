#include <stdio.h>

/* main idea
 * count numbers of each alphbet in the word
 * then subtract each other then count the differenece.
 */

int abS(int w1, int w2){
    int sub = w1 - w2;
    if(sub < 0) return sub * (-1);
    else return sub;
}

int alphabetCounter(char word[], int a[]){
   for(int i = 0; word[i] != '\0'; i++){
       int index = word[i] - 97;
       a[index]++;
   }
}

void main(){
    int a1[26] = {0, };
    int a2[26] = {0, };
    char word[1000] = {0, };
    int count = 0;
    
    scanf("%s", &word);
    alphabetCounter(word, a1);
    scanf("%s", &word);
    alphabetCounter(word, a2);
    
    for(int i = 0; i<26; i++){
        count = count + abS(a1[i], a2[i]);
    }

    printf("%d", count);
}
