#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char nombre[10];
char nombre2[10];
char auxCad[100];
int cant;
int x;
int y;


printf("Ingrese nombre: ");
gets(auxCad);

while(strlen(auxCad)>9){

    printf("\nError, demasiado largo, reingrese: ");
    gets(auxCad);
}

strcpy(nombre, auxCad);

printf("%s\n", nombre);


cant=strlen(nombre);

printf("%s tiene %d caracteres\n", nombre, cant);

printf("Ingrese nombre 2: ");
gets(auxCad);
strncpy(nombre2, auxCad,9);
printf("%s\n",nombre2);


x=strcmp(nombre, nombre2);
printf("Comp nombre 1 y nombre 2: %d\n",x);


y=stricmp(nombre,nombre2);
printf("Comp nombre 1 y nombre 2 no case sensitive: %d\n",y);

strcat(nombre,nombre2);
printf("Concatencacion: %s\n", nombre); //la variable nombre
//ahora es la concatencac�n d elo ingresado en nombre + lo ingresado en nombre2

strupr(nombre);
printf("%s\n",nombre);


strlwr(nombre);
printf("%s\n",nombre);

nombre[0]=toupper(nombre[0]);
printf("%s\n",nombre);




  return 0;
}