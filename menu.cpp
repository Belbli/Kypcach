#include "menu.h"
#include "FilesFunctions.h"
#include <iostream>
#include <cstdlib>
//#include "Global.h"
#include <conio.h>
using namespace std;

char fn[10];
Data *list;
int strctcount = 0;
int t = 0;
extern int n;

void menu()
{
	system("cls");
	char menulist[10][30] = { { "������ ������" },{ "��������� ������ ���������" },{ "���������� ������ ���������" },{ "������� ���� �� ����������" },{ "���������� ������ �� �����" },{ "������������� ����" },{ "��������� �� �����" } ,{ "����� ����" } ,{ "����� ����" } ,{ "�����" } };
	for (int i = 0; i < 10; i++)
		cout << menulist[i] << endl;
	int select = -1;
	char ch;
	do {
		//system("cls");
		switch (_getch())
		{
		case 72:
			select--;
			break;
		case 80:
			select++;
			break;
		case 13:
			ch = 'e';
			break;
		}
		system("cls");
		if (select == 10)
			select = 0;
		if (select == -1)
			select = 9;
		for (int i = 0; i < 10; i++)
		{
			if (i == select)
				cout << ">> ";
			cout << menulist[i];
			if (i == select)
			{
				cout << " <<";
			}
			cout << endl;
		}
	} while (ch != 'e');
	/*do {
		system("cls");
		cout << " _____________________________________________________\n"
			 << "|                         Menu                        |\n"
			<< "|_____________________________________________________|\n"
			<< "|1. ���������� ������ ����� ������.                   |\n"
			<< "|2. ������ ������.                                    |\n"
			<< "|3. ���������� ������ ���������.                      |\n"
			<< "|4. ������� ������.                                   |\n"
			<< "|5. ��������� ������ �� �����.                        |\n"
			<< "|6. ���������� ������.                                |\n"
			<< "|7. ������� ����� ���� � ������� ���.                 |\n"
			<< "|8. ��������� ������ �� ������������� �������.        |\n"
			<< "|9. �������� ���������� �����.                        |\n"
			<< "|10. �����.                                           |\n"
			<< "|_____________________________________________________|\n"
			<< endl;
		cout << "�������� �������� : ";
		cin >> choice;
		fchoice = atoi(choice);
		system("cls");
	} while (fchoice == 0 || fchoice > 10);*/
	
		switch (select)
		{
			case 0:system("cls");
				get_data();
				menu();
				break;
			case 1:system("cls");
				system("cls");
				save_DB(n);
				menu();
				break;
			case 2:system("cls");
				PrintFromStruct();
				menu();
				break;
			case 3:system("cls");
				remove_DB();
				menu();
				break;
			case 4:system("cls");
				cout << "������� ��� �����, ����� ���������� ��� ���������� : ";
				cin >> fn;
				printData(fn);
				break;
			case 5:system("cls");
				cout << "������� ��� �����, ����� ������������� ��� ���������� : ";
				cin >> fn;
				EditFile(fn);
				menu();
				break;
			case 6:system("cls");
				load_DB();
				menu();
				break;
			case 7:
				break;
			case 8:system("cls");
				break;
			case 9:system("cls");
				clear(list);
				break;
		}

}


