#include "menu.h"
#include "FilesFunctions.h"
#include <iostream>
#include <conio.h>
using namespace std;

char fn[10];

void menu()
{
	char choice[3];
	int fchoice;
	do {
		system("cls");
		cout << " _____________________________________________________\n"
			<< "|                         Menu                        |\n"
			<< "|_____________________________________________________|\n"
			<< "|1. ���������� ������ ����� ������.                   |\n"
			<< "|2. ������ ������.                                    |\n"
			<< "|3. ������� ������.                                   |\n"
			<< "|4. ��������� ������ �� �����.                        |\n"
			<< "|5. ���������� ������.                                |\n"
			<< "|6. ������� ����� ���� � ������� ���.                 |\n"
			<< "|7. ��������� ������ �� ������������� �������.        |\n"
			<< "|8. �������� ���������� �����.                        |\n"
			<< "|9. �����.                                            |\n"
			<< "|_____________________________________________________|\n"
			<< endl;
		cout << "�������� �������� : ";
		cin >> choice;
		fchoice = atoi(choice);
		system("cls");
	} while (fchoice == 0 || fchoice > 9);
	
		switch (fchoice)
		{
			case 1:system("cls");
				//system("color C");
				DB_parameters();
					break;
			case 2:system("cls");
				get_data();
				break;
			case 3:system("cls");
				remove_DB();
				break;
			case 4:system("cls");
				break;
			case 5:system("cls");
				cout << "������� ��� �����, ����� ���������� ��� ���������� : ";
				cin >> fn;
				printData(fn);
				break;
			case 6:system("cls");
				break;
			case 7:system("cls");
				break;
			case 8:system("cls");
				cout << "������� ��� �����, ����� ������������� ��� ���������� : ";
				cin >> fn;
				break;
			case 9:system("cls");
				break;
		}

}


