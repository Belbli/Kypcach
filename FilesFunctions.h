#ifndef STRUCT
#define STRUCT
struct Data
{
	char executor[15];
	char SongName[20];
	int compression;
	float price;
	int day;
	int month;
	int year;
};
#endif // !Struct


#ifndef FilesFunctions_h
#define FilesFunctions_h


Data get_data(Data *&ptrlist);
int Menu(char *submenu[], int rows, int cols);
void save_DB(int size);
void PrintFromStruct(Data *ptrlist);
//void printData(char *fname);
void EditStruct(Data *ptrlist);
void remove_DB();
Data load_DB(Data *&ptrlist);
int Sort_Select();
int Dir_Select();
//int(*cmp)(Data ptrlist1, Data ptrlist2);
int CompareDate(Data ptrlist1, Data ptrlist2);
int CompareNames(Data ptrlist1, Data ptrlist2);
int CompareSong(Data ptrlist1, Data ptrlist2);
int ComparePrice(Data ptrlist1, Data ptrlist2);
void sort(Data *ptrlist, int(*cmp)(Data ptrlist1, Data ptrlist2), int dir);
void del(Data *ptrlist);
void search(Data *ptrlist);
void clear(Data *ptrlist);

#endif

