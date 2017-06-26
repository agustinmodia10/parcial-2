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
    int opcion, flag=1, flag2=0, index, sizeArray, i, indexaux, r, auxindexof2, auxcontains,e;
    int id = 99;
    int turnos = 0;
    int traux = 0;
    int tuaux  = 0;
    char respuesta[100], auxindexof[100];
    Persona *pe;
    turnosurg *turg;
    turnosreg *treg;

    printf("\n");
    ArrayList* lista=al_newArrayList();
     ArrayList* listaturnosurg=al_newArrayList();
     ArrayList* listaturnosreg=al_newArrayList();
      ArrayList* listaturnosaten=al_newArrayList();

    printf("**Array List creado**\n");
    system("pause");

    while(flag)
    {
        opcion = menu();

        system("cls");

        switch(opcion)
        {
        case 1:
            pe=NULL;
            id = id+1;
            turnos = turnos+ 1;
            pe=per_nuevo2(id, turnos);
            lista->add(lista,pe);
            turnosurg* tturg = NULL;
             tturg = malloc(sizeof(turnosurg));
             turnosreg* ttreg = NULL;
             ttreg = malloc(sizeof(turnosreg));

            if(pe->tipoturno== 1)
            {
                 int turno = pe->turno;
                printf(" \n su numero de turno es: %d \n", turno);
                printf("\ y su tipo de turno es urgente\n");
                tturg->turno = pe->turno;
                listaturnosurg->add(listaturnosurg,tturg);

            }
             if(pe->tipoturno== 2)
            {
                printf(" \n su numero de turno es: %d \n", pe->turno);
                printf(" y  su tipo de turno es regular \n");
                ttreg->turno = pe->turno;
                listaturnosreg->add(listaturnosreg,ttreg);
            }

             flag2=1;
                printf("Los datos han sido cargados correctamente\n");
                system("pause");
                system("cls");
                break;

           case 2:
                if(flag2==1)
                {   int sizeArray2 = 0;
                    sizeArray=listaturnosurg->len(listaturnosurg);
                    sizeArray2=listaturnosreg->len(listaturnosreg);
                     turnosatendidos* ttaten = NULL;
                     ttaten = malloc(sizeof(turnosatendidos));
                    if(sizeArray!=0)
                    {
                         turnosurg* taux=listaturnosurg->pop(listaturnosurg,0);
                     if(taux!=NULL)
                    {
                        printf("\n el proximo turno a ser atendido es %d  y es un tramite urgente \n",  taux->turno);
                         ttaten->turno= taux->turno;
                   for(i=0;i<lista->len(lista);i++)
                    {
                        Persona* pAux = lista->get(lista,i);
                        if(pAux->turno == taux->turno)
                        {

                     ttaten->dni= pAux->dni;
                listaturnosaten->add(listaturnosaten,ttaten);
                        }
                    }

                    }
                    }

                    if(sizeArray2!=0 && sizeArray == 0)
                    {
                         turnosreg* taux2=listaturnosreg->pop(listaturnosreg,0);
                     if(taux2!=NULL)
                    {
                        printf("\n el proximo turno a ser atendido es %d  y es un tramite regular\n",  taux2->turno);
                           ttaten->turno=taux2->turno;
                              for(i=0;i<lista->len(lista);i++)
                    {
                        Persona* pAux = lista->get(lista,i);
                        if(pAux->turno == taux2->turno)
                        {

                     ttaten->dni= pAux->dni;
                listaturnosaten->add(listaturnosaten,ttaten);
                        }
                    }
                    }
                    }

                    if(sizeArray == 0 && sizeArray2 == 0)
                    {
                        printf("\n todos los turnos han sido atendidos \n");
                    }
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
                     int sizeArray2 = 0;
                     sizeArray=listaturnosurg->len(listaturnosurg);
                     if(sizeArray!=0)
                    {
                        printf("\n faltan atender %d turnos urgentes y los turnos son:  \n", sizeArray);

                    for(i=0;i<listaturnosurg->len(listaturnosurg);i++)
                    {
                        turnosurg* x = listaturnosurg->get(listaturnosurg,i);

                         for(e=0;e<lista->len(lista);e++)
                    {
                             Persona* pAux = lista->get(lista,e);
                        if(pAux->turno == x->turno)
                        {
                             printf("%d) ",e);
                             Mostrar(pAux);
                        }
                    }
                    }
                    }
                    else
                    {
                        printf(" \n no hay turnos urgentes para atender \n");
                    }

                       sizeArray2=listaturnosreg->len(listaturnosreg);
                    if(sizeArray2!=0)
                  {
                       printf("\n  los turnos regulares que faltan atender son: \n");

                    for(i=0;i<listaturnosreg->len(listaturnosreg);i++)
                    {
                        turnosreg* x = listaturnosreg->get(listaturnosreg,i);

                         for(e=0;e<lista->len(lista);e++)
                    {
                             Persona* pAux = lista->get(lista,e);
                        if(pAux->turno == x->turno)
                        {
                             printf("%d) ",e);
                             Mostrar(pAux);
                        }
                    }
                    }

                  }
                     else
                    {
                        printf("\n no hay turnos regulares para atender \n");
                    }

                   }



                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                system("pause");
                system("cls");
                break;

            case 4:
                     if(flag2==1)
                {
                        printf("\n  no ordenado :\n");
                    for(i=0;i<listaturnosaten->len(listaturnosaten);i++)
                    {
                        turnosatendidos* x = listaturnosaten->get(listaturnosaten,i);
                        printf(" %d) ",i);
                        Mostraratendidos(x);
                    }
                    al_sort(listaturnosaten,ordenodniatendidos,0);
                        printf("\n ordenado :\n");
                    for(i=0;i<listaturnosaten->len(listaturnosaten);i++)
                    {
                        turnosatendidos* x = listaturnosaten->get(listaturnosaten,i);
                        printf(" %d) ",i);
                        Mostraratendidos(x);
                    }
                     sizeArray=listaturnosaten->len(listaturnosaten);
                     if(sizeArray!=0)
                    {
                        printf("\n los turnos urgentes atendidos son: \n", sizeArray);

                    for(i=0;i<listaturnosaten->len(listaturnosaten);i++)
                    {
                        turnosurg* x = listaturnosaten->get(listaturnosaten,i);

                         for(e=0;e<lista->len(lista);e++)
                    {
                             Persona* pAux = lista->get(lista,e);
                        if(pAux->turno == x->turno && pAux->tipoturno == 1)
                        {
                             printf("%d) ",e);
                             Mostrar(pAux);
                        }
                    }
                    }


                       printf("\n los turnos regulares atendidos son: \n");
                       al_sort(listaturnosaten,ordenodniatendidos,0);
                        al_sort(lista,ordenodni,0);
                    for(i=0;i<listaturnosaten->len(listaturnosaten);i++)
                    {
                        turnosurg* x = listaturnosaten->get(listaturnosaten,i);

                         for(e=0;e<lista->len(lista);e++)
                    {
                             Persona* pAux = lista->get(lista,e);
                        if(pAux->turno == x->turno && pAux->tipoturno == 2)
                        {
                             printf("%d) ",e);
                             Mostrar(pAux);
                        }
                    }
                    }


                  }
                     else
                    {
                        printf("\n no hay turnos atendidos\n");
                    }

                   }



                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                system("pause");
                system("cls");
                break;


            /*case 6:
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
                break;*/
            case 12:
                if(flag2==1)
                {

                    printf("\n  no ordenado :\n");
                   for(i=0;i<lista->len(lista);i++)
                    {
                        Persona* pAux = lista->get(lista,i);
                        printf("%d) ",i);
                        Mostrar(pAux);
                    }
                    al_sort(lista,ordenodni,0);
                        printf("\n ordenado :\n");
                    for(i=0;i<lista->len(lista);i++)
                    {
                        Persona* pAux = lista->get(lista,i);
                        printf("%d) ",i);
                        Mostrar(pAux);
                    }
                     printf("\n  los turnos urgentes son: \n");
                    for(i=0;i<listaturnosurg->len(listaturnosurg);i++)
                    {
                        turnosurg* x = listaturnosurg->get(listaturnosurg,i);
                        printf("%d) ",i);
                        Mostrarint(x);
                    }

                    printf("\n  los turnos regulares son: \n");

                    for(i=0;i<listaturnosreg->len(listaturnosreg);i++)
                    {
                        turnosreg* x = listaturnosreg->get(listaturnosreg,i);
                        printf(" %d) ",i);
                        Mostrarint2(x);
                    }
                     printf("\n  los turnos atendidos son: \n");
                    for(i=0;i<listaturnosaten->len(listaturnosaten);i++)
                    {
                        turnosatendidos* x = listaturnosaten->get(listaturnosaten,i);
                        printf(" %d) ",i);
                        Mostraratendidos(x);
                    }
                }
                else
                {
                    printf("\nNo se han cargado datos a la lista anteriormente");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 13:
                flag=0;
                break;
            default:
                printf("\nOpcion incorrecta\n");
                system("pause");
        }
    }

   free(pe);
    lista->deleteArrayList(lista);
    printf("\nSe ha eliminado el ArrayList y se libero la memoria usada\n");

    return 0;
}
