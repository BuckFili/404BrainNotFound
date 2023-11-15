#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
提示：DFS；利用递归，对所走过的点进行标记，并判断边界。
## 描述
有一个矩形房间，铺有方形瓷砖。每个瓷砖要么是红色，要么是黑色。一个人站在一块黑色的瓷砖上。从一个瓷砖，他可以移动到四个相邻的瓷砖之一。但他不能移动到红色的瓷砖上，只能在黑色的瓷砖上移动。
编写一个程序，计算他可以通过重复上述移动到达的黑色瓷砖的数量。

## 输入
输入包含多个数据集。一个数据集以包含两个正整数W和H的行开始；W和H分别是x和y方向上的瓷砖数量，其中W和H不超过20。
数据集中还有H行，每行包含W个字符。每个字符表示瓷砖的颜色，如下所示。
‘.’ - 黑色瓷砖
‘#’ - 红色瓷砖
‘@’ - 站在黑色瓷砖上的人（在数据集中只出现一次）
输入的结束由包含两个零的行表示。

## 输出
对于每个数据集，程序应输出一行，其中包含从初始瓷砖到达的瓷砖数量（包括初始瓷砖本身）。*/

//定义方向数组
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
//深度优先搜索
void dfs(char room[20][20], int visited[20][20], int x, int y, int W, int H){
	visited[x][y] = 1;
	//遍历四个方向上的相邻瓷砖
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//判断新位置是否越界&已被访问&黑色瓷砖
        if ((nx >= 0 && nx < H && ny >= 0 && ny < W) && !visited[nx][ny] && room[nx][ny] == '.') {
        //递归调用dfs
            dfs(room, visited, nx, ny, W, H);
		}
	}
}
// 计算可达的黑色瓷砖数量
int cnt(char room[20][20], int W, int H) {
    int visited[20][20] = { 0 };
    //寻找“人”的位置
    int startx, starty;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (room[i][j] == '@') {
                startx = i;
                starty = j;
                break;
            }
        }
    }
    //调用dfs函数
    dfs(room, visited, startx, starty, W, H);
    //统计被访问过的瓷砖数量
    int count = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int W, H;
    char room[20][20];
    while (1) {
        // 输入数据
        scanf("%d %d", &W, &H);

        // 判断输入是否结束
        if (W == 0 && H == 0) {
            break;
        }

        // 输入房间信息
        for (int i = 0; i < H; ++i) {
            scanf("%s", room[i]);
        }

        // 计算并输出结果
        int ans = cnt(room, W, H);
        printf("%d\n", ans);
    }

    return 0;
}