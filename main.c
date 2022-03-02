#include "RS.h"
#include "RAC.h"

//Dupla: Schuvab Arce Mathias Ezequiel y Soria Borizo Diego Lautaro
//Según lo analizado por nuestro programa,

void cargarPersona(Persona *p);
void cargarEnEstructura(RS *rs, RAC *rac,int opcion2);
int  ingresarDNI(int valor);
void eliminarDeEstructura (RS *rs, RAC *rac,int opcion2);
void buscarPersonaEnEstructura(RS *rs, RAC *rac,int opcion2);
void consultarPersonaEnEstructura(RS *rs, RAC *rac,int opcion2);
void mostrarEstructura (RS rs, RAC rac, int opcion2);
void comparacionDeEstructuras(FILE *fp, RS *rs, RAC *rac);
double divisionPorCero(int numerador, double denominador);

int main()
{
    FILE *fp1;
    if((fp1 = fopen("Operaciones.txt","r"))==NULL);
    int opcion,opcion2,i=1,h=1,j=1;
    RS rs;
    RAC rac;
    inicializarRS(&rs);
    inicializarRAC(&rac);
    do{
        printf("=============MENU PRINCIPAL============\n\n");
        printf(" (1) Administracion de Estructuras\n");
        printf(" (2) Comparacion de Estructuras\n");
        printf(" (3) Salir del Programa\n\n");
        printf(" (4) Hashing\n\n");
        printf("============================Opcion: ");
        scanf("%d",&opcion);
        system("cls");
    while (opcion<1 || opcion>4){
        printf("=============MENU PRINCIPAL============\n\n");
        printf(" (1) Administracion de Estructuras\n");
        printf(" (2) Comparacion de Estructuras\n");
        printf(" (3) Salir del Programa\n\n");
        printf("==============Opcion No valida,ingrese de nuevo: ");
        scanf("%d",&opcion);
        system("cls");
    }
    switch(opcion){
        case 1:
                do{
                    do{
                        printf("===========Seleccione la estructura deseada===========\n\n");
                        printf(" (1) Rebalse Separado (RS)\n");
                        printf(" (2) Rebalse Abierto Cuadratico (RAC)\n");
                        printf(" (3) Volver al menu anterior\n\n");
                        printf("==========================================Opcion: ");
                        scanf("%d",&opcion2);
                        system("cls");
                    }while (opcion2<1 || opcion2>3);
                    if(opcion2!=3){
                        h=1;
                        do{
                            j=1;
                            do{
                                printf("========Operaciones sobre la Estructura===========\n\n");
                                printf(" (1) Ingresar Persona\n");
                                printf(" (2) Eliminar Persona\n");
                                printf(" (3) Buscar Persona\n");
                                printf(" (4) Consultar Informacion de una Persona\n");
                                printf(" (5) Mostrar Estructura\n");
                                printf(" (6) Volver al menu anterior\n\n");
                                printf("=========================================Opcion: ");
                                scanf("%d",&opcion);
                                system("cls");
                            }while(opcion<1 || opcion>6);
                            switch(opcion){
                                case 1:
                                    cargarEnEstructura(&rs,&rac,opcion2);
                                    break;
                                case 2:
                                    eliminarDeEstructura(&rs,&rac,opcion2);
                                    break;
                                case 3:
                                    buscarPersonaEnEstructura(&rs,&rac,opcion2);
                                    break;
                                case 4:
                                    consultarPersonaEnEstructura(&rs,&rac,opcion2);
                                    break;
                                case 5:
                                    mostrarEstructura(rs, rac, opcion2);
                                    break;
                                case 6: j=0;
                                    break;
                            }
                        }while(j);
                    }else{
                        h=0;
                    }
                }while(h);
                break;
        case 2:
                comparacionDeEstructuras(fp1,&rs,&rac);
                break;
        case 3:
                i=0;
                break;
        case 4: printf("%d\n",hashing(11000000,MRS));
                system("pause");
                system("cls");

    }
    }while(i);
    BorrarRS(&rs);
    fclose(fp1);
    return 0;
}

