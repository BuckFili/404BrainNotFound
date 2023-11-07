#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
��������Ľ��꣬ˮ�㼯��Farmer John��s��صĲ�ͬ�ط�������N��M��1 <= N <= 100; 1 <= M <= 100���������ξ��α�ʾ��ÿ���������ˮ����W�����򺵵أ���.������ũ��Լ����Ū�������������ж��ٸ�������������һ�����ӵ������Σ�������ˮ������һ�������α���Ϊ�������а˸��ھ����ڡ�

����ũ��Լ�������ͼ��ȷ�����ж��ٳ�����
����

*��1�У������Կո�ָ���������N��M.

*��2��N + 1��ÿ��M���ַ�����һ��Farmer John���ֶΡ�ÿ���ַ����ǡ�W����.�����ַ�֮��û�пո�
����

*��1�У�Farmer John�������ĳ���������*/

//����
char field[100][100];
int M = 0, N = 0;

//���ĳ�����Ƿ�Ϊ����ڵ�ˮ��
int DetectWaterAndArea(int x, int y) {
	return(x >= 0 && x < N && y >= 0 && y <= M && field[x][y] == 'W');
}

//������������㷨��������ˮ��
int ExplorePond(int x, int y) {
	if (!DetectWaterAndArea(x, y)) {
		return 0;
	}
	field[x][y] = '.';

	// ������ǰ����İ˸����ڷ���
	int dx, dy;
	for (dx = -1; dx <= 1; dx++) {
		for (dy = -1; dy <= 1; dy++) {
			ExplorePond(x + dx, y + dy);
		}
	}
}

//������
int main() {
	//input
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", field[i]);
	}
	int cnt = 0;
	//�������
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 'W') {
				ExplorePond(i, j);
				cnt++;
			}
		}
	}
	//output
	printf("%d\n", cnt);
}