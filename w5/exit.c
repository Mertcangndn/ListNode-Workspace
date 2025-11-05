#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void exit(Node** head){
    if(*head==NULL){
        printf("\n\n\n------------------------\n");
        printf("Hasta Sirasi Bos!");
        printf("\n------------------------\n\n\n");
        return;
    }

    Node* tempNode = *head;
    while(tempNode!=NULL){
        if(strcmp(tempNode->current,"Muayenede")){
            strcpy(tempNode->current,"Tamamlandi");
        }else{
            tempNode=tempNode->next;
        }
    }

    printf("\n\n\n------------------------\n");
    printf("Islem Tamamlandi!");
    printf("\n------------------------\n\n\n");
}