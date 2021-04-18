//Ввод/вывод. Для любой нетривиальной задачи написать набор тестов. Написать скрипт запускающий все тесты по-отдельности сравнивающий результаты решения задачи с заранее подготовленными.
#include <iostream>
#include "Insertion_sort.h"

using namespace std;

int main(int argc, char** argv)
{
	unsigned int i;
	int n;
	cin >> n;
	if (!cin) cout << "Input Error1!"<< endl;
	else
	{
		int* A = new int[n];
		for (i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		if (!cin) cout << "Input Error2!"<< endl;
		else 
		{
    		insertionsort(A, A+n); //вызов сортирующей процедуры
 
    		cout << "Упорядоченный массив: "; //вывод упорядоченного массива
    		for (i = 0; i < n; i++) cout <<A[i] << " ";
    		cout << endl;
		}
   }
    return 0;
}
