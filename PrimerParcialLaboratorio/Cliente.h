#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char localidad[51];
    int telefono;
    int edad;
    char sexo[51];

    int estado;

}eCliente;

void hardcodearClientes(eCliente lista[], int tamArray);
void inicializarArrayClientes(eCliente lista[], int tamArray);
void mostrarArrayClientes(eCliente lista[], int tamArray);
eCliente crearCliente();
int buscarIndiceLibreCliente(eCliente lista[], int tamArray);
void cargarCliente(eCliente lista[], int tamArray, int idCliente);
void eliminarClienteEnCascada(eCliente lista[], int tamArray);
void modificarCliente(eCliente lista[], int tamArray);
void calcularPromedioVaronesYMujeres(eCliente lista[], int tamArray);

#endif // CLIENTE_H_INCLUDED
