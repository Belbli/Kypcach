

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

Data get_data();
void printData(char *fname);

#endif

