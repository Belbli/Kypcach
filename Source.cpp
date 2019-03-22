#include<iostream>
#include "FilesFunctions.h"
#include"menu.h"
#include "ioput.h"
#include<Windows.h>
#include<string>
#include<fstream>

using namespace std;

int isopen = 0, StructAmount = 0,i = 0;
//Data data[100];

//void menu()
//{
//	cout << "Press (1) to display input format.\n"
//		 << "Press (2) to enter data.\n"
//		 << "Press (3) to delete data\n"
//		 << "Press (4) to load data from file\n"
//		 << "Press (5) to display data.\n";
//}

//struct Data
//{
//	char executor[15];
//	char SongName[20];
//	int compression;
//	float price;
//	char date[10];
//}data[10];




//void input(Data parameter)
//{
//	cout << "Enter singer's name : ";
//	cin.getline(parameter.executor,15);
//
//	cout << "Enter song name : ";
//	cin.getline(parameter.SongName,10);
//
//	cout << "Enter file compression ratio : ";
//	cin >> parameter.compression;
//
//	cout << "Enter price : ";
//	cin >> parameter.price;
//
//	cout << "Enter purchase date ";
//	cin >> parameter.date[10];
//}

void content()
{
	cout << "Имполнитель : имя исполнителя (<=15 символов)\n"
		 << "Имя песни (<=10 символов)\n"
		 << "степень сжатия : степень сжатия(int)\n"
		 << "цена : цена композиции(float)\n"
		 << "Дата : дата покупки(дд.мм.гггг)\n";
}

//void printData(Data parameter)
//{
//	cout.width(5);
//	cout << parameter.executor;
//	cout << parameter.SongName;
//	cout << parameter.compression;
//	cout << parameter.price;
//	cout << parameter.date;
//}

//void new_DB()
//{
//	string nof;
//	cout << "Enter name of file : ";
//	cin >> nof;
//	ofstream fout;
//	fout.open(nof);
//	if (!fout.is_open())
//	{
//		cout << "Ошибка открытия файла!!!";
//	}
//	else
//	{
//		cout << "Файл открыт.\n";
//	}
//}

void remove_DB()
{
	char fname[10];
	cout << "Введите имя файла для удаления : ";
	cin >> fname;
	remove(fname);
	if (!remove(fname))
		cout << "Ошибка удаления файла";
	else
		cout << "Файл успешно удалён.";
}

void clear()
{

}

void save_DB()
{

}

void load_DB()
{
	/*Data *list = new Data;
	char buff[50];
	char fname[10];
	cout << "Enter file name to load data : ";
	cin >> fname;
	ifstream fin(fname);
	while (!fin.eof())
		fin.getline(*list, 50);*/
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Data *list = new Data;
	menu();
	//printData(fn);
//	new_DB();
	//remove_DB();
//	get_data();
	//delete[] list;
	system("pause");
	return 0;
}