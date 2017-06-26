#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
        system("color 4F");
        ArrayList* lista;
        EPersona* AuxPersona;
        char seguir='s';
        int opcion, flag=0;

        while(seguir=='s')
        {
            opcion = menu();

            system("cls");

            switch(opcion)
            {
                case 1:
                    lista = al_newArrayList();
                    flag=1;
                    printf("\nArrayList creado\n");
                    system("pause");
                    break;
                case 2:
                    if(flag==1)
                    {
                        Agregar(lista,AuxPersona);
                        break;
                    }
                    else
                    {
                    }
                    break;
                case 3:
                    if(flag==1)
                    {
                    }
                    else
                    {
                    }
                    break;
                case 4:
                    if(flag==1)
                    {
                    }
                    else
                    {
                    }
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    printf("\nError, ingrese opcion correcta");
            }
        }

        return 0;
}
