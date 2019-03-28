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
			<< "|1. Отобразить формат ввода данных.                   |\n"
			<< "|2. Ввести данные.                                    |\n"
			<< "|3. Удалить данные.                                   |\n"
			<< "|4. Загрузить данные из файла.                        |\n"
			<< "|5. Отобразить данные.                                |\n"
			<< "|6. Создать новый файл и открыть его.                 |\n"
			<< "|7. Сохранить данные из динамического массива.        |\n"
			<< "|8. Изменить содержимое файла.                        |\n"
			<< "|9. Выход.                                            |\n"
			<< "|_____________________________________________________|\n"
			<< endl;
		cout << "Выберете операцию : ";
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
				cout << "Введите имя файла, чтобы отоброзить его содержимое : ";
				cin >> fn;
				printData(fn);
				break;
			case 6:system("cls");
				break;
			case 7:system("cls");
				break;
			case 8:system("cls");
				cout << "Введите имя файла, чтобы редактировать его содержимое : ";
				cin >> fn;
				break;
			case 9:system("cls");
				break;
		}

}


