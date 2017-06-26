#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include "persona.h"
#include "ArrayList.h"

int menu()
    {
        int op;

        printf("\n\n**BIENVENIDO AL MENU DE OPCIONES**");
        printf("\n1-Add\n");
        printf("2-Len\n");
        printf("3-Get\n");
        printf("4-Contains\n");
        printf("5-Set\n");
        printf("6-Remove\n");
        printf("7-Clear\n");
        printf("8-Push\n");
        printf("9-IndexOf\n");
        printf("10-IsEmpty\n");
        printf("11-Pop\n");
        printf("12-Mostrar todo el ArrayList\n");
        printf("13-Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d",&op);

        return op;
    }

Persona* per_nuevo(int edad, char nombre[],char apellido[], int legajo)
{
    Persona* returnAux = NULL;
    Persona* pPersona = malloc(sizeof(Persona));

    if(pPersona != NULL)
    {
        pPersona->edad = edad;
        strcpy(pPersona->nombre,nombre);
        strcpy(pPersona->apellido,apellido);
        pPersona->legajo = legajo;

        returnAux = pPersona;
    }

    return returnAux;

}

void Mostrar(Persona* p)
{
    printf("NOMBRE: %s // APELLIDO: %s // EDAD: %d // LEGAJO: %d\n",p->nombre,p->apellido,p->edad,p->legajo);
}

char validar(char rta)
{
    while(rta!='s' && rta!='n')
    {
        printf("\nError, ingrese opcion correcta: ");
        fflush(stdin);
        rta = tolower(getche());
    }

    return rta;
}
