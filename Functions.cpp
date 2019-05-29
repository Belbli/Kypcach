#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include <iostream>
#include <cstdlib>
#include <string>
//#include <Windows.h>
#include <conio.h>
#include <fstream>
using namespace std;


void save_DB(Data *ptrlist, char *fname, int size)
{
	ofstream fout(fname);
	for (int i = 0; i < size; i++)
	{
		fout << ptrlist[i].executor << endl << ptrlist[i].SongName << endl << ptrlist[i].compression << endl << ptrlist[i].price << endl << ptrlist[i].day<< "." << ptrlist[i].month << "." << ptrlist[i].year << endl;
	}
	fout.close();
}

void PrintStruct(Data *ptrlist, int output_form, int size)
{
	system("cls");
	if(output_form == 0)
	{
		cout << " ___________________________________________________________________________________________________________________\n";
		cout << "|\tИсполнитель\t|\tКомпозиция\t|\tСтепень сжатия(MB)   |\t Цена($)    |      Дата покупки     |\n";
		cout << " ___________________________________________________________________________________________________________________\n";

		for (int i = 0; i < size; i++)
		{
			printf("| %-22s| %-22s| %-27d| %-13.2f|        %d.%d.%d      |", ptrlist[i].executor, ptrlist[i].SongName, ptrlist[i].compression, ptrlist[i].price, ptrlist[i].day, ptrlist[i].month, ptrlist[i].year);
			cout << "\n ___________________________________________________________________________________________________________________\n";
		}
	}
	if (output_form == 1)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Исполнитель : " << ptrlist[i].executor << "\nКомпозиция : " << ptrlist[i].SongName << "\nСтепень сжатия(MB) : " << ptrlist[i].compression << "\nЦена($) : " << ptrlist[i].price;
			printf("\nДата покупки : %d.%d.%d\n\n", ptrlist[i].day, ptrlist[i].month, ptrlist[i].year);
		}
	}
	//cout << "Для продолжения нажмите клавишу";
	_getch();
}
			
void ReadFile(char *fname)
{
	ifstream fin(fname);
	if (!fin.is_open())
		cout << "Файл не может быть открыт" << endl;
	else
	{
		cout << "Файл открыт.\n";
		char buff[50];
		char c[2];
		int ch, j = 0;
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
		}
		while (!fin.eof())
		{
			fin.getline(buff, 25);
				switch (j)
				{
					case 0: printf("|%-23s|", buff);
						break;
					case 1: printf(" %-22s|", buff);
						break;
					case 2: printf(" %-27s|", buff);
						break;
					case 3: printf(" %-13s|", buff);
						break;
					case 4: printf("\t%s", buff);
						break;
					case 5: printf(".%s", buff);
						break;
					case 6: printf(".%s   |\n", buff);
						printf("____________________________________________________________________________________________________________\n");
						j = -1;
						break;
				}
				buff[0] = '\0';
				j++;
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
	}
	_getch();
}

int Menu(char *submenu[], int rows, int cols)
{
	int select = -1;
	char ch = '1';
	for (int i = 0; i < rows; i++)
		cout << submenu[i] << endl;
	do {
		switch (_getch())
		{
		case 72:
			select--;
			break;
		case 80:
			select++;
			break;
		case 13:
			if (select >= 0 && select < rows)
				ch = 'e';
			break;
		}
		system("cls");
		if (select == rows)
			select = 0;
		if (select == -1 || select == -2)
			select = rows - 1;
		for (int i = 0; i < rows; i++)
		{
			if (i == select)
				cout << ">> ";
			cout << submenu[i];
			if (i == select)
			{
				cout << " <<";
			}
			cout << endl;
		}
	} while (ch != 'e');
	return select;
}



int ComparePrice(Data ptrlist1, Data ptrlist2)
{
	if (ptrlist1.price > ptrlist2.price)
		return 1;
	else if (ptrlist1.price < ptrlist2.price)
		return -1;
	return 0;
}

