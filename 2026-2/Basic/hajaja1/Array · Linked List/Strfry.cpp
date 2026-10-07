#include <stdio.h>



int main() {
    int N = 0;
    scanf("%d", &N); // 케이스 숫자 입력 받기
    for (int j = 0; j < N; j++) {
        char word1[1000] = {}, word2[1000] = {};
        int word1_alpabet[26] = {}, word2_alpabet[26] = {};
        scanf("%s", word1); //단어를 입력 받음, 단 알파벳만 들어옴
        scanf("%s", word2);

        // word1의 알파벳 개수 세기 (널 문자 '\0'을 만날 때까지 반복)
        for (int i = 0; word1[i] != '\0'; i++) {
            char c = word1[i];
            word1_alpabet[c - 'a']++; // 누적 연산자(++) 추가
        }

        // word2의 알파벳 개수 세기
        for (int i = 0; word2[i] != '\0'; i++) {
            char c = word2[i];
            word2_alpabet[c - 'a']++; // 누적 연산자(++) 추가
        }

        int mi = 0;
        for (int i = 0; i < 26; i++) {
            int diff = word1_alpabet[i] - word2_alpabet[i];
            if (diff != 0) {
                printf("Impossible\n");
                mi++;
                break;
            }
        }
        if (mi == 0)
            printf("Possible\n");
    }
    return 0;
}