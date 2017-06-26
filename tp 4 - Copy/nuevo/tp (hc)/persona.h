#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include "ArrayList.h"

typedef struct
    {
        char nombre[31], apellido[31];
        int edad, legajo;
    }Persona;

Persona* per_nuevo(int edad, char nombre[],char apellido[], int legajo);
void Mostrarinicio(Persona* p);
void Mostrar(Persona* p);
int menu();
