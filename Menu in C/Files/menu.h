#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define MENU_MAX_WIDTH 119
#define MENU_MAX_HIGHT 29
#define MENU_MAX_STRING 31
#define MENU_MAX_FIELDS 5
#define MENU_TRUE 1
#define MENU_FALSE 0
typedef struct{

    int Fc;
    int Bc;
    char text[MENU_MAX_STRING];
    char sign;
}TField;

typedef struct{

    char headerText[MENU_MAX_STRING];
    int boolHeader;
    char footerText[MENU_MAX_STRING];
    int boolFooter;

}THeaderFooter;
typedef struct{

    int Fc;
    int Bc;
    THeaderFooter headerFooter;
    TField fieldArr[MENU_MAX_FIELDS];
    int fieldNoe;
}TMenu;

void screen(int Fc, int Bc);
void addField(TMenu *menu, int fc, int bc, char sign, char* txt);

void printMenu(TMenu* menu);
void printField(TField* field, int topY, int bottomY);
void printFieldArr(TField field[], int noe);
void printHeaderFooter(THeaderFooter* hf, int fc, int bc);

void setHeader(THeaderFooter* header , char* txt);
void setFooter(THeaderFooter* footer , char* txt);

char inputMenu(TMenu* menu);
int checkKey(TField field[], char key, int noe);
#endif // MENU_H_INCLUDED
