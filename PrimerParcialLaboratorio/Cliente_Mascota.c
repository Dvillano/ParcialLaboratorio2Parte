#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "utn.h"
#include "Cliente.h"
#include "Mascota.h"
#include "Cliente_Mascota.h"

#define TCLIENTES 10
#define TMASCOTAS 20

#define LIBRE 0
#define OCUPADO 1

/** \brief  Show ist of pets with their owners
 *
 * \param eMascota array of pets
 * \param int size of array of pets
 * \param eCliente array of clients
 * \param int size of array of clients
 * \return It shows the information of the pets and to which owner they belong
 *
 */

void mostrarMascotasConClientes(eMascota listaDeMascotas[], int tamArrayMascotas, eCliente listaDeClientes[], int tamArrayClientes)
{
    int i;
    int j;

    printf("\n--------------------------------LISTA MASCOTAS--------------------------------\n\n");
    printf("ID\tNOMBRE\tTIPO\t   RAZA\tEDAD\tPESO\tSEXO\tCLIENTE\n");
    for(i=0; i<tamArrayMascotas; i++)
    {

        for(j=0; j<tamArrayClientes; j++)
        {
            if(listaDeMascotas[i].idCliente == listaDeClientes[j].idCliente && (listaDeMascotas[i].estado == OCUPADO))
            {
                printf("%2d %11s %5s %10s %4d %7.2f %7s %10s\n", listaDeMascotas[i].idMascota, listaDeMascotas[i].nombre, listaDeMascotas[i].tipo, listaDeMascotas[i].raza.nombreRaza, listaDeMascotas[i].edad, listaDeMascotas[i].peso, listaDeMascotas[i].sexo, listaDeClientes[j].nombre);
            }
        }
    }
}


/** \brief Shows list of clients and all the pets that are owned by the client
 *
 * \param eMascota array of pets
 * \param int size of array of pets
 * \param eCliente array of clients
 * \param int size of array of clients
 * \return A list of the pet information for each owner
 *
 */

void mostrarClientesConMascotas(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas)
{
    int i;
    int j;

    printf("\n ---------------------------CLIENTES Y SUS MASCOTAS---------------------------\n\n");
    for(i=0;i<tamArrayClientes;i++)
    {
        if(listaDeClientes[i].estado == OCUPADO)
        {
            printf("\n\t---------------------CLIENTE: %s %s-----------------\n", listaDeClientes[i].nombre, listaDeClientes[i].apellido);
            printf("\t\tTIPO\t\t\tRAZA\n");

        }

        for(j=0;j<tamArrayMascotas;j++)
        {
            if(listaDeClientes[i].idCliente == listaDeMascotas[j].idCliente && (listaDeClientes[i].estado == OCUPADO && listaDeMascotas[j].estado == OCUPADO))
            {
                printf("%21s\t%20s\n", listaDeMascotas[j].tipo, listaDeMascotas[j].raza.nombreRaza);
            }
        }
    }
}

/** \brief Displays a list of clients with more than one pet

 *
 * \param eMascota array of pets
 * \param int size of array of pets
 * \param eCliente array of clients
 * \param int size of array of clients
 * \return If the client has more than one pet it shows its name
 *
 */

void listarClientesConMasDeUnaMascota(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas)
{
    eClienteMascota auxClienteMascota[TCLIENTES];
    int i; //Clientes
    int j; //Mascotas

    //inicio array auxiliar
    for(i=0;i<tamArrayClientes;i++)
    {
        auxClienteMascota[i].idCliente = listaDeClientes[i].idCliente;
        auxClienteMascota[i].cantMascotas = 0;
    }
    printf("\n---------LISTA DE CLIENTES CON MAS DE UNA MASCOTA---------\n\n");
    for(i=0;i<tamArrayClientes;i++)
    {
        for(j=0;j<tamArrayMascotas;j++)
        {
            if(listaDeClientes[i].idCliente == listaDeMascotas[j].idCliente && listaDeMascotas[j].estado == OCUPADO)
            {
                auxClienteMascota[i].cantMascotas++;
            }
        }
    }

    for(i=0;i<tamArrayClientes;i++)
    {
        if(auxClienteMascota[i].cantMascotas > 1)
        {
            for(j=0;j<tamArrayMascotas;j++)
            {
                if(auxClienteMascota[i].idCliente == listaDeClientes[i].idCliente)
                {
                    printf("%s\n", listaDeClientes[i].nombre);
                    break;
                }
            }
        }
    }

}

/** \brief Displays a list of clients with pets with tree years old or more

 *
 * \param eMascota array of pets
 * \param int size of array of pets
 * \param eCliente array of clients
 * \param int size of array of clients
 * \return Shows pets that have more than three years old with its  owner
 *
 */


void listarMascotasConMasDeTres(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas)
{
    int i;
    int j;

    printf("\n---------LISTA DE MASCOTAS CON MAS DE TRES AÑOS---------\n\n");
    printf("ID\tNOMBRE\tTIPO\t   RAZA\tEDAD\tPESO\tSEXO\tCLIENTE\n");
    //Usamos el mismo codigo de mostrar mascotas con dueño
    for(i=0; i<tamArrayMascotas; i++)
    {
        //Solo mostrar mascotas con mas de 3 años
        if(listaDeMascotas[i].edad > 3)
        {
            for(j=0; j<tamArrayClientes; j++)
            {
                if(listaDeMascotas[i].idCliente == listaDeClientes[j].idCliente && (listaDeMascotas[i].estado == OCUPADO))
                {

                    printf("%2d %11s %5s %10s %4d %7.2f %7s %10s\n", listaDeMascotas[i].idMascota, listaDeMascotas[i].nombre, listaDeMascotas[i].tipo, listaDeMascotas[i].raza.nombreRaza, listaDeMascotas[i].edad, listaDeMascotas[i].peso, listaDeMascotas[i].sexo, listaDeClientes[j].nombre);
                }
            }
        }
    }
}

