#include "FilesFunctions.h"
#include"menu.h"
#include <iostream>
#include<conio.h>
#include <fstream>
using namespace std;

char nof[10];

void GoTOMenu()
{
	cout << "\n\nДля выхода в главное меню нажмите Esc : ";
tryagain:
	switch (_getch())
	{
	case 27:
		menu();
		break;
	default:
		goto tryagain;
		break;
	}
}

Data get_data()
{
	int n = 0;
	cout << "Введите имя нового файла : ";
	cin >> nof;
	ofstream fout, file(nof);
	fout.open(nof);
		/*while (!file)
		{
			
			cout << "Имя файла занято.\nВведите имя нового файла : ";
			cin >> nof;
			
		}*/
	if (!fout.is_open())
		cout << "Файл не открыт.";
	
	else {

		cout << "Файл создан.\n";
		int ch = 0;

		Data data[10];
		do {
			if (ch == 1)
				n++;
			cout << "Enter singer's name : ";
			cin >> data[n].executor;
			fout << data[n].executor << endl;

			cout << "Enter song name : ";
			cin >> data[n].SongName;
			fout << data[n].SongName << endl;

			cout << "Enter file compression ratio : ";
			cin >> data[n].compression;
			fout << data[n].compression << endl;

			cout << "Enter price : ";
			cin >> data[n].price;
			fout << data[n].price << endl;

			cout << "Enter purchase date : ";
			cin >> data[n].date;
			fout << data[n].date << endl;
			fout.close();
			cout << "\nДанные успешно записаны в файл.\n";
			cin >> ch;
			
			return data[n];
		} while (ch == 1);
		
				//GoTOMenu();
	}
	
	
}
			//}
			/*cout << "Хотите ли вы добавить еще структуру(1 - да, 2 - нет) : ";
			cin >> q;*/
			//i++;
void printData(char *fname)
{
	ifstream fin(fname);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!!!\n";
	}
	else
	{
		cout << "Файл открыт.\n";
		char buff[50];

		for (int i = 0; i < 5; i++)
		{
			fin >> buff;
			cout << buff << endl;
		}
		fin.close();
		//GoToMenu();
	}

}

void remove_DB()
{
	char fname[10];
	cout << "Введите имя файла для удаления : ";
	cin >> fname;
	remove(fname);
	if (!remove(fname))
		cout << "Ошибка удаления файла\n";
	else 
		cout << "Файл успешно удалён.\n";
	//GoToMenu();
}

void EditData(char *fname)
{
	ofstream fin(fname);



}
		
void DB_parameters()
{
	cout << "Имполнитель : имя исполнителя (<=15 символов)\n"
		<< "Имя песни (<=10 символов)\n"
		<< "Степень сжатия(int)\n"
		<< "Цена : цена композиции(float)\n"
		<< "Дата : дата покупки(дд.мм.гггг)\n\n\n";
	
	GoTOMenu();
}
		
	
