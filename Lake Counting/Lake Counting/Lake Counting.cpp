#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
由于最近的降雨，水汇集在Farmer John’s田地的不同地方，其由N×M（1 <= N <= 100; 1 <= M <= 100）的正方形矩形表示。每个方块包含水（‘W’）或旱地（’.’）。农夫约翰想弄清楚他的田地里有多少个池塘。池塘是一组连接的正方形，其中有水，其中一个正方形被认为与其所有八个邻居相邻。

给出农夫约翰的田地图，确定他有多少池塘。
输入

*第1行：两个以空格分隔的整数：N和M.

*行2…N + 1：每行M个字符代表一行Farmer John的字段。每个字符都是’W’或’.’。字符之间没有空格。
产量

*第1行：Farmer John的田地里的池塘数量。*/

//定义
char field[100][100];
int M = 0, N = 0;

//检查某方格是否为田地内的水域
int DetectWaterAndArea(int x, int y) {
	return(x >= 0 && x < N && y >= 0 && y <= M && field[x][y] == 'W');
}

//利用深度优先算法搜索整个水域
int ExplorePond(int x, int y) {
	if (!DetectWaterAndArea(x, y)) {
		return 0;
	}
	field[x][y] = '.';

	// 遍历当前方格的八个相邻方格
	int dx, dy;
	for (dx = -1; dx <= 1; dx++) {
		for (dy = -1; dy <= 1; dy++) {
			ExplorePond(x + dx, y + dy);
		}
	}
}

//主函数
int main() {
	//input
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", field[i]);
	}
	int cnt = 0;
	//遍历田地
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