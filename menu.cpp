#include "menu.h"
#include <iostream>
using namespace std;

void menu()
{
	char choice[2];
	cout << " _____________________________________________________\n"
	     << "|                         Menu                        |\n"
		 << "|_____________________________________________________|\n"
		 << "|1. Отобразить формат ввода данных.                   |\n"
		 << "|2. Ввести данные.                                    |\n"
		 << "|3. Удалить данные.                                   |\n"
		 << "|4. Загрузить данные из файла.                        |\n"
		 << "|5. Отобразить данные.                                |\n"
		 << "|6. Создать новый файл и открыть его.                 |\n"
		 << "|7. Сохранить данные из динамического массива.        |\n"
		 << "|_____________________________________________________|\n"
		 << endl;
	cout << "Выберете операцию : ";
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


