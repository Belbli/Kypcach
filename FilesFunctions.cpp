#include "FilesFunctions.h"
#include"menu.h"
#include <iostream>
#include <fstream>
using namespace std;

char nof[10];

Data get_data()
{
	/*char key;
	cout << "X -- назад. Enter -- продолжить." << endl;
	cin >> key;
	if (key == 88)
	{
		menu();
	}
	else if (key == 13)
	{*/
	cout << "Введите имя нового файла : ";
	cin >> nof;
	ofstream fout;
	fout.open(nof);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!!!";
	}
	else
	{
		cout << "Файл открыт.\n";


		Data data;
		cout << "Enter singer's name : ";
		cin >> data.executor;
		fout << data.executor << endl;

		cout << "Enter song name : ";
		cin >> data.SongName;
		fout << data.SongName << endl;

		cout << "Enter file compression ratio : ";
		cin >> data.compression;
		fout << data.compression << endl;

		cout << "Enter price : ";
		cin >> data.price;
		fout << data.price << endl;

		cout << "Enter purchase date : ";
		cin >> data.date;
		fout << data.date << endl;
		fout.close();
		return data;
	}
}
			//}
			/*cout << "Хотите ли вы добавить еще структуру(1 - да, 2 - нет) : ";
			cin >> q;*/
			//i++;
void printData(char *fname)
{
	ifstream fin(fname);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!!!";
	}
	else
	{
		cout << "Файл открыт.\n";
		char buff[50];

		for (int i = 0; i < 5; i++)
		{
			fin >> buff;
			cout << buff << endl;
		}
		fin.close();
	}
}
			
		
	
