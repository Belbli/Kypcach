#ifndef Functions_h
#define Functions_h
#include "Struct.h"


int Menu(char *submenu[], int rows, int cols, char *menu_name);
void save_DB(Data *ptrlist, char *fname, int size);
void PrintStruct(Data *ptrlist, int output_form, int size);
void ReadFile(char *fname);
void EditStruct(Data *ptrlist, int size);
void remove_DB(char *fname);
int Sort_Select();
int Dir_Select();
int search_field();
void profit(Data *ptrlist, int size);
int CompareDate(Data ptrlist1, Data ptrlist2);
int CompareNames(Data ptrlist1, Data ptrlist2);
int CompareSong(Data ptrlist1, Data ptrlist2);
int ComparePrice(Data ptrlist1, Data ptrlist2);
void sort(Data *ptrlist, int(*cmp)(Data ptrlist1, Data ptrlist2), int dir, int size);
void del(Data *ptrlist, char  *name, int &size);
void search(Data *ptrlist, int(*cmp)(Data ptrlist1, Data ptrlist2), Data search, int size);
void clear(Data *ptrlist);

#endif

