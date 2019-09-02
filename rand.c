#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
void main(void)
{
    /*int array[16];
    for(int i=1;i<16;i++){
        array[i]=i;
        printf("%d\n", array[i]);
    }
    for(int i=1;i<16;i++){
        int temp=array[i];
        int randomIndex=rand()%16;
        }
        printf("after\n");
    for(int i=0;i<16;i++){
        printf("%d\n", array[i]);
    }*/
    int card[13];
    int i, j, temp;

    srand(time(NULL));
    for(i=0;i<13;i++)
        card[i]=i+1;

    for(j=0;j<13;j++)
        printf(" %d", card[j]);

    for(i=0;i<13;i++){
        j=(rand()%12)+1;
        temp=card[i];
        card[i]=card[j];
        card[j]=temp;
    }
    printf("\n\n--------------------------------\n\n");

    for(i=0;i<13;i++)
        printf(" %d", card[i]);



}
