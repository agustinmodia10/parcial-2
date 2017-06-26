#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int aux;
    printf("%s", mensaje);
    scanf("%d", &aux);
    return aux;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[])
{
   int i = 0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido sea float
 * \param str Array con la cadena a ser analizada
 * \return 1 si es float y 0 si no lo es
 *
 */
int esFloat(char str[])
{
   int i = 0;
   while(str[i] != '\0')
   {
       if((str[i] < '0' || str[i] > '9') && str[i] != '.')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i = 0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esSoloLetras(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo float
 */
int getStringFloat(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esFloat(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie)
{
    FILE *parch;

    parch = fopen("datos.dat", "rb+");

    if(parch == NULL) /**< Si no existe, lo abro en modo w para crearlo */
    {
        parch = fopen("datos.dat", "wb+");
        if(parch == NULL)
        {
            recuadroStr("Error al abrir el archivo.");
            return -1;
        }
    }

    /**< ESCRITURA */
    fseek(parch, 0L, SEEK_END); /**< Escribo al final del archivo */
    fwrite(&movie, sizeof(movie), 1, parch);

    return fclose(parch);
}

/** \brief Realiza todos los pasos para agregar una pelicula al archivo
 *
 * \return
 *
 */
void agregar ()
{
    EMovie pelicula;

    char auxTituloStr[50], auxGeneroStr[30], auxPuntajeStr[5], auxDuracionStr[5], auxLinkStr[250], auxDescripcionStr[400];
    int auxPuntaje, auxDuracion;

    /**< TITULO */
    getString("Ingrese el titulo: ", auxTituloStr);
    if(strlen(auxTituloStr) > 49) /**< Verifico que la longitud no sea mayor a 49 caracteres */
    {
        recuadroStr("El titulo no puede ser mas largo que 49 caracteres.");
        return;
    }

    /**< GENERO */
    getString("Ingrese el genero: ", auxGeneroStr);
    if(strlen(auxGeneroStr) > 29) /**< Verifico que la longitud no sea mayor a 29 caracteres */
    {
        recuadroStr("El genero no puede ser mas largo que 29 caracteres.");
        return;
    }

    /**< PUNTAJE */
    if(!getStringNumeros("Ingrese el puntaje entre 0 y 100 : ",auxPuntajeStr))/**< Verifica que sean solo numeros lo que se ingresa. */
    {
        recuadroStr("El puntaje no puede contener caracteres que no sean numeros.");
        return;
    }
    auxPuntaje = atoi(auxPuntajeStr);

    if((auxPuntaje < 0) || (auxPuntaje > 100))/**< Valido que el puntaje este entre 0 y 100 */
    {
        recuadroStr("El puntaje no puede ser menor a 0 ni mayor a 100.");
        return;
    }

    /**< DURACION */
    if(!getStringNumeros("Ingrese la duracion en minutos entre 0 y 300 : ",auxDuracionStr))/**< Verifica que sean solo numeros lo que se ingresa. */
    {
        recuadroStr("La duracion no puede contener caracteres que no sean numeros.");
        return;
    }
    auxDuracion = atoi(auxDuracionStr);

    if((auxDuracion < 0) || (auxDuracion > 300))/**< Valido que la duracion este entre 0 y 300 */
    {
        recuadroStr("La duracion no puede ser menor a 0 ni mayor a 300.");
        return;
    }

    /**< LINK */
    getString("Ingrese el link: ", auxLinkStr);
    if(strlen(auxLinkStr) > 249) /**< Verifico que la longitud no sea mayor a 249 caracteres */
    {
        recuadroStr("El link no puede ser mas largo que 249 caracteres.");
        return;
    }

    /**< DESCRIPCION */
    getString("Ingrese la descripcion: ", auxDescripcionStr);
    if(strlen(auxDescripcionStr) > 399) /**< Verifico que la descripcion no sea mayor a 399 caracteres */
    {
        recuadroStr("La descripcion no puede ser mas larga que 399 caracteres.");
        return;
    }

    /**< CARGO DATOS */
    /**< Si llego hasta esta parte, significa que no hubo ningun error.*/
    /**< Paso de las variables auxiliares a mi estructura. */
    strcpy(pelicula.titulo, auxTituloStr);
    strcpy(pelicula.genero, auxGeneroStr);
    strcpy(pelicula.linkImagen, auxLinkStr);
    strcpy(pelicula.descripcion, auxDescripcionStr);
    pelicula.puntaje = auxPuntaje;
    pelicula.duracion = auxDuracion;
    pelicula.estado = 1;/**< Cambio el estado a 1 para representar que esta ocupado */

    /**< AGREGO LA PELICULA */
    if(agregarPelicula(pelicula) == 0)
    {
        recuadroStr("pelicula agregada exitosamente.");
    }
    else
    {
        recuadroStr("Hubo un problema. No se agrego la pelicula.");
    }

    return;
}

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie, FILE *pArchBin)
{
    fseek(pArchBin, (-1)*sizeof(EMovie), SEEK_CUR);/**< Lo pongo en el principio del registro que modifico */
    return fwrite(&movie, sizeof(EMovie), 1, pArchBin);
}


/** \brief Realiza todos los pasos para borrar logicamente a una pelicula del archivo
 *
 * \return
 *
 */
void borrar()
{
    FILE *pArchBin;
    EMovie pelicula;
    char auxTituloStr[50];

    /**< TITULO */
    getString("Ingrese el titulo a buscar: ", auxTituloStr);
    if(strlen(auxTituloStr) > 49) /**< Verifico que la longitud no sea mayor a 49 caracteres */
    {
        recuadroStr("El titulo no puede ser mas largo que 49 caracteres.");
        return;
    }

    /**< ABRO EL ARCHIVO BINARIO */
    pArchBin = fopen("datos.dat", "rb+");
    if(pArchBin == NULL)
    {
        recuadroStr("Error al abrir el archivo.");
        return;
    }

    /**< BUSCO EN EL ARCHIVO */
    while(!feof(pArchBin))/**< si llega al final devuelve un 1 */
    {
        fread(&pelicula, sizeof(EMovie), 1, pArchBin);/**< En el caso de que el estado sea 0, la proxima vez va a pisar la estructura */
        if(pelicula.estado == 1) /**< Solo compara en los que no estan borrados  */
        {
           if(strcmp(pelicula.titulo, auxTituloStr) == 0)
            {
                pelicula.estado = 0;
                if(borrarPelicula(pelicula, pArchBin))/**< Le paso mi estructura y la modifica en el archivo */
                {
                    recuadroStr("Pelicula borrada exitosamente.");
                }
                else
                {
                    recuadroStr("Ocurrio un error al borrar la pelicula");
                }
                fclose(pArchBin);
                return;
            }
        }
    }

    recuadroStr("No se encontro la pelicula.");
    fclose(pArchBin);
    return;
}

/** \brief Permite modificar cada campo de la pelicula
 *
 * \param *pMovie La estructura de la pelicula a modificar
 * \return
 *
 */
void modificarPelicula(EMovie *pMovie)
{
    char seguir = 's';
    int opcion = 0;
    char auxTituloStr[50], auxGeneroStr[30], auxPuntajeStr[5], auxDuracionStr[5], auxLinkStr[250], auxDescripcionStr[400];
    int auxPuntaje, auxDuracion;

    printf("\nIndique campo a modificar:\n\n");
    while(seguir == 's')
    {
        printf("1- Titulo: %s\n", pMovie->titulo);
        printf("2- Genero: %s\n", pMovie->genero);
        printf("3- Puntaje: %d\n", pMovie->puntaje);
        printf("4- Duracion: %d\n\n", pMovie->duracion);
        printf("5- Link: %s\n\n", pMovie->linkImagen);
        printf("6- Descripcion: %s\n", pMovie->descripcion);
        printf("\n7- Salir\n");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                /**< TITULO */
                getString("Ingrese el titulo: ", auxTituloStr);
                if(strlen(auxTituloStr) > 49) /**< Verifico que la longitud no sea mayor a 49 caracteres */
                {
                    recuadroStr("El titulo no puede ser mas largo que 49 caracteres.");
                    break;
                }

                strcpy(pMovie->titulo, auxTituloStr);
                recuadroStr("Campo modificado exitosamente");
                break;
            case 2:
                /**< GENERO */
                getString("Ingrese el genero: ", auxGeneroStr);
                if(strlen(auxGeneroStr) > 29) /**< Verifico que la longitud no sea mayor a 29 caracteres */
                {
                    recuadroStr("El genero no puede ser mas largo que 29 caracteres.");
                    break;
                }

                strcpy(pMovie->genero, auxGeneroStr);
                recuadroStr("Campo modificado exitosamente");
                break;
            case 3:
                /**< PUNTAJE */
                if(!getStringNumeros("Ingrese el puntaje: ",auxPuntajeStr))/**< Verifica que sean solo numeros lo que se ingresa. */
                {
                    recuadroStr("El puntaje no puede contener caracteres que no sean numeros.");
                    break;
                }
                auxPuntaje = atoi(auxPuntajeStr);

                if((auxPuntaje < 0) || (auxPuntaje > 100))/**< Valido que el puntaje este entre 0 y 100 */
                {
                    recuadroStr("El puntaje no puede ser menor a 0 ni mayor a 100.");
                    break;
                }

                pMovie->puntaje = auxPuntaje;
                recuadroStr("Campo modificado exitosamente");
                break;
            case 4:
                /**< DURACION */
                if(!getStringNumeros("Ingrese la duracion: ",auxDuracionStr))/**< Verifica que sean solo numeros lo que se ingresa. */
                {
                    recuadroStr("La duracion no puede contener caracteres que no sean numeros.");
                    break;
                }
                auxDuracion = atoi(auxDuracionStr);

                if((auxDuracion < 0) || (auxDuracion > 300))/**< Valido que la duracion este entre 0 y 300 */
                {
                    recuadroStr("La duracion no puede ser menor a 0 ni mayor a 300.");
                    break;
                }

                pMovie->duracion = auxDuracion;
                recuadroStr("Campo modificado exitosamente");
                break;
            case 5:
                /**< LINK */
                getString("Ingrese el link: ", auxLinkStr);
                if(strlen(auxLinkStr) > 249) /**< Verifico que la longitud no sea mayor a 249 caracteres */
                {
                    recuadroStr("El link no puede ser mas largo que 249 caracteres.");
                    break;
                }

                strcpy(pMovie->linkImagen, auxLinkStr);
                recuadroStr("Campo modificado exitosamente");
                break;
            case 6:
                /**< DESCRIPCION */
                getString("Ingrese la descripcion: ", auxDescripcionStr);
                if(strlen(auxDescripcionStr) > 399) /**< Verifico que la descripcion no sea mayor a 399 caracteres */
                {
                    recuadroStr("La descripcion no puede ser mas larga que 399 caracteres.");
                    break;
                }

                strcpy(pMovie->descripcion, auxDescripcionStr);
                recuadroStr("Campo modificado exitosamente");
                break;
            case 7:
                seguir = 'n';
                break;
            default:
                recuadroStr("Por favor, ingrese una opcion correcta.");

        }
    }
    return;
}

/** \brief Realiza todos los pasos necesarios para modificar una pelicula
 *
 * \return
 *
 */
void modificar()
{
    FILE *pArchBin;
    EMovie pelicula;
    char auxTituloStr[50];

    /**< TITULO */
    getString("Ingrese el titulo a modificar: ", auxTituloStr);
    if(strlen(auxTituloStr) > 49) /**< Verifico que la longitud no sea mayor a 49 caracteres */
    {
        recuadroStr("El titulo no puede ser mas largo que 49 caracteres.");
        return;
    }

    /**< ABRO EL ARCHIVO BINARIO */
    pArchBin = fopen("datos.dat", "rb+");
    if(pArchBin == NULL)
    {
        recuadroStr("Error al abrir el archivo.");
        return;
    }

    /**< BUSCO EN EL ARCHIVO */
    while(!feof(pArchBin))/**< si llega al final devuelve un 1 */
    {
        fread(&pelicula, sizeof(EMovie), 1, pArchBin);/**< En el caso de que el estado sea 0, la proxima vez va a pisar la estructura */
        if(pelicula.estado == 1) /**< Solo compara en los que no estan borrados  */
        {
           if(strcmp(pelicula.titulo, auxTituloStr) == 0)
            {
                modificarPelicula(&pelicula);
                if(borrarPelicula(pelicula, pArchBin))
                {
                    recuadroStr("Pelicula modificada exitosamente.");
                }
                else
                {
                    recuadroStr("Ocurrio un error al modificar la pelicula");
                }
                fclose(pArchBin);
                return;
            }
        }
    }

    recuadroStr("No se encontro la pelicula.");
    fclose(pArchBin);
    return;
}

/** \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 * \param pelicula estructura que va a ser agregada al html
 * \param cantidad es la cantidad de peliculas.
 * \param nombre el nombre para el archivo.
 * \return
 *
 */
void generarPagina(EMovie pelicula[], int cantidad, char nombre[])
{
    FILE *parch;
    EMovie *pMovie;
    int i;

    pMovie = pelicula;

    /**< TEXTO FIJO */
    char textoFijo1[] = "<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n    <!--[if lt IE 9]>\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>\n\n\n			";
    char textoFijo2[] = "<!-- Repetir esto para cada pelicula -->\n            <article class='col-md-4 article-intro'>\n                <a href='#'>\n                    <img class='img-responsive img-rounded' src='";
    char textoFijo3[] = "' alt=''>\n                </a>\n                <h3>\n                    <a href='#'>";
    char textoFijo4[] = "</a>\n                </h3>\n				<ul>\n					<li>G&#233nero: ";
    char textoFijo5[] = "</li>\n					<li>Puntaje: ";
    char textoFijo6[] = "</li>\n					<li>Duraci&#243n: ";
    char textoFijo7[] = "</li>\n				</ul>\n                <p>";
    char textoFijo8[] = "</p>\n            </article>\n			<!-- Repetir esto para cada pelicula -->\n";
    char textoFijo9[] = "        </div>\n        <!-- /.row -->\n    </div>\n    <!-- /.container -->\n    <!-- jQuery -->\n    <script src='js/jquery-1.11.3.min.js'></script>\n    <!-- Bootstrap Core JavaScript -->\n    <script src='js/bootstrap.min.js'></script>\n	<!-- IE10 viewport bug workaround -->\n	<script src='js/ie10-viewport-bug-workaround.js'></script>\n	<!-- Placeholder Images -->\n	<script src='js/holder.min.js'></script>\n</body>\n</html>";

    if((parch = fopen(nombre, "w+")) == NULL) ///**< Se abre en modo escritura */
    {
        recuadroStr("El archivo HTML no puede ser generado.");
        return;
    }

    fprintf(parch, "%s", textoFijo1);
    for(i = 0; i < cantidad; i++)/**< Repite esta parte por cada pelicula */
    {
        fprintf(parch, "%s%s%s%s%s%s%s%d%s%d%s%s%s", textoFijo2, (pMovie+i)->linkImagen, textoFijo3, (pMovie+i)->titulo, textoFijo4, (pMovie+i)->genero, textoFijo5, (pMovie+i)->puntaje, textoFijo6, (pMovie+i)->duracion, textoFijo7, (pMovie+i)->descripcion, textoFijo8);
    }
    fprintf(parch, "%s", textoFijo9);

    fclose(parch);
    return;

}

/** \brief Realiza todas las tareas para pasar del archivo binario a generar el archivo de texto html
 *
 * \return
 *
 */
void generar ()
{
    FILE *pArchBin;
    EMovie *pArrayPelicula, *pAuxPelicula;
    int cont = 0;

    pArrayPelicula = (EMovie *) malloc(sizeof(EMovie)); /**< Le asigno una porcion de memoria dinamicamente */

    pAuxPelicula = pArrayPelicula;

    pArchBin = fopen("datos.dat", "rb+");
    if(pArchBin == NULL)
    {
        recuadroStr("Error al abrir el archivo.");
        return;
    }

    fread(pArrayPelicula+cont, sizeof(EMovie), 1, pArchBin);
    if((pArrayPelicula+cont)->estado == 1)
    {
        cont++;
    }
    while(!feof(pArchBin))/**< si llega al final devuelve un 1 */
    {
        /**< Reestructuro el espacio asignado dinamicamente */
        pAuxPelicula = (EMovie *) realloc(pArrayPelicula, sizeof(EMovie) * (cont+1) );/**< Hago cont+1 para que crezca una vez mas el bloque */
        if(pAuxPelicula != NULL)
        {
            pArrayPelicula = pAuxPelicula;
        }
        else
        {
            recuadroStr("NO QUEDA MEMORIA");
            return;
        }
        fread(pArrayPelicula+cont, sizeof(EMovie), 1, pArchBin);/**< En el caso de que el estado sea 0, la proxima vez va a pisar la estructura */
        if((pArrayPelicula+cont)->estado == 1)
        {
            cont++;
        }
    }

    generarPagina(pArrayPelicula, cont, "index.html");

    free(pArrayPelicula);
    fclose(pArchBin);
    recuadroStr("Pagina generada exitosamente");
    ShellExecute(GetDesktopWindow(), "open", "index.html", NULL, NULL, SW_SHOWMAXIMIZED);/**< Abre la pagina en el explorador */
    return;
}

/** \brief Muestra una cadena de caracteres con un recuadro
 *
 * \param cadena La cadena a mostrar
 * \return
 *
 */
void recuadroStr(char cadena[])
{
    int length = strlen(cadena), i;

    printf("\n\n");
    for(i = 0; i < (length + 4); i++)
    {
        printf("-");
    }
    printf("\n| %s |", cadena);
    printf("\n");
    for(i = 0; i < (length + 4); i++)
    {
        printf("-");
    }
    printf("\n");
    return;
}
/** \brief Muestra una cadena de caracteres con un recuadro en la portada
 *
 * \param cadena La cadena a mostrar
 * \return
 *
 */
void recuardoportada(char cadena[])
{
    int length = strlen(cadena), i;

    for(i = 0; i < (length + 4); i++)
    {
        printf("-");
    }
    printf("\n| %s |", cadena);
    printf("\n");
    for(i = 0; i < (length + 4); i++)
    {
        printf("-");
    }
    printf("\n\n\n");
    return;
}
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

