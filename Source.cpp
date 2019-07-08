#include<iostream>
#include"menu.h"
#include<Windows.h>

using namespace std;

int isopen = 0,i = 0; 

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	system("pause");
	return 0;
}