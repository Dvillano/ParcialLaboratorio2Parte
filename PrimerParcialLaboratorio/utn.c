#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "Cliente.h"
#include "Mascota.h"

#define LIBRE 0
#define OCUPADO 1

/**
 * \brief Request a number from the user and return the result
 * \param Message to be displayed
 * \return The integer number entered by the user
 *
 */
int getInt(int* pInput, char mensaje[])
{
    int retorno = -1;
    int aux;

    if(pInput != NULL)
    {
        printf("%s", mensaje);
        scanf("%d", &aux);
        *pInput = aux;
        retorno = 0;
    }

    return retorno;
}

/** \brief Creates a menu with options
 *
 * \param void No parameters
 * \return A menu with a list of options
 *
 */

void menu()
{
    printf("\n------MENU VETERINARIO------\n\n");
    printf("(1) LISTA CLIENTES\n");
    printf("(2) LISTA MASCOTA\n");
    printf("(3) LISTA CLIENTES CON MASCOTA\n");
    printf("(4) ALTA MASCOTA\n");
    printf("(5) ELIMINAR MASCOTA\n");
    printf("(6) MODIFICAR MASCOTA\n");
    printf("(7) CARGAR CLIENTE\n");
    printf("(8) ELIMINAR CLIENTE Y SUS MASCOTAS\n");
    printf("(9) LISTA DE MASCOTAS ORDENADA POR TIPO\n");
    printf("(10) MODIFICAR CLIENTES\n");
    printf("(11) LISTAR CLIENTES CON MAS DE UNA MASCOTA\n");
    printf("(12) LISTAR MASCOTAS CON MAS DE TRES AÑOS\n");
    printf("(13) LISTAR A LAS MASCOTAS POR TIPO\n");
    printf("(14) LISTAR DUEÑOS ORDENADOS POR CANTIDAD DE MASCOTAS\n");
    printf("(15) LISTAR DUEÑOS ORDENADOS POR CANTIDAD DE MASCOTAS Y ORDEN ALFABETICO\n");
    printf("(16) PROMEDIO DE EDAD ENTRE MASCOTAS\n");
    printf("(17) PROMEDIO DE EDAD MASCOTAS POR TIPO\n");
    printf("(18) PORCENTAJE DE MUJERES SOBRE EL TOTAL DE CLIENTES\n");
    printf("(19) SALIR\n");
    printf("\n-----------------------\n");

}

/**
 * \brief Request a number from the user and return the result
 * \param Message to be displayed
 * \return The floating point number entered by the user
 *
 */
float getFloat(float* pInput, char mensaje[])
{
    int retorno = -1;
    float aux;

    if(pInput != NULL)
    {
        printf("%s", mensaje);
        scanf("%f", &aux);
        *pInput = aux;
        retorno = 0;
    }

    return retorno;
}

/**
 * \brief Request a text from the user and return it
 * \param The message to be displayed
 * \param Array where the entered text will be loaded
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


/**
 * \brief Check if the received value contains only letters
 * \param str Array with the string to be parsed
 * \return 1 if it contains only '' and letters and 0 if it is not
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Request a text from the user and return it
 * \param  It is the message to be displaye
 * \param input Array where the entered text will be loaded
 * \return 1 if the text contains only letters
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Check if the received value is numeric
 * \param str Array with the string to be parsed
 * \return 1 if it is numeric and 0 if it is not
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Prompts the user for a numeric text and returns it
 * \param mensaje  message to be displayed
 * \param input Array where the entered text will be loaded
 * \return 1 if the text contains only numbers
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Verify if the received value is numeric accepting floats
 * \param str Array with the string to be parsed
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Prompts the user for a numeric text and returns it (accepts floats))
 * \param mensaje message to be displayed
 * \param input Array where the entered text will be loaded
 * \return 1 if the text contains only numbers
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
