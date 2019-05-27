//#ifndef STRUCT
//#define STRUCT
//struct Data
//{
//	char executor[15];
//	char SongName[20];
//	int compression;
//	float price;
//	int day;
//	int month;
//	int year;
//};
//#endif 


#ifndef FilesFunctions_h
#define FilesFunctions_h
#include "Struct.h"


//Data get_data(Data *&ptrlist, int &size);
int Menu(char *submenu[], int rows, int cols);
void save_DB(Data *ptrlist, int size);
void PrintFromStruct(Data *ptrlist, int output_form, int size);
void printData(char *fname);
void EditStruct(Data *ptrlist);
void remove_DB();
//Data load_DB(Data *&ptrlist, int &size);
int Sort_Select();
int Dir_Select();
void profit(Data *ptrlist, int size);
int CompareDate(Data ptrlist1, Data ptrlist2);
int CompareNames(Data ptrlist1, Data ptrlist2);
int CompareSong(Data ptrlist1, Data ptrlist2);
int ComparePrice(Data ptrlist1, Data ptrlist2);
void sort(Data *ptrlist, int(*cmp)(Data ptrlist1, Data ptrlist2), int dir, int size);
//void del(Data *ptrlist, int size);
void search(Data *ptrlist, int size);
void clear(Data *ptrlist);

#endif

