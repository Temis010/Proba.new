#include "Header.h"//подключение заголовочного файла с подключением модулей и объ€влением функций

using namespace std;

//функции нахождени€ точек пересечени€ прописаны в основном файле, так как при выносе в отдельный файл не подключаетс€ vector
vector<double> intersect(double step, int rounding_to_n_sign, float(*func)(float));//точки пересечени€ функции с осью Ox
vector<double> intersect(double step, int rounding_to_n_sign, float(*func1)(float), float(*func2)(float));//точки пересечени€ двух функций

int main()
{
	vector <double> data = intersect(0.00001, 6, func1, func2);//массив с точками пересечени€ функций

	cout << "Intersection points: ";
	for (int i = 0; i < data.size(); i++)
	{
		cout << data.at(i) << ' ';//вывод точек пересечени€
	}
	cout << endl;

	double square = abs(simpsons_(data.at(0), data.at(1), 10, func1) - simpsons_(data.at(0), data.at(1), 10, func2));//нахождение площади
	cout << "Square = " << square;
	return 0;
}

vector<double> intersect(double step, int rounding_to_n_sign, float(*func)(float))
{
	vector<double> arr;//массив со значени€ми, при которых значение функции находитс€ в допустимых пределах от 0
	vector<double> result;
	for (double i = -200.0; i <= 200; i = i + step)//перебираем значени€ x с определенным шагом, вли€ющим на количество точек в arr
	{
		if (abs(func(i)) <= step)//проверка на нахождение в допустимом пределе
			arr.push_back(i);
	}

	//далее нахожу средние арифметические всех точек вблизи "насто€щией точки" и таким образом нахожу примерное значение точек пересечени€
	//при этом округл€ю значени€ до n-ого знака после зап€той
	int count = 1;
	double summ = arr.at(0);
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr.at(i) - arr.at(i - 1) <= step * 2.0)
		{
			summ += arr.at(i);
			count++;
		}
		else
		{
			result.push_back(round(summ / count * pow(10, rounding_to_n_sign)) / pow(10, rounding_to_n_sign));
			count = 1;
			summ = arr.at(i);
		}
	}
	result.push_back(round(summ / count * pow(10, rounding_to_n_sign)) / pow(10, rounding_to_n_sign));
	return result;
}

vector<double> intersect(double step, int rounding_to_n_sign, float(*func1)(float), float(*func2)(float))
{
	vector<double> arr;
	vector<double> result;
	for (double i = -200.0; i <= 200; i = i + step)
	{
		if (abs(func1(i) - func2(i)) <= step)
			arr.push_back(i);
	}

	int count = 1;
	double summ = arr.at(0);
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr.at(i) - arr.at(i - 1) <= step * 2.0)
		{
			summ += arr.at(i);
			count++;
		}
		else
		{
			result.push_back(round(summ / count * pow(10, rounding_to_n_sign)) / pow(10, rounding_to_n_sign));
			count = 1;
			summ = arr.at(i);
		}
	}
	result.push_back(round(summ / count * pow(10, rounding_to_n_sign)) / pow(10, rounding_to_n_sign));
	return result;
}
