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
        printf("\n         �����������������������������������������������������������ͻ");
		printf("\n         �                   ::  bienvenido ::                       �");
		printf("\n         �����������������������������������������������������������ͼ\n\n");

         system("pause");
         system("cls");

    while(seguir == 'n')
    {  system("color 8e");

        printf("\n\n \n");
        printf("\n         ������������������������������������������������ͻ");
		printf("\n         �        :     MENU DE OPCIONES  ::              �");
		printf("\n         ������������������������������������������������͹");
		printf("\n         �  1- agregar programador                        �");
		printf("\n         �  2- modificar programador                      �");
		printf("\n         �  3- borrar programador                         �");
		printf("\n         �  4- asignar programador a proyecto             �");
	    printf("\n         �  5- asignar programador a proyecto             �");
		printf("\n         �  6- imprimir listado de programadores          �");
		printf("\n         �  7- imprimir listado de proyectos              �");
		printf("\n         �  8- proyecto mas demandante                    �");
		printf("\n         �  9- Salir                                      �");
		printf("\n         ������������������������������������������������ͼ");
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
