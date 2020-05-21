#include "choferes.h"

typedef struct
{
    char marca [20];
    int anio;
    float peso;
    char patente [20];
    int cantidadDeRuedas;
    char tipo [20];
    int estado;
    int idChofer;
    int idCamion;

}eCamiones;

void inicializarCamiones (eCamiones arrayCamiones [],int tamC);
void hardCodearCamiones (eCamiones arrayCamiones [],int tamCa);
void mostrarUnCamion(eCamiones unCamion,eChoferes arrayChoferes [],int tamC);
void mostrarCamiones (eCamiones arrayCamiones [],int tamCa,eChoferes arrayChoferes[],int tamC);
int altaCamiones (eCamiones camiones [],int tamCa,int idCamiones,eChoferes choferes [],int tamC);
eCamiones altaUnCamion();
int buscarLibre (eCamiones arrayCamiones [],int tamCa);
eCamiones buscarCamion (eCamiones arrayCamiones [],int tamCa,int id);
int buscarIdCamiones (eCamiones arrayCamiones [],int tamCa,int id);
int bajaCamiones (eCamiones arrayCamiones [],int tamCa,eChoferes choferes [],int tamC);
int modificarCamion (eCamiones arrayCamiones [],int tamCa,eChoferes choferes [],int tamC);
void ordernarCamionesPorTipo (eCamiones arrayCamiones [],int tamCa,eChoferes arrayChoferes [],int tamC);
void mostrarCamionesConMasDiesAnios (eCamiones arrayCamiones [],int tamCa,eChoferes choferes [],int tamC);
void listarCamionesPorMarca (eCamiones arrayCamiones [],int tamCa,eChoferes choferes [],int tamC);
int promedioCamionesAntiguos (eCamiones arrayCamiones [],int tamCa);
