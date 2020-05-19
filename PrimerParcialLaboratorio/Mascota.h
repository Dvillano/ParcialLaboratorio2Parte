#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    char nombreRaza[51];
    char pais[51];

}eRaza;

typedef struct
{
    char nombre[51];
    char tipo[51];
    eRaza raza;
    int edad;
    float peso;
    char sexo[51];

    int idMascota;
    int idCliente;
    int estado;

}eMascota;

void hardcodearMascotas(eMascota lista[], int tamArray);
void inicializarArrayMascotas(eMascota lista[], int tamArray);
eMascota crearMascota();
int buscarIndiceLibreMascota(eMascota lista[], int tamArray);
void cargarMascota(eMascota lista[], int tamArray, int idMascota);
void eliminarMascota(eMascota lista[], int tamArray);
void modificarMascota(eMascota lista[], int tamArray);
void ordenarMascotasPorTipo(eMascota lista[], int tamArray);
void calcularPromedioEdadMascotas(eMascota lista[], int tamArray);
void calcularPromedioEdadPorTipoMascota(eMascota lista[], int tamArray);
void listarMascotasPorTipo(eMascota lista[], int tamArray);

#endif // MASCOTA_H_INCLUDED
