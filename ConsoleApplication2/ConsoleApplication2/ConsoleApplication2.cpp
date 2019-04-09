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

template< class T, class B>
void encryption(vector<T> &arr, vector<B>& key);
template< class T, class B>
void decryption(vector<T> &arr, vector<B> key);

struct Key
{
	char ch;
	int number;
};

int main()
{
	Key keyCharacter;
	vector<Key> key;
	vector<string> myV;

	key.push_back(keyCharacter);
	key.push_back(keyCharacter);
	key.push_back(keyCharacter);
	key.push_back(keyCharacter);
	key.push_back(keyCharacter);

	key.at(0).number = 0;
	key.at(0).ch = 'A';
	key.at(1).number = 1;
	key.at(1).ch = 'N';
	key.at(2).number = 2;
	key.at(2).ch = 'D';
	key.at(3).number = 3;
	key.at(3).ch = 'P';
	key.at(4).number = 4;
	key.at(4).ch = 'B';



	input(myV, key.size());
	for (int i = 0; i < myV.size(); i++) {
		cout << myV[i] << endl;
	}
	/*for (int i = 0; i < key.size(); i++) {
		cout << key.at(i).ch << "	";
		cout << key.at(i).number << endl;
	}*/
	//decryption(myV, key);

	cout << endl;
	cout << endl;
	encryption(myV, key);
	for (int i = 0; i < myV.size(); i++) {
		cout << myV[i] << endl;
	}
	cout << endl;
	cout << endl;

	decryption(myV, key);
	for (int i = 0; i < myV.size(); i++) {
		cout << myV[i] << endl;
	}
	
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
	//std::getline(std::cin, str);
	str = ("No description, website, or topics provided.");
	// this gets a word
	//std::cin >> str;

	int count = str.size();
	int countStr = 0;
	bool cStr = 0;
	if (count %sizeKey == 0)
	{
		countStr = count / sizeKey;
		cStr = 0;
	}
	else
	{
		countStr = 1 + count / sizeKey;
		cStr = 1;
	}

	for (int i = 0; i < countStr; i++)
	{
		string tmp;
		if (i == (countStr - 1) && cStr == 1)
		{
			tmp = str.substr(sizeKey*i, sizeKey);
			int tSize = tmp.size();
			for (int i = tSize; i < sizeKey; i++)
				tmp.push_back('*');
		}
		else
			tmp = str.substr(sizeKey*i, sizeKey);



		arr.push_back(tmp);
	}
	

	 
}

template<class T, class B>
void encryption(vector<T>& arr, vector<B>& key)
{
	vector<B> BUFF;
	BUFF = key;
	B tmp;
	char tmp_1;
	string b;
	for (int k = 0; k < arr.size(); k++)
	{
		b = arr[k];
		key = BUFF;
		for (int i = 0; i < b.size(); i++) // i - номер текущего шага
		{
			int pos = i;
			tmp_1 =  b[i];
			for (int j = i + 1; j < b.size(); j++) // цикл выбора наименьшего элемента
			{
	
				if (key.at(j).ch < key.at(i).ch)
				{
					tmp_1 = b[j];
					b[j] = b[i];
					b[i] = tmp_1;
					
					tmp = key.at(j);
					key.at(j) = key.at(i);
					key.at(i) = tmp;
				}

			}
			// меняем местами наименьший с a[i]
		}

		arr[k] = b;
	}


}

template<class T, class B>
void decryption(vector<T>& arr, vector<B> key)
{
	vector<B> BUFF;
	BUFF = key;
	//selectSort(key, key.size());
	B tmp;
	char tmp_1;
	string b;
	for (int k = 0; k < arr.size(); k++)
	{
		b = arr[k];
		key = BUFF;
		for (int i = 0; i < b.size(); i++) // i - номер текущего шага
		{
			int pos = i;
			tmp_1 = b[i];
			for (int j = i + 1; j < b.size(); j++) // цикл выбора наименьшего элемента
			{

				if (key.at(j).number < key.at(i).number)
				{
					tmp_1 = b[j];
					b[j] = b[i];
					b[i] = tmp_1;

					tmp = key.at(j);
					key.at(j) = key.at(i);
					key.at(i) = tmp;
				}

			}
			// меняем местами наименьший с a[i]
		}

		arr[k] = b;
	}

}


