//显示中文
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>//用于函数SetConsoleOutputCP(65001);更改cmd编码为utf8
#include<iostream>
#include<iomanip>
using namespace std;


double f(double t, double x, double y)
{
	double dx;  
	dx = x + 2 * y;  
	return(dx);
}  
double g(double t, double x, double y)
{ 
	double dy;  
	dy = 3 * x + 2 * y; 
	return(dy);
}
void LG(double(*f)(double t, double x, double y), 
		double(*g)(double t, double x, double y), 
		double cz[3], double rs[3], double h)
{
	double f1, f2, f3, f4, g1, g2, g3, g4, t0, x0, y0, x1, y1;
	t0 = cz[0]; 
	x0 = cz[1]; 
	y0 = cz[2];
	f1 = f(t0, x0, y0);
	g1 = g(t0, x0, y0);
	f2 = f(t0 + h / 2, x0 + h * f1 / 2, y0 + h * g1 / 2);
	g2 = g(t0 + h / 2, x0 + h * f1 / 2, y0 + h * g1 / 2);
	f3 = f(t0 + h / 2, x0 + h * f2 / 2, y0 + h * g2 / 2);
	g3 = g(t0 + h / 2, x0 + h * f2 / 2, y0 + h * g2 / 2);
	f4 = f(t0 + h, x0 + h * f3, y0 + h * g3);
	g4 = f(t0 + h, x0 + h * f3, y0 + h * g3);
	x1 = x0 + h * (f1 + 2 * f2 + 2 * g3 + g4) / 6;
	y1 = y0 + h * (g1 + 2 * g2 + 2 * g3 + g4) / 6;
	rs[0] = t0 + h; rs[1] = x1; rs[2] = y1;
}


int main()
{
	//显示中文
    SetConsoleOutputCP(65001);
	
	double cz[3], rs[3]; 
	double a, b, S; 
	double t, step; 
	int i; 
	cout << "输入微分方程的初值:";  
	cin >> cz[0] >> cz[1] >> cz[2];
	cout << "输入所求微分方程组的微分区间[a,b]:";  cin >> a >> b;  
	cout << "输入所求微分方程组所分解子区间的个数:";  
	cin >> step; 
	S = (b - a) / step; 
	cout << cz[0] << setw(10) << cz[1] << setw(10) << cz[2] << endl; 
	for (i = 0; i < step; i++) 
	{ 
		LG(f, g, cz, rs, S);  
		cout << rs[0] << setw(10) << rs[1] << setw(10) << rs[2] << endl; 
		cz[0] = rs[0]; 
		cz[1] = rs[1]; 
		cz[2] = rs[2]; 
	}  

	system("pause");
	return 0;
} 

