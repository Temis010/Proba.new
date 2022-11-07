#include <iostream>
using namespace std;

int ris(int a, int b);

int main()
{
	int a, b, z;
	/*cin >> a;
	cin >> b;*/
	a = 5;
	b = 8;
	z = ris(a, b);
	return 0;
}

int ris(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		for (int y = 1; y <= i; y++)
		{
			for (int x = 1; x <= i; x++)
			{
				if (x % 2 == 1)
				{
					if ((x <= (i / 2 + 1 - (y - 1))) && (x >= (i / 2 + 1 + (y - 1))))

						cout << "#";

					else

						cout << ".";
				}
				else
					cout << ".";
			}
		cout << endl;
		}
		cout << endl << "new figure" << endl;
	}
	return 0;
}