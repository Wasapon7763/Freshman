#include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>


 typedef struct _item{
    char* name;
    struct _item* prev;
    struct _item* next;
 }Item;

 typedef struct{
    Item* head;
    Item* tail;
    Item* cur;
 }List;


 void show(List* list){
    Item* temp;
    temp = list->head;
    while(temp){
      printf("%s\n", temp->name);
      temp = temp->next;
    }
 }

 void connect(Item* prev, Item* next, List* list){
    if(prev == NULL){
      next->prev = NULL;
      list->head = next;
    }else if(next == NULL){
      prev->next = NULL;
      list->tail = prev;
    }else{
      prev->next = next;
      next->prev = prev;
    }
 }

 Item* additem(List* list, char* name){
    Item* newitem;
    newitem = (Item*)malloc(sizeof(Item));

    if(list->cur == NULL){
      connect(NULL, newitem, list);
      connect(newitem, NULL, list);
    }else{
      connect(newitem, list->cur->next, list);
      connect(list->cur, newitem, list);
    }

    newitem->name = name;
    list->cur = newitem;
    return newitem;
 }




 List* new_list(void){
    List* list;
    list = (List*)malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;
    list->cur  = NULL;
 }


 void keyword(List* list){
    Item* temp;
    int i=0;
    temp = list->head;
    while(temp){
        printf("%c", tolower(temp->name[0])+2);
        temp = temp->next;
    }
    printf("\n");
 }

 void delitem(List* list){
    connect(list -> cur -> prev, list -> cur ->next, list);
    free(list -> cur);
 }
 void push(List* list, char* str){
    list -> cur = list -> tail;
    additem(list,str);
 }

 void pop(List* list){
    list -> cur = list -> tail;
    printf("pop: %s\n", list -> tail -> name);
    delitem(list);
 }



 int main(void){  // ‚±‚±‚Í‚¢‚¶‚ç‚È‚¢
   List* list = new_list();
    push(list, "DeepPurple");
    push(list, "ASIA");

    pop(list);
    push(list, "Iron Maden");
    push(list, "Bon Jovi");
    pop(list);
    pop(list);
    push(list, "RIOT");
    push(list, "Van Halen");
    pop(list);
    pop(list);
    push(list, "Metallica");
    push(list, "Def Leppard");
    push(list, "Aerosmith");
    push(list, "Rainbow");
    pop(list);
    pop(list);
    pop(list);
    push(list, "Stryper");
    push(list, "KISS");
    push(list, "AC/DC");
    push(list, "Extreme");
    pop(list);
    pop(list);
    pop(list);
    push(list, "Pantera");
    show(list);
    printf("\n");
    keyword(list);
    return 0;
 }