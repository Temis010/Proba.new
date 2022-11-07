#include <iostream>
using namespace std;

int ris(int a, int b);

int main()
{
	int a, b, z;
	cin >> a;
	cin >> b;
	z = ris(a, b);
}

int ris(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		for (int y = 1; y <= i; y++)
		{
			for (int x = 1; x <= i; x = x + 2)
			{
				if (x <= (i / 2 + 1 - (y - 1)) && x >= (i / 2 + 1 + (y - 1)))
			
					cout << "#";
			
				else
				
					cout << ".";
				
			}
			cout << endl;
		}
	}
	return 0;
}