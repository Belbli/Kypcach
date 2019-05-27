#define _CRT_SECURE_NO_WARNINGS
#include "filling.h"
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

float checkinput(float min, float max)
{
	int num;
	char numstr[6];
	do {
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
	int num;
	char numstr[6];
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


Data get_data(Data *&ptrlist, int &size)
{
	char ch;
	do {
		ptrlist = (Data*)realloc(ptrlist, (size + 1) * sizeof(Data));
		system("cls");
		fseek(stdin, 0, SEEK_END);
		cout << "������� ��� ����������� : ";
		cin.getline(ptrlist[size].executor, 15);

		cout << "������� ��������� ����� : ";
		cin.getline(ptrlist[size].SongName, 20);

		cout << "������� ������� ������ ����� : ";
		ptrlist[size].compression = checkinput(0, 100);

		cout << "������� ��������� ����� : ";
		ptrlist[size].price = checkinput(0.0, 20);

		cout << "������� ���� ������� : ";
		ptrlist[size].day = checkinput(1, 31);

		cout << "������� ����� ������� : ";
		ptrlist[size].month = checkinput(1, 12);

		cout << "������� ��� ������� : ";
		ptrlist[size].year = checkinput(1000, 9999);

		size++;
		system("cls");
		cout << "������ �������� ��� ���� ���������? \nEnter - ��, ����� ������ ������ - ���.";
		ch = _getch();
	} while (ch == 13);
	return *ptrlist;
}

Data load_DB(Data *&ptrlist, int &size)
{
	int  t = 0, tmp;
	char buff[100], tmpstr[9], nof[15];
	cout << "������� ��� �����, ����� ���������� ��� ���������� : ";
	cin >> nof;
	if (strstr(nof, ".txt") == 0)
		strcat_s(nof, ".txt");
	ifstream fin(nof);
	if (!fin.is_open())
		cout << "���� �� ����� ���� ������" << endl;
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
		cout << "������ ������� ������� �� ����� : " << nof << endl;
	}
	fin.close();
	return *ptrlist;
}
