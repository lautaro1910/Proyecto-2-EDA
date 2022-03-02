#define MRAC 11//467

typedef struct RAC{
    Persona Arr[MRAC];
}RAC;       // 0 para celda virgen y 1 para celda libre

void inicializarRAC(RAC *rac){
    int i;
    for(i=0; i<MRAC; i++){
        rac->Arr[i].dni = 0;
    }
}

int LocalizarRAC(RAC rac, int dni, int *pos, int *costo){
    int i, j = 0, k = 1;
    i = hashing(dni, MRAC);
    while(j != MRAC && rac.Arr[i].dni != dni && rac.Arr[i].dni != 0){
        if(rac.Arr[i].dni == 1 && k == 1 ){
            *pos = i;
            k = 0;
        }
        j++;
        i = (i + j)%MRAC;       //PASO
        *costo += 1;
    }
    if(j == MRAC){
        *pos = -1;
        return 2;
    }
    *costo += 1;
    if(rac.Arr[i].dni == dni || k == 1){
        *pos = i;
    }
    return (rac.Arr[i].dni == dni);
}

int AltaRAC(RAC *rac, int dni, Persona p){
    int exito, pos, nada;
    exito = LocalizarRAC(*rac,dni,&pos, &nada);
    if(exito == 0){
        rac->Arr[pos] = p;
        return 1;
    }
    else{
        return 0;
    }
}

int BajaRAC(RAC *rac, int dni, Persona p, int compEstructura){
    int exito, pos, rta, nada;
    exito = LocalizarRAC(*rac,dni,&pos, &nada);
    if(exito == 1){
        if(compEstructura == 0){
            if(CompararPersonas(p,rac->Arr[pos])){
                rta = 1;
            }
            else{
                rta = 2;
            }
        }
        else{
            Imprimir(rac->Arr[pos]);
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
        rac->Arr[pos].dni = 1;
        return 1;
    }
    else{
        return 0;
    }
}

int EvocarRAC(RAC *rac, int dni, Persona *p){
    int exito, pos, nada;
    exito = LocalizarRAC(*rac,dni,&pos, &nada);
    if(exito == 1){
        *p = rac->Arr[pos];
        return 1;
    }
    else{
        return 0;
    }
}

void MostrarRAC(RAC rac){
    int i;
    for(i=0; i < MRAC; i++){
        printf("****************************************\n");
        printf("Posicion %d: \n",i);
        if(rac.Arr[i].dni == 0){
            printf("Virgen\n");
        }
        else{
            if(rac.Arr[i].dni == 1){
                printf("Libre\n");
            }else{
                Imprimir(rac.Arr[i]);
            }
        }
    }
}

void BorrarRAC(RAC *rac){
    int i;
    for(i=0; i<MRAC; i++){
        rac->Arr[i].dni = 0;
    }
}

int PerteneceRAC(RAC rac,int dni){
    int pos, nada;
    if(LocalizarRAC(rac, dni, &pos, &nada) == 1){
        return 1;
    }
    else{
        return 0;
    }
}
