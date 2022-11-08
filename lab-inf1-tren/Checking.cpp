#include <iostream>
#include <cmath>
using namespace std;

double lenght(int x, int x0, int y, int y0);

int main()
{
	int x1, x2, x3, x4, y1, y2, y3, y4;
	double a, b, c, d;
	double l1, l2, l3, l4, l5, l6;
	double minx;
	for (int i = 1; i <= 1; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2 
			>> x3 >> y3 >> x4 >> y4;
		l1 = lenght(x1, x2, y1, y2);
		l2 = lenght(x1, x3, y1, y3);
		l3 = lenght(x1, x4, y1, y4);
		l4 = lenght(x2, x3, y2, y3);
		l5 = lenght(x2, x4, y2, y4);
		l6 = lenght(x3, x4, y3, y4);

		a = sqrt(((l1 + l2 + l3) * 1.0 / 2) * ((l1 + l2 + l3) * 1.0 / 2 - l1) * ((l1 + l2 + l3) * 1.0 / 2 - l2) *
			((l1 + l2 + l3) * 1.0 / 2 - l3));
		b = sqrt(((l3 + l4 + l6) * 1.0 / 2) * ((l3 + l4 + l6) * 1.0 / 2 - l3) * ((l3 + l4 + l6) * 1.0 / 2 - l4) *
			((l3 + l4 + l6) * 1.0 / 2 - l6));
		c = sqrt(((l2 + l4 + l5) * 1.0 / 2) * ((l2 + l4 + l5) * 1.0 / 2 - l2) * ((l2 + l4 + l5) * 1.0 / 2 - l4) *
			((l2 + l4 + l5) * 1.0 / 2 - l5));
		d = sqrt(((l4 + l5 + l6) * 1.0 / 2) * ((l4 + l5 + l6) * 1.0 / 2 - l4) * ((l4 + l5 + l6) * 1.0 / 2 - l5) *
			((l4 + l5 + l6) * 1.0 / 2 - l6));

		if ((a + b) == (c + d))
		{
			if (i == 1)
				minx = a + b + c + d;
			else
				minx = min(minx, a + b + c + d);
		}
		else
		{
			cout << "Error!!!";
			i--;
		}
	}
	cout << "Min per = " << minx << endl;
}

double lenght(int x, int x0, int y, int y0)
{
	double a;
	a = pow((x - x0), 2) + pow((y - y0), 2);
	return sqrt(a);
}