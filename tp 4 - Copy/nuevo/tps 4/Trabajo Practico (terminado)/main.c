#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include "persona.h"
#include "ArrayList.h"

int main()
{
    system("color 9F");
    int opcion, flag=1, flag2=0, index, sizeArray, i, r, auxindexof2, auxcontains, auxleg, auxedad;
    Persona* persona_nueva = NULL;
    char respuesta[100], auxindexof[100], auxnombre[100], auxape[100], rta='s';

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
                while(rta=='s')
                {
                    printf("\n***CARGA DE DATOS***\n");
                    printf("\nIngrese nombre: ");
                    fflush(stdin);
                    gets(auxnombre);
                    strupr(auxnombre);

                    printf("\nIngrese apellido: ");
                    fflush(stdin);
                    gets(auxape);
                    strupr(auxape);

                    printf("\nIngrese legajo: ");
                    scanf("%d",&auxleg);

                    printf("\nIngrese edad: ");
                    scanf("%d",&auxedad);

                    persona_nueva = per_nuevo(auxedad,auxnombre,auxape,auxleg);
                    lista->add(lista,persona_nueva);

                    printf("\nDesea agregar otra persona a la lista? s/n: ");
                    fflush(stdin);
                    rta = tolower(getche());
                    validar(rta);
                    printf("\n");
                }
                rta = 's';
                flag2 = 1;
                printf("\nLos datos han sido cargados correctamente\n");
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
                    Persona* pAux = lista->get(lista,index);

                    if(pAux!=NULL)
                    {
                        for(i=index;i<lista->len(lista);i++)
                        {
                            printf("\nELEMENTO ENCONTRADO:\n\n");
                            Persona* pAux = lista->get(lista,i);
                            printf("%d) ",i);
                            Mostrar(pAux);
                            system("pause");
                        }
                    }
                    else
                    {
                        printf("\nNo se ingreso un indice correcto");
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
                    auxcontains = 0;
                    printf("\nIngrese el nombre del elemento a buscar: ");
                    fflush(stdin);
                    gets(respuesta);
                    strupr(respuesta);

                    for(i=0;i<lista->len(lista);i++)
                    {
                        if(stricmp(respuesta,lista->pElements[i])==0)
                        {
                            auxcontains = lista->contains(lista,persona_nueva);
                        }
                    }

                    if(auxcontains==1)
                    {
                        printf("\nSe encontro el nombre");
                    }
                    else
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
                    printf("\nIngrese indice de la posicion a pisar: ");
                    scanf("%d",&index);

                    Persona* pAux = lista->get(lista,index);

                    if(pAux!=NULL)
                    {
                        printf("\n\nSe va a pisar el siguiente dato:");
                        printf("\n");

                        for(i=index;i<lista->len(lista);i++)
                        {
                            Persona* pAux = lista->get(lista,i);
                            printf("%d) ",i);
                            Mostrar(pAux);
                        }

                        printf("\n***CARGA DE DATOS DEL ELEMENTO NUEVO***\n");
                        printf("\nIngrese nombre: ");
                        fflush(stdin);
                        gets(auxnombre);
                        strupr(auxnombre);

                        printf("\nIngrese apellido: ");
                        fflush(stdin);
                        gets(auxape);
                        strupr(auxape);

                        printf("\nIngrese legajo: ");
                        scanf("%d",&auxleg);

                        printf("\nIngrese edad: ");
                        scanf("%d",&auxedad);

                        persona_nueva = per_nuevo(auxedad,auxnombre,auxape,auxleg);

                        printf("\nEL DATO HA SIDO CORRECTAMENTE CARGADO\n");
                        printf("\nArrayList actualizado:\n");
                        for(i=0;i<lista->len(lista);i++)
                        {
                            Persona* pAux = lista->get(lista,i);
                            printf("%d) ",i);
                            Mostrar(pAux);
                        }
                    }
                    else
                    {
                        printf("\nNo se ingreso el indice correcto");
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
                    Persona* pAux = lista->get(lista,index);

                    if(pAux!=NULL)
                    {
                        lista->remove(lista,index);
                        printf("\nEl dato ha sido borrado, los nuevos elementos del ArrayList son:\n");
                        for(i=0;i<lista->len(lista);i++)
                        {
                            Persona* pAux = lista->get(lista,i);
                            printf("%d) ",i);
                            Mostrar(pAux);
                        }
                    }
                    else
                    {
                        printf("\nNo se encontro el indice deseado");
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
                    flag2 = 0;
                    rta = 's';
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
                    printf("\nIngrese indice de la posicion a donde se va a copiar el elemento nuevo (datos anteriores se moveran de posicion): ");
                    scanf("%d",&index);

                    Persona* pAux = lista->get(lista,index);

                    if(pAux!=NULL)
                    {
                        printf("\n\nSe va a pisar el siguiente dato:");
                        printf("\n");

                        for(i=index;i<lista->len(lista);i++)
                        {
                            Persona* pAux = lista->get(lista,i);
                            printf("%d) ",i);
                            Mostrar(pAux);
                        }

                        printf("\n***CARGA DE DATOS DEL ELEMENTO NUEVO***\n");
                        printf("\nIngrese nombre: ");
                        fflush(stdin);
                        gets(auxnombre);
                        strupr(auxnombre);

                        printf("\nIngrese apellido: ");
                        fflush(stdin);
                        gets(auxape);
                        strupr(auxape);

                        printf("\nIngrese legajo: ");
                        scanf("%d",&auxleg);

                        printf("\nIngrese edad: ");
                        scanf("%d",&auxedad);

                        persona_nueva = per_nuevo(auxedad,auxnombre,auxape,auxleg);
                        lista->push(lista,index,persona_nueva);

                        printf("\nEL DATO HA SIDO CORRECTAMENTE CARGADO\n");
                        printf("\nArrayList actualizado:\n");

                        for(i=0;i<lista->len(lista);i++)
                        {
                            Persona* pAux = lista->get(lista,i);
                            printf("%d) ",i);
                            Mostrar(pAux);
                        }
                    }
                    else
                    {
                        printf("\nEl indice a donde se quiere mover el elemento no existe");
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
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
                        if(stricmp(auxindexof,lista->pElements[i])==0)
                        {
                            auxindexof2 = lista->indexOf(lista,(lista->get(lista,i)));
                            printf("El indice encontrado en el elemento ingresado es: %d",auxindexof2);
                            break;
                        }
                        else
                        {
                            printf("\nEl nombre ingresado no existe en ninguno de los elementos");
                        }
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos a la lista anteriormente");
                }
                printf("\n");
                system("pause");
                break;
            case 10:
                if(lista->isEmpty(lista))
                {
                    printf("La lista se encuentra vacia");
                }
                else
                {
                    printf("La lista contiene elementos cargados");
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
                        printf("\nError, el indice ingresado es incorrecto");
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
                    printf("Arraylist:\n\n");
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

    lista->deleteArrayList(lista);
    printf("\nSe ha eliminado el ArrayList y se libero la memoria usada\n");

    return 0;
}
