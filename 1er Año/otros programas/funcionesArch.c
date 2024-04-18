/*
        ARCHIVOS

f = fopen("secu.txt","r");  //devuelve puntero
fclose(f);   //devuelve int (0 en caso exito)
strerror(errno)  // deveuelve una cadena con descripcion del error (definidir <errno.h> y int errno)
feof(f) //devuelve un int si es fin del archivo (1 en caso de serlo)
fflush(FILE* f); //vacia el buffer de escritura, es int

fseek(FILE *f, long int desplazamiento, int origen)  //ir a una posicion ()
      archivo,  0 o un sizeof         , SEEK_SET (inicio)
                                      , SEEK_END (final)
                                      , SEEK_CUR (random)   

ftell(FILE *f) //devuelve posicion actual (-1 si hay algún error)
rewind(FILE *f) //posiciona al principio del archivo


-TEXTO:
    LEER
    fgets(char* cadena, int longitud, FILE* f);  //leer cadena de archivo abierto ej: fgets(cad,10,f)
    fgetc(FILE* f);  //leer caracter de archivo abierto (en caso de error devuelve EOF)
    fscanf(FILE* f, char* fmt, ...);  //lee datos desde la posición actual ej: fscanf(archivo,"%c",&c) (devuelve int con numero de conversiones con exito)

    ESCRIBIR
    fputs(char* cadena, FILE* f); //escribir cadena, devuelve EOF en caso de error
    fputc(int c , FILE* f);  //excribrir caracter, devuelve EOF en caso de error
    fprintf(FILE* f, char* fmt, ...);  //almacena datos en archivo ej: fprintf(g,"%c",c); (devuelve int con numero de transformaciones con exito)

-BINARIO:
    LEER
    fread(void *ptr, size_t size, size_tcantidad, FILE *archivo)
             &var  ,  sizeof(var) , longitud(1)  , archivo
    
    ESCRIBIR
    fwrite(void *ptr, size_t tamano, size_t cantidad, FILE *archivo);
             &Var   , sizeof(var)  ,  longitud(1)   , archivo
*/
