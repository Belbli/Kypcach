#include "FilesFunctions.h"
#include"menu.h"
#include <iostream>
#include <fstream>
using namespace std;

char nof[10];

Data get_data()
{
	/*char key;
	cout << "X -- �����. Enter -- ����������." << endl;
	cin >> key;
	if (key == 88)
	{
		menu();
	}
	else if (key == 13)
	{*/
	cout << "������� ��� ������ ����� : ";
	cin >> nof;
	ofstream fout;
	fout.open(nof);
	if (!fout.is_open())
	{
		cout << "������ �������� �����!!!";
	}
	else
	{
		cout << "���� ������.\n";


		Data data;
		cout << "Enter singer's name : ";
		cin >> data.executor;
		fout << data.executor << endl;

		cout << "Enter song name : ";
		cin >> data.SongName;
		fout << data.SongName << endl;

		cout << "Enter file compression ratio : ";
		cin >> data.compression;
		fout << data.compression << endl;

		cout << "Enter price : ";
		cin >> data.price;
		fout << data.price << endl;

		cout << "Enter purchase date : ";
		cin >> data.date;
		fout << data.date << endl;
		fout.close();
		return data;
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
		cout << "������ �������� �����!!!";
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
	}
}
			
		
	
