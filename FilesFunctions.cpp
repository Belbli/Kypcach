#define _CRT_SECURE_NO_WARNINGS
#include "FilesFunctions.h"
#include <iostream>
#include <cstdlib>
#include <string.h>
//#include "Global.h"
#include <Windows.h>
#include<conio.h>
#include <fstream>
using namespace std;


Data *ptrlist;
char nof[10];
int n = 0;

void get_data()
{
	char ch;
		do {
			ptrlist = (Data*)realloc(ptrlist, (n + 1) * sizeof(Data));
			system("cls");
			
			cout << "Введите имя исполнителя : ";
			cin.getline(ptrlist[n].executor,15);
			
			cout << "Введите названние песни : ";
			cin.getline(ptrlist[n].SongName,20);
			
			cout << "Введите степень сжатия файла : ";
			cin >> ptrlist[n].compression;
		
			cout << "Введите стоимость песни : ";
			cin >> ptrlist[n].price;
			

			cout << "Введите день покупки : ";
			cin >> ptrlist[n].day;
			
			cout << "Введите месяц покупки : ";
			cin >> ptrlist[n].month;

			cout << "Введите год покупки : ";
			cin >> ptrlist[n].year;
			
			n++;
			system("cls");
			cout << "Хотите добавить еще одну структуру? \nEnter - да, любой другой символ - нет.";
			ch = _getch();
			cin.get();
			
		} while (ch == 13);
		
}

void save_DB(int count)
{
	cout << "Введите имя файла : ";
	cin >> nof;
	if (strstr(nof, ".txt") == 0)
		strcat_s(nof, ".txt");
	ofstream fout(nof);
	for (int i = 0; i < n; i++)
	{
		fout << ptrlist[i].executor << endl << ptrlist[i].SongName << endl << ptrlist[i].compression << endl << ptrlist[i].price << endl << ptrlist[i].day<< "." << ptrlist[i].month << "." << ptrlist[i].year << endl;
	}
	fout.close();
}

void PrintFromStruct()
{
	char c[2];
	int ch;
	do {
		cout << "Для вывода в форме таблицы введите 1, для обычного вывода введите 2.";
		cin >> c;
		ch = atoi(c);
		system("cls");
	} while (ch == 0 || ch > 2);
	if(ch == 1)
	{
		cout << " ____________________________________________________________________________________________________________\n";
		cout << "|\tИсполнитель\t|\tКомпозиция\t|\tСтепень сжатия(MB)   |\t Цена($)    |      Дата      |\n";
		cout << " ____________________________________________________________________________________________________________\n";

		for (int i = 0; i < n; i++)
		{
			printf("| %-22s| %-22s| %-27d| %-13.2f|    %d.%d.%d  |", ptrlist[i].executor, ptrlist[i].SongName, ptrlist[i].compression, ptrlist[i].price, ptrlist[i].day, ptrlist[i].month, ptrlist[i].year);
			cout << "\n ____________________________________________________________________________________________________________\n";
		}
	}
	if (ch == 2)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Исполнитель : " << ptrlist[i].executor << "\nКомпозиция : " << ptrlist[i].SongName << "\nСтепень сжатия(MB) : " << ptrlist[i].compression << "\nЦена($) : " << ptrlist[i].price;
			printf("\nДата : %d.%d.%d\n\n", ptrlist[i].day, ptrlist[i].month, ptrlist[i].year);
		}
	}
	_getch();
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
			cout << " ____________________________________________________________________________________________________________\n";
			cout << "|\tИсполнитель\t|\tКомпозиция\t|\tСтепень сжатия(MB)   |\t Цена($)    |      Дата      |\n";
			cout << " ____________________________________________________________________________________________________________\n";

			for (int i = 0; i < n; i++)
				for (int j = 0; j < 5; j++)
				{
					fin >> buff;
					switch (j) {
						case 1: printf("|%-22s|", buff);
							break;
						case 2: printf(" %-22s|", buff);
							break;
						case 3: printf(" %-27s", buff);

					}
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
		//GoToMenu();
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
	//GoToMenu();
}

void EditFile(char *fname)
{
	
	ifstream fin(fname);
	char ch, buff[50];
	int i = 0;
	int size = 0;
	int flag = 1;

	if (!fin.is_open())
		cout << "Файл не может быть открыт" << endl;
	else
	{
		for (int i = 0; i < 5; i++)
		{
			fin >> buff;
			size = strlen(buff);
			cout << buff;
			do {
				ch = _getch();
				switch (ch)
				{
				case 8:
					size--;
					buff[size] = '\0';
					system("cls");
					cout << buff;
					break;
				case 13:
					flag = 0;
					break;
				default:
					buff[size] = ch;
					buff[size + 1] = '\0';
					size++;
					system("cls");
					cout << buff;
					break;
				}
			} while (flag != 0);
		}
	}

	fin.close();
}

void load_DB()
{
	int i = 0, t = 0, tmp;
	char buff[100],tmpstr[9];
	cout << "Введите имя файла, чтобы отоброзить его содержимое : ";
	cin >> nof;
	strcat_s(nof, ".txt");
	ifstream fin(nof);
	if (!fin.is_open())
		cout << "Файл не может быть открыт" << endl;
	else
	{
		while (!fin.eof())
		{
			n++;
			buff[0] = '\0';
			ptrlist = (Data*)realloc(ptrlist, (n) * sizeof(Data));
			if(n > 1)
				fin.getline(buff, 16);
			fin.getline(buff,16);
			if (buff[0] != '\0')
				strcpy(ptrlist[n - 1].executor, buff);
			else
				break;
			
			fin.getline(buff,21);
			strcpy(ptrlist[n-1].SongName, buff);

			fin >> buff;
			ptrlist[n - 1].compression = atoi(buff);

			fin >> buff;
			ptrlist[n - 1].price = (float)atoi(buff);

			fin >> buff;
			t = 0;
			for (int j = 0; j < strlen(buff); j++)
			{
				if (buff[j] != '.')
				{
					tmpstr[t] = buff[j];
					t++;
				}
			}
			tmp = atoi(tmpstr);
			ptrlist[n - 1].day = tmp / 1000000;
			tmp %= 1000000;
			ptrlist[n - 1].month = tmp / 10000;
			tmp %= 10000;
			ptrlist[n - 1].year = tmp;
			tmp = 0;
			tmpstr[0] = '\0';
		}
		cout << "Данные успешно считаны из файла : " << nof << endl;
	}
	fin.close();
}
		
void clear(Data *ptrlist)
{
	free(ptrlist);
	exit(0);
}
		
	
