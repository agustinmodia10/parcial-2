#include "funcmodiaTP2.h"
#define num 20
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
/** \brief valida respuesta
 *
 * \param resp
 * \param
 * \return resp
 *
 */

char vRta(char resp)
{
    resp = tolower(getche());

    while(resp != 'y' && resp != 'n')
    {
        printf("\n  ERROR, ingrese nuevamente(y=si/n=no): ");
        resp = tolower(getche());
    }
    return resp;

}
/** \brief inicializa las variables en 0
 *
 * \param iper people[]
 * \param
 * \return 0
 *
 */

void inicio(iper people[])
{
    int e;
    for(e = 0; e < num; e++)
    {
        strcpy(people[e].name, "\0");
        people[e].doc = 0;
        people[e].age = 0;
        people[e].es = 0;
    }

}
/** \brief verifica espacio libre
 *
 * \param iper people[]
 * \param
 * \return oel
 *
 */


int oelibre(iper people[])
{
    int oel = -1, e;

	for(e = 0; e < num ; e++)
    {
        if(people[e].es == 0)
        {
            oel = e;
            break;
	    }
    }

	return oel;

}
/** \brief verifica alta del usuario
 *
 * \param iper people[]
 * \param
 * \return ups
 *
 */


void ups(iper people[])
{
    int e, l, oel, enc = 0;
    long int auxa;
    char auxname[100];

    oel = oelibre(people);

    if(oel != -1)
    {
        printf("  INGRESE DATOS: \n");

        printf("\n  Ingrese DNI entre 1000000, 90000000 : ");
        auxa = vM(1000000, 90000000);

        for(e = 0; e < num; e++)
        {
            if(auxa == people[e].doc)
            {
                enc = 1;
                break;
            }
        }

        if(!enc)
		{
            people[oel].doc = auxa;

		    printf("\n  Ingrese nombre: ");
		    fflush(stdin);
            gets(auxname);

            while(strlen(auxname) > 49)
            {
                printf("\n  ERROR, puede ingresar hasta 49 caracteres: ");
                fflush(stdin);
                gets(auxname);
            }

            strlwr(auxname);
            auxname [0] = toupper(auxname[0]);

            for( l = 0; l < 50; l++)
            {
                if(auxname[l] == ' ')
                {
                    auxname [ l + 1] = toupper(auxname[l + 1]);
                }
            }


            strcpy(people[oel].name, auxname);

            printf("\n  Ingrese edad: ");
            people[oel].age = vM(1, 99);

            people[oel].es = 1;

		}

		else
		{
			printf("\n  El DNI ingresado ya existe, ingrese otro.  \n\n");
			system("pause");
			system("cls");
		}


    }

    else
    {
        printf("\n  no hay mas espacio \n\n\n");
        system("pause");
    }



}

/** \brief borra usuario
 *
 * \param iper people[]
 * \param
 * \return clears
 *
 */


void clears(iper people[])
{
    long int auxb;
    int e, flagi = 0;
    char resp = 'y';

         /*/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */


    printf("\n  Ingrese DNI entre 1000000, 90000000 de la persona que desea borrar: ");
    auxb = vM(1000000, 90000000);

    for(e = 0; e < num; e++)
    {
        if(auxb == people[e].doc)
        {
            printf("\n  DATOS:  \n");
            printf("\n  Nombre: %s\n  DNI: %ld\n  Edad: %d\n", people[e].name,people[e].doc, people[e].age);
            printf("\n  Desea elminiar esta persona? (y=si/n=no) ");
            resp = vRta(resp);

            if(resp == 'y')
            {
                strcpy(people[e].name, "\0");
                people[e].doc = 0;
                people[e].age = 0;
                people[e].es = 0;

                printf("\n  Persona eliminada. \n\n\n");
            }
            else
			{
				printf("\n  La persona no fue eliminada. \n\n\n");
				system("pause");
			}
			flagi = 1;
			break;

        }
    }

    if(flagi == 0)
    {
        printf("\n  DNI inexistente. \n\n\n");
        system("  pause");
    }


}

/** \brief muestra lista
 *
 * \param iper people[]
 * \param
 * \return lista
 *
 */

void lista(iper people[])
{
    int e,l;
	iper auxpeople;

	for(e = 0; e < num - 1; e++)
    {
        for(l = e + 1; l < num; l++)
        {
            if(strcmp(people[e].name, people[l].name) > 0)
			{
				auxpeople = people[e];
				people[e] = people[l];
				people[l] = auxpeople;
			}
        }
    }

    for(e = 0; e < num; e++)
	{
        if(people[e].es != 0)
        {
            printf("\n  Nombre: %s\n  DNI: %ld\n  Edad: %d\n", people[e].name, people[e].doc, people[e].age);
        }

    }


}
/** \brief muestra el grafico pedido
 *
 * \param iper people[]
 * \param
 * \return grafico
 *
 */


void grafico(iper people[])
{
    int e, m18 = 0, entre19y35 = 0, more35 = 0, flage = 0, more;

    for(e = 0; e < num; e++)
    {

        if(people[e].age > 35)
        {
            more35++;
        }
        else
        {
            if(people[e].age > 18 && people[e].age <= 35)
            {
                entre19y35++;
            }
            else
            {
                if(people[e].age > 0 && people[e].age <= 18)
                {
                    m18++;
                }
            }
        }
    }


    if(m18 >= entre19y35 && m18 >= more35)
    {
        more = m18;
    }
    else
        {
            if(entre19y35 >= m18 && entre19y35 >= more35)
            {
                more = entre19y35;
            }
            else
                {
                    more = more35;
                }
        }

    for(e = more; e > 0; e--)
    {
        if(e < num)
        {
            printf("  %02d|", e);
        }
        else
        {
            printf("  %02d|", e);
        }


        if(e <= m18)
        {
            printf(" *");
        }

        if(e <= entre19y35)
        {
            flage = 1;
            printf("\t    *");
        }

        if(e <= more35)
        {
            if(flage == 0)
            {
                printf("\t\t  *");
            }

            if(flage == 1)
            {
                printf("\t  *");
            }

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("  --+-----------------");
    printf("\n    |<18  19-35  >35\n");
    printf("\n      %d     %d \t  %d  \n\n", m18, entre19y35, more35);
    system("pause");
    system("cls");





}

