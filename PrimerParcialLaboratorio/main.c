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
#define OCUPADO

int main()
{
    /*Arrays Principales*/
    eCliente listaClientes[TCLIENTES];
    eMascota listaMascotas[TMASCOTAS];

    /*Opcion para el menu*/
    int opcion;

    /*Contadores unicos para ID*/
    int contIdMascota = 0;
    int contIdCliente = 0;

    /*Colocamos todos los estados en 0 (LIBRE)*/
    inicializarArrayClientes(listaClientes, TCLIENTES);
    inicializarArrayMascotas(listaMascotas, TMASCOTAS);

    /*Para testear*/
    hardcodearClientes(listaClientes, TCLIENTES);
    hardcodearMascotas(listaMascotas,TMASCOTAS);

    do
    {
        menu();
        getInt(&opcion,"Ingrese una opcion: \n");

        switch(opcion)
        {
        case 1:
            mostrarArrayClientes(listaClientes, TCLIENTES);
            break;
        case 2:
            mostrarMascotasConClientes(listaMascotas,TMASCOTAS,listaClientes,TCLIENTES);
            break;
        case 3:
            mostrarClientesConMascotas(listaClientes,TCLIENTES,listaMascotas,TMASCOTAS);
            break;
        case 4:
            mostrarArrayClientes(listaClientes,TCLIENTES);
            cargarMascota(listaMascotas,TMASCOTAS, contIdMascota);
            break;
        case 5:
            mostrarMascotasConClientes(listaMascotas,TMASCOTAS,listaClientes,TCLIENTES);
            eliminarMascota(listaMascotas,TMASCOTAS);
            break;
        case 6:
            mostrarMascotasConClientes(listaMascotas,TMASCOTAS,listaClientes,TCLIENTES);
            modificarMascota(listaMascotas,TMASCOTAS);
            break;
        case 7:
            cargarCliente(listaClientes,TCLIENTES,contIdCliente);
            break;
        case 8:
            mostrarArrayClientes(listaClientes,TCLIENTES);
            eliminarClienteEnCascada(listaClientes,TCLIENTES);
            break;
        case 9:
            ordenarMascotasPorTipo(listaMascotas, TMASCOTAS);
            mostrarMascotasConClientes(listaMascotas,TMASCOTAS,listaClientes,TCLIENTES);
            break;
        case 10:
            mostrarArrayClientes(listaClientes,TCLIENTES);
            modificarCliente(listaClientes, TCLIENTES);
            break;
        case 11:
            listarClientesConMasDeUnaMascota(listaClientes,TCLIENTES,listaMascotas,TMASCOTAS);
            break;
        case 12:
            listarMascotasConMasDeTres(listaClientes, TCLIENTES, listaMascotas, TMASCOTAS);
            break;
        case 13:
            listarMascotasPorTipo(listaMascotas,TMASCOTAS);
            break;
        case 14:
            ordenarClientesPorCantidadMascotas(listaClientes,TCLIENTES,listaMascotas,TMASCOTAS);
            break;
        case 15:
            ordenarClientesPorCantidadMascotasYOrdenAlfabetico(listaClientes,TCLIENTES,listaMascotas,TMASCOTAS);
            break;
        case 16:
            calcularPromedioEdadMascotas(listaMascotas,TMASCOTAS);
            break;
        case 17:
            calcularPromedioEdadPorTipoMascota(listaMascotas,TMASCOTAS);
            break;
        case 18:
            calcularPromedioVaronesYMujeres(listaClientes,TCLIENTES);
            break;
        }

    }while(opcion != 19);

    return 0;
}

