// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cctype> //tolower
#include <string>

using namespace std;


template< class T >
void selectSort(vector<T> &arr, int size);
template< class T >
void p(const vector<T> &arr, int size = 0);
template< class T >
void input(vector<T> &arr,const int sizeKey = 0);
//string inputVector(const string str, const int sizeKey = 0);
int main()
{
	vector<char> key;
	vector<string> myV;
	key.push_back('A');
	key.push_back('a');
	key.push_back('A');
	key.push_back('O'); 
	key.push_back('O');
	key.push_back('o');
	key.push_back('b');
	key.push_back('p');
	key.push_back('i');


	input(myV, 6);
	
	/*for (int i = 0; i < myV.size(); i++) {
		cout << myV[i] << endl;
	}*/
	//p(key, key.size());
	//selectSort(key, key.size());
	//p(key, key.size());
}



template< class T >
void selectSort(vector<T>  &arr, int size)
{
	T tmp;
	for (int i = 0; i < size; i++) // i - номер текущего шага
	{
		int pos = i;
		tmp = arr[i];
		for (int j = i + 1; j < size; j++) // цикл выбора наименьшего элемента
		{
			int s = tolower(arr[i] - arr[j]);
			if (s == 0)
			{
				s = arr[i] - arr[j];
			}
			if (s > 0)
			{
				if (arr[j] < tmp)
				{
					pos = j;
					tmp = arr[j];
					arr[pos] = arr[i];
					arr[i] = tmp;
				}
			}

		}
// меняем местами наименьший с a[i]
	}
}



template<class T>
void p(const vector<T>& arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

template<class T>
void input(vector<T>& arr,const int sizeKey)
{
	std::string str;
	
	// I'm confused about whether you want a line, or a word.
	// this gets a line
	std::getline(std::cin, str);

	// this gets a word
	//std::cin >> str;

	int count = str.size();
	int countStr = 0;
	if (count %sizeKey == 0)
		countStr =  count / sizeKey;
	else
		countStr = 1 + count / sizeKey;

	for (int i = 0; i < countStr; i++)
	{
		string tmp;
		//for (int j = 0; j < sizeKey; j++)
		//{
			tmp.copy(str, sizeKey, sizeKey*i);
		//}
		arr.push_back(tmp);
	}
	

	 
}

string inputVector(const string str, const int sizeKey)
{
	return string();
}
