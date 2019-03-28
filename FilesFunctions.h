

#ifndef Struct
#define Struct
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

Data get_data();
void printData(char *fname);
void EditFile(char *fname);
void remove_DB();
void DB_parameters();
void GoToMenu();

#endif

