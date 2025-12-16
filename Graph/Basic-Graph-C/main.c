#include <stdio.h>
#include <stdlib.h>

//Temel Node Yapısı
typedef struct Node{
    int value; //Bu hangi düğüm
    struct Node* next;
}Node;

//Node Oluşurma Fonksiyonu
Node* createNode(int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->value=value;
    newNode->next=NULL;
    return newNode;
}

//Temel Graph Yapısı
typedef struct Graph{
    int totalNode; //Graftaki toplam düğüm sayısını tutan değişken
    struct Node** adjLists; //Pointer dizisi (LinkedList'lerin başı)
    int* visited;   //BFS veya DFS arama yaparken ziyaret edilen node'ları tutar.
}Graph;

//Graph Oluşturma Fonksiyonu
Graph* createGraph(int totalNode){
    Graph* graph = malloc(sizeof(Graph));   //graph için yer açma
    
    graph->adjLists = malloc(totalNode * sizeof(Node)); //graph'ın adjlayer'i için yer açma (toplam node sayısı * 1 Node büyüküğü kdr)
    graph->visited = malloc(totalNode * sizeof(int));   //graph'ın gezilenlari tutma listesi için yer açma (toplam node sayısı * 1 int büyüklüğü)
    
    //adjList'i ve visited listelerini doldurma
    for(int i=0 ; i<totalNode ; i++){
        graph->adjLists[i]=NULL; //Başlangıçta hiçbir node birbirine bağlı değil
        graph->visited[i]=0; //Başlangıçta hiçbir node ziyaret edilmedi (gezilmedi)
    }

    return graph;
}

//Graph'a node ekleme fonksiyonu
void addEdge(Graph* graph, int src, int dest){

    // Kaynaktan Hedefe (src -> dest) bağ ekle
    Node* newNode = createNode(dest);   //yeni node oluşturuldu (src eskiden vardı, dest oluşturuldu ve src'ye bağlanacak)
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    //Eğer yönsüz graph ise tam tersini de eklemelisin. (dest -> src)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph){
    for(int i=0 ; i<graph->totalNode ; i++){
        Node* tempNode = graph->adjLists[i];

        printf("\n %d. Node: ", i);

        while (tempNode) {
            printf("%d -> ", tempNode->value);
            tempNode = tempNode->next;
        }
        printf("NULL")
    }
}

int main(void){
    return 0;
}