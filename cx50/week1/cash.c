#include <stdio.h>
#include <cs50.h>

int main(void){
    int money, quarters=0, dimes=0, nickels=0, pennies=0;
    do{
        money = get_int("Change owed: ");
    }
    while(money < 0);

    while (money >= 25){
        quarters++;
        money -= 25;
    }
    while(money >= 10){
        dimes++;
        money -= 10;
    }
    while(money >= 5){
        nickels++;
        money -= 5;
    }
    while(money >= 1){
        pennies++;
        money-= 1;
    }

    int sum = quarters + dimes + nickels + pennies;

    printf("%i\n", sum);


}
