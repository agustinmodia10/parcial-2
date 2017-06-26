#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

typedef struct
    {
        char nombre[51];
        int edad;
        char apellido[31];
    }EPersona;

int menu();
void Agregar(ArrayList* pList, EPersona* persona);
void Borrar();
void Modificar();
void val_tam(char x[], int tam);
void val_edad(int edad);
