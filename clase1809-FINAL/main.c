#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 1


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty;

} eAlumno;

void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
int altaAlumno(eAlumno alumnos[], int tam);
int menu();
void iniciarAlumnos(eAlumno alumnos [], int tam);
int buscarLibre(eAlumno alumnos[], int tam);
int buscarAlumno(int legajo, eAlumno alumnos[], int tam);
eAlumno newAlumno(int legajo, char nombre[],char sexo, int edad, int nota1, int nota2, eFecha fecha);
int bajaAlumno(eAlumno alumnos[], int tam);
int modificarNota(eAlumno alumnos[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);

int main()
{

    eAlumno lista[TAM];

    char salir='n';

    iniciarAlumnos(lista,TAM);

    do
    {

        switch(menu())
        {
        case 1:
            altaAlumno(lista,TAM);
            break;

        case 2:
            bajaAlumno(lista,TAM);
            break;

        case 3:
            modificarNota(lista,TAM);
            break;

        case 4:
            mostrarAlumnos(lista,TAM);
            break;

        case 5:
            ordenarAlumnos(lista,TAM);
            break;


        case 6:
            printf("Informes\n");
            break;

        case 7:
            printf("Confirma salida?: ");
            fflush(stdin);
            salir = getchar();
        default:
            printf("Opci�n invalida: ");
        }

        system("pause");
    }
    while(salir=='n');



    return 0;
}

void mostrarAlumno(eAlumno x)
{
    printf("  %d  %s  %d  %c  %d %d %.2f %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    system("cls");
    printf("***MOSTRAR ALUMNO\n\n\n");

    int flag=0;

    printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarAlumno(vec[i]);
            flag=1;
        }


    }
    if(flag==0)
    {
        system("cls");
        printf("\n---No hay alumnos que mostrar");
        printf("\n\n");
    }
}



