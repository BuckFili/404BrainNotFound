#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//���庯��
void cal(double a[], const double b[3][3]);
void print_max(double m[]);
//����
char* name[] = { (char*)"���ֻ�",(char*)"����",(char*)"ѧϰ" };
int term = 0;
//״̬ת�Ƹ���
double mx[3][3] = {
    {0.9, 0.075, 0.025},  // �����ֻ�������״̬�ĸ���
    {0.15, 0.8, 0.05},   // �ӹ���������״̬�ĸ���
    {0.25, 0.25, 0.5}    // ��ѧϰ������״̬�ĸ���
};
//��������ʵĴ�
void answer_of_the_third_question(){
    printf("�۲�ɵã����۳�ʼ���ʷֲ���Σ��ھ���һ���㹻����ʱ���Elwin���ǻ���0.625�ĸ������ֻ���0.3125�ĸ��ʹ�����0.0625�ĸ���ѧϰ����ѧ�ڽ�������ѧϰ״̬�ĸ��ʲ������κ���ߣ�Elwinֻ�иı�����������ɲ����������ѧϰ���ʡ�");
}

//��ʼ���ʷֲ�
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
        //������˷����н��
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
    printf("��%dѧ�ڽ�����Elwin����ܴ���%s״̬\n",term,name[k]);
}