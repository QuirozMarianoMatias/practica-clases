#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#define TAMCHO 12
#define TAMCAM 25


int main()
{
    eChoferes choferes [TAMCHO];
    eCamiones camiones [TAMCAM];
    int idCamiones=11;
    int idChoferes = 70;
    int opcion;

    inicializarCamiones(camiones,TAMCAM);
    inicializarChoferes(choferes,TAMCHO);

    hardCodearCamiones(camiones,10);
    hardCodearChoferes(choferes,6);

    do
    {
        system("cls");
        if(getInt("***********MENU PRINCIPAL*********\n1-altas \n2-modificar \n3-bajas \n4-listado \n5-promedios \n6-salir\n","error\n",1,3,0,&opcion)!=0)
        {
            opcion = -1 ;
        }
        switch(opcion)
        {


        case 1:
            menuAltas(choferes,TAMCHO,camiones,TAMCAM,&idCamiones,&idChoferes);

            break;

        case 2:
            menuModificar(choferes,TAMCHO,camiones,TAMCAM);


            break;
        case 3:

            menuBajas(choferes,TAMCHO,camiones,TAMCAM);

            break;

        case 4:
            menuListado(choferes,TAMCHO,camiones,TAMCAM);

            break;

        case 5:

            menuPromedios(choferes,TAMCHO,camiones,TAMCAM);
            break;
        case 6:

            printf("usted salio!!!\n");
            break;

        default:
            printf("opcion incorrecta");


        }


    }
    while(opcion != 6);



    return 0;
}
