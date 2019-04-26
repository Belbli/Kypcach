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
	char menulist[10][30] = { { "Ввести данные" },{ "Сохранить данные структуры" },{ "Отобразить данные структуры" },{ "Удалить файл со структурой" },{ "Отобразить данные из файла" },{ "Редактировать файл" },{ "Загрузить из файла" } ,{ "Пункт меню" } ,{ "Пункт меню" } ,{ "Выход" } };
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
			<< "|1. Отобразить формат ввода данных.                   |\n"
			<< "|2. Ввести данные.                                    |\n"
			<< "|3. Отобразить данные структуры.                      |\n"
			<< "|4. Удалить данные.                                   |\n"
			<< "|5. Загрузить данные из файла.                        |\n"
			<< "|6. Отобразить данные.                                |\n"
			<< "|7. Создать новый файл и открыть его.                 |\n"
			<< "|8. Сохранить данные из динамического массива.        |\n"
			<< "|9. Изменить содержимое файла.                        |\n"
			<< "|10. Выход.                                           |\n"
			<< "|_____________________________________________________|\n"
			<< endl;
		cout << "Выберете операцию : ";
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
				cout << "Введите имя файла, чтобы отоброзить его содержимое : ";
				cin >> fn;
				printData(fn);
				break;
			case 5:system("cls");
				cout << "Введите имя файла, чтобы редактировать его содержимое : ";
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


