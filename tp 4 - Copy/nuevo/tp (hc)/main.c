#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include "persona.h"
#include "ArrayList.h"

int main()
{
    system("color 5F");
    int opcion, flag=1, flag2=0, index, sizeArray, i, indexaux, r, auxindexof2, auxcontains;
    char respuesta[100], auxindexof[100];
Persona* pPersona;
    Persona *p0 = per_nuevo(22, "diego alberto", "milito", 2222);
    Persona *p1 = per_nuevo(10, "diego armando", "maradona", 1010);
    Persona *p2 = per_nuevo(11, "diego sebastian","saja", 1111 );
    Persona *p3 = per_nuevo(2, "claudio", "ubeda", 0202);
    Persona *pe;
 printf("            Nombre:               Apellido:             Edad:         Legajo: \n");
    Mostrarinicio(p0);
    Mostrarinicio(p1);
    Mostrarinicio(p2);
    Mostrarinicio(p3);

    printf("\n");
    ArrayList* lista=al_newArrayList();

    printf("**Array List creado**\n");
    system("pause");

    while(flag)
    {
        opcion = menu();

        system("cls");

        switch(opcion)
        {

            case 1:

                lista->add(lista,p0);
                lista->add(lista,p1);
                lista->add(lista,p2);
                lista->add(lista,p3);
                flag2=1;
                printf("Los datos han sido cargados correctamente\n");
                system("pause");
                break;
            case 2:
                if(flag2==1)
                {
                    sizeArray=lista->len(lista);
                    printf("\nCantidad de elementos que posee el array es: %d\n",sizeArray);
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                system("pause");
                break;
            case 3:
                if(flag2==1)
                {
                    printf("\nIngrese indice del elemento a mostrar: ");
                    scanf("%d",&index);

                    for(i=index;i<lista->len(lista);i++)
                    {
                        Persona* pAux = lista->get(lista,i);
                        printf("%d) ",i);
                        Mostrar(pAux);
                        system("pause");
                        break;
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                system("pause");
                break;
            case 4:
                if(flag2==1)
                {
                    printf("\nIngrese el nombre del elemento a buscar: ");
                    fflush(stdin);
                    gets(respuesta);
                    strupr(respuesta);
                    auxcontains=0;


                          for(i=0;i<lista->len(lista);i++)
                    {
                         Persona* pAux = lista->get(lista,i);
                        if(stricmp(respuesta, pAux->nombre)==0)
                    {
                        auxcontains = lista->contains(lista,pAux->nombre);

                    }

                    }
                    if(auxcontains==1)
                    {
                        printf("\nSe encontro el nombre");
                    }
                    if(auxcontains==0)
                    {
                        printf("\nNo se encontro el nombre");

                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                printf("\n");
                system("pause");
                break;
            case 5:
                if(flag2==1)
                {
                    printf("\nIngrese indice a pisar: ");
                    scanf("%d",&index);
                    printf("\nIngrese indice a ser ingresado: ");
                    scanf("%d",&indexaux);
                         for(i=0;i<lista->len(lista);i++)
                    {
                         Persona* pAux = lista->get(lista,i);

                        auxindexof2 = lista->indexOf(lista,pAux->nombre);
                        if(indexaux==auxindexof2)
                    {
                        lista->set(lista,index,pAux->nombre);

                    }

                    }

                    for(i=0;i<lista->len(lista);i++)
                    {
                        Persona* pAux = lista->get(lista,i);
                        printf("%d) ",i);
                        Mostrar(pAux);
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                printf("\n");
                system("pause");
                break;
            case 6:
                if(flag2==1)
                {
                    printf("Ingrese indicie del elemento a eliminar: ");
                    scanf("%d) ",&index);
                    r = lista->remove(lista,index);
                    for(i=0;i<lista->len(lista);i++)
                    {
                        Persona* pAux = lista->get(lista,i);
                        printf("%d) ",i);
                        Mostrar(pAux);
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                printf("\n");
                system("pause");
                break;
            case 7:
                if(flag2==1)
                {
                    r = lista->clear(lista);
                    if(r==0)
                    {
                        printf("\nSe eliminaron todos los elementos del ArrayList con exito\n");
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                system("pause");
                break;
            case 8:
                if(flag2==1)
                {
                    printf("\nIngrese el indice de la posicion a donde se movera el elemento: ");
                    scanf("%d",&index);
                    printf("Ingrese indice a mover: ");
                    scanf("%d",&indexaux);
                    printf("\n");


                    for(i=0;i<lista->len(lista);i++)
                    {
                         Persona* pAux = lista->get(lista,i);

                        auxindexof2 = lista->indexOf(lista,pAux->nombre);
                        if(indexaux==auxindexof2)
                    {
                        lista->push(lista,index,pAux->nombre);

                    }

                    }


                   for(i=0;i<lista->len(lista);i++)
                    {
                        Persona* pAux = lista->get(lista,i);
                        printf("%d) ",i);
                        Mostrar(pAux);
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente\n");
                }
                printf("\n");
                system("pause");
                break;
            case 9:
                if(flag2==1)
                {
                    printf("Ingrese el nombre del elemento del cual se quiere obtener el indice: ");
                    fflush(stdin);
                    gets(auxindexof);
                    strupr(auxindexof);
                    printf("\n");

                        for(i=0;i<lista->len(lista);i++)
                    {
                         Persona* pAux = lista->get(lista,i);
                        if(stricmp(auxindexof, pAux->nombre)==0)
                    {
                        auxindexof2 = lista->indexOf(lista,pAux->nombre);
                        printf("\nEl indice encontrado es %d\n",auxindexof2);
                    }

                    }

                    if(auxindexof2 = -1)
                    {
                        printf("\n el nombre no esta cargado");
                    }


                }

                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente\n");
                }
                system("pause");
                break;
            case 10:
                if(flag2==1)
                {
                    if(lista->isEmpty(lista))
                    {
                        printf("La lista se encuentra vacia");
                    }
                    else
                    {
                        printf("Contiene elementos");
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                printf("\n");
                system("pause");
                break;
            case 11:
                if(flag2==1)
                {
                    printf("\nIngrese el indice del elemento a buscar, que luego va a ser eliminado: ");
                    scanf("%d",&index);
                    Persona* pAux=lista->pop(lista,index);
                    if(pAux!=NULL)
                    {
                        printf("\nELEMENTO BORRADO:\n");
                        Mostrar(pAux);
                    }
                    else
                    {
                        printf("\nError, indice incorrecto");
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                printf("\n");
                system("pause");
                break;
            case 12:
                if(flag2==1)
                {

                    for(i=0;i<lista->len(lista);i++)
                    {
                        Persona* pAux = lista->get(lista,i);
                        printf("%d) ",i);
                        Mostrar(pAux);
                    }
                }
                else
                {
                    printf("\nNo se han cargado datos a la lista anteriormente");
                }
                printf("\n");
                system("pause");
                break;
            case 13:
                flag=0;
                break;
            default:
                printf("\nOpcion incorrecta\n");
                system("pause");
        }
    }

    free(p0);
    free(p1);
    free(p2);
    free(p3);
    lista->deleteArrayList(lista);
    printf("\nSe ha eliminado el ArrayList y se libero la memoria usada\n");

    return 0;
}
