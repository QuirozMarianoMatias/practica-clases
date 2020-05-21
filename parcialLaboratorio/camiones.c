#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camiones.h"

void inicializarCamiones (eCamiones arrayCamiones [],int tamC)
{
    int i;

    for(i=0; i<tamC; i++)
    {
        arrayCamiones[i].estado=LIBRE;

    }

}

void hardCodearCamiones (eCamiones arrayCamiones [],int tamCa)
{
    char patente [10][20]= {"123asd","321waf","156wrw","174wrq","658enr","122mri","123mri","124mri","125mri","126mri"};
    char marca[10][20]= {"ford","ford","fiat","fiat","WV","ford","ford","ford","ford","ford"};
    char tipo[10][20]= {"largaDistancia","largaDistancia","largaDistancia","largaDistancia","largaDistancia","cortaDistancia","cortaDistancia","cortaDistancia","cortaDistancia","cortaDistancia"};
    int anio[10]= {2000,2000,1999,1999,2010,2005,2015,2002,2002,2002};
    float peso [10]= {1500,1500,1500,1500,1500,1500,1500,1500,1500,1500};
    int cantidadDeRuedas[10] = {8,8,8,8,8,8,8,8,8,8};
    int idChofer[10]= {10,10,20,20,30,40,40,50,50,50};
    int idCamion[10]= {1,2,3,4,5,6,7,8,9,10};
    int estado[10]= {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};
    int i;

    for (i=0; i<tamCa; i++)
    {
        strcpy (arrayCamiones[i].patente,patente[i]);
        strcpy (arrayCamiones[i].marca,marca[i]);
        strcpy (arrayCamiones[i].tipo,tipo[i]);
        arrayCamiones[i].anio= anio[i];
        arrayCamiones[i].peso=peso[i];
        arrayCamiones[i].cantidadDeRuedas=cantidadDeRuedas[i];
        arrayCamiones[i].idChofer= idChofer[i];
        arrayCamiones[i].idCamion = idCamion[i];
        arrayCamiones[i].estado= estado[i];

    }
}

void mostrarUnCamion(eCamiones unCamion,eChoferes arrayChoferes [],int tamC)
{
    eChoferes auxChofer;

    auxChofer = buscarChoferes(arrayChoferes,tamC,unCamion.idChofer);
    if (auxChofer.estado==LIBRE)
    {
        strcpy(auxChofer.nombre,"no tiene chofer");
    }

    printf("%d %13s  %12s %17s  %5d  %3f  %3d  %30s \n",unCamion.idCamion
           ,unCamion.patente
           ,unCamion.marca
           ,unCamion.tipo
           ,unCamion.anio
           ,unCamion.peso
           ,unCamion.cantidadDeRuedas
           ,auxChofer.nombre);




}



void mostrarCamiones (eCamiones arrayCamiones [],int tamCa,eChoferes arrayChoferes[],int tamC)
{

    int i;
    printf("id\t patente \t marca \t tipo \t          anio \t peso \t       cantidadDeRuedas \t chofer\n");
    for (i=0; i<tamCa; i++)
    {
        if (arrayCamiones[i].estado==OCUPADO)
        {
            mostrarUnCamion(arrayCamiones[i],arrayChoferes,tamC);
        }

    }
}

