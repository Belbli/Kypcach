#include "filling.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;


int ifstr(char *str, int data_type)
{
	int dots_count = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if(data_type == 1)
			if (str[i] < '0' || str[i] > '9')
				return -1;
		if (data_type == 2)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				if (str[i] == '.' && dots_count == 0)
				{
					dots_count++;
					continue;
				}
				return -1;
			}
		}
	}
	return 1;
}

float checkinput(float min, float max)
{
	float num;
	int flag;
	char numstr[10];
	do {
		flag = 0;
		fseek(stdin, 0, SEEK_END);
		fgets(numstr, 10, stdin);
		numstr[strlen(numstr) - 1] = '\0';
		num = atof(numstr); 
		if (ifstr(numstr, 2) == -1 || num < min || num > max || strlen(numstr) == 0)
		{
			cout << "Некорректный ввод!\nЭтот параметр должен находиться в промежутке от " << min << " до " << max << endl;
			flag = -1;
		}
	} while (flag == -1 || num < min || num > max);
	return num;
}

int checkinput(int min, int max)
{
	int num, flag;
	char numstr[10];
	do {
		flag = 0;
		fseek(stdin, 0, SEEK_END);
		fgets(numstr, 10, stdin);
		numstr[strlen(numstr) - 1] = '\0';
		num = atoi(numstr);
		if (ifstr(numstr, 1) == -1 || num < min || num > max || strlen(numstr) == 0)
		{
			cout << "Некорректный ввод!\nЭтот параметр должен находиться в промежутке от " << min << " до " << max << endl;
			flag = -1;
		}
	} while (flag == -1 || num < min || num > max);
	return num;
}

Data get_data(Data *&ptrlist, int &size)
{
	char ch, buff[23];
	do {
		ptrlist = (Data*)realloc(ptrlist, (size + 1) * sizeof(Data));
		system("cls");
		cout << "ВВОД ДАННЫХ\n\n";
		do {
		cout << "Введите имя исполнителя : ";
			fseek(stdin, 0, SEEK_END);
			fgets(buff, 18, stdin);
			buff[strlen(buff) - 1] = '\0';
		} while (strlen(buff) == 0 || strlen(buff) > 15);
		strcpy(ptrlist[size].executor, buff);

		do {
			cout << "Введите названние песни : ";
			fseek(stdin, 0, SEEK_END);
			fgets(buff, 23, stdin);
			buff[strlen(buff) - 1] = '\0';
		} while (strlen(buff) == 0 || strlen(buff) > 20);
		strcpy(ptrlist[size].SongName, buff);
		
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
		cout << "Хотите добавить еще одну структуру? \nEnter - да, любой другой символ - нет.";
		ch = _getch();
	} while (ch == 13);
	return *ptrlist;
}

Data load_DB(Data *&ptrlist, int &size)
{
	int  t = 0;
	char buff[100], nof[15];
	cout << "Введите имя файла, чтобы отоброзить его содержимое : ";
	cin >> nof;
	if (strstr(nof, ".txt") == 0)
		strcat_s(nof, ".txt");
	ifstream fin(nof);
	if (!fin.is_open())
	{
		cout << "Файл не может быть открыт" << endl;
		_getch();
	}
	else
	{
		int k = size;
		while (!fin.eof())
		{

			buff[0] = '\0';
			if (size > k)
				fin.getline(buff, 16);
			fin.getline(buff, 16);
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
		_getch();
	}
	fin.close();
	return *ptrlist;
}
