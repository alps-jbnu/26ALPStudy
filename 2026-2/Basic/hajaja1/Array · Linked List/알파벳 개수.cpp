#include <stdio.h>

int main() {
	char word[100] = {}; //문자열 입력 받기위해 char형 배열
	scanf("%s", word); //문자열 입력 받기
	int alp[26] = {}; //알파벳 개수 저장 배열
	for (int i = 0; word[i] != '\0'; i++) { // 각 알파벳 개수 세는 로직
		alp[word[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) //알파벳 개수 a부터 z순서로 출력
		printf("%d ", alp[i]);
	return 0;
}