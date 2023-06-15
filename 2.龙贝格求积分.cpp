#include<iostream>
#include<math.h>
#define N 20             //区间等分份数
#define MAX 10 
#define a 0
#define b 1
#define f(x) (sin(x))    //函数
#define epsilon 0.0001    //有效数字
using namespace std;

double Romberg(double aa,double bb,long int n)
{
    int i;
    double sum,h=(bb-aa)/n;
    sum = 0;
    for(i=1;i<n;i++)
    {
        sum=sum+f(aa+i*h);
    }
    sum = sum + (f(aa)+f(bb))/2;
    return (h*sum);
}

int main()
{
    int i;
    long int n=N, m=0;
    double T[2][MAX+1];
    T[1][0]=Romberg (a, b,n) ;
    n=n*2;
    for (m=1;m<MAX;m++)
    {
        for(i=0;i<=m;i++)
        {
            T [0][i]=T[1][i];
        }
        T[1][0]=Romberg(a, b, n) ;
        n=n*2;
        for(i=1;i<=m;i++)
        {
            T[1][i]=T[1][i-1]+(T[1][i-1]-T[0] [i-1])/(pow (2, 2*m)-1);
        }
        if ((T[0][m-1]-T[1] [m]) <epsilon)
        {
            cout<<"T="<<T[1] [m]<<endl;
        }
        system("pause");
        return 0;
    }
}
