#ifndef CLIENTE_MASCOTA_H_INCLUDED
#define CLIENTE_MASCOTA_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombreCliente[51];
    int cantMascotas;

}eClienteMascota;
void mostrarMascotasConClientes(eMascota listaDeMascotas[], int tamArrayMascotas, eCliente listaDeClientes[], int tamArrayClientes);
void mostrarClientesConMascotas(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas);
void listarClientesConMasDeUnaMascota(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas);
void listarMascotasConMasDeTres(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas);
void ordenarClientesPorCantidadMascotas(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas);
void ordenarClientesPorCantidadMascotasYOrdenAlfabetico(eCliente listaDeClientes[], int tamArrayClientes, eMascota listaDeMascotas[], int tamArrayMascotas);

#endif // CLIENTE_MASCOTA_H_INCLUDE