int CompareSong(Data ptrlist1, Data ptrlist2)
{
	if (strcmp(ptrlist1.SongName, ptrlist2.SongName) > 0)
		return 1;
	else if (strcmp(ptrlist1.SongName, ptrlist2.SongName) < 0)
		return -1;
	else
		return 0;
}

int CompareNames(Data ptrlist1, Data ptrlist2)
{
	if (strcmp(ptrlist1.executor, ptrlist2.executor) > 0)
		return 1;
	else if (strcmp(ptrlist1.executor, ptrlist2.executor) < 0)
		return -1;
	else
		return 0;
}

int selectdir(int select)
{
	if (select == 0)
		return 1;
	if (select == 1)
		return -1;
	else
		return 0;
}

int CompareDate(Data ptrlist1, Data ptrlist2)
{
	if (ptrlist1.year > ptrlist2.year)
		return 1;
	else if (ptrlist1.year < ptrlist2.year)
		return -1;
	else
	{
		if (ptrlist1.month > ptrlist2.month)
			return 1;
		else if (ptrlist1.month < ptrlist2.month)
			return -1;
		else
		{
			if (ptrlist1.day > ptrlist2.day)
				return 1;
			else if (ptrlist1.day < ptrlist2.day)
				return -1;
			else
				return 0;
		}
	}
}

int Sort_Select()
{
	int select = -1, dir;
	char *SortingMenu[4] = { { "По исполнителю" },{ "По композиции" },{ "По цене" },{ "По дате покупки" } };
	select = Menu(SortingMenu, 4, 30);
	return select;
}

int Dir_Select()
{
	int dir;
	char *SortNumbers[2] = { { "MIN - MAX" },{ "MAX - MIN" } };
	dir = Menu(SortNumbers, 2, 30);
	return dir;
}

void sort(Data *ptrlist, int(*cmp)(Data ptrlist1, Data ptrlist2), int dir, int size)
{
	Data tmp;
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if ((cmp(ptrlist[j], ptrlist[j + 1]) == 1 && dir == 0) || (cmp(ptrlist[j], ptrlist[j + 1]) == -1 && dir == 1))
			{
				tmp = ptrlist[j + 1];
				ptrlist[j + 1] = ptrlist[j];
				ptrlist[j] = tmp;
			}
}

void remove_DB(char *fname) {
	if (remove(fname) == -1)
		cout << "Не удалось удалить файл";
	else 
		cout << "Файл " << fname << " успешно удалён";
	_getch();
}


int ChooseEditLine(Data *ptrlist)
{
	cout << "Выберете имя исполнителя, чтобы редакировать информацию о нем\n";
	char ch, buff[50];
	int i = 0, select = -1;
	int size = 0, m = 25;
	
	char **EditByName = new char*[size];
	for (i = 0; i < size; i++)
	{
		EditByName[i] = new char;
		EditByName[i] = ptrlist[i].executor; 
	}
	select = Menu(EditByName, size, 21);
	for (int i = 0; i < size; i++)
		delete[] EditByName[i];
	delete[] EditByName;
	return select;
}

void EditStruct(Data *ptrlist)
{
	int i = ChooseEditLine(ptrlist), select = -1;
	int size, flag = 1;
	char ch;
	char compression[4], price[5], day[3], month[3], year[5];
	char *EditInfo[7] = { { ptrlist[i].executor },{ ptrlist[i].SongName },{ compression },{ price },{ day },{ month },{ year } };
	_itoa(ptrlist[i].compression, compression, 10);
	_itoa(ptrlist[i].price, price, 10);
	_itoa(ptrlist[i].day, day, 10);
	_itoa(ptrlist[i].month, month, 10);
	_itoa(ptrlist[i].year, year, 10);
	select = Menu(EditInfo, 7, 21);
	system("cls");

			size = strlen(EditInfo[select]);
			cout << EditInfo[select];
			do {
				ch = _getch();
				switch (ch)
				{
				case 8:
					size--;
					EditInfo[select][size] = '\0';
					system("cls");
					cout << EditInfo[select];
					break;
				case 13:
					flag = 0;
					break;
				default:
					EditInfo[select][size] = ch;
					EditInfo[select][size + 1] = '\0';
					size++;
					system("cls");
					cout << EditInfo[select];
					break;
				}
			} while (flag != 0);
			ptrlist[i].compression = atoi(compression);
			ptrlist[i].price = atof(price);
			ptrlist[i].day = atoi(day);
			ptrlist[i].month = atoi(month);
			ptrlist[i].year = atoi(year);
}

