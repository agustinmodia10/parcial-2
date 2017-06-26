#include <stdio.h>
#include <stdlib.h>
#include "funcmodiaTP2.h"
#define num 20



int main()
{

    iper people[num];



    char seguir = 'n';
    int option = 0;
  system("color 8e");
        printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
		printf("\n         บ                   ::  bienvenido ::                       บ");
		printf("\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n");

         system("pause");
         system("cls");

    while(seguir == 'n')
    {  system("color 8e");

        printf("\n\n \n");
        printf("\n         ษออออออออออออออออออออออออออออออออออออออออออออออออป");
		printf("\n         บ        :     MENU DE OPCIONES  ::              บ");
		printf("\n         ฬออออออออออออออออออออออออออออออออออออออออออออออออน");
		printf("\n         บ  1- agregar programador                        บ");
		printf("\n         บ  2- modificar programador                      บ");
		printf("\n         บ  3- borrar programador                         บ");
		printf("\n         บ  4- asignar programador a proyecto             บ");
	    printf("\n         บ  5- asignar programador a proyecto             บ");
		printf("\n         บ  6- imprimir listado de programadores          บ");
		printf("\n         บ  7- imprimir listado de proyectos              บ");
		printf("\n         บ  8- proyecto mas demandante                    บ");
		printf("\n         บ  9- Salir                                      บ");
		printf("\n         ศออออออออออออออออออออออออออออออออออออออออออออออออผ");
		printf("\n");



        printf("\n  Ingrese una de las opciones: ");

        option = vM(1, 9);
        printf("\n\n");

        switch(option)
        {
            case 1:


                break;

            case 2:

                system("pause");
                system("cls");

                break;

            case 3:
                system("color 5b ");

                system("pause");

                break;

            case 4:
                system("color 9f");


                break;



                case 5:
                system("color 9f");


                break;


                   case 6:
                system("color 9f");


                break;


                   case 7:
                system("color 9f");


                break;


                case 8:
                system("color 9f");


                break;



            case 9:
                printf("  Esta seguro que desea salir? (y=si/n=no): ");
                seguir = vRta(seguir);

                if(seguir == 'y')
                {
                    printf("\n\n  Adios, vuelva pronto!\n\n");
                }

                break;
        }
system("cls");
    system("pause");
    }


    return 0;
}
