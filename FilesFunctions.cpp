#include "FilesFunctions.h"
#include"menu.h"
#include <iostream>
#include<conio.h>
#include <fstream>
using namespace std;

char nof[10];

void GoTOMenu()
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
		do {
			if (ch == 1)
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

			cout << "Enter purchase date : ";
			cin >> data[n].date;
			fout << data[n].date << endl;
			fout.close();
			cout << "\n������ ������� �������� � ����.\n";
			cin >> ch;
			
			return data[n];
		} while (ch == 1);
		
				//GoTOMenu();
	}
	
	
}
			//}
			/*cout << "������ �� �� �������� ��� ���������(1 - ��, 2 - ���) : ";
			cin >> q;*/
			//i++;
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

		for (int i = 0; i < 5; i++)
		{
			fin >> buff;
			cout << buff << endl;
		}
		fin.close();
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
	
	GoTOMenu();
}
		
	
