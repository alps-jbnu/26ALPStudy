# Editor

## 풀이 과정

리스트의 iterator를 커서로 생각해 동작을 구현

## 참고

- iterator의 이동에서 연산자를 앞에 붙이는 것이 더 자연스러움 (반환 후 이동과 이동 후 반환의 차이)
- insert 함수는 iterator가 가리키는 원소의 앞에 삽입하며 반환값은 새로 삽입한 원소를 가리키는 iterator
- 범위 기반 for는 list에서도 사용 가능 (list 뿐만 아니라 begin과 end로 순회 가능한 객체에서 사용 가능)
