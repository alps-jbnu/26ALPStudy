#include <stdio.h>

int main() {
	int N = 0;
	scanf("%d", &N);
	char cmd[10] = {};
	int quu[10001] = {};
	int tail = 0, head =0;

	for (int i = 0; i < N; i++) {
		scanf("%s", cmd);
		if (cmd[0] == 'p') {
			if (cmd[1] == 'u') {
				//푸시
				int a = 0;
				scanf("%d", &a);
				quu[tail++] = a;
				//printf("%d\n", quu[head]);
			}
			else {
				//팝
				if(head != tail)
					printf("%d\n", quu[head++]);
				else
					printf("-1\n"); // 비어있으면 -1출력
			}
		}
		else if (cmd[0] == 's') {
			printf("%d\n", tail - head);//사이즈 출력
		}
		else if (cmd[0] == 'e') {
			//비어있으면1,아니면 0을 출력
			if (head != tail)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (cmd[0] == 'f') {
			//큐의 맨 앞 원소를 출력한다. 큐가 비어 있으면 -1을 출력한다.
			
			if (head != tail)
				printf("%d\n", quu[head]);
			else
				printf("-1\n");
		}
		else if (cmd[0] == 'b') {
			//큐의 맨 뒤 원소를 출력한다. 큐가 비어 있으면 -1을 출력한다.
			
			if (head != tail)
				printf("%d\n", quu[tail - 1]);
			else
				printf("-1\n");
		}
		else
			printf("뭔가 잘못됨");
	}
	return 0;
}