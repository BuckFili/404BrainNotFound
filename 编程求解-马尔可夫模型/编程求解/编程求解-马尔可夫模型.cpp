#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//定义函数
void cal(double a[], const double b[3][3]);
void print_max(double m[]);
//定义
char* name[] = { (char*)"玩手机",(char*)"工作",(char*)"学习" };
int term = 0;
//状态转移概率
double mx[3][3] = {
    {0.9, 0.075, 0.025},  // 从玩手机到其他状态的概率
    {0.15, 0.8, 0.05},   // 从工作到其他状态的概率
    {0.25, 0.25, 0.5}    // 从学习到其他状态的概率
};
//输出第三问的答案
void answer_of_the_third_question(){
    printf("观察可得，无论初始概率分布如何，在经过一段足够长的时间后，Elwin总是会有0.625的概率玩手机，0.3125的概率工作，0.0625的概率学习，即学期结束后处于学习状态的概率不会有任何提高，Elwin只有改变他的生活规律才能提高他的学习概率。");
}

//初始概率分布
double s1[3] = { 0.3, 0.4, 0.3 };
double s2[3] = { 0.1, 0.4, 0.5 };

int main() {
    cal(s1, mx);
    cal(s2, mx);
    answer_of_the_third_question();
}

void cal(double a[], const double b[3][3]) {
    double m[3]{};
    for(double diff = 100; diff > 1e-15;){
        for (int i = 0; i < 3; i++) {
            double cnt = 0;
            for (int j = 0; j < 3; j++) {
                cnt += a[j] * b[j][i];
            }
            m[i] = cnt;
        }
        //检查矩阵乘法运行结果
        for (int i = 0; i < 3; i++) {
            printf("%lf  ", a[i]);
        }
        diff = 0;
        double c = 0;
        for (int i = 0; i < 3; i++) {
            c = m[i] - a[i];
            if (c <= 0)c = -c;
            diff += c;
        }
        memcpy(a, m, sizeof(m));
    }
    print_max(m);
}

void print_max(double m[]) {
    double max = 0;
    int k = 0;
    term++;
    for (int i = 0; i < 3; i++) {
        if (max < m[i]) { 
            max = m[i];
            k = i;
        }
    }
    printf("第%d学期结束后，Elwin最可能处于%s状态\n",term,name[k]);
}