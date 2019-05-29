#include "filling.h"
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;


int ifstr(char *str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return -1;
	}
	return 1;
}

float checkinput(float min, float max)
{
	int num;
	char numstr[6];
	do {
		fseek(stdin, 0, SEEK_END);
		fgets(numstr, 6, stdin);
		num = atoi(numstr);
		if (ifstr(numstr) == -1 || num < min || num > max)
			cout << "Некорректный ввод!\nЭтот параметр должен находиться в промежутке от " << min << " до " << max << endl;
	} while (ifstr(numstr) == -1 || num < min || num > max);
	return num;
}

int checkinput(int min, int max)
{
	int num;
	char numstr[6];
	do {
		fseek(stdin, 0, SEEK_END);
		fgets(numstr, 6, stdin);
		num = atoi(numstr);
		if(ifstr(numstr) == -1 || num < min || num > max)
			cout << "Некорректный ввод!\nЭтот параметр должен находиться в промежутке от " << min << " до " << max << endl;
	} while (ifstr(numstr) == -1 || num < min || num > max);
	return num;
}

Data get_data(Data *&ptrlist, int &size)
{
	char ch;
	do {
		ptrlist = (Data*)realloc(ptrlist, (size + 1) * sizeof(Data));
		system("cls");
		fseek(stdin, 0, SEEK_END);
		cout << "Введите имя исполнителя : ";
		cin.getline(ptrlist[size].executor, 15);

		cout << "Введите названние песни : ";
		cin.getline(ptrlist[size].SongName, 20);

		cout << "Введите степень сжатия файла : ";
		ptrlist[size].compression = checkinput(0, 100);

		cout << "Введите стоимость песни : ";
		ptrlist[size].price = checkinput((float)0.0, (float)20.0);

		cout << "Введите день покупки : ";
		ptrlist[size].day = checkinput(1, 31);

		cout << "Введите месяц покупки : ";
		ptrlist[size].month = checkinput(1, 12);

		cout << "Введите год покупки : ";
		ptrlist[size].year = checkinput(1000, 9999);

		size++;
		system("cls");
		cout << "Хотите добавить еще одну структуру? \nEnter - да, любой другой символ - нет.";
		ch = _getch();
	} while (ch == 13);
	return *ptrlist;
}

Data load_DB(Data *&ptrlist, int &size)
{
	int  t = 0, tmp;
	char buff[100], tmpstr[9], nof[15];
	cout << "Введите имя файла, чтобы отоброзить его содержимое : ";
	cin >> nof;
	if (strstr(nof, ".txt") == 0)
		strcat_s(nof, ".txt");
	ifstream fin(nof);
	if (!fin.is_open())
		cout << "Файл не может быть открыт" << endl;
	else
	{
		while (!fin.eof())
		{
			buff[0] = '\0';
			if (size > 0)
				fin.getline(buff, 16);
			fin.getline(buff, 16);
			buff[strlen(buff)] = '\0';
			if (buff[0] != '\0')
			{
				ptrlist = (Data*)realloc(ptrlist, (size + 1) * sizeof(Data));
				strcpy(ptrlist[size].executor, buff);
			}
			else
			{
				break;
			}
			fin.getline(buff, 21);
			buff[strlen(buff)] = '\0';
			strcpy(ptrlist[size].SongName, buff);

			fin >> buff;
			ptrlist[size].compression = atoi(buff);

			fin >> buff;
			ptrlist[size].price = atof(buff);

			fin >> buff;
			ptrlist[size].day = atoi(buff);

			fin >> buff;
			ptrlist[size].month = atoi(buff);

			fin >> buff;
			ptrlist[size].year = atoi(buff);
			size++;
		}
		cout << "Данные успешно считаны из файла : " << nof << endl;
	}
	fin.close();
	return *ptrlist;
}
