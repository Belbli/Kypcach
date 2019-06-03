#include "menu.h"
#include "Functions.h"
#include "filling.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

char fn[15];
Data *list, tmp;
int n = 0;

int(*cmp)(Data ptrlist1, Data ptrlist2);

void menu()
{
	system("cls");
	char *menu_name = "ГЛАВНОЕ МЕНЮ\n";
	char *output_menu = "ОТОБРАЗИТЬ ДАННЫЕ\n";
	char *output[2] = { { "Вывод в форме таблицы" },{ "Обычный вывод" } };
	char *menulist[12] = { { "Ввести данные" },{ "Сохранить данные структуры" },{ "Отобразить данные структуры" },{ "Удалить файл со структурой" },{ "Отобразить данные из файла" },{ "Редактировать структуру" },{ "Загрузить из файла" } ,{ "Сортировка" } ,{ "Удалить по имени исполнителя" } ,{ "Поиск" } ,{ "Выручка" },{ "Выход" } };
	int  output_form;
	char find_field[30];
	char name[30];
	int select = -1, field = -1, dir = 0, k;
	int i = 0;
	select = Menu(menulist, 12, 30, menu_name);
		switch (select)
		{
			case 0:system("cls");
				get_data(list, n);
				menu();
				break;
			case 1:system("cls");
				system("cls");
				cout << "Введите имя файла, в который вы хотите сохранить данные : ";
				cin >> fn;
				if (strstr(fn, ".txt") == 0)
					strcat(fn, ".txt");
				save_DB(list, fn, n);
				menu();
				break;
			case 2:system("cls");
				if (n != 0)
				{
					output_form = Menu(output, 2, 10, output_menu);
					PrintStruct(list, output_form, n);
				}
				else
					cout << "База данных пуста.\n";
				_getch();
				menu();
				break;
			case 3:system("cls");
				cout << "Введите имя файла, который хотите удалить : ";
				cin >> fn;
				if (strstr(fn, ".txt") == 0)
					strcat(fn, ".txt");
				remove_DB(fn);
				menu();
				break;
			case 4:system("cls");
				cout << "Введите имя файла, чтобы отоброзить его содержимое : ";
				cin >> fn;
				if(strstr(fn, ".txt") == 0)
					strcat_s(fn, ".txt");
				ReadFile(fn);
				menu();
				break;
			case 5:system("cls");
				EditStruct(list, n);
				menu();
				break;
			case 6:system("cls");
				load_DB(list, n);
				menu();
				break;
			case 7:system("cls");
				field = Sort_Select();
				system("cls");
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
				sort(list, cmp, dir, n);
				menu();
				break;
			case 8:system("cls");
				if (n == 0)
				{
					cout << "База данных пуста.\n";
					_getch();
				}
				else 
				{
					cout << "Введите имя исполенителя для удаления : ";
					fseek(stdin, 0, SEEK_END);
					del(list, name, n);
				}
					menu();
				break;
			case 9:system("cls");
				select = search_field();
				system("cls");
				k = -1;
				cout << "Поиск : ";
				fseek(stdin, 0, SEEK_END);
				switch (select)
				{
				case 0:
					fseek(stdin, 0, SEEK_END);
					fgets(tmp.executor, 15, stdin);
					tmp.executor[strlen(tmp.executor) - 1] = '\0';
					cmp = CompareNames;
					break;
				case 1:
					fseek(stdin, 0, SEEK_END);
					fgets(tmp.SongName, 15, stdin);
					tmp.SongName[strlen(tmp.SongName) - 1] = '\0';
					cmp = CompareSong;
					break;
				case 2:
					cin >> tmp.price;
					cmp = ComparePrice;
					break;
				case 3:
					cmp = CompareDate;
					cin >> find_field;
					sscanf(find_field, "%d.%d.%d", &tmp.day, &tmp.month, &tmp.year);
					break;
				}
				search(list, cmp, tmp, n);
				menu();
				break;
			case 10:system("cls");
				PrintStruct(list, 0, n);
				profit(list, n);
				menu();
				break;
			case 11:system("cls");
				clear(list);
				break;
			default:system("cls");
				menu();
				break;

		}

}


