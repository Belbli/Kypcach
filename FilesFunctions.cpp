#include "FilesFunctions.h"
#include"menu.h"
#include <iostream>
#include<conio.h>
#include <fstream>
using namespace std;

char nof[10];


void GoToMenu()
{
	cout << "\n\n��� ������ � ������� ���� ������� Esc : ";
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
	cout << "������� ��� ������ ����� : ";
	cin >> nof;
	ofstream fout, file(nof);
	fout.open(nof);
		/*while (!file)
		{
			
			cout << "��� ����� ������.\n������� ��� ������ ����� : ";
			cin >> nof;
			
		}*/
	if (!fout.is_open())
		cout << "���� �� ������.";
	
	else {

		cout << "���� ������.\n";
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

			cout << "������� ���� ������� : ";
			cin >> data[n].day;
			fout << data[n].day << endl;

			cout << "������� ����� ������� : ";
			cin >> data[n].month;
			fout << data[n].month << endl;

			cout << "������� ��� ������� : ";
			cin >> data[n].year;
			fout << data[n].year << endl;

			fout.close();
			cout << "\n������ ������� �������� � ����.\n";
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
			cout << "�����������\t\t����������\t������� ������(MB)\t����($)\t\t����\n\n";
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
	cout << "������� ��� ����� ��� �������� : ";
	cin >> fname;
	remove(fname);
	if (!remove(fname))
		cout << "������ �������� �����\n";
	else 
		cout << "���� ������� �����.\n";
	GoToMenu();
}

void EditData(char *fname)
{
	ofstream fin(fname);



}
		
void DB_parameters()
{
	cout << "����������� : ��� ����������� (<=15 ��������)\n"
		 << "��� ����� (<=10 ��������)\n"
		 << "������� ������(int)\n"
		 << "���� : ���� ����������(float)\n"
		 << "���� : ���� �������(��.��.����)\n\n\n";
	
	GoToMenu();
}


		
	
