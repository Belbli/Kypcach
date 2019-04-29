#define _CRT_SECURE_NO_WARNINGS
#include "FilesFunctions.h"
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <Windows.h>
#include<conio.h>
#include <fstream>
using namespace std;


Data *ptrlist, tmp;
char nof[10], numstr[10];
int n = 0, num = 0;

float checkinput(float min, float max)
{
	do{
		fseek(stdin, 0, SEEK_END);
		fgets(numstr, 6, stdin);
		num = atoi(numstr);
		if (min == 0)
		{
			if (num < 0)
				cout << "���� �������� ������ ���� ������������� : ";
			if (num == 0)
				cout << "���� �������� ������ ���� ������ : ";
		}
	} while (num == 0 || num < min || num < 0);
	return num;
}

int checkinput(int min, int max)
{
	do {
		fseek(stdin, 0, SEEK_END);
		fgets(numstr, 6, stdin);
		num = atoi(numstr);
		if (min == 1000)
			if (num == 0 || num < min || num > max || num < 0)
			{
				if (num == 0)
					printf("��������� ������.\n��� ������ �������� �� 4-� ����\n��������� ���� : ");
				else if (num < min || num > max)
					printf("��� ������ �������� �� 4 ���� : ");
				else
					printf("������� ������������� 4-� ������� ����� : ");
			}
		if (min == 1 && max == 12)
			if (num == 0 || num < 0 || num > 12)
			{
				if (num == 0)
					printf("��������� ������.\n����� ������ ���� � ���������� �� (1-12)\n��������� ���� : ");
				else
					printf("����� ������ ���� � ���������� �� (1-12) : ");
			}
		if (min == 1 && max == 31)
			if (num == 0 || num < 0 || num > 31)
			{
				if (num == 0)
					printf("��������� ������.\n���� ������ ���� � ���������� �� (1-31) : ");
				else
					printf("���� ������ ���� � ���������� �� (1-31) : ");
			}
		if (min == 0)
			if (num < 0 || num == 0)
				cout << "���� �������� ������ ���� ������������� : ";
		
	} while (num == 0 || num < min || num > max || num < 0);
	return num;
}



void get_data()
{
	char ch;
		do {
			ptrlist = (Data*)realloc(ptrlist, (n + 1) * sizeof(Data));
			system("cls");
			fseek(stdin, 0, SEEK_END);
			cout << "������� ��� ����������� : ";
			cin.getline(ptrlist[n].executor,15);
			
			cout << "������� ��������� ����� : ";
			cin.getline(ptrlist[n].SongName,20);
			
			cout << "������� ������� ������ ����� : ";
			ptrlist[n].compression = checkinput(0,100);
		
			cout << "������� ��������� ����� : ";
			ptrlist[n].price = checkinput(0.0, 20);
			

			cout << "������� ���� ������� : ";
			ptrlist[n].day = checkinput(1,31);
			
			cout << "������� ����� ������� : ";
			ptrlist[n].month = checkinput(1,12);

			cout << "������� ��� ������� : ";
			ptrlist[n].year = checkinput(1000, 9999);
			
			n++;
			system("cls");
			cout << "������ �������� ��� ���� ���������? \nEnter - ��, ����� ������ ������ - ���.";
			ch = _getch();
			
			
		} while (ch == 13);
		
}

void save_DB(int count)
{
	cout << "������� ��� ����� : ";
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
	int ch;
	char *output[2] = { { "����� � ����� �������" }, {"������� �����"} };
	ch = Menu(output, 2, 10);
	system("cls");
	if(ch == 0)
	{
		cout << " ____________________________________________________________________________________________________________\n";
		cout << "|\t�����������\t|\t����������\t|\t������� ������(MB)   |\t ����($)    |      ����      |\n";
		cout << " ____________________________________________________________________________________________________________\n";

		for (int i = 0; i < n; i++)
		{
			printf("| %-22s| %-22s| %-27d| %-13.2f|    %d.%d.%d  |", ptrlist[i].executor, ptrlist[i].SongName, ptrlist[i].compression, ptrlist[i].price, ptrlist[i].day, ptrlist[i].month, ptrlist[i].year);
			cout << "\n ____________________________________________________________________________________________________________\n";
		}
	}
	if (ch == 1)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "����������� : " << ptrlist[i].executor << "\n���������� : " << ptrlist[i].SongName << "\n������� ������(MB) : " << ptrlist[i].compression << "\n����($) : " << ptrlist[i].price;
			printf("\n���� : %d.%d.%d\n\n", ptrlist[i].day, ptrlist[i].month, ptrlist[i].year);
		}
	}
	_getch();
}
			
