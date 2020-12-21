#ifndef MYCONIO_H_INCLUDED
#define MYCONIO_H_INCLUDED

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
typedef char String[50];
void setColor(int ForgC);
void setColorAndBackground(int ForgC, int BackC);
void gotoxy(int x,int y);
void setWindow(int topx, int topy, int bottomx, int bottomy, int forgc, int backc);
void setTitle(String nameOfConsole);

#endif // MYCONIO_H_INCLUDED
