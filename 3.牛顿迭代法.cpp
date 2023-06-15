//显示中文
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>//用于函数SetConsoleOutputCP(65001);更改cmd编码为utf8
#include<iostream>
#include <math.h>
using namespace std;


//https://wk.baidu.com/view/165668308c9951e79b89680203d8ce2f0066653a?pcf=2&bfetype=new
int main()
{
    //显示中文
    SetConsoleOutputCP(65001);
    
    int k = 1;
    long double p,p1,f,f1;
    cout<<"输入初值p0=";
    cin>>p1;
    cout<<endl;
    while(true)
    {
        f = 500.0 - (pow(1.0+p1,20)-1.0)/p1;
        cout<<"p="<<f<<endl;
        f1 = -(20.0*pow(1.0+p1,19)-pow(1.0+p1,20))/(p1*p1);
        cout<<"p="<<f1<<endl;
        p=p1-f/f1;
        if(fabs(p-p1)<1e-2)
        {
            break;
        }
        p1=p;
        k++;
    }
    cout<<"p="<<p<<endl;
    cout<<"k="<<k<<endl;
    system("pause");
    return 0;
}
