#include <stdio.h>
#include <stdlib.h>

int main() {
	char* all_input, *all_input_ex;
	all_input = (char*)malloc(100);
	all_input_ex = all_input;
	int group,k;
	group = 0;
	gets_s(all_input,100); // "00 000 00 0000"이 저장된 메모리 내 저장공간의 첫번째 주소를 저장함
	all_input_ex = all_input;
	for (;(*all_input_ex)!='\0';all_input_ex++) {
		if (*(all_input_ex) == ' ') {
			group++;
		}
	}
	group++; // 그룹의 갯수 구하기 (공백문자 개수 +1)
	int* G;
	G = (int*)malloc(group * 4); // 각 그룹의 인원수를 저장할 배열 G 선언
	all_input_ex = all_input;
	for (k = 0;k < group;k++) { 
		(*(G + k)) = 0;
		for (;((*all_input_ex) != ' ')&&((*all_input_ex)!='\0');all_input_ex++) {
			(*(G + k))++;
		} // 배열 G에 그룹 인원수 기록 G+k는 G[k], 문법상 이렇게 적음 -> G[0]은 첫번째 그룹의 인원수를 저장, G[k]는 k+1번째 그룹의 인원수 저장
		all_input_ex++; // 안의 for문으로만 끝나면 all_input_ex는 ' '을 가리키게 되므로 증가시켜서 그 다음 문자부터 가리키게 해야함
	} // 각 그룹에 몇명 있는지 확인
	for (k = 1;k <= group;k++) {
		printf("%d %d\n", k, *(G + k - 1));
	}
	free(all_input);
	free(G);
	return 0;
}