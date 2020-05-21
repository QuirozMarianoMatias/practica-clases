#include "input.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    char apellido [20];
    char nombre [20];
    int dni;
    int legajo;
    char nacionalidad[20];
    int telefono;
    int edad;
    char sexo;
    int estado;
    int idChofer;
    int cantidadDeCamiones;

}eChoferes;

void inicializarChoferes (eChoferes arrayChoferes [],int tamC);
void hardCodearChoferes (eChoferes arrayChoferes [],int tamC);
eChoferes buscarChoferes (eChoferes arrayChoferes [],int tamC,int idChoferes);
void mostrarUnChofer(eChoferes unChofer);
void mostrarChoferes (eChoferes arrayChoferes[],int tamC);
int buscarId (eChoferes arrayChoferes[],int tamC,int id);
eChoferes altaUnChofer();
int altaChofer (eChoferes arrayChofer [], int tamC,int idChoferes);
int buscarLibreChoferes (eChoferes arrayChoferes [],int tamC);
int retornarIndicePorId (eChoferes arrayChoferes[],int tamC,int id);
int modificarChofer (eChoferes arrayChoferes [],int tamC);
int promedioEdades (eChoferes arrayChoferes [],int tamC);
int promedioMujeresVarones (eChoferes arrayChoferes [],int tamC);
