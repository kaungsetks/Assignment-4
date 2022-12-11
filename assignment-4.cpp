#include "stdio.h"

int main(){

    int b= 0;

    printf("How many numbers do you want to type:");
    scanf("%d",&b);

    char input_word[b];
    printf("Please type the word that you want to find:\n(***Numbers of words should be same with the numbers before you type)\n");

    for (int l = 0; l < b; l++) {
        scanf(" %c",&input_word[l]);
    }




    char text_word[10000];

    FILE *fptr;
    fptr = fopen("testing.txt","r");
    char word = fgetc(fptr);
    int i =0;

    while(word != EOF){
        text_word[i] = word;
        word =  fgetc(fptr);
        i++;
    }

    int total = 0;


    for (int j = 0; j < i; j++){
        for (int k = 0; k < sizeof(input_word); k++) {
            if(text_word[j] == input_word[0] && text_word[j+1] == input_word[1] && text_word[j+2] == input_word[2] && text_word[j + sizeof(input_word)-1] == input_word[sizeof(input_word)-1] && text_word[j + sizeof(input_word)-2] == input_word[sizeof(input_word)-2] ){
                total++;
            }


        }
    }

    printf("%d\n",total/sizeof(input_word));




    return 0;
}

