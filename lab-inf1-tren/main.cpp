#include "Header.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{	
	vector <double> data = intersect(func2);
	
	for (int i = 0; i < data.size(); i++)
	{
		cout << data.at(i) << ' ';
	}
	cout << endl;
	/*double sum = 0;
	for (int i = 0; i < data.size(); i++)
		sum += data.at(i);
	double per = sum * 1.0 / data.size();*/
	//cout << round(per * pow(10, 6)) / pow(10, 6);
	return 0;
}

vector<double> intersect(float(*func)(float))
{
	vector<double> arr;
	for (double i = -3.1; i <= 3.1; i = i + 0.0005)
	{
		if (abs(func(i)) <= 0.001)
			arr.push_back(i);
	}
	return arr;
}