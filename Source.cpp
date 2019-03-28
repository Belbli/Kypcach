#include<iostream>
#include "FilesFunctions.h"
#include"menu.h"
#include "ioput.h"
#include<Windows.h>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

int isopen = 0, n = 0,i = 0; // n - счётчик структур
//Data data[100];








//void content()
//{
//	cout << "Имполнитель : имя исполнителя (<=15 символов)\n"
//		 << "Имя песни (<=10 символов)\n"
//		 << "степень сжатия : степень сжатия(int)\n"
//		 << "цена : цена композиции(float)\n"
//		 << "Дата : дата покупки(дд.мм.гггг)\n";
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

//void remove_DB()
//{
//	char fname[10];
//	cout << "Введите имя файла для удаления : ";
//	cin >> fname;
//	remove(fname);
//	if (!remove(fname))
//		cout << "Ошибка удаления файла";
//	else
//		cout << "Файл успешно удалён.";
//}

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
	//system("color B");
	Data *list = new Data;
	menu();
	//printData(fn);
//	new_DB();
	//remove_DB();
//	get_data();
	//delete[] list;
	system("pause");
	return 0;
}