#include <iostream>
#include <fstream>

using namespace std;

void print(int* mass, int count)
{
	for (int i = 0; i < count; ++i)
		cout << mass[i] << " ";
}

void swap(int* mass, int i, int j)
{
	int temp = mass[i];
	mass[i] = mass[j];
	mass[j] = temp;
}

void sort(int* mass, int i, int count)
{
	//cout << "--------------" << endl;
	//print(mass, count);
	cout << endl;
	for (int k = i; k < count; ++k)
	{
		//cout << "ELEMENT: " << mass[k] << endl;
		for (int t = i; t < count - 1; ++t)
		{
			//cout << "MASS: " << mass[t] << ", " << mass[t + 1] << endl;
			if (mass[t] > mass[t + 1])
				swap(mass, t, t + 1);
		}
	}
}

void find(int* mass, int count)
{
	for (int i = count - 1; i > 0; --i)
	{
		cout << mass[i] << " : " << mass[i - 1] << endl;
		if (mass[i - 1] > mass[i]) // следующий элемент больше текущего
			continue;

		for (int j = count - 1; j > 0; --j)
		{
			if (mass[j] < mass[i - 1]) // больше отмеченного из первого цикла
				continue;

			swap(mass, i - 1, j); // меняем местами
			sort(mass, i, count); // сортируем

			print(mass, count);
			cout << endl;
		}
	}
}

int main()
{
	fstream f;
	int count;

	f.open("input.txt", ios::in);
	f >> count;

	int* mass = new int[count];
	for (int i = 0; i < count; ++i)
		f >> mass[i];

	f.close();

	find(mass, count);

	f.open("output.txt", ios::out);
	f.close();

	delete[] mass;
	return 0;
}