int altaCamiones (eCamiones camiones [],int tamCa,int idCamiones,eChoferes choferes [],int tamC)
{
    int indice;
    eCamiones auxCamion;
    int id;
    int idCorrecto;
    int retorno = -1;
    char respuesta [3];

    indice = buscarLibre(camiones,tamCa);

    if (indice != -1)
    {
        auxCamion = altaUnCamion();
        if(auxCamion.estado==OCUPADO)
        {

            mostrarChoferes(choferes,tamC);
            if(getInt("ingrese id de chofer que desea darle al camion: ","\nError\n",2,4,3,&id)==0)
            {
                idCorrecto =  buscarId(choferes,tamC,id);


            }
            if (idCorrecto != -1)
            {
                auxCamion.idChofer = idCorrecto;
                auxCamion.idCamion = idCamiones;
                printf("id\t patente \t marca \t tipo \t          anio \t peso \t       cantidadDeRuedas \t chofer\n");
                mostrarUnCamion(auxCamion,choferes,tamC);
                if (getName("esta seguro que desea cargar los datos ingresados(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                {

                    camiones[indice] = auxCamion;
                    retorno = 0;


                }

            }
            else
            {
                printf("id incorrecto");
            }

        }
    }
    return retorno;

}

eCamiones altaUnCamion()
{
    eCamiones unCamion;
    char patente [10];
    char marca [20];
    int anio;
    float peso;
    int cantidadDeRuedas;
    char tipo[20];



    if ((getPatente("ingrese la patente: ","error\n",6,7,3,patente)==0)
            && (getName("ingrese la marca del camion: ","error\n",4,10,3,marca)==0)
            &&(getInt("ingrese el anio del camion: ","error\n",4,5,3,&anio)==0)
            && (getFloat("ingrese el peso del camion: ","error\n",4,10,3,&peso)==0)
            && (getInt("ingrese cantidad de ruedas del camion: ","error\n",1,3,3,&cantidadDeRuedas)==0)
            && (getName("ingrese tipo (larga distancia o corta distancia): ","error\n",15,16,3,tipo))==0)
    {
        unCamion.anio = anio;
        unCamion.peso = peso;
        unCamion.cantidadDeRuedas=cantidadDeRuedas;
        strcpy(unCamion.marca,marca);
        strcpy(unCamion.patente,patente);
        strcpy(unCamion.tipo,tipo);
        unCamion.estado=OCUPADO;


    }
    else
    {
        printf("datos no ingresados correctamente\n");
        unCamion.estado=LIBRE;
    }



    return unCamion;
}

int buscarLibre (eCamiones arrayCamiones [],int tamCa)
{
    int i;
    int indice = -1;

    for (i=0; i<tamCa; i++)
    {
        if(arrayCamiones[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int bajaCamiones (eCamiones arrayCamiones [],int tamCa,eChoferes choferes [],int tamC)
{

    int id=-1;
    eCamiones auxCamion;
    int indice;
    int retorno = -1;
    char respuesta[4];

    mostrarCamiones(arrayCamiones,tamCa,choferes,tamC);

    if(getInt("ingrese el id que desea dar de baja: ","error\n",1,4,3,&id)==0)
    {
        auxCamion = buscarCamion(arrayCamiones,tamCa,id);

        if (auxCamion.estado == OCUPADO)
        {
            printf("id\t patente \t marca \t tipo \t          anio \t peso \t       cantidadDeRuedas \t chofer\n");
            mostrarUnCamion(auxCamion,choferes,tamC);
            if (getName("esta seguro que desea dar de baja este camion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
            {
                indice = buscarIdCamiones(arrayCamiones,tamCa,id);
                arrayCamiones[indice].estado = LIBRE;
                retorno = 0;
            }

        }
        else
        {
            printf("id incorrecto\n");
        }
    }

    return retorno;
}

int buscarIdCamiones (eCamiones arrayCamiones [],int tamCa,int id)
{
    int i;
    int retorno = -1;

    for (i=0; i<tamCa; i++)
    {

        if (arrayCamiones[i].idCamion == id && arrayCamiones[i].estado== OCUPADO)
        {
            retorno = i;
            break;
        }


    }

    return retorno;
}

eCamiones buscarCamion (eCamiones arrayCamiones [],int tamCa,int id)

{
    int i;
    eCamiones auxCamion;
    auxCamion.estado = LIBRE;

    for(i=0; i<tamCa; i++)
    {
        if(arrayCamiones[i].idCamion==id && arrayCamiones[i].estado == OCUPADO)
        {
            auxCamion=arrayCamiones[i];
            break;
        }

    }

    return auxCamion;
}

int modificarCamion (eCamiones arrayCamiones [],int tamCa,eChoferes choferes [],int tamC)
{

    int id=-1;
    eCamiones auxCamion;
    eChoferes auxChoferes;
    int indice;
    int retorno = -1;
    char respuesta[4];
    char auxTipo [20];
    int auxId;

    mostrarCamiones(arrayCamiones,tamCa,choferes,tamC);

    if(getInt("ingrese el id que desea modificar: ","error\n",1,4,3,&id)==0)
    {
        auxCamion = buscarCamion(arrayCamiones,tamCa,id);

        if (auxCamion.estado == OCUPADO)
        {
            mostrarChoferes(choferes,tamC);
            if (getInt("ingrese el id del nuevo chofer: ","error\n",1,4,3,&auxId)==0
                && getName("ingrese nuevo tipo (larga distancia o corta distancia): ","error\n",15,16,3,auxTipo)==0)
            {
               auxChoferes = buscarChoferes(choferes,tamC,auxId);
                if (auxChoferes.estado == OCUPADO)
                {
                    printf("el nuevo chofer es : %s y el nuevo tipo es: %s\n",auxChoferes.nombre,auxTipo);

                printf("los anteriores datos son: \n");
                printf("id\t patente \t marca \t tipo \t          anio \t peso \t       cantidadDeRuedas \t chofer\n");
                mostrarUnCamion(auxCamion,choferes,tamC);
                if (getName("esta seguro que desea la modificacion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                {
                    indice = buscarIdCamiones(arrayCamiones,tamCa,id);
                    strcpy(arrayCamiones[indice].tipo,auxTipo);
                    arrayCamiones[indice].idChofer=auxId;
                    retorno = 0;
                }
            }else
            {
                printf("chofer no encontrado");
            }

            }
        }
        else
        {
            printf("id incorrecto\n");
        }
    }

    return retorno;



}


void ordernarCamionesPorTipo (eCamiones arrayCamiones [],int tamCa,eChoferes arrayChoferes [],int tamC)

{
    int i;
    int j;
    eCamiones auxCamiones;

    for(i=0; i<tamCa-1; i++)
    {
        for(j=i+1; j<tamCa; j++)
        {
            if (arrayCamiones[i].estado == OCUPADO && arrayCamiones[j].estado == OCUPADO)
            {
                if(stricmp(arrayCamiones[i].tipo,arrayCamiones[j].tipo)>0)
                {
                    auxCamiones = arrayCamiones[i];
                    arrayCamiones[i] = arrayCamiones[j];
                    arrayCamiones[j] = auxCamiones;
                }


            }
        }

    }

    mostrarCamiones(arrayCamiones,tamCa,arrayChoferes,tamC);

}
void mostrarCamionesConMasDiesAnios (eCamiones arrayCamiones [],int tamCa,eChoferes choferes [],int tamC)
{
    int i;
    printf("id\t patente \t marca \t tipo \t          anio \t peso \t       cantidadDeRuedas \t chofer\n");
    for (i=0;i<tamCa;i++)
    {
        if(arrayCamiones[i].anio < 2010 && arrayCamiones[i].estado == OCUPADO)
        {
            mostrarUnCamion(arrayCamiones[i],choferes,tamC);
        }
    }



}

void listarCamionesPorMarca (eCamiones arrayCamiones [],int tamCa,eChoferes choferes [],int tamC)
{
    int i;
    char marca [20];

    mostrarCamiones(arrayCamiones,tamCa,choferes,tamC);
    if(getName("ingrese la marca que desea listar: ","error\n",2,20,3,marca)==0)
    {   printf("\nid\t patente \t marca \t tipo \t          anio \t peso \t       cantidadDeRuedas \t chofer\n");
        for (i=0;i<tamCa;i++)
        {
            if(stricmp(arrayCamiones[i].marca,marca)==0&&arrayCamiones[i].estado==OCUPADO)
            {
                mostrarUnCamion(arrayCamiones[i],choferes,tamC);
            }
        }
    }


}

int promedioCamionesAntiguos (eCamiones arrayCamiones [],int tamCa)
{
    int total=0;
    int cont=0;
    float promedio;
    int retorno =-1;
    int i;

    for (i=0;i<tamCa;i++)
    {
       if (arrayCamiones[i].estado==OCUPADO)
       {
            total += (2020-arrayCamiones[i].anio);
            cont++;
       }


    }
    if(cont !=0)
    {
        promedio= (float)total/cont;
        printf("el promedio de intiguedad de camiones es: %.2f\n",promedio);
        retorno = 0;
    }

    return retorno;
}
