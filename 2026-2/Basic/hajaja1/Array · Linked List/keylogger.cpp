#include <stdio.h>
void insert(char text[], int cursur, int len, char alp) {
	for (int i = len - 1; i >= cursur; i--) {
		text[i + 1] = text[i];
	}
	text[cursur] = alp;
	text[len + 1] = '\0'; // 문자열 끝 처리 추가
}

void erase(char text[], int cursur, int len) {
	for (int i = cursur-1; i < len-1; i++) {
		text[i] = text[i + 1];
	}
	text[len - 1] = '\0'; // 줄어든 길이에 맞게 널 문자 삽입
}

char text[1000001];
char text2[1000001];

int main() {
	int N = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {

		for (int k = 0; k < 1000001; k++) {
			text[k] = 0;
			text2[k] = 0; // [해결] 이전 테스트 케이스의 잔여 데이터를 초기화합니다!
		}
		
		scanf("%s", text);
		int len = 0;
		for (int j = 0; text[j] != '\0'; j++)
			len++;
		int cursur = 0;
		int curtxtlen = 0;
		for (int j = 0; j < len; j++) {
			if (text[j] == '<') {
				if (cursur > 0) {
					cursur--;
				}
			}
			else if (text[j] == '>') {
				if (cursur < curtxtlen) {
					cursur++;
				}
			}
			else if (text[j] == '-') {
				if (cursur > 0) {
					erase(text2, cursur, curtxtlen);
					curtxtlen--;
					cursur--;
				}
			}
			else {
				insert(text2, cursur,curtxtlen, text[j]);
				cursur++;
				curtxtlen++;
			}
		}
		printf("%s\n", text2);
	}
	return 0;
}
