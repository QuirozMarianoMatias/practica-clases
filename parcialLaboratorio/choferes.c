#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choferes.h"
void inicializarChoferes (eChoferes arrayChoferes [],int tamC)
{
    int i;

    for(i=0; i<tamC; i++)
    {
        arrayChoferes[i].estado=LIBRE;

    }

}
void hardCodearChoferes (eChoferes arrayChoferes [],int tamC)
{

    char apellido [6][20]= {"quiroz","quintana","sanchez","ponce","caballero","albornoz"};
    char nombre [6][20] = {"Lucrecia","Jorge","Natalia","Matias","Jeremias","roberto"};
    char nacionalidad[6][20]= {"argentino","argentino","argentino","argentino","argentino","argentino"};
    int dni[6]= {39628925,39628926,39628927,39628928,39628929,39628930};
    int telefono[6]= {42740846,42740847,42740848,42740849,42740850,42740851};
    char sexo[6]= {'f','f','m','m','m','m'};
    int legajo[6]= {100,101,102,103,104,105};
    int edad [6]= {21,22,23,24,25,26};
    int idChofer [6]= {10,20,30,40,50,60};
    int estado[6]= {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};
    int i;

    for (i=0; i<tamC; i++)
    {
        strcpy (arrayChoferes[i].nombre,nombre[i]);
        strcpy (arrayChoferes[i].apellido,apellido[i]);
        strcpy (arrayChoferes[i].nacionalidad,nacionalidad[i]);
        arrayChoferes[i].dni= dni[i];
        arrayChoferes[i].telefono=telefono[i];
        arrayChoferes[i].sexo=sexo[i];
        arrayChoferes[i].legajo=legajo[i];
        arrayChoferes[i].edad= edad[i];
        arrayChoferes[i].idChofer=idChofer[i];
        arrayChoferes[i].estado= estado[i];

    }
}
void mostrarUnChofer(eChoferes unChofer)
{

    printf("%d %13s  %15s %16s  %13d  %3d  %6c  %7d %14d \n"
           ,unChofer.idChofer
           ,unChofer.apellido
           ,unChofer.nombre
           ,unChofer.nacionalidad
           ,unChofer.dni
           ,unChofer.telefono
           ,unChofer.sexo
           ,unChofer.legajo
           ,unChofer.edad);
}

