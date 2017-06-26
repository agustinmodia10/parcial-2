#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;

  system("color 8e");
        printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
		printf("\n         บ                   ::  bienvenido ::                       บ");
		printf("\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n");
		                          recuardoportada("BY ALUMNO AGUSTIN MODIA  ");

         system("pause");
         system("cls");

    while(seguir == 's')
    {
        system("color 8e");

        printf("\n\n \n");
        printf("\n         ษออออออออออออออออออออออออออออออออออออออออออออออออป");
		printf("\n         บ        :     MENU DE OPCIONES  ::              บ");
		printf("\n         ฬออออออออออออออออออออออออออออออออออออออออออออออออน");
		printf("\n         บ  1- agregar pelicula                           บ");
		printf("\n         บ  2- Borrar pelicula                            บ");
		printf("\n         บ  3- Modificar pelicula                         บ");
		printf("\n         บ  4- Generar pagina web                         บ");
	    printf("\n         บ  5- salir                                      บ");
		printf("\n         ศออออออออออออออออออออออออออออออออออออออออออออออออผ");
		printf("\n");


         printf("\n  Ingrese una de las opciones: ");

        opcion = vM(1, 9);
        printf("\n\n");

        switch(opcion)
        {
            case 1:
                agregar();
                break;
            case 2:
                borrar();
                break;
            case 3:
                modificar();
                break;
            case 4:
                generar();
                break;
            case 5:
                  seguir = 'n';

                   recuadroStr("HASTA LA PROXIMA");




                break;
        }

    }

    return 0;
}