/** \brief Shows list of pets ordered by quantity
 *
 * \param eMascota size of array of pets
 * \param int size of array of pets
 * \param eCliente array of clients
 * \param int size of array of clients
 * \return The list of pets sorted by quantity
 *
 */


void ordenarClientesPorCantidadMascotas(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas)
{

    eClienteMascota auxClienteMascota[TCLIENTES];
    eClienteMascota auxOrdenamiento;
    int i; //Clientes
    int j; //Mascotas

    //inicio array auxiliar
    for(i=0; i<tamArrayClientes; i++)
    {
        auxClienteMascota[i].idCliente = listaDeClientes[i].idCliente;
        strcpy(auxClienteMascota[i].nombreCliente, listaDeClientes[i].nombre);
        auxClienteMascota[i].cantMascotas = 0;
    }

    //Contamos cantidad de mascotas por dueño
    for(i=0; i<tamArrayClientes; i++)
    {
        for(j=0; j<tamArrayMascotas; j++)
        {
            if(listaDeClientes[i].idCliente == listaDeMascotas[j].idCliente && listaDeMascotas[j].estado == OCUPADO)
            {
                auxClienteMascota[i].cantMascotas++;
            }
        }
    }

    printf("\n-----------LISTA DE CLIENTES CON CANTIDAD DE MASCOTAS-----------\n\n");
    for(i=0;i<tamArrayClientes-1;i++)
    {
        for(j=i+1;j<tamArrayClientes;j++)
        {
            if(auxClienteMascota[i].cantMascotas > auxClienteMascota[j].cantMascotas)
            {
                auxOrdenamiento = auxClienteMascota[i];
                auxClienteMascota[i] = auxClienteMascota[j];
                auxClienteMascota[j] = auxOrdenamiento;
            }
        }
    }

    for(i=0;i<tamArrayClientes;i++)
    {
        if(auxClienteMascota[i].cantMascotas >= 1)
        {
            for(j=0;j<tamArrayClientes;j++)
            {
                if(listaDeClientes[i].idCliente == auxClienteMascota[j].idCliente)
                {
                    printf("NOMBRE CLIENTE: %s - CANTIDAD MASCOTAS: %d\n", auxClienteMascota[i].nombreCliente, auxClienteMascota[i].cantMascotas);
                    break;
                }
            }
        }
    }
}


/** \brief Shows list of pets ordered by quantity and alphabetical order of the owner's name
 *
 * \param eMascota size of array of pets
 * \param int size of array of pets
 * \param eCliente array of clients
 * \param int size of array of clients
 * \return The list of pets sorted by quantity and order of the owner's name
 *
 */

void ordenarClientesPorCantidadMascotasYOrdenAlfabetico(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas)
{

    eClienteMascota auxClienteMascota[TCLIENTES];
    eClienteMascota auxOrdenamiento;
    int i; //Clientes
    int j; //Mascotas

    //inicio array auxiliar
    for(i=0; i<tamArrayClientes; i++)
    {
        auxClienteMascota[i].idCliente = listaDeClientes[i].idCliente;
        strcpy(auxClienteMascota[i].nombreCliente, listaDeClientes[i].nombre);
        auxClienteMascota[i].cantMascotas = 0;
    }

    //Contamos cantidad de mascotas por dueño
    for(i=0; i<tamArrayClientes; i++)
    {
        for(j=0; j<tamArrayMascotas; j++)
        {
            if(listaDeClientes[i].idCliente == listaDeMascotas[j].idCliente && listaDeMascotas[j].estado == OCUPADO)
            {
                auxClienteMascota[i].cantMascotas++;
            }
        }
    }

    for(i=0;i<tamArrayClientes-1;i++)
    {
        for(j=i+1;j<tamArrayClientes;j++)
        {
            if(auxClienteMascota[i].cantMascotas > auxClienteMascota[j].cantMascotas)
            {
                auxOrdenamiento = auxClienteMascota[i];
                auxClienteMascota[i] = auxClienteMascota[j];
                auxClienteMascota[j] = auxOrdenamiento;
            }
            else
            {
                if(auxClienteMascota[i].cantMascotas == auxClienteMascota[j].cantMascotas)
                {
                    if(strcmp(auxClienteMascota[i].nombreCliente,auxClienteMascota[j].nombreCliente)>0)
                    {
                        auxOrdenamiento = auxClienteMascota[i];
                        auxClienteMascota[i] = auxClienteMascota[j];
                        auxClienteMascota[j] = auxOrdenamiento;
                    }
                }
            }
        }
    }

    printf("\n-----------LISTA DE CLIENTES CON CANTIDAD DE MASCOTAS-----------\n\n");
    for(i=0;i<tamArrayClientes;i++)
    {
        if(auxClienteMascota[i].cantMascotas >= 1)
        {
            for(j=0;j<tamArrayClientes;j++)
            {
                if(listaDeClientes[i].idCliente == auxClienteMascota[j].idCliente)
                {
                    printf("NOMBRE CLIENTE: %s - CANTIDAD MASCOTAS: %d\n",auxClienteMascota[i].nombreCliente, auxClienteMascota[i].cantMascotas);
                    break;
                }

            }
        }
    }
}
