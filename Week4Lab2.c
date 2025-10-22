#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char c;
    struct Node* next;
}Node;

//Eğer stack boşsa 1, doluysa 0 döndüren fonksiyon.
int isEmpty(Node* top){
    if(top==NULL){
        return 0;
    }else{
        return 1;
    }
}

//Node ekleme fonksiyonu
void push(Node** Top,char c){
    //Yeni node oluşturma
    Node* newNode = malloc(sizeof(Node));
    newNode->c=c;
    newNode->next=NULL;

    //Geçici Node

    //Eğer hiç Node yoksa
    if(isEmpty){
        (*Top)=newNode;
        return;
    }else{  //Eğer başka karakter varsa
        newNode->next=*Top;
        *Top=newNode;
        return;
    }
}

int pop(Node** top,char c){
    Node* tempNode = *top;

    if(isEmpty(top)){
        return -1; //Karakter yokken parantez kapatma koymak dengeyi engeller.
    }else{
        tempNode->c==c //BIRAYI ASCII İLE YAP
    }
}

void balance(Node** top,char str[]){
    char tempC;
    for(int i=0 ; i<20 && str[i]!=NULL ; i++){  //dizi bitmediği ve girdi tükenmediği sürece
        tempC = str[i]; //teker teker karakterleri alıyor.
        switch(tempC){
            //Ekleme
            case '(':
                push(top,tempC);
                break;
            case '[':
                push(top,tempC);
                break;
            case '{':
                push(top,tempC);
                break;
            //Çıkartma
            case '[':
                pop(top,tempC);
                break;
        }
        
    }
}

void menu(){
    int select;
    char str[20];
    for(int i=0;i<20;i++){  //String'in içini boşaltma (Garbage değerlerden kurtulma)
        str[i]=NULL;
    }
    Node* x = NULL;
    
    while(1){
        printf("\n\n\n");
        printf("Parantez Girişi Yapınız: ");
        scanf("%s",str);
        

    }
}

int main(void){

    menu();

    return 0;
}