#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include "ArrayList.h"

typedef struct
    {
        int dni, id, turno,tipoturno;
    }Persona;

typedef struct
    {
        int turno;
    }turnosurg;
    typedef struct
    {
        int turno;
    }turnosreg;
        typedef struct
    {
        int turno,dni;
    }turnosatendidos;

//Persona* per_nuevo(int edad, char nombre[],char apellido[], int legajo);
void Mostrarinicio(Persona* p);
void Mostrar(Persona* p);
int menu();
int ordenodni();
int ordenodniatendidos();
