#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include "persona.h"
#include "ArrayList.h"


/** \brief  valida maximo
 *
 * \param min
 * \param max
 * \return val
 *
 */

int vM(int min, int max)
{
    int val;
    scanf("%d",&val);

    while(val < min || val > max)
    {
        printf("\n  ERROR, ingrese valor nuevamente: ");
        scanf("%d", &val);
    }

    return val;

}


int menu()
    {
        int op;

        printf("\n\n**BIENVENIDO AL MENU DE OPCIONES**");
        printf("\n1  - Add\n");
        printf("2  - proximo cliente\n");
        printf("3  - listar \n");
        printf("4  - informar\n");
        printf("5  - mostrar todo\n");
        printf("6  - Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d",&op);

        return op;
    }
    int menuturno()
    {
        int op;

        printf("\n\n**BIENVENIDO AL MENU DE OPCIONES DE TURNOS**");
        printf("\n1-TRAMITE URGENTE\n");
        printf("2-TRAMITE REGULAR\n");
        printf("Ingrese opcion: ");
        scanf("%d",&op);

        return op;
    }

/*Persona* per_nuevo(int edad, char nombre[],char apellido[], int legajo)
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
*/

Persona* per_nuevo2(int id, int turno)
{int dni;
int tipoturno=0;
 int opcion = 0;
    Persona* returnAux = NULL;
    Persona* pPersona = malloc(sizeof(Persona));

    printf("ingrese dni");
    fflush(stdin);
    scanf("%d", &dni);
opcion=menuturno();
if(opcion ==1)
{
 tipoturno= 1;
}
if(opcion ==2)
{
tipoturno= 2;
}

  if(pPersona != NULL)
    {
        pPersona->dni = dni;
        pPersona->id = id;
        pPersona->turno = turno;
         pPersona->tipoturno = tipoturno;

        returnAux = pPersona;
    }

    return returnAux;

}

void Mostrar(Persona* p)
{
    printf("dni: %d id: %d turno: %d tipo de turno: ",p->dni, p->id, p->turno);

    if(p->tipoturno==1)
    {
        printf(" URGENTE \n");
    }
    if(p->tipoturno==2)
    {
        printf(" REGULAR \n");
    }



    }
void Mostrarint( turnosurg *turg)
{
    printf(" %d\n", turg->turno);
}
void Mostrarint2( turnosreg *turg)
{
    printf(" %d\n", turg->turno);
}

void Mostraratendidos( turnosatendidos *turg)
{
    printf(" turno : %d dni: %d\n", turg->turno, turg->dni);
}
/*void Mostrarinicio(Persona* p)
{

    printf("%25s  %15s %15d %15d\n",p->nombre,p->apellido,p->edad,p->legajo);

}
*/

int ordenodni(Persona* x, Persona* y)
{
        int auxreturn = 0;
    if(x->dni > y->dni)
    {
        auxreturn = 1;
    }
    else if (x->dni < y->dni)
    {
         auxreturn= -1;
    }
    return auxreturn;


}

int ordenodniatendidos (turnosatendidos* x, turnosatendidos* y)
{
        int auxreturn = 0;
    if(x->dni > y->dni)
    {
        auxreturn = 1;
    }
    else if (x->dni < y->dni)
    {
         auxreturn= -1;
    }
    return auxreturn;


}
