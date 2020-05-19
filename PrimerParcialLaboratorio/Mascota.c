#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "Mascota.h"
#include "utn.h"
#include "Cliente.h"

#define LIBRE 0
#define OCUPADO 1

/** \brief Assign values to all data in the structure in the first 5 positions
 *
 * \param eMascota Array of pets
 * \param int Length of the array
 * \return 5 Pets loaded in the array
 *
 */

void hardcodearMascotas(eMascota lista[], int tamArray)
{
    char nombre[11][51] = {"Alex","Firulais","Rocky","Guardian","Pepe","Fifi","Napoleon","Odin","Thor","Buddy","Lucky"};
    char tipo[11][51] = {"Gato","Gato","Perro","Perro","Gato","Perro","Raro","Perro","Gato","Gato","Perro"};
    eRaza raza[11] = {{"Siames","Tailandia"},{"Persa","Iran"},{"Bulldog","Inglaterra"},{"Poodle","Francia"},{"Persa","Iran"},{"Pitbull","USA"},{"Iguana","Cuba"},{"Labrador","USA"},{"Siames","Tailandia"},{"Persa","Iran"},{"Bulldog","Inglaterra"}};
    int edad[11] = {11,5,3,4,5,6,8,3,3,6,7};
    float peso[11] = {20,20.5,30,40,40.5,32.5,50.5,42.5,30.2,39.4,15.3};
    char sexo[11][51] = {"m","m","m","m","m","m","m","f","f","f","f"};
    int idMascota[11] = {1,2,3,4,5,6,7,8,9,10,11};
    int idCliente[11] = {2,2,1,1,1,5,5,3,4,4,4};
    int estado[11] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;
    for(i=0;i<tamArray;i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].tipo, tipo[i]);
        lista[i].raza = raza[i];
        lista[i].edad = edad[i];
        lista[i].peso = peso[i];
        strcpy(lista[i].sexo, sexo[i]);
        lista[i].idCliente = idCliente[i];
        lista[i].idMascota = idMascota[i];
        lista[i].estado = estado[i];
    }
}

/** \brief Initializes the array state value to 0 in all positions
 *
 * \param eMascota Array of pets
 * \param int Length of the array
 * \return All the state positions of the array in 0
 *
 */

void inicializarArrayMascotas(eMascota lista[], int tamArray)
{
    int i;

    for(i=0;i<tamArray;i++)
    {
        lista[i].estado = LIBRE;
    }

}

/** \brief Creates a pet structure and ask the user for data input
 *
 * \param void No parameters
 * \return It returns a pet structure to be saved
 *
 */

eMascota crearMascota()
{
    eMascota miMascota;

    char auxInt[51];
    char auxFloat[51];

    getInt(&miMascota.idCliente,"\nELIJA ID DEL DUEÑO DE LA MASCOTA: ");

    while(!getStringLetras("\nNombre Mascota: ", miMascota.nombre))
    {
        printf("El nombre debe ser en letras\n");
    }

    while(!getStringLetras("Tipo de mascota (Perro-Gato-Raro): ",miMascota.tipo) || (strcmp(miMascota.tipo,"Perro")&&strcmp(miMascota.tipo,"Gato")&&strcmp(miMascota.tipo,"Raro")!=0))
    {
        printf("El tipo debe ser en Perro, Gato o Raro\n");
    }

    while(!getStringLetras("Nombre de Raza: ",miMascota.raza.nombreRaza))
    {
        printf("La raza debe ser en letras\n");
    }

    while(!getStringLetras("Pais de Raza: ",miMascota.raza.pais))
    {
        printf("La el pais de la raza debe ser en letras\n");
    }

    while(!getStringNumeros("Edad: ",auxInt))
    {
        printf("La edad debe ser numerica\n");
    }
    miMascota.edad = atoi(auxInt);

    while(!getStringNumerosFlotantes("Peso: ", auxFloat))
    {
        printf("El peso debe ser numerico\n");
    }
    miMascota.peso = atof(auxFloat);

    while(!getStringLetras("Sexo (m o f): ",miMascota.sexo) || (strcmp(miMascota.sexo,"m")&&strcmp(miMascota.sexo,"f")))
    {
        printf("El sexo debe ser m o f\n");
    }

    miMascota.estado = OCUPADO;

    return miMascota;
}

/** \brief Find the first occurrence of value 0 within an array
 *
 * \param eMascota Array of pets
 * \param int Size of the array
 * \return Returns the value of the empty index or -1 in case of not finding empty spaces in the array
 *
 */


