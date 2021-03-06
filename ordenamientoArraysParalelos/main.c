#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void mostrarAlumnos(int leg[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam);
void mostrarAlumno(int leg, int age, int sex, int n1, int n2, float prom);
void ordenarAlumnosPorLegajo(int leg[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam);
void ordenarAlumnosPorSexo(int leg[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam);

int main()
{

 int legajo [TAM]={222,444,333};
 int edad [TAM]={19,22,52};
 char sexo [TAM]={'m','f','m'};
 int nota1 [TAM]={5,9,6};
 int nota2 [TAM]={6,8,7};
 float promedio[TAM]={7,8.50,6.50};

 /*
 for(int i=0; i<TAM; i++){
 printf("Ingrese legajo:\n");
 scanf("%d", &legajo[i]);

 printf("Ingrese edad:\n");
 scanf("%d", &edad[i]);

 printf("Ingrese sexo:\n");
 __fpurge(stdin);
 scanf("%c", &sexo[i]);

 printf("Ingrese nota 1:\n");
scanf("%d", &nota1[i]);

 printf("Ingrese nota 2:\n");
scanf("%d", &nota2[i]);

promedio[i]=(float) (nota1[i] + nota2[i])/2;
}
*/

mostrarAlumnos(legajo, edad, sexo, nota1, nota2, promedio, TAM);

 ordenarAlumnosPorLegajo(legajo,edad,sexo,nota1,nota2,promedio,TAM);

mostrarAlumnos(legajo, edad, sexo, nota1, nota2, promedio, TAM);
  ordenarAlumnosPorSexo(legajo,edad,sexo,nota1,nota2,promedio,TAM);

mostrarAlumnos(legajo, edad, sexo, nota1, nota2, promedio, TAM);

    return 0;
}


void mostrarAlumnos(int leg[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam){
    printf("Legajo Edad Sexo Nota1 Nota2 Promedio\n");
    for(int i=0; i<tam; i++){
        mostrarAlumno(leg[i], edad [i], sexo[i], nota1[i], nota2[i], promedio[i]);

    }
}

void mostrarAlumno(int leg, int age, int sex, int n1, int n2, float prom){

printf(" %d    %d    %c    %d    %d    %.2f\n", leg, age, sex, n1, n2, prom);

}



void ordenarAlumnosPorLegajo(int leg[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam){

   int intAux;
    char sexoAux;
    float promedioAux;


    for (int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){

          if (leg[j]<leg[i]){

              intAux =leg[j];
                leg[j]=leg[i];
                leg[i]=intAux;

           intAux=edad[j];
                edad[j]=edad[i];
                edad[i]=intAux;

                sexoAux=sexo[j];
                sexo[j]=sexo[i];
                sexo[i]=sexoAux;

                intAux=nota1[j];
                nota1[j]=nota1[i];
                nota1[i]=intAux;

                intAux=nota2[j];
                nota2[j]=nota2[i];
                nota2[i]=intAux;

                promedioAux=promedio[j];
                promedio[j]=promedio[i];
                promedio[i]=promedioAux;
            }
        }
   }


}

void ordenarAlumnosPorSexo(int leg[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam){

   int intAux;
    char sexoAux;
    float promedioAux;


    for (int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){

          if (sexo[j]<sexo[i]){

              intAux =leg[j];
                leg[j]=leg[i];
                leg[i]=intAux;

           intAux=edad[j];
                edad[j]=edad[i];
                edad[i]=intAux;

                sexoAux=sexo[j];
                sexo[j]=sexo[i];
                sexo[i]=sexoAux;

                intAux=nota1[j];
                nota1[j]=nota1[i];
                nota1[i]=intAux;

                intAux=nota2[j];
                nota2[j]=nota2[i];
                nota2[i]=intAux;

                promedioAux=promedio[j];
                promedio[j]=promedio[i];
                promedio[i]=promedioAux;
            }
        }
   }


}



