#include "menu.h"
#include "FilesFunctions.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

char fn[10];
Data *list;
int strctcount = 0;
int t = 0;
extern int n;

int(*cmp)(Data ptrlist1, Data ptrlist2);

void menu()
{
	system("cls");
	char *menulist[11] = { { "Ввести данные" },{ "Сохранить данные структуры" },{ "Отобразить данные структуры" },{ "Удалить файл со структурой" },{ "Отобразить данные из файла" },{ "Редактировать структуру" },{ "Загрузить из файла" } ,{ "Сортировка" } ,{ "Удалить по имени исполнителя" } ,{ "Поиск" } ,{ "Выход" } };
	int prev, next;
	int select = -1, field = -1, dir = 0;
	int i = 0;
	select = Menu(menulist, 11, 30);
	
		switch (select)
		{
			case 0:system("cls");
				get_data(list);
				menu();
				break;
			/*case 1:system("cls");
				system("cls");
				save_DB(list, n);
				menu();
				break;*/
			case 2:system("cls");
				PrintFromStruct(list);
				menu();
				break;
			case 3:system("cls");
				remove_DB();
				menu();
				break;
			case 4:system("cls");
				cout << "Введите имя файла, чтобы отоброзить его содержимое : ";
				cin >> fn;
				//printData(fn);
				break;
			case 5:system("cls");
				EditStruct(list);
				menu();
				break;
			case 6:system("cls");
				load_DB(list);
				menu();
				break;
			case 7:system("cls");
				field = Sort_Select();
				switch (field)
				{
					case 0:
						cmp = CompareNames;
						break;
					case 1:
						cmp = CompareSong;
						break;
					case 2:
						cmp = ComparePrice;
						break;
					case 3:
						cmp = CompareDate;
						break;
				}
				dir = Dir_Select();
				sort(list, cmp, dir);
				menu();
				break;
			case 8:system("cls");
				del(list);
				menu();
				break;
			case 9:system("cls");
				search(list);
				menu();
				break;
			case 10:system("cls");
				clear(list);
				break;
			default:system("cls");
				menu();
				break;

		}

}


