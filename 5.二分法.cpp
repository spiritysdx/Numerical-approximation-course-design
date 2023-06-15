//显示中文
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>//用于函数SetConsoleOutputCP(65001);更改cmd编码为utf8
#include<iostream>
#include<math.h>
#define eps 0.001
using namespace std;


double fun(double x)
{
    return x*sin(x)-1;
}

double dichotomy(double a,double b)
{
    double c = 0.0;
    if((fun(a)<0)&&(fun(b)>0))
    {
        while(true)
        {
            c=(a+b)/2;
            if(fun(c)<0)
            {
                a=c;
                if(fabs((a-b))<eps)
                {
                    return (a+b)/2;
                }
            }
            else if(fun(c)==0)
            {
                return c;
            }
            else
            {
                b=c;
                if(fabs((a-b))<eps)
                {
                    return (a+b)/2;
                }
            }
        }
    }
    else
    {
        cout<<"你输入的a和b不正确"<<endl;
        return -1;
    }
}

int main()
{
    //显示中文
    SetConsoleOutputCP(65001);
    
    double a = 0;
    double b = 2;
    double result=dichotomy(a,b);
    cout<<"求解的结果是："<<result<<endl;
    return 0;
}
