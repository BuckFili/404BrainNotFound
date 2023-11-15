#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
��ʾ��DFS�����õݹ飬�����߹��ĵ���б�ǣ����жϱ߽硣
## ����
��һ�����η��䣬���з��δ�ש��ÿ����שҪô�Ǻ�ɫ��Ҫô�Ǻ�ɫ��һ����վ��һ���ɫ�Ĵ�ש�ϡ���һ����ש���������ƶ����ĸ����ڵĴ�ש֮һ�����������ƶ�����ɫ�Ĵ�ש�ϣ�ֻ���ں�ɫ�Ĵ�ש���ƶ���
��дһ�����򣬼���������ͨ���ظ������ƶ�����ĺ�ɫ��ש��������

## ����
�������������ݼ���һ�����ݼ��԰�������������W��H���п�ʼ��W��H�ֱ���x��y�����ϵĴ�ש����������W��H������20��
���ݼ��л���H�У�ÿ�а���W���ַ���ÿ���ַ���ʾ��ש����ɫ��������ʾ��
��.�� - ��ɫ��ש
��#�� - ��ɫ��ש
��@�� - վ�ں�ɫ��ש�ϵ��ˣ������ݼ���ֻ����һ�Σ�
����Ľ����ɰ�����������б�ʾ��

## ���
����ÿ�����ݼ�������Ӧ���һ�У����а����ӳ�ʼ��ש����Ĵ�ש������������ʼ��ש������*/

//���巽������
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
//�����������
void dfs(char room[20][20], int visited[20][20], int x, int y, int W, int H){
	visited[x][y] = 1;
	//�����ĸ������ϵ����ڴ�ש
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//�ж���λ���Ƿ�Խ��&�ѱ�����&��ɫ��ש
        if ((nx >= 0 && nx < H && ny >= 0 && ny < W) && !visited[nx][ny] && room[nx][ny] == '.') {
        //�ݹ����dfs
            dfs(room, visited, nx, ny, W, H);
		}
	}
}
// ����ɴ�ĺ�ɫ��ש����
int cnt(char room[20][20], int W, int H) {
    int visited[20][20] = { 0 };
    //Ѱ�ҡ��ˡ���λ��
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
    //����dfs����
    dfs(room, visited, startx, starty, W, H);
    //ͳ�Ʊ����ʹ��Ĵ�ש����
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
        // ��������
        scanf("%d %d", &W, &H);

        // �ж������Ƿ����
        if (W == 0 && H == 0) {
            break;
        }

        // ���뷿����Ϣ
        for (int i = 0; i < H; ++i) {
            scanf("%s", room[i]);
        }

        // ���㲢������
        int ans = cnt(room, W, H);
        printf("%d\n", ans);
    }

    return 0;
}