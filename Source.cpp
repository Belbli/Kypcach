#include<iostream>
#include "FilesFunctions.h"
#include"menu.h"
#include "ioput.h"
#include<Windows.h>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

int isopen = 0, n = 0,i = 0; // n - ������� ��������
//Data data[100];








//void content()
//{
//	cout << "����������� : ��� ����������� (<=15 ��������)\n"
//		 << "��� ����� (<=10 ��������)\n"
//		 << "������� ������ : ������� ������(int)\n"
//		 << "���� : ���� ����������(float)\n"
//		 << "���� : ���� �������(��.��.����)\n";
//}


//void new_DB()
//{
//	string nof;
//	cout << "Enter name of file : ";
//	cin >> nof;
//	ofstream fout;
//	fout.open(nof);
//	if (!fout.is_open())
//	{
//		cout << "������ �������� �����!!!";
//	}
//	else
//	{
//		cout << "���� ������.\n";
//	}
//}

//void remove_DB()
//{
//	char fname[10];
//	cout << "������� ��� ����� ��� �������� : ";
//	cin >> fname;
//	remove(fname);
//	if (!remove(fname))
//		cout << "������ �������� �����";
//	else
//		cout << "���� ������� �����.";
//}

void clear()
{

}

void save_DB()
{

}

void load_DB()
{
	/*Data *list = new Data;
	char buff[50];
	char fname[10];
	cout << "Enter file name to load data : ";
	cin >> fname;
	ifstream fin(fname);
	while (!fin.eof())
		fin.getline(*list, 50);*/
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color B");
	Data *list = new Data;
	menu();
	//printData(fn);
//	new_DB();
	//remove_DB();
//	get_data();
	//delete[] list;
	system("pause");
	return 0;
}