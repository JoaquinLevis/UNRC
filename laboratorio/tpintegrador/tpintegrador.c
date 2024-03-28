//ALUMNOS: Levis, Joaquin; Picco, Valentino. Comision 5

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//registro para la fecha
typedef struct Tfecha{
    int dia;
    int mes;
    int anio;
}TFecha;

#define MAX 150

//registro para los datos de cada persona
typedef struct Tpersona{
    int DNI;
    char nombre[20];
    char apellido[20];
    TFecha nacimiento;
    int edad;
    char ciudad[20];
    char DP[30]; //direccion postal
    char CE[20]; //correo electronico
    char tel[15]; //telefono
    int VF; //verdadero = vivo, falso = fallecido
    TFecha fallecimiento;
} TPersona;

//estructura de los datos
typedef struct { 
    TPersona arr [MAX]; 
    int cant;
} TData;

//estructura de lista simplemente enlazada
typedef struct tdoblete{
    TPersona info;
    struct tdoblete *next;
}TElem;

//estructura de lista doblemente enlazada
typedef struct ttriplete{
    TPersona info;
    struct ttriplete *next;
    struct ttriplete *back;
}Tnodo;

TData datosPersona; //variable principal que almacena los datos
TPersona persona;   //variable auxiliar para pasar de arreglo a archivo y viseversa
FILE* f; //archivo
TElem *cab; //cabeza de la lista simplemente enlazada
int opcion; //variable para el menu
int dniNuevo; //dni de la persona que se va a buscar y/o modificar
char modo; //modo de visualizacion de listas
char localidad[20]; //localidad a visualizar

//declaraciones de funciones y acciones
int llena(TData pers);
int vacia(TData dat);
void intercambiar (TPersona *a, TPersona *b);
void burbuja1(TData *s);
void burbuja2(TData *s);
TFecha obtenerFechaActual();
int calcularEdad (TFecha a);
void insertar(TData *per);
void suprimir(TData *dat, int num);
void mostrarDatos (TData dat);
void inicializarListaD(Tnodo **q, Tnodo **p);
void insertarListaD(Tnodo **r, Tnodo **p, TPersona per[datosPersona.cant], int cant);
void liberarLista1(Tnodo **q);
void listLocalidad (TData dat, char localid [20], char modo);
void crearListFallecidos (TData dat, TElem **q);
void mostrarListFallecido (TElem *q);
void mostrarIndividual(TData dat, int i);
void buscarModificar(TData *dat, int dni);
void liberarLista2(TElem **q);


