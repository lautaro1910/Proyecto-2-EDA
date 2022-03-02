#define MRS 11//260
#include "lista.h"

typedef struct RS {
    Lista Arr[MRS];
}RS;

int hashing (int dni , int M) {
    char x [8];
    int longitud, i;
    int contador = 0;
    sprintf(x, "%d", dni);
    longitud = strlen(x);
    for (i=0; i<longitud; i++) {
        contador += ((int)x[i])*(i+1);
    }
    return contador % M;
}

void inicializarRS (RS *rs){
    int i;
    for (i=0; i<MRS; i++){
        inicializarL(&rs->Arr[i]);
    }
}

int LocalizarRS (RS *rs, int dni, int *costo) {
    int i;
    i = hashing(dni, MRS);
    resetL(&rs->Arr[i]);
    while (rs->Arr[i].cur != NULL && rs->Arr[i].cur->vipd.dni != dni){
        forwardL(&rs->Arr[i]);
        *costo += 1;
    }
    if (rs->Arr[i].cur != NULL) {
        *costo += 1;
        return 1;
    }
    else{
        return 0;
    }
}

int BajaRS (RS *rs, int dni, Persona p, int compEstructura) {
    int exito, j, rta, nada;
    exito = LocalizarRS(rs, dni, &nada);
    j = hashing(dni, MRS);
    if (exito == 1){
        if(compEstructura == 0){
            if(CompararPersonas(p,rs->Arr[j].cur->vipd)){
                rta = 1;
            }
            else{
                rta = 2;
            }
        }
        else{
            Imprimir(rs->Arr[j].cur->vipd);
            printf("\n\t¿Eliminar?\n\t1 = Si, deseo eliminar\n\t 2 = No, deseo conservarlo\n");
            scanf("%d",&rta);
            system("cls");
            while(rta<1 || rta>2){
                Imprimir(p);
                printf("Opcion Incorrecta, Por favor seleccione opcion 1 o 2\n¿Eliminar?\n\t1 = Si, deseo eliminar\n\t 2 = No, deseo conservarlo\n");
                scanf("%d",&rta);
                system("cls");
            }
        }
        if(rta == 1){
            supressL(&rs->Arr[j]);
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int AltaRS (RS *rs, int dni, Persona p) {
    int exito, exitoCarga, j, nada;
    exito = LocalizarRS(rs, dni, &nada);
    j = hashing(dni, MRS);
    if (exito == 0){
        exitoCarga = insertL(&rs->Arr[j], p);
        return exitoCarga;
    }
    else{
        return 0;
    }
}

int EvocarRS (RS *rs, int dni, Persona *p) {
    int exito, j, nada;
    exito = LocalizarRS(rs, dni, &nada);
    j = hashing(dni, MRS);
    if (exito){
        *p = copyL(rs->Arr[j]);
        return 1;
    }
    else{
        return 0;
    }
}

void MostrarRS(RS rs){
    int i;
    for(i=0; i<MRS; i++){
        printf("****************************************\n");
        resetL(&rs.Arr[i]);
        printf("Posicion %d: \n",i);
        if(rs.Arr[i].cur == NULL){
            printf("Lista Vacia\n");
        }
        else{
            Imprimir(rs.Arr[i].cur->vipd);
            forwardL(&rs.Arr[i]);
            while(rs.Arr[i].cur != NULL){
                printf("----------------------------------------\n");
                Imprimir(rs.Arr[i].cur->vipd);
                forwardL(&rs.Arr[i]);
            }
        }
    }
}

void BorrarRS(RS *rs){
    int i;
    for(i=0; i<MRS; i++){
        while(rs->Arr[i].cur != NULL){
            supressL(&rs->Arr[i]);
        }
    }
}

int PerteneceRS(RS rs, int dni){
    int nada;
    if(LocalizarRS(&rs, dni, &nada)){
        return 1;
    }
    else{
        return 0;
    }
}
