#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int rec[1000] = { 0 };
//recursion
int cal(int i) {
    if (i >= 0){
        if (rec[i] != -1) {
            return rec[i];
        }else{
            return rec[i] = (cal(i - 1) + cal(i - 2));
        }
    }else{
        return 0;
    }
}

int main(){
    int r=0;
    //input
    scanf("%d",&r);
  
    //initialize
    for (int i = 0; i < 1000; i++) {
        rec[i] = -1;
    }
    rec[0] = 1;
    //output
    printf("%d", cal(r));
}