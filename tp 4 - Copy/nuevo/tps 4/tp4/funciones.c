#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include "ArrayList.h"
#include "funciones.h"

int menu()
    {
        int op;

        printf("\nBienvenido al menu, seleccione una opcion:\n");
        printf("\n1- Generar ArrayList\n");
        printf("2- Agregar persona\n");
        printf("3- Borrar persona\n");
        printf("4- Imprimir lista\n");
        printf("5- Salir\n\n");
        scanf("%d",&op);

        return op;
    }

void Agregar(ArrayList* lista, EPersona* persona)
    {
        int auxed;
        char auxnom[1000], auxape[1000];

        printf("\nIngrese nombre (hasta 50 caracteres inclusive): ");
        fflush(stdin);
        gets(auxnom);
        val_tam(auxnom,51);
        strcpy(persona->nombre,auxnom);

        printf("\nIngrese apellido: (hasta 30 caracteres inclusive): ");
        fflush(stdin);
        gets(auxape);
        val_tam(auxape,31);
        strcpy(persona->apellido,auxape);

        printf("\nIngrese edad (1-100 inclusive): ");
        scanf("%d",&auxed);
        val_edad(auxed);
        persona->edad = auxed;

        al_add(lista,&persona);

        printf(*(lista->pElements+index));
    }

void val_tam(char x[], int tam)
    {
        while(strlen(x)>tam-1)
        {
            printf("\nERROR. Reingrese una cadena que no supere los %d caracteres: ",tam-1);
            fflush(stdin);
            gets(x);
        }
    }

void val_edad(int edad)
    {
        while(edad<=0 || edad>=101)
        {
        printf("\nIngrese una edad correcta (del 1 al 100): ");
        scanf("%d",&edad);
        }
    }