void cargarPersona(Persona *p){
    int rta=1, anio, mes, dia;
    char fechaa[10];
    char fecham[10];
    char fechad[10];
    do{
    //DNI
        do{
            printf("======Cargando Persona======\n");
            printf("Ingrese dni de la Persona: ");
            fflush(stdin);
            scanf("%d",&p->dni);
            system("cls");
        }while(p->dni<10000000 || p->dni>99999999);
    //NOMBRE
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Ingrese nombre de la Persona: ");
        fflush(stdin);
        scanf("%[^\n]",p->nombre);
        system("cls");
    //APELLIDO
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Ingrese apellido de la Persona: ");
        fflush(stdin);
        scanf("%[^\n]",p->apellido);
        system("cls");
    //NRO DE TELEFONO
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Ingrese numero de telefono de la Persona: ");
        fflush(stdin);
        scanf("%[^\n]",p->numTelefono);
        system("cls");
    //DOMICILIO
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Numero de telefono: %s\n",p->numTelefono);
        printf("Ingrese domicilio de la Persona: ");
        fflush(stdin);
        scanf("%[^\n]",p->domicilio);
        system("cls");
    //AÑO
        do{
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Numero de telefono: %s\n",p->numTelefono);
        printf("Domicilio: %s\n",p->domicilio);
        printf("Ingrese a%co desde que esta inhibida la Persona: ",164);
        fflush(stdin);
        scanf("%d",&anio);
        system("cls");
        }while(anio<1950 || anio>2100);
    //MES
        do{
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Numero de telefono: %s\n",p->numTelefono);
        printf("Domicilio: %s\n",p->domicilio);
        printf("Fecha: %d-MM-DD\n",anio);
        printf("Ingrese mes desde que esta inhibida la Persona: ");
        fflush(stdin);
        scanf("%d",&mes);
        system("cls");
        }while(mes<1 || mes>12);
    //DIA
        do{
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Numero de telefono: %s\n",p->numTelefono);
        printf("Domicilio: %s\n",p->domicilio);
        printf("Fecha: %d-%d-DD\n",anio,mes);
        printf("Ingrese dia desde que esta inhibida la Persona: ");
        fflush(stdin);
        scanf("%d",&dia);
        system("cls");
        }while(dia<1 || dia>31);
        itoa(anio,fechaa,10);
        itoa(mes,fecham,10);
        itoa(dia,fechad,10);
        strcat(fechaa,"-");
        strcat(fechaa,fecham);
        strcat(fechaa,"-");
        strcat(fechaa,fechad);
        strcpy(p->fechaInhibicion,fechaa);
        system("cls");
        //re ingreso
        Imprimir(*p);
        printf("Desea modificar la persona?\n1 - SI\n2 - NO\n");
        printf("Ingrese opcion: ");
        scanf("%d", &rta);
        while(rta < 1 || rta > 2){
            printf("Opcion Incorrecta.Desea modificar la persona?\n1 - SI\n2 - NO\n");
            printf("Ingrese opcion: ");
            scanf("%d", &rta);
        }
        system("cls");
    }
    while(rta == 1);
}

void cargarEnEstructura(RS *rs, RAC *rac,int opcion2){
    Persona p;
    int /*costo = 1,*/exito;
    cargarPersona(&p);
    if(opcion2==1){
        exito = AltaRS(rs,p.dni,p);
    }
    else{
        exito = AltaRAC(rac,p.dni,p);
    }
    if(exito){
        if(exito==1){
            printf("\n\n\t %c Se ha cargado exitosamente.  %c\n\n",186,186);
        }
        else{
            printf("\n\n\t %c No se ha podido cargar porque la estructura esta llena.  %c\n\n",186,186);
        }
    }
    else{
        printf("\n\n\t %c No se ha cargardo porque ya exite una persona con ese DNI.  %c\n\n",186,186);
    }
    printf("\t");
    system("pause");
    system("cls");
}

