//Персональный шаблон проекта С++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define crtdarr(t, n, s) t * n = new t [s]
//Заполняет переданый массив случайными числами от мин до макс
void fillArr(int arr[], int length, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + max;
}
//Выводит массив в консоль
template <typename T> void  showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//Задача 1. Увеличение длины массива
template <typename T> T* addEl(T arr[], int length, int n) {
	if (n <= 0)
		return arr;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = new T[length + n];
	for (int i = 0; i < length; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}
//Задача 2. Уменьшение длины массива
template <typename T> T* delEl(T arr[], int length, int n) {
	if (n >= length || n <= 0)
		return arr;
	length -= n;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	return tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");

	/*int n;
	cout << "Введите длину массива: ";
	cin >> n;
	int* dArr = new int[n];
	fillArr(dArr, n, 10, 31);
	cout << "Массив длиною в " << n << ":\n";
	showArr(dArr, n);

	delete[] dArr;
	dArr = nullptr;

	crtdarr(int, myDArr, n); //int * myDArr = new int[n];*/
	/*int* pn = new int;
	cout << pn << endl;
	*pn = 10;
	cout << *pn << endl;

	delete pn;
	pn = nullptr;
	
	pn = new int;
	*pn = 17;
	cout << pn << endl;
	cout << *pn << endl;*/
	//Задача 1.
	/*cout << "Задача 1.\nВведите длину массива: ";
	int size1;
	cin >> size1;
	int *z1 = new int[size1];
	fillArr(z1, size1, 10, 31);
	cout << "Изначальный массив:\n";
	showArr(z1, size1);
	z1 = addEl(z1, size1, 3);
	size1 += 3;
	cout << "Итоговый массив:\n";
	showArr(z1, size1);*/
	//Задача 2.
	cout << "Задача 2.\nВведите длину массива: ";
	int size2;
	cin >> size2;
	int* z2 = new int[size2];
	fillArr(z2, size2, 20, 41);
	cout << "Изначальный массив:\n";
	showArr(z2, size2);
	z2 = delEl(z2, size2, 2);
	size2 -= 2;
	cout << "Итоговый массив:\n";
	showArr(z2, size2);

	return 0;
}