int buscarIndiceLibreMascota(eMascota lista[], int tamArray)
{
    int indice = -1;
    int i;

    for(i=0;i<tamArray;i++)
    {
        if(lista[i].estado == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


/** \brief Add in a existing list of pets the values received as parameters in the first empty position
 *
 * \param eMascota list of pets
 * \param int size of array
 * \param int id counter of the pet
 * \return A position in the array with all the data created from the user input
 *
 */
void cargarMascota(eMascota lista[], int tamArray, int idMascota)
{

    int indiceLibre;


    indiceLibre = buscarIndiceLibreMascota(lista,tamArray);
    idMascota = indiceLibre + 1;
    if(indiceLibre != -1)
    {
        lista[indiceLibre] = crearMascota();
        lista[indiceLibre].idMascota = idMascota;
        system("clear");
        printf("SE CREO MASCOTA CON EXITO\n");
    }
    else
    {
        system("clear");
        printf("NO HAY MAS ESPACIO\n");
    }
}

/** \brief Remove a pet in by ID
 *
 * \param eMascota list of pets
 * \param int size of array
 * \return Return a message of success if the pet was erased
 *
 */

void eliminarMascota(eMascota lista[], int tamArray)
{
    int i;
    int idABuscar;

    getInt(&idABuscar, "\nID MASCOTA A ELIMINAR: \n");

    for(i=0;i<tamArray;i++)
    {
        if(lista[i].idMascota == idABuscar && lista[i].estado == OCUPADO)
        {
            lista[i].estado = LIBRE;
            system("clear");
            printf("SE ELIMINO MASCOTA CON EXITO\n");
            break;
        }
    }
}

/** \brief Searches for a pet by ID and changes his information
 *
 * \param eMascota list of pets
 * \param int size of array
 * \return A list of the pets data and lets the user pick what it would like to change
 *
 */
void modificarMascota(eMascota lista[], int tamArray)
{
    int i;
    char nombreNuevo[51];
    char tipoNuevo[51];
    eRaza razaNueva[51];
    char sexoNuevo[51];
    int idABuscar;
    int opcion;

    char auxInt[51];
    char auxFloat[51];

    while(!getStringNumeros("\nIngrese ID de la Mascota a modificar: ",auxInt))
    {
        printf("El ID debe ser numerico\n");
    }
    idABuscar = atoi(auxInt);

    for(i=0;i<tamArray;i++)
    {
        if(lista[i].idMascota == idABuscar && lista[i].estado == OCUPADO)
        {
            while(!getStringNumeros("Que desea modificar?\n1.Nombre\n2.Tipo\n3.Raza\n4.Edad\n5.Peso\n6.Sexo\n",auxInt))
            {
               printf("La opcion debe ser numerica\n");
            }
            opcion = atoi(auxInt);

            if(opcion == 1)
            {
                while(!getStringLetras("Ingrese nombre nuevo: ", nombreNuevo))
                {
                    printf("El nombre debe ser en letras\n");
                }
                strcpy(lista[i].nombre,nombreNuevo);
                system("clear");
                printf("SE MODIFICO NOMBRE DE MASCOTA\n");
            }
            if(opcion == 2)
            {
                while(!getStringLetras("Ingrese nuevo tipo (Perro - Gato - Raro): ", tipoNuevo) || (strcmp(tipoNuevo,"Perro")&&strcmp(tipoNuevo,"Gato")&&strcmp(tipoNuevo,"Raro")!=0))
                {
                    printf("El tipo debe ser en Perro, Gato o Raro\n");
                }
                strcpy(lista[i].tipo,tipoNuevo);
                system("clear");
                printf("SE MODIFICO TIPO DE MASCOTA\n");
            }
            if(opcion == 3)
            {
                while(!getStringLetras("Ingrese nombre nueva raza: ", razaNueva->nombreRaza))
                {
                    printf("El nombre de la raza debe ser en letras\n");
                }
                strcpy(lista[i].raza.nombreRaza,razaNueva->nombreRaza);
                while(!getStringLetras("Ingrese pais nueva raza: ", razaNueva->pais))
                {
                    printf("El pais de la raza debe ser en letras\n");
                }
                strcpy(lista[i].raza.pais,razaNueva->pais);
                system("clear");
                printf("SE MODIFICO RAZA DE MASCOTA\n");
            }
            if(opcion == 4)
            {
                while(!getStringNumeros("Ingrese nueva edad: ",auxInt))
                {
                    printf("La edad debe ser numerica\n");
                }
                lista[i].edad = atoi(auxInt);
                system("clear");
                printf("SE MODIFICO EDAD DE MASCOTA\n");
            }
            if(opcion == 5)
            {
                while(!getStringNumerosFlotantes("Ingrese nuevo peso: ",auxFloat))
                {
                    printf("El peso debe ser numerico\n");
                }
                lista[i].peso = atof(auxFloat);
                system("clear");
                printf("SE MODIFICO PESO DE MASCOTA\n");
            }
            if(opcion == 6)
            {
                while(!getStringLetras("Ingrese nuevo sexo (m o f): ",sexoNuevo) || (strcmp(sexoNuevo,"m")&&strcmp(sexoNuevo,"f")))
                {
                    printf("El sexo debe ser m o f\n");
                }
                strcpy(lista[i].sexo,sexoNuevo);
                system("clear");
                printf("SE MODIFICO SEXO DE MASCOTA\n");
            }
            if(opcion < 1 || opcion > 6)
            {
                system("clear");
                printf("INGRESE OPCION CORRECTA\n");
            }
        }
    }
}

/** \brief Sort pets based on their type
 *
 * \param eMascota Array of pets
 * \param int Size of array
 * \return A list of pets depending on the type chosen
 *
 */
void ordenarMascotasPorTipo(eMascota lista[], int tamArray)
{
    int i;
    int j;
    eMascota auxMascota;

    for(i=0;i<tamArray-1;i++)
    {
        for(j=i+1;j<tamArray;j++)
        {
            if (strcmp(lista[i].tipo,lista[j].tipo)>0)
            {
                auxMascota = lista[i];
                lista[i] = lista[j];
                lista[j] = auxMascota;
            }
        }
    }
}

/** \brief Calculate the average age of all pets
 *
 * \param eMascota Array of pets
 * \param int size of array
 * \return The average age value of all pets
 *
 */

void calcularPromedioEdadMascotas(eMascota lista[], int tamArray)
{
    float promedioEdades;
    int sumaEdades = 0;
    int cantidadMascotas = 0;
    int i;

    for(i=0;i<tamArray;i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            sumaEdades = sumaEdades + lista[i].edad;
            cantidadMascotas++;
        }
    }

    promedioEdades = (float)sumaEdades/cantidadMascotas;
    printf("\nEL PROMEDIO DE EDAD DE MASCOTAS ES: %.2f \n", promedioEdades);
}

/** \brief Calculate the average age of all pets for each type
 *
 * \param eMascota Array of pets
 * \param int size of array
 * \return List with the averages of the respective pets for each type
 *
 */

void calcularPromedioEdadPorTipoMascota(eMascota lista[], int tamArray)
{
    int i;
    int contGato = 0;
    int sumaGato = 0;
    int contPerro = 0;
    int sumaPerro = 0;
    int sumaRaro = 0;
    int contRaro = 0;
    float promedioGato;
    float promedioPerro;
    float promedioRaro;

    for(i=0;i<tamArray;i++)
    {
        if(strcmp(lista[i].tipo,"Gato")==0)
        {
            sumaGato = sumaGato + lista[i].edad;
            contGato++;
        }
        if(strcmp(lista[i].tipo,"Perro")==0)
        {
            sumaPerro = sumaPerro + lista[i].edad;
            contPerro++;
        }
        if(strcmp(lista[i].tipo,"Raro")==0)
        {
            sumaRaro = sumaRaro + lista[i].edad;
            contRaro++;
        }
    }

    promedioGato = (float)sumaGato/contGato;
    promedioPerro = (float)sumaPerro/contPerro;
    promedioRaro = (float)sumaRaro/contRaro;

    printf("PROMEDIO DE EDAD MASCOTAS TIPO GATO: %.2f \n", promedioGato);
    printf("PROMEDIO DE EDAD MASCOTAS TIPO PERRO: %.2f \n", promedioPerro);
    printf("PROMEDIO DE EDAD MASCOTAS TIPO RARO: %.2f \n", promedioRaro);
}

/** \brief Show a list of pets by type
 *
 * \param eMascota Array of pets
 * \param int size of array
 * \return A list of pet information depending on the type chosen
 *
 */

void listarMascotasPorTipo(eMascota lista[], int tamArray)
{
    int i;
    int opcion;

    getInt(&opcion,"Tipo: 1.Gato 2.Perro 3.Raro\n");
    switch(opcion)
    {
    case 1:
        printf("\nID\tNOMBRE\tTIPO\tRAZA\tEDAD\tPESO\tSEXO\n");
        printf("-----------------------------------------------------\n");
        for(i=0;i<tamArray;i++)
        {
            if(strcmp(lista[i].tipo,"Gato")==0)
            {
                printf("%2d %11s %5s %7s %7d %7.2f %7s\n",lista[i].idMascota, lista[i].nombre, lista[i].tipo, lista[i].raza.nombreRaza, lista[i].edad, lista[i].peso, lista[i].sexo);
            }
        }
        break;
    case 2:
        printf("\nID\tNOMBRE\tTIPO\tRAZA\tEDAD\tPESO\tSEXO\n");
        printf("-----------------------------------------------------\n");
        for(i=0;i<tamArray;i++)
        {
            if(strcmp(lista[i].tipo,"Perro")==0)
            {
                printf("%2d %11s %5s %7s %7d %7.2f %7s\n",lista[i].idMascota, lista[i].nombre, lista[i].tipo, lista[i].raza.nombreRaza, lista[i].edad, lista[i].peso, lista[i].sexo);
            }
        }
        break;
    case 3:
        printf("\nID\tNOMBRE\tTIPO\tRAZA\tEDAD\tPESO\tSEXO\n");
        printf("-----------------------------------------------------\n");
        for(i=0;i<tamArray;i++)
        {
            if(strcmp(lista[i].tipo,"Raro")==0)
            {
                printf("%2d %11s %5s %7s %7d %7.2f %7s\n",lista[i].idMascota, lista[i].nombre, lista[i].tipo, lista[i].raza.nombreRaza, lista[i].edad, lista[i].peso, lista[i].sexo);
            }
        }
        break;
    default:
        printf("Ingrese opcion correcta (1.Gato - 2.Perro - 3.Raro)\n");
        break;
    }
}
