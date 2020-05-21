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

/** \brief esta funcion inicializa los estados en libre (0) para decir que no tenemos datos cargados
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \return no retorna nada (void)
 *
 */
void inicializarChoferes (eChoferes arrayChoferes [],int tamC);
/** \brief esta funcion carga datos solo es de uso para el programador (testeo)
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \return no retorna nada (void)
 *
 */
void hardCodearChoferes (eChoferes arrayChoferes [],int tamC);

/** \brief esta funcion busca choferes los compara por id de la estructura choferes y el id que recibe por parametros y devuelve el chofer
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \param recibe un id tipo int para comparar
 * \return devuelve un echofer (todos los datos de un chofer si se encontro) si no devuelve un chofer con el estado en libre
 *
 */
eChoferes buscarChoferes (eChoferes arrayChoferes [],int tamC,int idChoferes);
/** \brief esta funcion muestra un chofer
 *
 * \param unChofer eChoferes recibe un chofer
 * \return void
 *
 */
void mostrarUnChofer(eChoferes unChofer);
/** \brief esta funcion muestra todos los choferes
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \return void
 *
 */
void mostrarChoferes (eChoferes arrayChoferes[],int tamC);
/** \brief esta funcion compara el id de choferes con el que recibe si hubo coincidencias retorna el id
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \param recibe el id un tipo int para comparar
 * \return retorna el id si hubo coincidencias si no devuelve -1
 *
 */
int buscarId (eChoferes arrayChoferes[],int tamC,int id);
/** \brief esta funcion carga un chofer y lo retorna si los datos fueron cargados correctamente
 *
 * \return eChoferes devuelve un chofer cargado de no haber cargado los datos requeridos bien retorna el chofer con el estado libre
 *
 */
eChoferes altaUnChofer();
/** \brief esta funcion da de alta a un chofer si los datos fueron cargados correctamente
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \param recibe el id de choferes para cargarlo en el chofer que se dara de alta
 * \return retorna 0 si se realizo correctamente y -1 si se cancelo o no se cargaron bien los datos
 *
 */
int altaChofer (eChoferes arrayChofer [], int tamC,int idChoferes);
/** \brief esta funcion busca un espacio LIBRE en el array y lo devuelve de no encontrar ninguno retorna -1
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \return retorna el lugar encontrado de lo contrario retorna -1
 *
 */
int buscarLibreChoferes (eChoferes arrayChoferes [],int tamC);
/** \brief esta funcion compara dos id de encontrar coincidencias retorna el indice de ese id
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \param recibe un id tipo int para comparar
 * \return retorna el indice de haber coincidencias de lo contrario retorna -1
 *
 */
int retornarIndicePorId (eChoferes arrayChoferes[],int tamC,int id);
/** \brief esta funcion modifica un dato de un chofer de ser modificado correctamente devuelve 0 de lo cotrario devuelve -1
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \return retorna 0 si se realizo la modificacion de lo contrario -1
 *
 */
int modificarChofer (eChoferes arrayChoferes [],int tamC);
/** \brief esta funcion calcula y muestra el promedio que se tiene entre las edades de los choferes retorna 0 si se pudo calcular y -1 si no se pudo
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \return retorna 0 si se pudo calcular y -1 si no se pudo
 *
 */
int promedioEdades (eChoferes arrayChoferes [],int tamC);
/** \brief esta funcion calcula y muestra el promedio de varones y el de mujeres retorna 0 si se pudo calcular y -1 si no se pudo
 *
 * \param recibe el array de choferes
 * \param recibe el tamanio del array de choferes
 * \return retorna 0 si se pudo calcular y -1 si no se pudo
 *
 */
int promedioMujeresVarones (eChoferes arrayChoferes [],int tamC);
