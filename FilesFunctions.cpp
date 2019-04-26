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
			
			cout << "������� ��� ����������� : ";
			cin.getline(ptrlist[n].executor,15);
			
			cout << "������� ��������� ����� : ";
			cin.getline(ptrlist[n].SongName,20);
			
			cout << "������� ������� ������ ����� : ";
			cin >> ptrlist[n].compression;
		
			cout << "������� ��������� ����� : ";
			cin >> ptrlist[n].price;
			

			cout << "������� ���� ������� : ";
			cin >> ptrlist[n].day;
			
			cout << "������� ����� ������� : ";
			cin >> ptrlist[n].month;

			cout << "������� ��� ������� : ";
			cin >> ptrlist[n].year;
			
			n++;
			system("cls");
			cout << "������ �������� ��� ���� ���������? \nEnter - ��, ����� ������ ������ - ���.";
			ch = _getch();
			cin.get();
			
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
	char c[2];
	int ch;
	do {
		cout << "��� ������ � ����� ������� ������� 1, ��� �������� ������ ������� 2.";
		cin >> c;
		ch = atoi(c);
		system("cls");
	} while (ch == 0 || ch > 2);
	if(ch == 1)
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
	if (ch == 2)
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
	if (!fin.is_open())
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
		//GoToMenu();
	}
	
}

void remove_DB()
{
	char fname[10];
	cout << "������� ��� ����� ��� �������� : ";
	cin >> fname;
	remove(fname);
	if (!remove(fname))
		cout << "������ �������� �����\n";
	else 
		cout << "���� ������� �����.\n";
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
		cout << "���� �� ����� ���� ������" << endl;
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
		cout << "������ ������� ������� �� ����� : " << nof << endl;
	}
	fin.close();
}
		
void clear(Data *ptrlist)
{
	free(ptrlist);
	exit(0);
}
		
	
