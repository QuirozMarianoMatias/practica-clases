#include "menu.h"

void menuAltas (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa,int * idCamiones,int * idChoferes)
{
    int opcion;
    int estadoCamionesAlta;
    int estadoChoferAlta;

    do
    {
        system("cls");
        if(getInt("***********MENU ALTAS***********\n1-altas camiones\n2-altas choferes\n3-volver al menu principal\n","error\n",1,2,0,&opcion)==0)

        {
            switch(opcion)
            {


            case 1:
                system("cls");
                printf("*********ALTA CAMION*******\n");
                estadoCamionesAlta = altaCamiones(arrayCamiones,tamCa,*idCamiones,arrayChoferes,tamC);
                if (estadoCamionesAlta == 0)
                {
                    printf("camion cargado correctamente\n");
                    *idCamiones= *idCamiones+1;
                }
                else
                {
                    printf("opcion cancelada\n");
                }
                break;
            case 2:
                system("cls");
                printf("*********ALTA CHOFERES*******\n");
                estadoChoferAlta = altaChofer(arrayChoferes,tamC,*idChoferes);
                if (estadoChoferAlta == 0)
                {
                    printf("chofer cargado correctamente\n");
                    * idChoferes=*idChoferes+10;
                }
                else
                {
                    printf("opcion cancelada\n");
                }
                break;
            case 3:
                printf("volviendo al menu principal\n");
                break;
            default:
                printf("opcion incorrecta\n");
            }



        }


        system("pause");
    }
    while(opcion!= 3);

}


void menuModificar (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)
{
    int opcion;
    int estadoCamionesModificar;
    int estadoChoferModificar;

    do
    {
        system("cls");
        if(getInt("***********MENU MODIFICAR***********\n1-modificar camiones\n2-modificar choferes\n3-volver al menu principal\n","error\n",1,2,0,&opcion)==0)

        {
            switch(opcion)
            {


            case 1:
                system("cls");
                printf("*********MODIFICAR CAMION*******\n");
                estadoCamionesModificar =   modificarCamion(arrayCamiones,tamCa,arrayChoferes,tamC);
                if (estadoCamionesModificar == 0)
                {
                    printf("camion modificado correctamente\n");
                }
                else
                {
                    printf("opcion cancelada\n");
                }
                break;
            case 2:
                system("cls");
                printf("*********MODIFICAR CHOFER*******\n");
                estadoChoferModificar = modificarChofer(arrayChoferes,tamC);
                if (estadoChoferModificar == 0)
                {
                    printf("chofer modificado correctamente\n");
                }
                else
                {
                    printf("opcion cancelada\n");
                }
                break;
            case 3:
                printf("volviendo al menu principal\n");
                break;
            default:
                printf("opcion incorrecta\n");
            }



        }


        system("pause");
    }
    while(opcion!= 3);
}

void menuBajas (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)
{


    int opcion;
    int estadoCamionesBaja;
    int estadoBajaCascada;

    do
    {
        system("cls");
        if(getInt("***********MENU BAJAS***********\n1-baja camiones\n2-baja cascada\n3-volver al menu principal\n","error\n",1,2,0,&opcion)==0)

        {
            switch(opcion)
            {


            case 1:
                system("cls");
                printf("*********BAJA CAMION*******\n");
                estadoCamionesBaja = bajaCamiones(arrayCamiones,tamCa,arrayChoferes,tamC);
                if (estadoCamionesBaja == 0)
                {
                    printf("camion dado de baja correctamente\n");
                }
                else
                {
                    printf("opcion cancelada\n");
                }

                break;
            case 2:
                system("cls");
                printf("*********BAJA CHOFER*******\n");
                estadoBajaCascada =  bajaCascada(arrayChoferes,tamC,arrayCamiones,tamCa);

                if (estadoBajaCascada == 0)
                {
                    printf("baja de chofer con sus camiones realizado con exito\n");
                }
                else
                {
                    printf("opcion cancelada\n");
                }
                break;

            case 3:
                printf("volviendo al menu principal\n");
                break;
            default:
                printf("opcion incorrecta\n");
            }



        }


        system("pause");
    }
    while(opcion!= 3);

}

