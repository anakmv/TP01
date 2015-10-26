#ifndef MATRIZ_H
#define MATRIZ_H
#include "floodfill.h"



unsigned char** New_Matriz_char(int, int);

void Set_Matriz_char (char**, int, int, char);

char Get_Matriz_char (char**, int, int);

char Get_Matriz_uchar (unsigned char**, int, int);

void Print_Matriz_char(char**, int, int);

void Print_Matriz_uchar(unsigned char**, int, int);

PGM* New_Matriz_Pgm(int, int );


#endif