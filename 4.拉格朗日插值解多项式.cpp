//显示中文
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>//用于函数SetConsoleOutputCP(65001);更改cmd编码为utf8
#include<iostream>
#define N 4   //插值 节点的个数
using namespace std;


int main()
{
    //显示中文
    SetConsoleOutputCP(65001);
    
    float x[N],y[N],a,f=0,temp;
    int i,j;
    cout<<"输入插值节点的坐标: "<<endl;
    for(i=0;i<N;i++)
    { 
        cin>>x[i];
        cin>>y[i] ;
    }
    cout<<"输入所求点横坐标:";
    cin>>a;
    for(i=0;i<N;i++)
    {
        temp=1;
        {
            for(i=0; i<N; i++)
            if(i!=j)
                temp=temp*(a-x[j])/(x[i]-x[j]);
        }
        f=f+temp*y[i];
    }
    cout<<"所求值为："<<f<<endl;
    return 0;
}
