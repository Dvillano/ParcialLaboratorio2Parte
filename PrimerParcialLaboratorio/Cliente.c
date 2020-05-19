#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <math.h>

#include "Cliente.h"
#include "utn.h"

#define LIBRE 0
#define OCUPADO 1

/** \brief Assign values to all data in the structure in the first 5 positions
 *
 * \param eCliente Array of clients
 * \param int Length of the array
 * \return 5 Clients loaded in the array
 *
 */

void hardcodearClientes(eCliente lista[], int tamArray)
{
    int idCliente[5] = {1,2,3,4,5};
    char nombre[5][51] = {"Juan","Maria","Pedro","Jose","Luisa"};
    char apellido[5][51] = {"Fernandez","Rodriguez","Hernandez","Suarez","Castro"};
    char localidad[5][51] = {"Quilmes","Recoleta","Palermo","Avellaneda","Microcentro"};
    int telefono [5] = {1123459837,112948394,1129384059,1129384384,1120394829};
    int edad[5] = {50,22,34,51,41};
    char sexo[5][51] = {"m","f","m","m","f"};

    int estado[5] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;
    for(i=0;i<tamArray;i++)
    {
        lista[i].idCliente = idCliente[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].apellido,apellido[i]);
        strcpy(lista[i].localidad,localidad[i]);
        lista[i].telefono = telefono[i];
        lista[i].edad = edad[i];
        strcpy(lista[i].sexo, sexo[i]);
        lista[i].estado = estado[i];
    }
}


/** \brief Initializes the array state value to 0 in all positions
 *
 * \param eCliente Array of clients
 * \param int Length of the array
 * \return All the state positions of the array in 0
 *
 */

void inicializarArrayClientes(eCliente lista[], int tamArray)
{
    int i;

    for(i=0;i<tamArray;i++)
    {
        lista[i].estado = LIBRE;
    }
}

/** \brief Show the values of an array
 *
 * \param eCliente Array of clients
 * \param int Size of array
 * \return Returns a table with the data of the array
 *
 */

void mostrarArrayClientes(eCliente lista[], int tamArray)
{
    int i;

    printf("\n--------------------------------LISTA CLIENTES--------------------------------\n\n");
    printf("ID  NOMBRE\tAPELLIDO\tLOCALIDAD\tTELEFONO\tEDAD\tSEXO\n");
    for(i=0;i<tamArray;i++)
    {
        if(lista[i].estado == OCUPADO)
        {

            printf("%2d %7s %13s %16s %14d %11d %7s\n", lista[i].idCliente, lista[i].nombre, lista[i].apellido, lista[i].localidad, lista[i].telefono, lista[i].edad, lista[i].sexo);
        }
    }
}

/** \brief Creates a client structure and ask the user for data input
 *
 * \param void No parameters
 * \return It returns a client structure to be saved
 *
 */

eCliente crearCliente()
{
    eCliente miCliente;
    char auxInt[51];

    while(!getStringLetras("Nombre cliente: ",miCliente.nombre))
    {
        printf("El nombre debe ser en letras\n");
    }

    while(!getStringLetras("Apellido cliente: ",miCliente.apellido))
    {
        printf("El apellido debe ser en letras\n");
    }

    while(!getStringLetras("Localidad: ",miCliente.localidad))
    {
        printf("La localidad debe ser en letras\n");
    }

    while(!getStringNumeros("Telefono: ",auxInt))
    {
        printf("El telefono debe ser en numeros\n");
    }
    miCliente.telefono = atoi(auxInt);

    while(!getStringNumeros("Edad: ",auxInt))
    {
        printf("La edad debe ser en numeros\n");
    }
    miCliente.edad = atoi(auxInt);

    while(!getStringLetras("Sexo (m o f): ",miCliente.sexo) || (strcmp(miCliente.sexo,"m")&&strcmp(miCliente.sexo,"f")))
    {
        printf("El sexo debe ser m o f\n");
    }

    miCliente.estado = OCUPADO;

    return miCliente;
}

/** \brief Find the first occurrence of value 0 within an array
 *
 * \param eCliente Array of clients
 * \param int Size of the array
 * \return Returns the value of the empty index or -1 in case of not finding empty spaces in the array
 *
 */

int buscarIndiceLibreCliente(eCliente lista[], int tamArray)
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

/** \brief Add in a existing list of clients the values received as parameters in the first empty position
 *
 * \param eCliente list of clients
 * \param int size of array
 * \param int id counter of client
 * \return A position in the array with all the data created from the user input
 *
 */

void cargarCliente(eCliente lista[], int tamArray, int idCliente)
{
    int indiceLibre;

    indiceLibre = buscarIndiceLibreCliente(lista,tamArray);
    idCliente = indiceLibre + 1;
    if(indiceLibre != -1)
    {
        lista[indiceLibre] = crearCliente();
        lista[indiceLibre].idCliente = idCliente;
        system("clear");
        printf("SE CREO CLIENTE CON EXITO\n");
    }
    else
    {
        system("clear");
        printf("NO HAY MAS ESPACIO\n");
    }
}

