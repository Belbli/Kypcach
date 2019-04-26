

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


void get_data();
void save_DB(int count);
void PrintFromStruct();
void printData(char *fname);
void EditFile(char *fname);
void remove_DB();
void load_DB();
void clear(Data *ptrlist);

#endif

