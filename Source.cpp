#include<iostream>
#include"menu.h"
#include<Windows.h>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

int isopen = 0,i = 0; // n - счётчик структур
//Data data[100];




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	menu();
	system("pause");
	return 0;
}