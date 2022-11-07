#include <iostream>
using namespace std;
int main()
{
	float a, b, c, x, y, z, otv;
	a = (5 + 1.0 / 2) / 2.2 + 6 + 2.0 / 3;
	b = 0.75 + 4 + 1.0 / 4 - 0.8 * (6 + 2.0 / 3);
	x = (4 + 1.0 / 3 + 9) * 0.75;
	y = 6.25 - (3 + 3.0 / 4);
	c = (a / b) / (1 + 3.0 / 7);
	z = x / y;
	otv = c - z;
	cout << "Otvet: " << otv;	
	return 0;
}