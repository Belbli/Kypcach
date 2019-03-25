

#ifndef Struct
#define Struct
struct Data
{
	char executor[15];
	char SongName[20];
	int compression;
	float price;
	char date[10];
};
#endif // !Struct


#ifndef FilesFunctions_h
#define FilesFunctions_h

void GoToMenu();
Data get_data();
void printData(char *fname);
void EditFile(char *fname);
void remove_DB();
void DB_parameters();


#endif

