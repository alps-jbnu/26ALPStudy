# 덱 회전 최소 횟수

## 풀이 과정

deque를 원형처럼 회전시키며 1부터 n까지의 숫자를 모두 넣고 front를 기준으로 타겟 넘버를 찾은 다음 pop

오른쪽 회전은 타겟 넘버의 index만큼, 왼쪽 회전은 원형 덱의 사이즈에서 index를 빼준 만큼 이동

두 값 중 더 작은 값만큼 이동 후 pop front

## 참고

- find함수는 시작 it, 끝 it, 타겟을 받아 해당 위치의 it를 반환
- deque는 it를 제공하며 임의 접근 가능, it - dq.begin()처럼 연산해 index 계산 가능 (list는 안됨)
- size 함수는 size_t로 반환함
