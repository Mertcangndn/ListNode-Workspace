#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int number;
    char name[10];
    struct Node* next;
    struct Node* prev;
}Node;

void insertOrdered(Node** head, int number, char name[]){
    Node* newNode = malloc(sizeof(Node));
    strncpy(newNode->name,name,9);
    newNode->name[9]='\n';
    newNode->number=number;
    newNode->next=NULL;
    newNode->prev=NULL;

    Node* tempNode = *head;

    while(1){
        if((*head)==NULL){    //Hiç Node Yoksa
            (*head)=newNode;
            return;
        }

        

        if(tempNode->number>newNode->number){   //Koyulacak yere ulaşıldıysa
            if(tempNode->prev==NULL){   //Tek Node'sa veya İlk Node ise
                tempNode->prev=newNode;
                newNode->next=tempNode;
                (*head)=newNode;
                return;
            }else{ //Ortadaysa
                tempNode->prev->next=newNode;
                newNode->next= tempNode;
                return;
            }
        }else if(tempNode->next==NULL){ //Sona gelindiyse
            tempNode->next=newNode;
            newNode->prev=tempNode;
            return;
        }

        tempNode=tempNode->next;
    }
}

void displayForward(Node* head){
    printf("\n\n----------------------------\n");
    while(head!=NULL){
        printf("Number: %d  Name: %s\n",head->number,head->name);
        head=head->next;
    }
    printf("----------------------------\n\n");
}

void displayBackward(Node* head){
    if(head==NULL){
        return;
    }

    displayBackward(head->next);

    printf("Number: %d  Name: %s\n",head->number,head->name);
}

void menu(void){
    
    int select;
    char name[10];
    int number;
    Node* x = NULL;
    
    while(1){
        printf("\n\n\n");
        printf("[1] Öğrenci Girişi Yap\n");
        printf("[2] Öğrencileri Baştan Yazdır\n");
        printf("[3] Öğrencileri Sondan Yazdır\n");
        printf("[0] Çıkış Yap\n\n\n");
        
        scanf("%d",&select);
        
        switch(select){
            case 1:
                printf("Bir Numara Girin: ");
                scanf("%d",&number);
                printf("Bir İsim Girin: ");
                scanf("%s",name);
                insertOrdered(&x,number,name);
                printf("\n\nİŞLEM BAŞARIYLSA GERÇEKLEŞTİ!\n\n");
                break;
             case 2:
                displayForward(x);
                break;
            case 3:
                printf("\n\n----------------------------\n");
                displayBackward(x);
                printf("----------------------------\n\n");
                break;
            case 0:
                if(x!=NULL){
                    while (x!=NULL && x->next==NULL){
                        Node* temp = x;
                        x = x->next;
                        free(temp);
                    }
                }
                return;
            default:
                printf("Yanlış Seçim, Lütfen Tekrar Deneyin.\n");
                break;
        }
    }
}

int main(void){

    menu();


    return 0;
}