int ingresarDNI (int valor){
    int dni, rta;
    rta=1;
    if(valor == 9){
        do{
            do{
            printf("\n\t%s", "Ingrese DNI de la Persona que desea eliminar: ");
            scanf("%d", &dni);
            system("cls");
            }while(dni<10000000 || dni>99999999);
            printf("\n\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
            printf("%s", "\tIngrese opcion: ");
            scanf("%d", &rta);
            system("cls");
            while (rta < 1 || rta > 2){
                printf("\n\t%s\n", "Opcion incorrecta.");
                printf("\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
                printf("%s", "\tIngrese opcion: ");
                scanf("%d", &rta);
                system("cls");
            }
        }while (rta==1);
    }
    if(valor == 2){
        do{
            do{
            printf("\n\t%s", "Ingrese DNI de la Persona que desea buscar: ");
            scanf("%d", &dni);
            system("cls");
            }while(dni<10000000 || dni>99999999);
            printf("\n\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
            printf("%s", "\tIngrese opcion: ");
            scanf("%d", &rta);
            system("cls");
            while (rta < 1 || rta > 2){
                printf("\n\t%s\n", "Opcion incorrecta.");
                printf("\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
                printf("%s", "\tIngrese opcion: ");
                scanf("%d", &rta);
                system("cls");
            }
        }while (rta==1);
    }
    if(valor == 5){
        do{
            do{
            printf("\n\t%s", "Ingrese DNI de la Persona de la que desea consultar informacion: ");
            scanf("%d", &dni);
            system("cls");
            }while(dni<10000000 || dni>99999999);
            printf("\n\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
            printf("%s", "\tIngrese opcion: ");
            scanf("%d", &rta);
            system("cls");
            while (rta < 1 || rta > 2){
                printf("\n\t%s\n", "Opcion incorrecta.");
                printf("\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
                printf("%s", "\tIngrese opcion: ");
                scanf("%d", &rta);
                system("cls");
            }
        }while (rta==1);
    }
    return dni;
}

void eliminarDeEstructura(RS *rs, RAC *rac,int opcion2){
    int dni, nada = 1;
    Persona p;
    dni = ingresarDNI(9);
    if(opcion2==1){
         if(BajaRS(rs, dni, p, nada)){
            printf("\n\n\t %c Se ha eliminado exitosamente  %c\n\n",186,186);
         }
         else{
            printf("\n\n\t %c No ha sido posible eliminar a la persona  %c\n\n",186,186);
         }
    }
    else{
        if(BajaRAC(rac, dni, p, nada)){
            printf("\n\n\t %c Se ha eliminado exitosamente  %c\n\n",186,186);
        }
        else{
            printf("\n\n\t %c No ha sido posible eliminar a la persona  %c\n\n",186,186);
        }
    }
    printf("\t");
    system("pause");
    system("cls");
}

void buscarPersonaEnEstructura(RS *rs, RAC *rac,int opcion2){
    int dni,exito;
    dni = ingresarDNI (2);
    if(opcion2==1){
        exito = PerteneceRS(*rs,dni);
    }
    else{
        exito = PerteneceRAC(*rac,dni);
    }
    if(exito){
        printf("\n\tLa persona con el dni:%d se encuentra inhibida\n\n\t",dni);
    }
    else{
        printf("\n\tLa persona con el dni:%d no se encuentra inhibida\n\n\t",dni);
    }
    system("pause");
    system("cls");
}

void consultarPersonaEnEstructura(RS *rs, RAC *rac,int opcion2){
    int dni,exito;
    dni = ingresarDNI (2);
    Persona p;
    if(opcion2==1){
         exito = EvocarRS(rs,dni,&p);
    }
    else{
        exito = EvocarRAC(rac,dni,&p);
    }
    if(!exito){
        printf("\n\tLa persona con el dni:%d no se encuentra inhibida\n",dni);
    }
    else{
        printf("===== Persona Inhibida ======\n");
        Imprimir(p);
    }
    printf("\n\n\t");
    system("pause");
    system("cls");
}

void mostrarEstructura (RS rs, RAC rac, int opcion2){
    printf("** MOSTRANDO ESTRUCTURA **\n");
    if (opcion2 == 1){
        printf("Rebalse Separado: \n\n");
        MostrarRS(rs);
    }
    if (opcion2 == 2){
        printf("Rebalse Abierto Cuadratico: \n\n");
        MostrarRAC(rac);
    }
    printf("\n");
    system("pause");
    system("cls");
}

void comparacionDeEstructuras(FILE *fp, RS *rs, RAC *rac){
    int operacion, longitud,costo=0,pos,exito;
    double operacionesRS[2]={0,0}, operacionesRAC[2]={0,0};
    int costoRS[2]={0,0},costoRAC[2]={0,0};
    int mayorRS[2]={0,0}, mayorRAC[2]={0,0};
    rewind(fp);
    Persona p;
    inicializarPersona(&p);
    BorrarRS(rs);
    BorrarRAC(rac);
    while(!feof(fp)){
        costo = 0;
        fscanf(fp,"%d",&operacion);
        if(operacion==1 || operacion==2){
            fscanf(fp,"%d\n",&p.dni);
            fgets(p.nombre, 51, fp);
            longitud = strlen(p.nombre) - 1;
            if (p.nombre && p.nombre[longitud] == '\n'){
                p.nombre[longitud] = '\0';
            }
            fgets(p.apellido, 51, fp);
            longitud = strlen(p.apellido) - 1;
            if (p.apellido && p.apellido[longitud] == '\n'){
                p.apellido[longitud] = '\0';
            }
            fgets(p.numTelefono, 21, fp);
            longitud = strlen(p.numTelefono) - 1;
            if (p.numTelefono && p.numTelefono[longitud] == '\n'){
                p.numTelefono[longitud] = '\0';
            }
            fgets(p.domicilio, 70, fp);
            longitud = strlen(p.domicilio) - 1;
            if (p.domicilio && p.domicilio[longitud] == '\n'){
                p.domicilio[longitud] = '\0';
            }
            fgets(p.fechaInhibicion,11,fp);
            longitud = strlen(p.fechaInhibicion) - 1;
            if (p.fechaInhibicion && p.fechaInhibicion[longitud] == '\n'){
                p.fechaInhibicion[longitud] = '\0';
            }
            if(operacion == 1){ //ALTA
                AltaRAC(rac, p.dni, p);
                AltaRS(rs, p.dni, p);
            }
            if(operacion == 2){ //BAJA
                BajaRAC(rac, p.dni, p, costo);
                BajaRS(rs, p.dni, p, costo);
            }
        }
        if(operacion == 3){ //LOCALIZAR
            fscanf(fp,"%d",&p.dni);
            exito = LocalizarRS(rs, p.dni, &costo);
            if(exito == 1){
                operacionesRS[0] += 1;
                costoRS[0] += costo;
                if(costo>mayorRS[0]){
                    mayorRS[0] = costo;
                }
            }
            else{
                operacionesRS[1] += 1;
                costoRS[1] += costo;
                if(costo>mayorRS[1]){
                    mayorRS[1] = costo;
                }
            }
            costo = 0;
            exito = LocalizarRAC(*rac, p.dni, &pos, &costo);
            if(exito == 1){
                operacionesRAC[0] += 1;
                costoRAC[0] += costo;
                if(costo>mayorRAC[0]){
                    mayorRAC[0] = costo;
                }
            }
            else{
                operacionesRAC[1] += 1;
                costoRAC[1] += costo;
                if(costo>mayorRAC[1]){
                    mayorRAC[1] = costo;
                }
            }
        }
        operacion = 4;
    }
    printf("============================Comparacion de Estructura=============================\n");
    printf("\t\t\t\t\tCosto RS\tCosto RAC\n");
    printf("MAX. LOCALIZACION EXITOSA:\t\t%d\t\t%d\n",mayorRS[0],mayorRAC[0]);
    printf("MED. LOCALIZACION EXITOSA:\t\t%.2f\t\t%.2f\n",divisionPorCero(costoRS[0],operacionesRS[0]),divisionPorCero(costoRAC[0],operacionesRAC[0]));
    printf("MAX. LOCALIZACION FRACASO:\t\t%d\t\t%d\n",mayorRS[1],mayorRAC[1]);
    printf("MED. LOCALIZACION FRACASO:\t\t%.2f\t\t%.2f\n",divisionPorCero(costoRS[1],operacionesRS[1]),divisionPorCero(costoRAC[1],operacionesRAC[1]));
    printf("==================================================================================\n");
    printf("OPERACIONES:\tRS:\tE:%.0f-F:%.0f\t\tRAC:\tE:%.0f-F:%.0f\n",operacionesRS[0],operacionesRS[1],operacionesRAC[0],operacionesRAC[1]);
    printf("SUMA DE COSTOS:\tRS:\tE:%d-F:%d\t\tRAC:\tE:%d-F:%d\n",costoRS[0],costoRS[1],costoRAC[0],costoRAC[1]);
    printf("MAYOR COSTO:\tRS:\tE:%d-F:%d\t\tRAC:\tE:%d-F:%d\n",mayorRS[0],mayorRS[1],mayorRAC[0],mayorRAC[1]);
    system("pause");
    system("cls");
}

double divisionPorCero(int numerador, double denominador){
    if(denominador == 0){
        return 0.0;
    }
    else{
        return (numerador/denominador);
    }
}
