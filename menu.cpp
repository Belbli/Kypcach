#include "menu.h"
#include <iostream>
using namespace std;

void menu()
{
	char choice[2];
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
		 << "|_____________________________________________________|\n"
		 << endl;
	cout << "�������� �������� : ";
	cin >> choice;
	int ichoice = atoi(choice);
		switch (ichoice)
		{
			case 1:system("cls");
					break;
			case 2:system("cls");
				break;
			case 3:system("cls");
				break;
			case 4:system("cls");
				break;
			case 5:system("cls");
				break;
			case 6:system("cls");
				break;
			case 7:system("cls");
				break;
		}



}


