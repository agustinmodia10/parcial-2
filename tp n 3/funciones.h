#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[30];
    int duracion;
    char descripcion[400];
    int puntaje;
    char linkImagen[250];
    int estado;
}EMovie;

int getInt(char mensaje[]);

int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esFloat(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringFloat(char mensaje[],char input[]);

void agregar (void);
int agregarPelicula(EMovie movie);

void generar (void);
void generarPagina(EMovie lista[], int cantidad, char nombre[]);

void borrar (void);
int borrarPelicula(EMovie movie, FILE *pArchBin);

void modificar (void);
void modificarPelicula(EMovie *pMovie);

void recuadroStr(char cadena[]);
void recuardoportada(char cadena[]);

/** \brief  valida maximo
 *
 * \param min
 * \param max
 * \return val
 *
 */

int vM(int minimo, int maximo);

#endif // FUNCIONES_H_INCLUDED
