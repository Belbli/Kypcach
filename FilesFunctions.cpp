#include "FilesFunctions.h"
#include"menu.h"
#include <iostream>
#include<conio.h>
#include <fstream>
using namespace std;

char nof[10];


void GoToMenu()
{
	cout << "\n\nДля выхода в главное меню нажмите Esc : ";
tryagain:
	switch (_getch())
	{
	case 27:
		menu();
		break;
	default:
		goto tryagain;
		break;
	}
}


Data get_data()
{
	int n = 0;
	cout << "Введите имя нового файла : ";
	cin >> nof;
	ofstream fout, file(nof);
	fout.open(nof);
		/*while (!file)
		{
			
			cout << "Имя файла занято.\nВведите имя нового файла : ";
			cin >> nof;
			
		}*/
	if (!fout.is_open())
		cout << "Файл не открыт.";
	
	else {

		cout << "Файл создан.\n";
		int ch = 0;

		Data data[10];
		//do {
			n++;
			cout << "Enter singer's name : ";
			cin >> data[n].executor;
			fout << data[n].executor << endl;

			cout << "Enter song name : ";
			cin >> data[n].SongName;
			fout << data[n].SongName << endl;

			cout << "Enter file compression ratio : ";
			cin >> data[n].compression;
			fout << data[n].compression << endl;

			cout << "Enter price : ";
			cin >> data[n].price;
			fout << data[n].price << endl;

			cout << "Введите день покупки : ";
			cin >> data[n].day;
			fout << data[n].day << endl;

			cout << "Введите месяц покупки : ";
			cin >> data[n].month;
			fout << data[n].month << endl;

			cout << "Введите год покупки : ";
			cin >> data[n].year;
			fout << data[n].year << endl;

			fout.close();
			cout << "\nДанные успешно записаны в файл.\n";
			//cin >> ch;
		//} while (ch == 1);
			GoToMenu();
			return data[n];
		
				
	}
	
	
}
			
void printData(char *fname)
{
	ifstream fin(fname);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!!!\n";
	}
	else
	{
		cout << "Файл открыт.\n";
		char buff[50];
		char c[2];
		int ch;
		do {
			cout << "Для вывода в форме таблицы введите 1, для обычного вывода введите 2.";
			cin >> c;
			ch = atoi(c);
			system("cls");
		} while (ch == 0 || ch > 2);
		if (ch == 1)
		{
			cout << "Исполнитель\t\tКомпозиция\tСтепень сжатия(MB)\tЦена($)\t\tДата\n\n";
			for (int i = 0; i < 5; i++)
			{
				fin >> buff;
				cout << buff << "\t\t";
				if (i > 1 && i < 3)
					cout << "\t";
			}
		}
		if (ch == 2)
		{
			for (int i = 0; i < 7; i++)
			{
				fin >> buff;
				cout << buff << endl;
			}
		}
		fin.close();
		cout << endl;
		GoToMenu();
	}
	
}

void remove_DB()
{
	char fname[10];
	cout << "Введите имя файла для удаления : ";
	cin >> fname;
	remove(fname);
	if (!remove(fname))
		cout << "Ошибка удаления файла\n";
	else 
		cout << "Файл успешно удалён.\n";
	GoToMenu();
}

void EditData(char *fname)
{
	ofstream fin(fname);



}
		
void DB_parameters()
{
	cout << "Имполнитель : имя исполнителя (<=15 символов)\n"
		 << "Имя песни (<=10 символов)\n"
		 << "Степень сжатия(int)\n"
		 << "Цена : цена композиции(float)\n"
		 << "Дата : дата покупки(дд.мм.гггг)\n\n\n";
	
	GoToMenu();
}


		
	
