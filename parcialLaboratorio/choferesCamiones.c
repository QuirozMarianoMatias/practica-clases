#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choferesCamiones.h"

void MostrarchoferesConCamiones (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)
{
    int i;
    int j;
    char banderaTieneProducto;


    for(i=0; i<tamC; i++)
    {
        if ( arrayChoferes[i].estado==OCUPADO)
        {

            printf("id\t apellido \t nombre \t nacionalidad \t dni \t   telefono \t sexo \t legajo \t edad\n");
            mostrarUnChofer(arrayChoferes[i]);
            printf("id\t patente \t marca \t tipo \t          anio \t peso \t       cantidadDeRuedas \t chofer\n");
            banderaTieneProducto = 'n';

            for(j=0; j<tamCa; j++)
            {
                if(arrayCamiones[j].estado==OCUPADO)
                {
                    if(arrayChoferes[i].idChofer == arrayCamiones[j].idChofer)
                    {
                        banderaTieneProducto = 's';
                        mostrarUnCamion(arrayCamiones[j],arrayChoferes,tamC);
                    }
                }
            }

            if(banderaTieneProducto == 'n')
            {
                printf("No tiene camion\n");
            }
        }
    }
}

int bajaCascada (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)

{
    int id=-1;
    eChoferes auxChofer;
    int indice;
    int retorno = -1;
    char respuesta[4];
    int i;

    MostrarchoferesConCamiones(arrayChoferes,tamC,arrayCamiones,tamCa);

    if(getInt("ingrese el id del chofer que desea dar de baja: ","error\n",1,4,3,&id)==0)
    {
        auxChofer = buscarChoferes(arrayChoferes,tamC,id);


        if (auxChofer.estado == OCUPADO)
        {
            printf("id\t apellido \t nombre \t nacionalidad \t dni \t   telefono \t sexo \t legajo \t edad\n");
            mostrarUnChofer(auxChofer);


            printf("id\t patente \t marca \t tipo \t          anio \t peso \t       cantidadDeRuedas \t chofer\n");
            for (i=0; i<tamCa; i++)
            {
                if(arrayCamiones[i].idChofer==id && arrayCamiones[i].estado == OCUPADO)
                {
                    mostrarUnCamion(arrayCamiones[i],arrayChoferes,tamC);

                }





            }
            if (getName("esta seguro que desea dar de baja este chofer tambien se daran de baja sus camiones(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
            {

                indice = retornarIndicePorId(arrayChoferes,tamC,id);
                arrayChoferes[indice].estado = LIBRE;

                for (i=0; i<tamCa; i++)
                {
                    if(arrayCamiones[i].idChofer==id && arrayCamiones[i].estado == OCUPADO)
                    {
                        arrayCamiones[i].estado = LIBRE;

                    }
                }
                retorno = 0;
            }

        }


    }
    else
    {
        printf("id incorrecto\n");
    }
    return retorno;
}

void contarCamiones (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)
{
    int i;
    int j;
    int cont;


    for(i=0; i<tamC; i++)
    {
        cont = 0;
        if ( arrayChoferes[i].estado==OCUPADO)
        {

            for(j=0; j<tamCa; j++)
            {
                if(arrayChoferes[i].idChofer == arrayCamiones[j].idChofer && arrayCamiones[j].estado== OCUPADO)
                {

                    cont++;
                }
            }

            arrayChoferes[i].cantidadDeCamiones = cont;
        }
    }

}


void mostrarChoferesConMasDeUnCamion (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)
{

    contarCamiones(arrayChoferes,tamC,arrayCamiones,tamCa);
    int i;
        printf("id\t apellido \t nombre \t nacionalidad \t dni \t   telefono \t sexo \t legajo \t edad\n");
    for (i=0; i<tamC; i++)
    {
        if(arrayChoferes[i].cantidadDeCamiones > 1 && arrayChoferes [i].estado == OCUPADO)
        {
            mostrarUnChofer(arrayChoferes[i]);
        }

    }


}

void ordernarChoferesPorCantidadDecamiones (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)
{
    int i;
    int j;
    eChoferes auxChoferes;
    contarCamiones(arrayChoferes,tamC,arrayCamiones,tamCa);

    for(i=0; i<tamC-1; i++)
    {
        for(j=i+1; j<tamC; j++)
        {
            if (arrayChoferes[i].estado == OCUPADO && arrayChoferes[j].estado== OCUPADO)
            {
                if(arrayChoferes[i].cantidadDeCamiones > arrayChoferes[j].cantidadDeCamiones)
                {
                    auxChoferes = arrayChoferes[i];
                    arrayChoferes[i] = arrayChoferes[j];
                    arrayChoferes[j] = auxChoferes;
                }


            }
        }

    }
    MostrarchoferesConCamiones(arrayChoferes,tamC,arrayCamiones,tamCa);
}

void ordernarChoferesPorCantidadDecamionesYOrdenAlfabetico (eChoferes arrayChoferes [], int tamC, eCamiones arrayCamiones[], int tamCa)
{
    int i;
    int j;
    eChoferes auxChoferes;
    contarCamiones(arrayChoferes,tamC,arrayCamiones,tamCa);

    for(i=0; i<tamC-1; i++)
    {
        for(j=i+1; j<tamC; j++)
        {
            if (arrayChoferes[i].estado == OCUPADO && arrayChoferes[j].estado== OCUPADO)
            {
                if(arrayChoferes[i].cantidadDeCamiones > arrayChoferes[j].cantidadDeCamiones)
                {
                    auxChoferes = arrayChoferes[i];
                    arrayChoferes[i] = arrayChoferes[j];
                    arrayChoferes[j] = auxChoferes;
                }
                else
                {

                    if(arrayChoferes[i].cantidadDeCamiones == arrayChoferes[j].cantidadDeCamiones)
                    {
                        if(stricmp(arrayChoferes[i].nombre,arrayChoferes[j].nombre)>0)
                           {
                            auxChoferes = arrayChoferes[i];
                            arrayChoferes[i] = arrayChoferes[j];
                            arrayChoferes[j] = auxChoferes;
                           }
                    }

                }

            }


        }

    }

    MostrarchoferesConCamiones(arrayChoferes,tamC,arrayCamiones,tamCa);
}
