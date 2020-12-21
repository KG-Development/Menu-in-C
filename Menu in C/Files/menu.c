#include "menu.h"
#include "myconio.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

void screen(int Fc, int Bc){

    setWindow(0, 0, MENU_MAX_WIDTH, MENU_MAX_HIGHT, Fc, Bc);
}
void addField(TMenu* menu, int fc, int bc, char sign, char* txt){


    if(menu->fieldNoe > 4) return;

    menu->fieldArr[menu->fieldNoe].Fc = fc;
    menu->fieldArr[menu->fieldNoe].Bc = bc;
    strcpy(menu->fieldArr[menu->fieldNoe].text, txt);
    menu->fieldArr[menu->fieldNoe].sign = sign;
    menu->fieldNoe += 1;

}
void printField(TField* field, int topY, int bottomY){

    setWindow(25, topY, 95, bottomY, field->Fc, field->Bc);
    gotoxy(46, (topY + bottomY) / 2);
    printf("Press [%c] %s", field->sign, field->text);
}
void printFieldArr(TField field[], int noe){

    int topY = 5, bottomY = 7;

    for(int idx = 0; idx < noe; idx++){

        printField(&field[idx], topY, bottomY);
        topY += 4;
        bottomY += 4;
    }
}
void setHeader(THeaderFooter* header, char* txt){

    strcpy(header->headerText, txt);
    header->boolHeader = MENU_TRUE;
}
void setFooter(THeaderFooter* footer, char* txt){

    strcpy(footer->footerText, txt);
    footer->boolFooter = MENU_TRUE;
}
void printHeaderFooter(THeaderFooter* hf, int fc, int bc){

    if(hf->boolHeader){
        setWindow(0, 0, MENU_MAX_WIDTH, 2, fc, bc);
        gotoxy(MENU_MAX_WIDTH / 2 - (strlen(hf->headerText) / 2), 1);
        puts(hf->headerText);
    }
    if(hf->boolFooter){
        setWindow(0, MENU_MAX_HIGHT - 2, MENU_MAX_WIDTH, MENU_MAX_HIGHT, fc, bc);
        gotoxy(MENU_MAX_WIDTH / 2 - (strlen(hf->footerText) / 2), 28);
        puts(hf->footerText);
    }
}
void printMenu(TMenu* menu){

    const int fc = menu->Fc;
    const int bc = menu->Bc;

    int topY = 3;
    int bottomY = 3;

    if(menu->headerFooter.boolHeader || menu->headerFooter.boolFooter){
        printHeaderFooter(&menu->headerFooter, fc, bc);
        if(!menu->headerFooter.boolHeader) topY = 0;
        if(!menu->headerFooter.boolFooter) bottomY = 0;
        setWindow(0, topY, MENU_MAX_WIDTH, MENU_MAX_HIGHT - bottomY, fc, bc);
    }else{
        screen(fc, bc);
    }

    printFieldArr(menu->fieldArr, menu->fieldNoe);

    setColorAndBackground(WHITE, BLACK);
}
char inputMenu(TMenu* menu){

    char user_input;

    if(!menu->fieldNoe) return 'º';
    do{
        user_input = getch();
    }while(!checkKey(menu->fieldArr, user_input, menu->fieldNoe));

    return user_input;
}
int checkKey(TField field[], char key, int noe){

    for(int idx = 0; idx < noe; idx++){

        if(key == field[idx].sign) return 1;
    }
    return 0;
}
