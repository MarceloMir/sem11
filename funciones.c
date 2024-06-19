#include <stdio.h>
#include "funciones.h"
#include <string.h>
void ingresarCliente(char clientes[][2][40]){
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(clientes[i][0],"")==0){
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s",clientes[i][0]);
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s",clientes[i][1]);
            break;
        }
    } 
    imprimirClientes(clientes);
}

void imprimirClientes(char clientes[][2][40]){
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(clientes[i][0],"")!=0)
        printf("%s\t\t%s\n",clientes[i][0],clientes[i][1]);
    }   
}

void listarPeliculas(char peliculas[][4][40]){
    printf("numero\t\tPelicula\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\n%s\t\t%s\t\t%s\t\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }   
}
void buscarporNombre(char peliculas[][4][40]){
    char nPelicula[40];
    printf("Ingrese el nombre de la pelicula que desee buscar: ");
    scanf("%s",nPelicula);
    printf("numero\t\tPelicula\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++)
    {
        if(strcmp(peliculas[i][1],nPelicula)==0){
            printf("\n%s\t\t%s\t\t%s\t\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);           
        }
    }
}
void buscarporGenero(char peliculas[][4][40]){
    char Gen[40];
    printf("Ingrese el genero de la pelicula que desea buscar: ");
    scanf("%s",Gen);
    printf("numero\t\tPelicula\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++)
    {
        if(strcmp(peliculas[i][3],Gen)==0){
            printf("\n%s\t\t%s\t\t%s\t\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
        }
    }
}
#define precioGeneral 7
#define precioVermouth 3.5
#define precioTerceraEdad 3
void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]){
    char nombre[40];
    int numPelicula;
    printf("\nIngrese su nombre para buscar si esta en la lista--> ");
    scanf("%s", nombre);
    int indexNombre=-1;
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(clientes[i][0],nombre)==0){
            indexNombre=i;
            break;
        }
    }
    if(indexNombre==-1){
        printf("Cliente no encontrado. Ingrese un nombre valido de la lista\n");
        return;
    }
    printf("\nESTAS SON LAS PELICULAS DISPONIBLES... \n");
    listarPeliculas(peliculas);
    printf("\nIngrese el numero de pelicula que desea reservar-> ");
    scanf("%d",&numPelicula);
    if(numPelicula<1 || numPelicula>10){
        printf("\nNO SE HA ENCONTRADO LA PELICULA");
        return;
    }
    if (reserva[numPelicula-1][indexNombre]!=-1)
    {
        printf("\nYa esta realizada la reserva para esta funcion");
        return;
    }
    int cantGeneral, cantVermouth, cantTerceraEdad;
    printf("\nIngrese la cantidad de boletos generales que desee comprar-> ");
    scanf("%d",&cantGeneral);
    printf("\nIngrese la cantidad de boletos Vermouth que desee comprar-> ");
    scanf("%d",&cantVermouth); 
    printf("\nIngrese la cantidad de boletos para tercera edad que desee comprar-> ");
    scanf("%d",&cantTerceraEdad);
    if(cantGeneral==0 && cantVermouth==0 && cantTerceraEdad==0){
        printf("\n\tIngrese al menos un boleto\n");
    }
    double PrecioTotal= cantGeneral*precioGeneral + cantVermouth*precioVermouth + cantTerceraEdad*precioTerceraEdad;
    printf("\nESTE ES EL RESUMEN DE SU COMPRA...\n");
    printf("Cliente: %s\n",nombre);
    printf("Pelicula: %s\n",peliculas[numPelicula-1][1]);
    printf("Cantidad de Entradas Generales: %d\n",cantGeneral);
    printf("Cantidad de Entradas Vermouth: %d\n",cantVermouth);
    printf("Cantidad de Entradas Tercera Edad: %d\n",cantTerceraEdad);
    printf("El precio TOTAL es: %.2f\n",PrecioTotal);
    int cantidadTotalBoletos= cantGeneral+cantVermouth+cantTerceraEdad;
    int confirmacion;
    printf("\nDesea confirmar la compra? 1.si / 2.no ");
    scanf("%d",&confirmacion);
    if(confirmacion==1){
        reserva[numPelicula-1][indexNombre]=cantidadTotalBoletos;
        printf("\n\tCOMPRA CONFIRMADA\n");
    }else{
        printf("\n\tLA COMPRA HA SIDO CANCELADA\n");
    }    
}

void verCompras(char peliculas[][4][40], double precio[3], char clientes[][2][40], int reserva[][4]){
    printf("Estas son sus compras realizadas\n");
    int hayCompras = 0; 

    for (int i = 0; i < 10; i++){  
        for (int j = 0; j < 5; j++){  
            if (reserva[i][j] != -1 && strcmp(clientes[j][0],"")!=0){
                printf("Cliente: %s, Pelicula: %s, Cantidad de boletos: %d\n", clientes[j][0], peliculas[i][1], reserva[i][j]);
                hayCompras=1;
            }
        }
        
    }
    if (!hayCompras){
        printf("No se han realizado compras.\n");
        return;
    }
}