//������������ ������ ������� �++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define crtdarr(t, n, s) t * n = new t [s]
//��������� ��������� ������ ���������� ������� �� ��� �� ����
void fillArr(int arr[], int length, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + max;
}
//������� ������ � �������
template <typename T> void  showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//������ 1. ���������� ����� �������
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
//������ 2. ���������� ����� �������
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
	cout << "������� ����� �������: ";
	cin >> n;
	int* dArr = new int[n];
	fillArr(dArr, n, 10, 31);
	cout << "������ ������ � " << n << ":\n";
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
	//������ 1.
	/*cout << "������ 1.\n������� ����� �������: ";
	int size1;
	cin >> size1;
	int *z1 = new int[size1];
	fillArr(z1, size1, 10, 31);
	cout << "����������� ������:\n";
	showArr(z1, size1);
	z1 = addEl(z1, size1, 3);
	size1 += 3;
	cout << "�������� ������:\n";
	showArr(z1, size1);*/
	//������ 2.
	cout << "������ 2.\n������� ����� �������: ";
	int size2;
	cin >> size2;
	int* z2 = new int[size2];
	fillArr(z2, size2, 20, 41);
	cout << "����������� ������:\n";
	showArr(z2, size2);
	z2 = delEl(z2, size2, 2);
	size2 -= 2;
	cout << "�������� ������:\n";
	showArr(z2, size2);

	return 0;
}
