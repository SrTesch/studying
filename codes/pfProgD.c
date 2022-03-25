#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int crescente(const void *x, const void *y){	
	long long int a = *((const long long int*) x), b = *((const long long int *) y);
	if (a<b)
		return -1;
	if (a>b)
		return 1;
	
	return 0;
}

int main(){
    int i, j, k, l, usb, ps2, usbPs2, totalMouses, totalPcs, auxUsb = 0, auxPs2 = 0, auxUsbPs2 = 0;
    long long int valorTotal = 0, valor = 0, *arrayUsb, *arrayPs2, *arrayTotal;
    char *tipo;
    scanf("%d %d %d", &usb, &ps2, &usbPs2);
    scanf("%d", &totalMouses);
    arrayUsb = (long long int*) malloc(totalMouses * sizeof(long long int));
    arrayPs2 = (long long int*) malloc(totalMouses * sizeof(long long int));
    arrayTotal = (long long int*) malloc(totalMouses * sizeof(long long int));
    tipo = (char*) malloc ((5)*sizeof(char));


    for(i = 0; i < totalMouses; i++){
        scanf("%lld %s", &valor, tipo);
        if(strcmp(tipo, "USB") == 0){
            arrayUsb[auxUsb++] = valor;
        }else if(strcmp(tipo, "PS/2") == 0){
            arrayPs2[auxPs2++] = valor;
        }
    }

    qsort(arrayUsb, auxUsb, sizeof(long long int), crescente);
    qsort(arrayPs2, auxPs2, sizeof(long long int), crescente);

    for(i = 0; i < auxUsb; i++){
        if(usb > 0){
            valorTotal += arrayUsb[i];
            usb--;
        }else{
            break;
        }
    }

    for(j = 0; j < auxPs2; j++){
        if(ps2 > 0){
            valorTotal += arrayPs2[j];
            ps2--;
        }else{
            break;
        }
    }

    for(k = i; k < auxUsb; k++){
        arrayTotal[auxUsbPs2++] = arrayUsb[k];
    }

    for(k = j; k < auxPs2; k++){
        arrayTotal[auxUsbPs2++] = arrayPs2[k];
    }
    qsort(arrayTotal, auxUsbPs2, sizeof(long long int), crescente);

    for(l = 0; l < auxUsbPs2; l++){
        if(usbPs2 > 0){
            valorTotal += arrayTotal[l];
            usbPs2--;
        }else{
            break;
        }
    }

    totalPcs = i+j+l;
    printf("%d %lld\n", totalPcs, valorTotal);
    free(tipo);free(arrayPs2);free(arrayUsb);free(arrayTotal);
    return 0;
}
