#include <stdio.h>
void insert(char text[], char cmd, int cursur, int len) {
	for (int i = len-1; i >= cursur; i--) {
		text[i + 1] = text[i];
	}
	text[cursur] = cmd;
}

void erase(char text[], int cursur, int len) {
	for (int i = cursur-1; i < len; i++) {
		text[i] = text[i + 1];
	}
}
int main() {
	char text[600001] = {};
	(void)scanf("%s", text);
	int len = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		len++;
	}
	int cursur = len;

	int N = 0;
	(void)scanf("%d", &N);
	char cmd[4] = {};
	for (int i = 0; i < N; i++) {
		(void)scanf(" %[^\n]", cmd);
		if (cmd[0] == 'P') {
			insert(text, cmd[2], cursur, len);
			len++;
			cursur++;
		}
		else if (cmd[0] == 'L') {
			if (cursur != 0)
				cursur--;
		}
		else if (cmd[0] == 'D') {
			if (cursur != len)
				cursur++;
		}
		else {
			if (cursur != 0) {
				erase(text, cursur, len);
				len--;
				cursur--;
			}
		}
		
	}
	
	printf("%s\n", text);
	return 0;
}