int main () {
    printf("Hola, bienvenido al sistema de personas del TPI\n");
    f = fopen("personasTP.dat", "a+"); //abre el archivo
    if (f == NULL){ //valida que el archivo se abrio correctamente
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    fseek(f, 0, SEEK_SET); //posiciona el cursor al principio
    int i = 0;
    datosPersona.cant = 0;
    while((fread(&persona, sizeof(TPersona), 1, f) == 1)){ //pasa la informacion del archivo al arreglo para su manipulacion
        datosPersona.arr[i] = persona;
        i++;
        datosPersona.cant++;
    }
    fclose(f); //cierra el archivo
    do { //menu
        printf("\nQue desea hacer?\n1. Insertar personas\n2. Eliminar personas\n3. Modificar datos\n4. Listar todas las personas\n5. Listar personas fallecidas\n6. Listar personas de una localidad\n7. Mostrar por DNI\n8. Salir\n---> ");
        scanf("%d", &opcion);
        switch (opcion){
        case (1): //insertar personas
            insertar(&datosPersona);
            break;
        case (2): //eliminar personas
            printf("Cual es el dni de la persona que desea eliminar?\n");
            scanf("%d", &dniNuevo);
            suprimir(&datosPersona, dniNuevo);
            break;
        case (3): //modificar datos
            if (vacia(datosPersona)){ 
                printf("No hay personas para modificar\n");
            } else {
                printf("Cual es el dni de la persona que desea buscar?\n");
                scanf("%d", &dniNuevo);
                buscarModificar(&datosPersona, dniNuevo);
            }
            break;
        case (4): //listar todas las personas
            if (vacia(datosPersona)){
                printf("La lista se encuentra vacia\n");
            } else {
                mostrarDatos (datosPersona);
            }
            break;
        case (5): //listar personas fallecidas
            if (vacia(datosPersona)){
                printf("La lista se encuentra vacia\n");
            } else {
                crearListFallecidos(datosPersona, &cab);
                mostrarListFallecido(cab);
            }
            break;
        case (6): //listar personas de una localidad
            if (vacia(datosPersona)){
                printf("La lista se encuentra vacia\n");
            } else {
                printf("Cual es la localidad que desea ver?\n");
                scanf("     %[^\n]s", localidad);
                do {
                    printf("Seleccione el modo de visualizacion, A para ascendente y D para descendente: ");
                    scanf(" %c", &modo);
                    if(modo != 'A' && modo != 'D'){
                        printf("Opcion no valida\n");
                    }
                } while(modo != 'A' && modo != 'D');
            }
            listLocalidad(datosPersona, localidad, modo);
            break;
        case (7): //mostrar por DNI
            burbuja2(&datosPersona); //ordena por dni
            mostrarDatos(datosPersona); //muestra
            burbuja1(&datosPersona); //vuelve al orden inicial
            break;
        case (8): //salir
            break;
        default: //admite solo las opciones del menu
            printf("Opcion no valida\n");
            break;
        }
        printf("\n");
    } while(opcion != 8);
    f = fopen("personasTP.dat","wb"); //abre el archivo para escritura
    if (f == NULL) { //valida que el archivo se abrio correctamente
    perror("Error al abrir el archivo para escritura");
    exit(EXIT_FAILURE);
    }
    for(int i = 0; i < datosPersona.cant; i++){ //escribe la informacion del arreglo en el archivo
        persona = datosPersona.arr[i];
        fwrite(&persona, sizeof(TPersona), 1, f);
    }
    fclose(f); //cierra el archivo
}

//evalua si la lista esta llena
int llena(TData pers){
    if(pers.cant >= MAX - 1){
        return 1;
    }else {
        return 0;
    }
}

//evalua si la lista esta vacia
int vacia(TData lista){
    if(lista.cant > 0){
        return 0;
    }else {
        return 1;
    }
}

//intercambia dos personas
void intercambiar (TPersona *a, TPersona *b){
    TPersona aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//ordena la lista de personas por apellido, nombre y por ultimo dni, usando metodo burbuja
void burbuja1(TData *s){
    int i, j;
    i = s->cant;
    while(i > 1){
        j = 0;
        while(j < i - 1){
            if (strcmp(s->arr[j].apellido, s->arr[j+1].apellido) > 0){
                intercambiar(&s->arr[j], &s->arr[j+1]); //intercambia las personas
            } else if (strcmp(s->arr[j].nombre, s->arr[j+1].nombre) == 0){
                if (strcmp(s->arr[j].apellido, s->arr[j+1].apellido) > 0){
                    intercambiar(&s->arr[j], &s->arr[j+1]); //intercambia las personas
                } else if (strcmp(s->arr[j].apellido, s->arr[j+1].apellido) == 0){
                    if (s->arr[j].DNI > s->arr[j+1].DNI){
                    intercambiar(&s->arr[j], &s->arr[j+1]); //intercambia las personas
                    }
                }
            }
            j++;
        }
        i--;
    }
}


//ordena la lista de personas por dni, usando metodo burbuja
void burbuja2(TData *s){
    int i, j;
    i = s->cant;
    while(i > 1){
        j = 0;
        while(j < i - 1){
            if (s->arr[j].DNI > s->arr[j+1].DNI){
                intercambiar(&s->arr[j], &s->arr[j+1]); //intercambia las personas
            }
            j++;
        }
        i--;
    }
}

//obtiene la fecha actual de tu computadora
TFecha obtenerFechaActual(){
    TFecha aux;
    time_t tiempoActual; 
    time(&tiempoActual);
    struct tm* fecha = localtime(&tiempoActual); 
    aux.dia = fecha->tm_mday;
    aux.mes = fecha->tm_mon + 1;
    aux.anio = fecha->tm_year + 1900;
    return aux;
}

//calcula la edad de una persona
int calcularEdad (TFecha a){
    int n;
    TFecha b = obtenerFechaActual(); //obtiene la fecha actual para calcular la edad
    if (b.mes>a.mes) { //calcula la edad
        n = b.anio - a.anio;
    } else if (b.mes<a.mes) {
        n = b.anio - a.anio - 1;
    } else if (b.mes==a.mes) {
        if (b.dia>=a.dia) {
            n = b.anio - a.anio;
        } else {
            n = b.anio - a.anio - 1;
        }
    }
    return n;
}

//inserta una persona en la lista
void insertar(TData *per){
    int aux, i;
    if(llena(*per)){
        printf("No se pueden aniadir personas, el espacio esta lleno\n");
    }else {
        printf("Ingrese el numero de DNI: "); //pide el dni de la nueva persona
        scanf("%d", &aux);
        i = 0;
        while(i < per->cant && aux != per->arr[i].DNI){ //busca si ese dni no esta repetido
            i++;
        }
        if (i >= per->cant){ //si el dni no esta repetido pide los demas datos
            per->arr[per->cant].DNI = aux;
            printf("Ingrese el nombre de la persona: ");
            scanf("     %[^\n]s", per->arr[per->cant].nombre);
            printf("Ingrese el apellido de la persona: ");
            scanf("     %[^\n]s", per->arr[per->cant].apellido);
            printf("Ingrese el dia de nacimento de la persona: ");
            scanf("%d", &per->arr[per->cant].nacimiento.dia);
            printf("Ingrese el mes de nacimiento de la persona: ");
            scanf("%d", &per->arr[per->cant].nacimiento.mes);
            printf("Ingrese el anio de nacimiento de la persona: ");
            scanf("%d", &per->arr[per->cant].nacimiento.anio);
            printf("Ingrese si la persona se encuentra viva o fallecida (1 = vivo, 0 = fallecido): ");
            scanf("%d", &per->arr[per->cant].VF);
            if(per->arr[per->cant].VF == 1){ //en caso de estar vivo se ingresan los demas datos
                printf("Ingrese la ciudad de residencia: ");
                scanf("     %[^\n]s", per->arr[per->cant].ciudad);
                printf("Ingrese la direccion postal de su vivienda: ");
                scanf("     %[^\n]s", per->arr[per->cant].DP);
                printf("Ingrese el correo electronico de la persona: ");
                scanf("     %[^\n]s", per->arr[per->cant].CE);
                printf("Ingrese el telefono de la persona: ");
                scanf("     %[^\n]s", per->arr[per->cant].tel);
                per->arr[per->cant].edad = calcularEdad(per->arr[per->cant].nacimiento); //calcula la edad en base a la fecha de nacimiento
            }else { //en caso de estar fallecido se ingresa la fecha de fallecimiento
                printf("ingrese el dia de fallecimiento: ");
                scanf("%d", &per->arr[per->cant].fallecimiento.dia);
                printf("ingrese el mes de fallecimiento: ");
                scanf("%d", &per->arr[per->cant].fallecimiento.mes);
                printf("ingrese el anio de fallecimiento: ");
                scanf("%d", &per->arr[per->cant].fallecimiento.anio);
            }
            per->cant = per->cant + 1;
            burbuja1(per); //ordena por apellido, nombre y DNI
            } else {
                printf("La persona ya está registrada\n");
            }
        
    }
}

//elimina una persona de la lista
void suprimir(TData *dat, int num){
    int pos, j;
    pos = 0;
    if (dat->cant <= 0){
        printf("La lista se encuentra vacia\n");
    } else {
        while (pos < dat->cant && dat->arr[pos].DNI != num){
            pos++;
        }
        if (pos >= dat->cant){
            printf("Persona no encontrada\n");
        } else {
            for (j = pos + 1; j < dat->cant; j++){
                dat->arr[j-1] = dat->arr[j];
            }
            dat->cant--;
            printf("Has eliminado a la persona de DNI %d\n", num);
        }
    }
}

//muestra la lista
void mostrarDatos (TData dat) {
    int i;
        for (i = 0; i < dat.cant; i++){
            printf("Esta es la persona numero %d:\n", i + 1);
            printf("DNI: %d\n", dat.arr[i].DNI);
            printf("Nombre: %s\n", dat.arr[i].nombre);
            printf("Apellido: %s\n", dat.arr[i].apellido);
            printf("Fecha de nacimiento: %d/%d/%d\n", dat.arr[i].nacimiento.dia, dat.arr[i].nacimiento.mes, dat.arr[i].nacimiento.anio);
            if (dat.arr[i].VF == 1){
                dat.arr[i].edad = calcularEdad(dat.arr[i].nacimiento);
                printf("La persona se encuentra con vida\n");
                printf("Edad: %d\n", dat.arr[i].edad);
                printf("Ciudad de residencia: %s\n", dat.arr[i].ciudad);
                printf("Domicilio postal: %s\n", dat.arr[i].DP);
                printf("Correo electronico: %s\n", dat.arr[i].CE);
                printf("Telefono: %s\n", dat.arr[i].tel);
            } else {
                printf("La persona se encuentra fallecida\n");
                printf("Fecha de fallecimiento: %d/%d/%d\n\n", dat.arr[i].fallecimiento.dia, dat.arr[i].fallecimiento.mes, dat.arr[i].fallecimiento.anio);
            }
            printf("\n");
        }
}

//inicializa la lista doblemente encadenada
void inicializarListaD(Tnodo **q, Tnodo **p){
    *q = (Tnodo*)malloc(sizeof(Tnodo));
    *p = (Tnodo*)malloc(sizeof(Tnodo));
    (*q)->next = NULL;
    (*p)->next = NULL;
    (*q)->back = NULL;
    (*p)->back = NULL;
}

//inserta la lista doblemente encadenada
void insertarListaD(Tnodo **r, Tnodo **p, TPersona per[datosPersona.cant], int cant){
    Tnodo *aux;
    int i;
    for (i = 0; i < cant; i++){
        aux = (Tnodo*)malloc(sizeof(Tnodo));
        aux->info = per[i];
        aux->next = *p;
        aux->back = *r;
        (*p)->back = aux;
        (*r)->next = aux;
        *r = aux;
    }
}

//libera la lista doblemente encadenada
void liberarLista1(Tnodo **q){
    Tnodo *act, *sig;
    act = *q;
    while (act != NULL){
        sig = act->next;
        free(act);
        act = sig;
    }
}

//lista por localidad dada
void listLocalidad (TData dat, char localid [20], char modo) {
    int cant, i;
    TPersona vec [dat.cant];
    Tnodo *p, *r, *cab;
    cant = 0;
    for (i = 0; i < dat.cant; i++){
        if (strcmp(dat.arr[i].ciudad, localid) == 0){
            vec[cant] = dat.arr[i];
            cant++;
        }
    }
    if (cant == 0){
        printf("No se encontro nadie de esa localidad\n");
    } else {
        inicializarListaD(&cab, &p); //inicializa la lista localidad
        r = cab;
        insertarListaD(&r, &p, vec, cant); //inserta la lista localidad
        if (modo == 'A'){ //muestra la lista localidad de manera ascendente
            r = cab->next;
            while (r->next != NULL){
                printf("\n");
                printf("DNI: %d\n", r->info.DNI);
                printf("Nombre: %s\n", r->info.nombre);
                printf("Apellido: %s\n", r->info.apellido);
                printf("Fecha de nacimiento: %d/%d/%d\n", r->info.nacimiento.dia, r->info.nacimiento.mes, r->info.nacimiento.anio);
                if (r->info.VF == 1){
                    r->info.edad = calcularEdad(r->info.nacimiento);
                    printf("La persona se encuentra con vida\n");
                    printf("Edad: %d\n", r->info.edad);
                    printf("Ciudad de residencia: %s\n", r->info.ciudad);
                    printf("Domicilio postal: %s\n", r->info.DP);
                    printf("Correo electronico: %s\n", r->info.CE);
                    printf("Telefono: %s\n", r->info.tel);
                } else {
                    printf("La persona se encuentra fallecida\n");
                    printf("Fecha de fallecimiento: %d/%d/%d\n", r->info.fallecimiento.dia, r->info.fallecimiento.mes, r->info.fallecimiento.anio);
                }
                printf("\n");
                r = r->next;
            }
        }
        if (modo == 'D'){ //muestra la lista localidad de manera descendente
            while (r->back != NULL){
                printf("\n");
                printf("DNI: %d\n", r->info.DNI);
                printf("Nombre: %s\n", r->info.nombre);
                printf("Apellido: %s\n", r->info.apellido);
                printf("Fecha de nacimiento: %d/%d/%d\n", r->info.nacimiento.dia, r->info.nacimiento.mes, r->info.nacimiento.anio);
                if (r->info.VF == 1){
                    r->info.edad = calcularEdad(r->info.nacimiento); //calcula la edad en base a la fecha de nacimiento
                    printf("La persona se encuentra con vida\n");
                    printf("Edad: %d\n", r->info.edad);
                    printf("Ciudad de residencia: %s\n", r->info.ciudad);
                    printf("Domicilio postal: %s\n", r->info.DP);
                    printf("Correo electronico: %s\n", r->info.CE);
                    printf("Telefono: %s\n", r->info.tel);
                } else {
                    printf("La persona se encuentra fallecida\n");
                    printf("Fecha de fallecimiento: %d/%d/%d\n", r->info.fallecimiento.dia, r->info.fallecimiento.mes, r->info.fallecimiento.anio);
                }
                r = r->back;
            }
            printf("\n");
        }
        liberarLista1(&cab); //libera la lista localidad
        printf("\n");
    }
}

//inicializa la lista simplemente encadenada
void inicializarListaS(TElem **q){
    *q = (TElem*)malloc(sizeof(TElem));
    (*q)->next = NULL;
}

//inserta en la lista simplemente encadenada
void insertarListaS(TElem **q, TData data){
    TElem *r, *aux;
    r = *q;
    for(int i = 0; i < data.cant;i++){
        if(data.arr[i].VF == 0){
            aux = (TElem*)malloc(sizeof(TElem));
            aux->info = data.arr[i];
            aux->next = NULL;
            r->next = aux;
            r = aux;
        }
    } 
}

//libera la lista simplemente encadenada
void liberarLista2(TElem **q){
    TElem *act, *sig;
    act = *q;
    while (act != NULL){
        sig = act->next;
        free(act);
        act = sig;
    }
}

//crea la lista de personas fallecidas
void crearListFallecidos(TData data, TElem **q){
    if(data.cant <= 0){
        printf("No hay personas fallecidas\n");
    }else {
        inicializarListaS(q); //inicializa la lista de personas fallecidas
        insertarListaS(q, data); //inserta la lista de personas fallecidas
    }
}

//muestra la lista de personas fallecidas
void mostrarListFallecido(TElem *q){
    TElem *aux;
    aux = q->next;
    int i = 1;
    if(aux != NULL){
        while(aux != NULL){
            printf("Persona %d\n", i);
            printf("DNI: %d\n", (*aux).info.DNI);
            printf("Nombre: %s\n", (*aux).info.nombre);
            printf("Apellido: %s\n", (*aux).info.apellido);
            printf("Fecha de Nacimiento: %d/%d/%d\n", (*aux).info.nacimiento.dia, (*aux).info.nacimiento.mes, (*aux).info.nacimiento.anio);
            printf("Fecha de Fallecimiento: %d/%d/%d\n", (*aux).info.fallecimiento.dia, (*aux).info.fallecimiento.mes, (*aux).info.fallecimiento.anio);
            printf("\n");
            aux = aux->next;
            i++;
        }
        liberarLista2(&q);  //se libera la lista de personas fallecidas
    }
}

//muestra los datos de una persona
void mostrarIndividual(TData dat, int i){
    int edad;

    printf("Los datos de la persona buscada son\n");
    printf("Numero de DNI: %d\n", dat.arr[i].DNI);
    printf("Nombre de la persona: %s\n", dat.arr[i].nombre);
    printf("Apellido de la persona: %s\n", dat.arr[i].apellido);
    printf("Fecha de nacimiento: %d/%d/%d\n", dat.arr[i].nacimiento.dia, dat.arr[i].nacimiento.mes, dat.arr[i].nacimiento.anio);
    if(dat.arr[i].VF == 1){
        edad = calcularEdad(dat.arr[i].nacimiento); //calcula la edad
        printf("Esta persona aun vive\n");
        printf("Su edad es: %d\n", edad);
        printf("Correo electronico: %s\n", dat.arr[i].CE);
        printf("Ciudad de residencia: %s\n", dat.arr[i].ciudad);
        printf("Numero de telefono: %s\n", dat.arr[i].tel);
        printf("Direccion postal: %s\n", dat.arr[i].DP);
    }else {
        printf("La persona ha fallecido\n");
        printf("Fecha de Fallecimiento: %d/%d/%d\n", dat.arr[i].fallecimiento.dia, dat.arr[i].fallecimiento.mes, dat.arr[i].fallecimiento.anio);
    }
    printf("\n");
}

void buscarModificar (TData *dat, int dni){
    int k, inf, sup;
    char mod[30];
    char sn;
    int edad;
    burbuja2(dat); //ordena el arreglo por DNI
    if(dni < dat->arr[0].DNI || dni > dat->arr[dat->cant - 1].DNI){
        printf("No se encontro el DNI\n");
    }else {
        inf = 0;
        sup = dat->cant - 1;
        while(inf < sup){
            k = (inf + sup) / 2;
            if(dni <= dat->arr[k].DNI){
                sup = k;
            }else {
                inf = k + 1;
            }
        }
        if(dat->arr[inf].DNI == dni){
            mostrarIndividual(*dat, inf); //muestra los datos de la persona
            do {
                printf("\nDesea modificar alguno de los datos mostrados si(s) o no(n)? \n");
                scanf(" %c", &sn);
                if (sn != 's' && sn != 'n'){
                    printf("Por favor ingrese 's' o 'n'\n");
                }
            } while(!(sn == 's' || sn == 'n'));
            if(sn == 's'){
                do {
                    printf("Que desea modificar? apellido / nombre / ciudad / nacimiento / correo / telefono / vf(vivo o fallecido) / postal\n");
                    scanf(" %s", mod);
                } while (!(strcmp(mod, "apellido") == 0 || strcmp(mod, "nombre") == 0 || strcmp(mod, "ciudad") == 0 || strcmp(mod, "nacimiento") == 0 || strcmp(mod, "correo") == 0 || strcmp(mod, "telefono") == 0 || strcmp(mod, "vf") == 0 || strcmp(mod, "postal") == 0));
                if(strcmp(mod, "apellido") == 0){
                    printf("Ingresar el nuevo apellido: ");
                    scanf("     %[^\n]s", dat->arr[inf].apellido);
                }else if(strcmp(mod, "nombre") == 0){
                    printf("Ingresar el nuevo nombre: ");
                    scanf("     %[^\n]s", dat->arr[inf].nombre);
                }else if(strcmp(mod, "ciudad") == 0){
                    printf("Ingresar la nueva ciudad de residencia: ");
                    scanf("     %[^\n]s", dat->arr[inf].ciudad);
                }else if(strcmp(mod, "nacimiento") == 0){
                    printf("Ingresar el nuevo dia de nacimiento: ");
                    scanf("%d", &dat->arr[inf].nacimiento.dia);
                    printf("Ingresar el nuevo mes de nacimiento: ");
                    scanf("%d", &dat->arr[inf].nacimiento.mes);
                    printf("Ingresar el nuevo anio de nacimiento: ");
                    scanf("%d", &dat->arr[inf].nacimiento.anio);
                }else if(strcmp(mod, "correo") == 0){
                    printf("Ingresar el nuevo correo electronico: ");
                    scanf("     %[^\n]s", dat->arr[inf].CE);
                }else if(strcmp(mod, "telefono") == 0){
                    printf("Ingresar el nuevo telefono: ");
                    scanf("     %[^\n]s", dat->arr[inf].tel);
                }else if(strcmp(mod, "vf") == 0){
                    printf("Ingresar el nuevo estado de de vida (vivo = 1, fallecido = 0): ");
                    scanf("%d", &dat->arr[inf].VF);
                    if (dat->arr[inf].VF == 0){
                        printf("Ingresar el dia de fallecimiento: ");
                        scanf("%d", &dat->arr[inf].fallecimiento.dia);
                        printf("Ingresar el mes de fallecimiento: ");
                        scanf("%d", &dat->arr[inf].fallecimiento.mes);
                        printf("Ingresar el anio de fallecimiento: ");
                        scanf("%d", &dat->arr[inf].fallecimiento.anio);
                    } else {
                        printf("Ingrese la ciudad de residencia: ");
                        scanf("     %[^\n]s", dat->arr[inf].ciudad);
                        printf("Ingrese la direccion postal de su vivienda: ");
                        scanf("     %[^\n]s", dat->arr[inf].DP);
                        printf("Ingrese el correo electronico de la persona: ");
                        scanf("     %[^\n]s", dat->arr[inf].CE);
                        printf("Ingrese el telefono de la persona: ");
                        scanf("     %[^\n]s", dat->arr[inf].tel);
                        edad = calcularEdad(dat->arr[inf].nacimiento); //calcula la edad
                        dat->arr[inf].edad = edad;
                    }
                }else if(strcmp(mod, "postal") == 0){
                    scanf("     %[^\n]s", dat->arr[inf].DP);
                }
                printf("Datos ya cambiados\n");
                mostrarIndividual(*dat, inf); //muestra los datos de la persona nuevamente
            }              
        }else{
            printf("No se encuentra la persona\n");
        }
        burbuja1(dat); // Ordena nuevamente por apellido, nombre y DNI
    }
}

/*
⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ 
⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀ 
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀ 
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀ 
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆ 
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿ 
⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀ 
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ 
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ 
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ 
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀ 
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀ 
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀ 
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀ 
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉
*/