int search_field()
{
	int select;
	char *SearchMenu[4] = { { "Поиск по исполнителю" },{ "Поиска по композиции" },{ "Поиск по цене" },{ "Поиск по дате покупки" } };
	cout << "Выберете поле для поиска\n";
	select = Menu(SearchMenu, 4, 21);
	return select;
}

void SearchOutput(Data *ptrlist, int k)
{
	if (k == -1)
		cout << "По вашему запросу ничего не найдено.";

	else
	{
		cout << "Результат поиска :\n\n";

		cout << "Исполнитель : " << ptrlist[k].executor << endl;
		cout << "Композиция : " << ptrlist[k].SongName << endl;
		cout << "Степень сжатия(МВ) : " << ptrlist[k].compression << endl;
		cout << "Цена($) : " << ptrlist[k].price << endl;
		cout << "Дата покупки : " << ptrlist[k].day << "." << ptrlist[k].month <<
			"." << ptrlist[k].year << endl;
		cout << endl;
	}
}

void search(Data *ptrlist, int(*cmp)(Data ptrlist1, Data ptrlist2), Data search, int size)
{
	int k = -1;
	for (int i = 0; i < size; i++)
	{
		if (cmp(search, ptrlist[i]) == 0)
		{
			k = i;
			SearchOutput(ptrlist, i);
		}
	}
	if(k == -1)
		SearchOutput(ptrlist, k);
	
	_getch();
}

void profit(Data *ptrlist, int size)
{
	Data profit_begin, profit_end;
	char profit_from[12], profit_to[12];
	float profit = 0;
	cout << "\nВведите промежуток времени, за который нужно расчитать прибыль :\nПрибыль начиная от : ";
	cin >> profit_from;
	cout << "Прибыль до : ";
	cin >> profit_to;
	sscanf(profit_from, "%d.%d.%d", &profit_begin.day, &profit_begin.month, &profit_begin.year);
	sscanf(profit_to, "%d.%d.%d", &profit_end.day, &profit_end.month, &profit_end.year);
	for (int i = 0; i < size; i++)
	{
		if (CompareDate(profit_begin, ptrlist[i]) == -1 && CompareDate(profit_end, ptrlist[i]) == 1 || CompareDate(profit_begin, ptrlist[i]) == 0 || CompareDate(profit_end, ptrlist[i]) == 0)
			profit += ptrlist[i].price;
	}
	cout << "Прибыль с : " << profit_from << ", по : " << profit_to << " cотсавляет : " << profit << "$\n";
	_getch();
}

void del(Data *ptrlist, int &size)
{
	if (size == 0)
		cout << "База данных пуста.\n";
	else 
	{
		int deleted = 0;
		char name[30];
		cout << " Введите имя исполенителя для удаления : ";
		fseek(stdin, 0, SEEK_END);
		cin.getline(name, 30);
		for (int i = 0; i < size; i++)
		{
			if (strcmp(ptrlist[i].executor, name) == 0)
			{
				deleted = 1;
				do {
					for (int j = i; j < size - 1; j++)
					{
						ptrlist[j] = ptrlist[j + 1];
					}
					size--;
					ptrlist = (Data *)realloc(ptrlist, size * sizeof(Data));
				} while (strcmp(ptrlist[i].executor, name) == 0);
			}
		}
		cout << size;
		_getch();
		if (deleted == 0)
			cout << "Не найдено имени исполнителя для удаления\n";
	}
}
		
void clear(Data *ptrlist)
{
	free(ptrlist);
	exit(0);
}
		
	