int menu()
{

    int opcion;

    system("cls");
    printf("Menu de opciones\n");
    printf("1.Alta alumno\n");
    printf("2.Baja alumno\n");
    printf("3.Modificar alumno\n");
    printf("4.Listar alumnos\n");
    printf("5.Ordenar alumnos\n");
    printf("6.Informes\n");
    printf("7.Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void iniciarAlumnos(eAlumno alumnos [], int tam)
{

    for(int i =0; i<tam; i++)
    {

        alumnos[i].isEmpty=1;

    }

}


int buscarLibre(eAlumno alumnos[], int tam)
{

    int indice=-1;
    for(int i =0; i<tam; i++)
    {

        if(alumnos[i].isEmpty)
        {

            indice=i;
            break;
        }

    }
    return indice;
}

int buscarAlumno(int legajo, eAlumno alumnos[], int tam)
{

    int indice=-1;
    for(int i =0; i<tam; i++)
    {

        if(!alumnos[i].isEmpty && alumnos[i].legajo==legajo)
        {

            indice=i;
            break;
        }

    }
    return indice;
}

int altaAlumno(eAlumno alumnos[], int tam)
{
    system("cls");
    printf("***ALTA ALUMNO\n\n\n");


    int todoOk=0;
    int indice;
    int esta;
    int legajo;
    int edad;
    int nota1;
    int nota2;
    char sexo;
    char nombre[20];

    eFecha fecha;



    indice=buscarLibre(alumnos,tam);
    if(indice==-1)
    {
        printf("Sistema completo, no se puede agregar m�s alumnos\n");
        system("pause");
    }
    else
    {

        printf("Ingrese legajo: ");
        scanf("%d",&legajo);
        esta=buscarAlumno(legajo, alumnos,tam);
        if(esta!=-1)
        {
            printf("Legajo ya registrado:\n");
            mostrarAlumno(alumnos[esta]);
            system("pause");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad:");

            scanf("%d", &edad);
            printf("Ingrese sexo:");

            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1:");
            scanf("%d", &nota1);

            printf("Ingrese nota parcial 2:");
            scanf("%d", &nota2);



            printf("Ingrese fecha ingreso: dd/mm/aaaa ");
            scanf("%d/%d/%d",&fecha.dia, &fecha.mes, &fecha.anio);

            alumnos[indice]= newAlumno(legajo,nombre,sexo,edad,nota1,nota2,fecha);
            todoOk=1;

        }

    }

    return todoOk;
}

eAlumno newAlumno(int legajo, char nombre[],char sexo, int edad, int nota1, int nota2, eFecha fecha)
{

    eAlumno nuevoAlumno;

    nuevoAlumno.legajo=legajo;
    strcpy(nuevoAlumno.nombre,nombre);
    nuevoAlumno.edad=edad;
    nuevoAlumno.sexo=sexo;
    nuevoAlumno.nota1= nota1;
    nuevoAlumno.nota2=nota2;
    nuevoAlumno.promedio=(float) (nota1+nota2)/2;
    nuevoAlumno.fechaIngreso= fecha;
    nuevoAlumno.isEmpty=0;

    return nuevoAlumno;

}

int bajaAlumno(eAlumno alumnos[], int tam)
{

    int todoOk=0;
    int indice;
    int legajo;
    char confirma;

    system("cls");
    printf("***BAJA ALUMNO\n\n\n");
    printf("Ingrese legajo: ");
    scanf("%d",&legajo);

    indice=buscarAlumno(legajo,alumnos,tam);

    if(indice==-1)
    {

        printf("Legajo  no registrado");
        system("pause");
    }
    else
    {

        mostrarAlumno(alumnos[indice]);
        printf("\nConfirma eliminaci�n?: \n");
        fflush(stdin);
        confirma=getchar();

        if (confirma=='s')
        {

            alumnos[indice].isEmpty=1;
            printf("\nSe ha eliminado el alumno\n");
            todoOk=1;

        }
        else
        {

            printf("\nSe ha cancelado la baja");
        }
        system("pause");
    }
    return todoOk;
}

int modificarNota(eAlumno alumnos[], int tam){

    int todoOk=0;
    int indice;
    int legajo;
    char nota;
    int notaNueva;


    system("cls");
    printf("***MODIFICAR ALUMNO\n\n\n");
    printf("Ingrese legajo: ");
    scanf("%d",&legajo);

    indice=buscarAlumno(legajo,alumnos,tam);

    if(indice==-1)
    {

        printf("Legajo  no registrado");
        system("pause");
    }
    else
    {

        mostrarAlumno(alumnos[indice]);
        printf("\nDesea modificar la primera o la segunda nota? (ingrese 1 o 2)\n");
        fflush(stdin);
        nota=getchar();

        if(nota=='1')
        {
            printf("\nIngrese nueva nota 1:\n" );
            scanf("%d", &notaNueva);
            alumnos[indice].nota1= notaNueva;
            alumnos[indice].promedio=(float)(alumnos[indice].nota1+alumnos[indice].nota2)/2;
            printf("\nSe ha modificado la nota");
            mostrarAlumno(alumnos[indice]);
            todoOk=1 ;
        }
        else if (nota=='2')
    {
        printf("\nIngrese nueva nota 2:\n");
            scanf("%d", &notaNueva);
            alumnos[indice].nota2= notaNueva;
             alumnos[indice].promedio=(float)(alumnos[indice].nota1+alumnos[indice].nota2)/2;
            printf("\nSe ha modificado la nota");
            mostrarAlumno(alumnos[indice]);
            todoOk=1 ;
        }
        else
        {

            printf("\nSe ha cancelado la modificacion");
        }
 system("pause");
    }
   return todoOk;
}

void ordenarAlumnos(eAlumno vec[], int tam){

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++){
        for(int j= i+1; j <tam; j++){
            if( vec[i].legajo > vec[j].legajo && !vec[i].isEmpty && !vec[j].isEmpty) {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

