#include <stdio.h>
#include <stdlib.h>

int main() {
	char* all_input, *all_input_ex;
	all_input = (char*)malloc(100);
	all_input_ex = all_input;
	int group,k;
	group = 0;
	gets_s(all_input,100); // "00 000 00 0000"�� ����� �޸� �� ��������� ù��° �ּҸ� ������
	all_input_ex = all_input;
	for (;(*all_input_ex)!='\0';all_input_ex++) {
		if (*(all_input_ex) == ' ') {
			group++;
		}
	}
	group++; // �׷��� ���� ���ϱ� (���鹮�� ���� +1)
	int* G;
	G = (int*)malloc(group * 4); // �� �׷��� �ο����� ������ �迭 G ����
	all_input_ex = all_input;
	for (k = 0;k < group;k++) { 
		(*(G + k)) = 0;
		for (;((*all_input_ex) != ' ')&&((*all_input_ex)!='\0');all_input_ex++) {
			(*(G + k))++;
		} // �迭 G�� �׷� �ο��� ��� G+k�� G[k], ������ �̷��� ���� -> G[0]�� ù��° �׷��� �ο����� ����, G[k]�� k+1��° �׷��� �ο��� ����
		all_input_ex++; // ���� for�����θ� ������ all_input_ex�� ' '�� ����Ű�� �ǹǷ� �������Ѽ� �� ���� ���ں��� ����Ű�� �ؾ���
	} // �� �׷쿡 ��� �ִ��� Ȯ��
	for (k = 1;k <= group;k++) {
		printf("%d %d\n", k, *(G + k - 1));
	}
	free(all_input);
	free(G);
	return 0;
}