void menuListado (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)
{


    int opcion;

    do
    {
        system("cls");
        if(getInt("***********MENU LISTADO***********\n1-Listado Choferes\n2-listado de camion con su chofer\n3-listado de chofer con sus camiones\n4-listado de camiones por tipo\n5-listado de choferes con mas de un camion\n6-listado de choferes por cantidad de camiones\n7-listado de choferes por cantidad de camiones y orden alfabetico\n8-listado de camiones con mas de 10 anios de antiguedad\n9-listado de camiones por marca\n10-volver al menu principal\n","error\n",1,3,0,&opcion)==0)

        {
            switch(opcion)
            {


            case 1:
                system("cls");
                printf("*********LISTADO CHOFERES*******\n");
                mostrarChoferes(arrayChoferes,tamC);

                break;
            case 2:
                system("cls");
                printf("*********LISTADO DE CAMION CON SU CHOFER*******\n");
                mostrarCamiones(arrayCamiones,tamCa,arrayChoferes,tamC);
                break;

            case 3:
                system("cls");
                printf("*********LISTADO DE CHOFER CON SUS CAMIONES*******\n");
                MostrarchoferesConCamiones(arrayChoferes,tamC,arrayCamiones,tamCa);
                break;

            case 4:
                system("cls");
                printf("*********LISTADO DE CAMIONES ORDENADOS POR TIPO*******\n");
                ordernarCamionesPorTipo(arrayCamiones,tamCa,arrayChoferes,tamC);
                break;

            case 5:
                system("cls");
                printf("*********LISTADO DE CHOFERES CON MAS DE UN CAMION*******\n");
                mostrarChoferesConMasDeUnCamion(arrayChoferes,tamC,arrayCamiones,tamCa);
                break;

            case 6:
                system("cls");
                printf("*********LISTADO DE CHOFERES POR CANTIDAD DE CAMIONES*******\n");
                ordernarChoferesPorCantidadDecamiones (arrayChoferes,tamC,arrayCamiones,tamCa);
                break;

            case 7:
                system("cls");
                printf("*********LISTADO DE CHOFERES POR CANTIDAD DE CAMIONES Y POR ORDEN ALFABETICO*******\n");
                ordernarChoferesPorCantidadDecamionesYOrdenAlfabetico (arrayChoferes,tamC,arrayCamiones,tamCa);
                break;
            case 8:
                system("cls");
                printf("*********LISTADO DE CAMIONES CON MAS DE 10 ANIOS DE ANTIGUEDAD*******\n");
                mostrarCamionesConMasDiesAnios(arrayCamiones,tamCa,arrayChoferes,tamC);
                break;
            case 9:
                system("cls");
                printf("*********LISTADO DE CAMIONES POR MARCA*******\n");
                listarCamionesPorMarca(arrayCamiones,tamCa,arrayChoferes,tamC);
                break;
            case 10:
                printf("volver al anterior menu");
                break;
            default:
                printf("opcion incorrecta\n");
            }



        }


        system("pause");
    }
    while(opcion!= 10);

}


void menuPromedios (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)
{


    int opcion;
    int estadoPromedioEdades;
    int estadoPromedioAntiguos;
    int estadoPromedioVaronesMujeres;

    do
    {
        system("cls");
        if(getInt("***********MENU BAJAS***********\n1-promedio de edades\n2-promedio de anios de Camiones\n3-promedio entre varones y mujeres\n4-volver al menu principal\n","error\n",1,2,0,&opcion)==0)

        {
            switch(opcion)
            {


            case 1:
                system("cls");
                printf("*********PROMEDIO DE EDADES*******\n");
                estadoPromedioEdades = promedioEdades(arrayChoferes,tamC);
                if (estadoPromedioEdades == -1 )
                {
                    printf("usted no tiene choferes cargados");
                }

                break;
            case 2:
                system("cls");
                printf("*********PROMEDIO DE ANIOS DE CAMIONES*******\n");
                estadoPromedioAntiguos = promedioCamionesAntiguos(arrayCamiones,tamCa);
                if (estadoPromedioAntiguos == -1 )
                {
                    printf("usted no tiene camiones cargados");
                }
                break;
            case 3:
                system("cls");
                printf("*********PROMEDIO ENTRE VARONES Y MUJERES*******\n");
                estadoPromedioVaronesMujeres = promedioMujeresVarones(arrayChoferes,tamC);
                if (estadoPromedioVaronesMujeres == -1 )
                {
                    printf("usted no tiene choferes cargados");
                }
                break;
            case 4:
                printf("volviendo al menu principal\n");
                break;
            default:
                printf("opcion incorrecta\n");
            }



        }


        system("pause");
    }
    while(opcion!= 4);

}
