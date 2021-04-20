#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define max 100
char* toChar(int n)
{
    int m = n;
    char s[max];
    char *ss = new char[100];
    int i=0,j=0;
    ss[j++] = 's';ss[j++] = 'd';ss[j++] = 'a';ss[j++] = 't';ss[j++] = 'a';
    if (n < 0)// 处理负数
    {
        m = 0 - m;
        j = 1;
        ss[j++] = '-';
    }
    while (m>0)
    {
        s[i++] = m % 10 + '0';
        m /= 10;
    }
    s[i] = '\0';
    i = i - 1;
    while (i >= 0)
    {
        ss[j++] = s[i--];
    }
    ss[j++] = '.';ss[j++] = 'o';ss[j++] = 'u';ss[j++] = 't';
    ss[j] = '\0';
    return ss;
}