void printData(char *fname)
{
	ifstream fin(fname);
	if (fin.is_open())
	{
		cout << "������ �������� �����!!!\n";
	}
	else
	{
		cout << "���� ������.\n";
		char buff[50];
		char c[2];
		int ch;
		do {
			cout << "��� ������ � ����� ������� ������� 1, ��� �������� ������ ������� 2.";
			cin >> c;
			ch = atoi(c);
			system("cls");
		} while (ch == 0 || ch > 2);
		if (ch == 1)
		{
			cout << " ____________________________________________________________________________________________________________\n";
			cout << "|\t�����������\t|\t����������\t|\t������� ������(MB)   |\t ����($)    |      ����      |\n";
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
	}
	
}


int Menu(char *submenu[], int rows, int cols)
{
	int select = -1;
	char ch = '1';
	for (int i = 0; i < rows; i++)
		cout << submenu[i] << endl;
	do {
		tryagain:
		switch (_getch())
		{
		case 72:
			select--;
			break;
		case 80:
			select++;
			break;
		case 13:
			if (select >= 0 && select < 11)
				ch = 'e';
			else
				goto tryagain;
			break;
		default:
			goto tryagain;
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

int ComparePrice(int j)
{
	if (ptrlist[j].price > ptrlist[j + 1].price)
		return 1;
	else if (ptrlist[j].price < ptrlist[j + 1].price)
		return -1;
	else
		return 0;
}

int CompareSong(int j)
{
	if (strcmp(ptrlist[j].SongName, ptrlist[j + 1].SongName) > 0)
		return 1;
	else if (strcmp(ptrlist[j].SongName, ptrlist[j + 1].SongName) < 0)
		return -1;
	else
		return 0;
}

int CompareNames(int j)
{
	if (strcmp(ptrlist[j].executor, ptrlist[j + 1].executor) > 0)
		return 1;
	else if (strcmp(ptrlist[j].executor, ptrlist[j + 1].executor) < 0)
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

//int CompareDate(int j)
//{
//
//}

void sort()
{
	int select = -1;
	char ch;
	char *SortingMenu[4] = { {"�� �����������"},{"�� ����������"},{"�� ����"},{"�� ����"}};
	char *SortNames[2] = { { "A-Z" },{ "Z-A" } };
	char *SortNumbers[2] = { {"MAX - MIN"}, {"MIN - MAX"} };
	select = Menu(SortingMenu, 4, 30);
	int	dir = 0;
	switch (select)
	{
		case 0:
			system("cls");
			select = Menu(SortNames, 2, 5);
				for (int i = 0; i < n; i++)
				{
					for (int i = 0; i < n - 1; i++)
						for (int j = 0; j < n - i - 1; j++)
							if (CompareNames(j) == selectdir(select))
							{
								tmp = ptrlist[j + 1];
								ptrlist[j + 1] = ptrlist[j];
								ptrlist[j] = tmp;
							}
				}
			break;
		case 1:
			system("cls");
			select = Menu(SortNames, 2, 5);
					for (int i = 0; i < n - 1; i++)
						for (int j = 0; j < n - i - 1; j++)
							if (CompareSong(j) == selectdir(select))
							{
								tmp = ptrlist[j + 1];
								ptrlist[j + 1] = ptrlist[j];
								ptrlist[j] = tmp;
							}
			break;
		case 2:
			system("cls");
			select = Menu(SortNumbers, 2, 5);
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if(ComparePrice(j) == selectdir(select))
						{
							tmp = ptrlist[j+1];
							ptrlist[j+1] = ptrlist[j];
							ptrlist[j] = tmp;
						}
			break;
		case 3:
			system("cls");
			select = Menu(SortNumbers, 2, 5);
			if(select == 0)
				for (int i = n - 1; i >= 0; i--)
				{
					for (int j = 0; j < n - i; j++)
					{
						if (i > j && ptrlist[i].year * 10000 + ptrlist[i].month * 100 + ptrlist[i].day > ptrlist[j].year * 10000 + ptrlist[j].month * 100 + ptrlist[j].day)
						{
							tmp = ptrlist[j];
							ptrlist[j] = ptrlist[i];
							ptrlist[i] = tmp;
						}
					}
				}
			if(select == 1)
				for (int i = n - 1; i >= 0; i--)
				{
					for (int j = 0; j < n - i; j++)
					{
						if (i > j && ptrlist[i].year * 10000 + ptrlist[i].month * 100 + ptrlist[i].day < ptrlist[j].year * 10000 + ptrlist[j].month * 100 + ptrlist[j].day)
						{
							tmp = ptrlist[j];
							ptrlist[j] = ptrlist[i];
							ptrlist[i] = tmp;
						}
					}
				}
			break;
	}
}

void remove_DB() {
	char name[100];
	cout << "������� ��� �����, ������� ������ ������� : ";
	cin >> name;
	strcat(name, ".txt");
	if (remove(name) == -1)
		cout << "�� ������� ������� ����";
	else cout << "���� " << name << " ������� �����";
	_getch();
}


void EditStruct()
{
	char ch, buff[50];
	int i = 0, select = -1;
	int size = 0;
	int flag = 1;
	char compression[4], price[5], day[3], month[3], year[5];
	_itoa(ptrlist[i].compression, compression, 10);
	_itoa(ptrlist[i].price, price, 10);
	_itoa(ptrlist[i].day, day, 10);
	_itoa(ptrlist[i].month, month, 10);
	_itoa(ptrlist[i].year, year, 10);
	char *EditInfo[7] = { { ptrlist[i].executor }, { ptrlist[i].SongName}, {compression}, {price}, {day}, {month}, {year} };
	select = Menu(EditInfo, 7, 21);
	
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
			ptrlist[i].price = (float)atoi(price);
			ptrlist[i].day = atoi(day);
			ptrlist[i].month = atoi(month);
			ptrlist[i].year = atoi(year);
		
}

void search()
{

}

void del()
{
	char name[30];
	cout << " ������� ��� ������������ ��� �������� : ";
	cin >> name;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ptrlist[i].executor, name) == 0)
		{
			printf("%d\n", n);
			for (int j = i; j < n - 1; j++)
			{
				ptrlist[j] = ptrlist[j + 1];
			}
			ptrlist = (Data *)realloc(ptrlist, --n * sizeof(Data));
			break;
		}
	}
}

void load_DB()
{
	int  t = 0, tmp;
	char buff[100],tmpstr[9];
	cout << "������� ��� �����, ����� ���������� ��� ���������� : ";
	cin >> nof;
	strcat_s(nof, ".txt");
	ifstream fin(nof);
	if (!fin.is_open())
		cout << "���� �� ����� ���� ������" << endl;
	else
	{
		while (!fin.eof())
		{
			buff[0] = '\0';
			if(n > 0)
				fin.getline(buff, 16);
			fin.getline(buff,16);
			buff[strlen(buff)] = '\0';
			if (buff[0] != '\0')
			{
				ptrlist = (Data*)realloc(ptrlist, (n + 1) * sizeof(Data));
				strcpy(ptrlist[n].executor, buff);
			}
			else
			{
				break;
			}
			fin.getline(buff,21);
			buff[strlen(buff)] = '\0';
			strcpy(ptrlist[n].SongName, buff);

			fin >> buff;
			ptrlist[n].compression = atoi(buff);

			fin >> buff;
			ptrlist[n].price = atof(buff);

			fin >> buff;
			ptrlist[n].day = atoi(buff);

			fin >> buff;
			ptrlist[n].month = atoi(buff);

			fin >> buff;
			ptrlist[n].year = atoi(buff);
			n++;
		}
		cout << "������ ������� ������� �� ����� : " << nof << endl;
	}
	fin.close();
}
		
void clear(Data *ptrlist)
{
	free(ptrlist);
	exit(0);
}
		
	