int altaChofer (eChoferes arrayChofer [], int tamC,int idChoferes)
{

    int indice;
    eChoferes auxChofer;
    int retorno = -1;
    char respuesta [3];

    indice = buscarLibreChoferes(arrayChofer,tamC);

    if (indice != -1)
    {
        auxChofer = altaUnChofer();
        if(auxChofer.estado==OCUPADO)
        {

            auxChofer.idChofer=idChoferes;
            printf("id\t apellido \t nombre \t nacionalidad \t dni \t   telefono \t sexo \t legajo \t edad\n");
            mostrarUnChofer(auxChofer);
            if (getName("esta seguro que desea cargar los datos ingresados(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
            {

                arrayChofer[indice] = auxChofer;
                retorno = 0;


            }




        }
    }
    return retorno;

}





eChoferes altaUnChofer()
{
    eChoferes unChofer;
    char apellido [20];
    char nombre [20];
    char nacionalidad[20];
    int dni;
    int legajo;
    int telefono;
    int edad;
    char sexo;


    if ((getSex("ingrese el sexo: ","error\n",1,2,3,&sexo)==0)
            && (getName("ingrese nombre: ","error\n",4,20,3,nombre)==0)
            && (getName("ingrese apellido: ","error\n",4,20,3,apellido)==0)
            &&(getInt("ingrese dni: ","error\n",8,9,3,&dni)==0)
            && (getInt("ingrese legajo: ","error\n",1,5,3,&legajo)==0)
            && (getInt("ingrese telefono: ","error\n",6,12,3,&telefono)==0)
            && (getInt("ingrese edad: ","error\n",2,3,3,&edad)==0)
            && (getName("ingrese nacionalidad: ","error\n",4,20,3,nacionalidad))==0)
    {
        unChofer.edad = edad;
        unChofer.dni = dni;
        unChofer.legajo=legajo;
        unChofer.telefono=telefono;
        unChofer.sexo=sexo;
        strcpy(unChofer.apellido,apellido);
        strcpy(unChofer.nombre,nombre);
        strcpy(unChofer.nacionalidad,nacionalidad);
        unChofer.estado=OCUPADO;


    }
    else
    {
        printf("datos no ingresados correctamente\n");
        unChofer.estado=LIBRE;
    }



    return unChofer;
}

void mostrarChoferes (eChoferes arrayChoferes[],int tamC)
{

    int i;
    printf("id\t apellido \t nombre \t nacionalidad \t dni \t   telefono \t sexo \t legajo \t edad\n");
    for (i=0; i<tamC; i++)
    {
        if (arrayChoferes[i].estado==OCUPADO)
        {
            mostrarUnChofer(arrayChoferes[i]);
        }

    }
}

eChoferes buscarChoferes (eChoferes arrayChoferes [],int tamC,int idChoferes)

{
    int i;
    eChoferes auxChoferes;
    auxChoferes.estado = LIBRE;

    for(i=0; i<tamC; i++)
    {
        if(arrayChoferes[i].idChofer==idChoferes && arrayChoferes[i].estado == OCUPADO)
        {
            auxChoferes=arrayChoferes[i];
            break;
        }
    }

    return auxChoferes;
}

int buscarId (eChoferes arrayChoferes[],int tamC,int id)
{
    int i;
    int retorno = -1;

    for (i=0; i<tamC; i++)
    {

        if (arrayChoferes[i].idChofer == id && arrayChoferes[i].estado == OCUPADO)
        {
            retorno = id;
            break;
        }


    }

    return retorno;
}

int buscarLibreChoferes (eChoferes arrayChoferes [],int tamC)
{
    int i;
    int indice = -1;

    for (i=0; i<tamC; i++)
    {
        if(arrayChoferes[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int retornarIndicePorId (eChoferes arrayChoferes[],int tamC,int id)
{
    int i;
    int retorno = -1;

    for (i=0; i<tamC; i++)
    {

        if (arrayChoferes[i].idChofer == id && arrayChoferes[i].estado == OCUPADO)
        {
            retorno = i;
            break;
        }


    }

    return retorno;
}

int modificarChofer (eChoferes arrayChoferes [],int tamC)
{

    int id=-1;
    eChoferes auxChofer;
    int indice;
    int retorno = -1;
    char respuesta[4];
    int opcion;
    char auxNombre [20];
    char auxApellido [20];
    char auxNacionalidad [20];
    int auxDni;
    int auxTelefono;
    int auxLegajo;
    int auxEdad;
    char auxSexo;

    mostrarChoferes(arrayChoferes,tamC);

    if(getInt("ingrese el id del chofer que desea modificar: ","error\n",1,4,3,&id)==0)
    {
        auxChofer = buscarChoferes(arrayChoferes,tamC,id);

        if (auxChofer.estado == OCUPADO)
        {
            system("cls");
                printf("******************MODIFICAR CHOFER****************\n");
                printf("id\t apellido \t nombre \t nacionalidad \t dni \t   telefono \t sexo \t legajo \t edad\n");
                mostrarUnChofer(auxChofer);
                indice = retornarIndicePorId(arrayChoferes,tamC,id);

                if (getInt("1-nombre\n2-apellido\n3-nacionalidad\n4-dni\n5-telefono\n6-sexo\n7-legajo\n8-edad\n9-volver al menu anterior","error\n",1,2,3,&opcion)==0)
                {
                    switch(opcion)
                    {
                    case 1:
                        if (getName("ingrese nuevo nombre: ","error\n",4,20,3,auxNombre)==0)
                        {
                            if (getName("esta seguro que desea realizar la modificacion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                            {

                                strcpy(arrayChoferes[indice].nombre,auxNombre);
                                retorno = 0;

                            }

                        }
                        break;
                    case 2:
                        if (getName("ingrese nuevo apellido: ","error\n",4,20,3,auxApellido)==0)
                        {
                            if (getName("esta seguro que desea realizar la modificacion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                            {

                                strcpy(arrayChoferes[indice].apellido,auxApellido);
                                retorno = 0;

                            }

                        }
                        break;

                    case 3:
                        if (getName("ingrese la nueva nacionalidad: ","error\n",4,20,3,auxNacionalidad)==0)
                        {
                            if (getName("esta seguro que desea realizar la modificacion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                            {

                                strcpy(arrayChoferes[indice].nacionalidad,auxNacionalidad);
                                retorno = 0;

                            }

                        }
                        break;
                    case 4:
                        if (getInt("ingrese nuevo dni: ","error\n",8,9,3,&auxDni)==0)
                        {
                            if (getName("esta seguro que desea realizar la modificacion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                            {

                                arrayChoferes[indice].dni = auxDni;
                                retorno = 0;

                            }

                        }
                        break;


                    case 5:
                        if (getInt("ingrese nuevo telefono: ","error\n",6,12,3,&auxTelefono)==0)
                        {
                            if (getName("esta seguro que desea realizar la modificacion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                            {

                                arrayChoferes[indice].telefono = auxTelefono;
                                retorno = 0;

                            }

                        }
                        break;
                    case 6:
                        if (getSex("ingrese nuevo sexo: ","error\n",1,2,3,&auxSexo)==0)
                        {
                            if (getName("esta seguro que desea realizar la modificacion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                            {

                                arrayChoferes[indice].sexo = auxSexo;
                                retorno = 0;

                            }

                        }
                        break;
                    case 7:

                        if (getInt("ingrese nuevo legajo: ","error\n",1,6,3,&auxLegajo)==0)
                        {
                            if (getName("esta seguro que desea realizar la modificacion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                            {

                                arrayChoferes[indice].legajo = auxLegajo;
                                retorno = 0;

                            }

                        }
                        break;

                    case 8:
                        if (getInt("ingrese nueva edad: ","error\n",2,3,3,&auxEdad)==0)
                        {
                            if (getName("esta seguro que desea realizar la modificacion(si/no): ","\nerror\n",2,3,3,respuesta)==0 && stricmp(respuesta,"si")==0)
                            {

                                arrayChoferes[indice].edad = auxEdad;
                                retorno = 0;

                            }

                        }
                        break;

                    case 9:
                        printf("esta volviendo al menu modificar");
                    default:
                        printf("opcion incorrecta");

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

int promedioEdades (eChoferes arrayChoferes [],int tamC)
{

    int total=0;
    int cont=0;
    float promedio;
    int retorno =-1;
    int i;

    for (i=0; i<tamC; i++)
    {
        if (arrayChoferes[i].estado==OCUPADO)
        {
            total += arrayChoferes[i].edad;
            cont++;
        }


    }
    if(cont !=0)
    {
        promedio= (float)total/cont;
        printf("el promedio de edades es: %.2f\n",promedio);
        retorno = 0;
    }



    return retorno;
}

int promedioMujeresVarones (eChoferes arrayChoferes [],int tamC)
{

    int cont=0;
    int contVarones=0;
    int contMujeres=0;
    float promedioMujeres;
    float promedioVarones;
    int retorno =-1;
    int i;

    for (i=0; i<tamC; i++)
    {
        if (arrayChoferes[i].estado==OCUPADO )
        {
            if (arrayChoferes[i].sexo == 'f'|| arrayChoferes[i].sexo == 'F')
            {
                contMujeres++;
                cont++;
            }
            else
            {
                contVarones++;
                cont++;
            }
        }


    }
    if(cont !=0)
    {
        promedioMujeres= (float)contMujeres/cont;
        printf("el promedio de mujeres es: %.2f\n",promedioMujeres);     // 2*100/5

        promedioVarones= (float)contVarones/cont;
        printf("el promedio de varones es: %.2f\n",promedioVarones);

        retorno = 0;
    }



    return retorno;
}

