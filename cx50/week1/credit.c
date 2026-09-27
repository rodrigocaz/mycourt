#include <stdio.h>
#include <cs50.h>

/*
MISTAKES
# Usar variable aparte para checar checksum
# Estar checando el checksum
# checar el ultimo digito mayor a uno
#funcion calc digitos de cada tarjeta en ints
# solo dividir entre 10 una vez en el checksum en vez de dos veces
#checar el segundo digito de visa en vez del primero
# checar si el numero de la tarjeta era mayor a 100 cuando es mayor o igual (funcion sacar dos ultimos digitos de la tarjeta)
# checar tambien si es valido pero no coincide con la longtiud y el numero con el que empieza
*/

int contador = 0;

int calcNUM(long card){
    while(card >= 100){
        card /= 10;
        contador++;
    }
    return card;
}

int main(void){
    long cardNum, temp;
    int sum1= 0, sum2=0, nluhn=0, last2=0;
    cardNum = get_long("Number: ");
    temp = cardNum;
    while(temp > 0){
        sum1 += (temp % 10);
        temp /= 10;
        nluhn = ((temp % 10) * 2);
        if(nluhn >= 10){
            sum2 += ((nluhn % 10) + (nluhn / 10));
        }
        else{
            sum2 += nluhn;
        }
        temp /= 10;

    }

    sum1 += sum2;

    if(sum1 % 10 != 0){
        printf("INVALID\n");
    }
    else{
        last2 = calcNUM(cardNum);
        if((last2 / 10 == 4) && ((contador == 11) || (contador == 14))){
            printf("VISA\n");
        }
        else if(((last2 > 50) && (last2 < 56)) && (contador == 14)){
            printf("MASTERCARD\n");
        }
        else if(((last2 == 34) || (last2 == 37)) && (contador == 13)){
            printf("AMEX\n");
        }
        else{
            printf("INVALID\n");
        }

    }

    return 0;
}


