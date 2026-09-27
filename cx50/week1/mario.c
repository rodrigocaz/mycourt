#include <stdio.h>
#include <cs50.h>

void print_row(int bricks){
    for(int i = 0; i < bricks; i++){
        printf("#");

    }
}

void print_spaces(int spaces){
    for(int i = 0; i < spaces; i++){
        printf(" ");
    }
}

void print_row2(int bricks){
    for(int i = 0; i < bricks; i++){
        printf("#");

    }
    printf("\n");
}

int main(void){
    int height;
    do{
        height = get_int("Height: ");
    }
    while(height < 1 || height > 8);

    for(int i = 0; i < height; i++){
        print_spaces(height - i - 1);
        print_row(i+1);
        printf(" ");
        printf(" ");
        print_row2(i+1);
    }
}
