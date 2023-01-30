#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	double A = -2, B = -0.1, E = 0.000001;
	double x, SN, SE, Y, k, SE1;
	int n = 40, j;
	k = (B - A) / 10;
	cout << fixed << setprecision(5);
	for (x = A; x < B; x+=k)
	{
		SN = 0;
		SE = 0;
		for (int i = 1; i <= n; i++)
		{
			SN += pow((-1), i) * (pow(1 + x, 2 * i) / i);
		}
		j = 1;
		do
		{
			SE1 = SE;
			SE += pow((-1), j) * (pow(1 + x, 2 * j) / j);
			++j;
		} while (abs(SE - SE1) > E);
		Y = log(1 / (2 + 2 * x + x * x));
		cout << "X = " << x << "\t" << "SN = " << SN << "\t" << "SE = " << SE << "\t" << "Y = " << Y << endl;
	}
	return 0;
}