/** \brief Remove a client in by ID
 *
 * \param eCliente list of clients
 * \param int size of array
 * \return Return a message of success if the client was erased
 *
 */

void eliminarClienteEnCascada(eCliente lista[], int tamArray)
{
    int i;
    int idABuscar;
    eCliente auxCliente;

    getInt(&idABuscar, "\nID CLIENTE A ELIMINAR: \n");

    for(i=0;i<tamArray;i++)
    {
        if(lista[i].idCliente == idABuscar && lista[i].estado == OCUPADO)
        {
            lista[i] = auxCliente;
            printf("EL CLIENTE Y SUS DATOS HAN SIDO ELIMINADOS CON EXITO\n");
            break;
        }
    }
}

/** \brief Searches for a client by ID and changes his information
 *
 * \param eCliente list of Clients
 * \param int size of array
 * \return A list of the clients data and lets the user pick what it would like to change
 *
 */

void modificarCliente(eCliente lista[], int tamArray)
{
    int i;
    char nombreNuevo[51];
    char apellidoNuevo[51];
    char localidadNueva[51];
    char sexoNuevo[51];

    int idABuscar;
    int opcion;
    char auxInt[51];

    while(!getStringNumeros("\nIngrese ID del Cliente a modificar: ",auxInt))
    {
        printf("El ID debe ser numerico\n");
    }
    idABuscar = atoi(auxInt);


    for(i=0; i<tamArray; i++)
    {
        if(lista[i].idCliente == idABuscar && lista[i].estado == OCUPADO)
        {
            while(!getStringNumeros("Que desea modificar?\n1.Nombre\n2.Apellido\n3.Localidad\n4.Telefono\n5.Edad\n6.Sexo\n",auxInt))
            {
                printf("La opcion debe ser numerica: \n");
            }
            opcion = atoi(auxInt);

            if(opcion == 1)
            {
                while(!getStringLetras("Ingrese nuevo nombre: ",nombreNuevo))
                {
                    printf("El nombre debe ser en letras\n");
                }
                strcpy(lista[i].nombre,nombreNuevo);
                system("clear");
                printf("SE MODIFICO NOMBRE DE CLIENTE\n");
            }
            if(opcion == 2)
            {
                while(!getStringLetras("Ingrese nuevo apellido: ", apellidoNuevo))
                {
                    printf("El apellido debe ser en letras\n");
                }
                strcpy(lista[i].apellido,apellidoNuevo);
                system("clear");
                printf("SE MODIFICO APELLIDO DE CLIENTE\n");
            }
            if(opcion == 3)
            {
                while(!getStringLetras("Ingrese nueva localidad: ", localidadNueva))
                {
                    printf("La localidad debe ser en letras\n");
                }
                strcpy(lista[i].localidad,localidadNueva);
                system("clear");
                printf("SE MODIFICO LOCALIDAD DE CLIENTE\n");
            }
            if(opcion == 4)
            {
                while(!getStringNumeros("Ingrese nuevo telefono: ", auxInt))
                {
                    printf("El telefono debe contener solo numeros\n");
                }
                lista[i].telefono = atoi(auxInt);
                system("clear");
                printf("SE MODIFICO TELEFONO DE CLIENTE\n");
            }
            if(opcion == 5)
            {
                while(!getStringNumeros("Ingrese edad nueva: ",auxInt))
                {
                    printf("La edad debe contener solo numeros\n");
                }
                lista[i].edad = atoi(auxInt);
                system("clear");
                printf("SE MODIFICO EDAD DE CLIENTE\n");
            }
            if(opcion == 6)
            {
                while(!getStringLetras("Ingrese nuevo sexo (m o f): ", sexoNuevo) || ((strcmp(sexoNuevo,"m") && strcmp(sexoNuevo,"f"))))
                {
                    printf("El sexo debe ser m o f\n");
                }
                strcpy(lista[i].sexo,sexoNuevo);
                system("clear");
                printf("SE MODIFICO SEXO DE CLIENTE\n");
            }
            if(opcion < 1 || opcion > 6)
            {
                system("clear");
                printf("INGRESE OPCION CORRECTA\n");
            }
        }
    }

}

/** \brief Calculate the average value of men and women among all clients
 *
 * \param eCliente list of clients
 * \param int size of array
 * \return Returns the average count of men and the average count of women
 *
 */

void calcularPromedioVaronesYMujeres(eCliente lista[], int tamArray)
{
    float promedioVarones;
    int cantidadVarones = 0;
    int cantidadClientes = 0;

    float promedioMujeres;
    int cantidadMujeres = 0;

    int i;

    for(i=0;i<tamArray;i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            cantidadClientes++;
        }
        if(strcmp(lista[i].sexo,"m")==0)
        {
            cantidadVarones++;
        }
        if(strcmp(lista[i].sexo,"f")==0)
        {
            cantidadMujeres++;
        }
    }

    promedioVarones = (float)(cantidadVarones*100)/cantidadClientes;
    promedioMujeres = (float)(cantidadMujeres*100)/cantidadClientes;
    printf("\nEL PORCENTAJE DE MUJERES ES: %.0f%%\n", round(promedioMujeres));
}

