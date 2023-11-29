#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int a[1000][1000] = { 0 };
int rec[1000][1000] = { 0 };

int max(int x, int y) {
    return(x > y ? x : y);
}

int cal(int i, int j) {
    rec[i][j] = (max(rec[i + 1][j], rec[i + 1][j + 1]) + a[i][j]);
    return 0;
}

int main(){
  int r=0;
  //input
  scanf("%d",&r);
  for(int i=0,k=1;i<r;i++,k++){
    for(int j=0;j<k;j++){
      scanf("%d",&a[i][j]);
    }
  }

  //recursion
  for (int i = r-1, k = r-1; i >-1; i--, k--) {
      for (int j = 0; j <= k; j++) {
          cal(i, j);
      }
  }

  //output
  printf("%d", rec[0][0]);
}