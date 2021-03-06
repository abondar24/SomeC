//
// Created by abondar on 07.03.16.
//

#include "list.h"
#include<stdlib.h>
#include <string.h>

#include "list.h"

void list_init(List *list, void (*destroy)(void *data)) {
        list->size = 0;
        list->destroy = destroy;
        list->head = NULL;
        list->tail = NULL;

                return;
    };


void list_destroy(List *list){

        void *data;

                //remove each elem
                        while (list_size(list)>0){
                if (list_rem_next(list,NULL,(void **)&data) ==0 && list->destroy !=NULL){
                        list->destroy(data);
                    }
            }
        memset(list,0, sizeof(List));
        return;
    };

// elem- after which to insert
int list_ins_next(List *list, ListElem *elem, const void *data){
         ListElem *new_elem;
     
                 //Allocate strorage for elem
                         if ((new_elem = (ListElem *)malloc(sizeof(ListElem)))==NULL){
                 return -1;
             }
     
                 new_elem ->data = (void *)data;
     
                 //insert to head
                         if (elem==NULL){
                 if (list_size(list)==0){
                         list->tail = new_elem;
                     }
                 new_elem->next = list->head;
                 list->head = new_elem;
             } else{
                 //insert not to head
                         if (elem->next==NULL){
                         list->tail = new_elem;
                     }
         
                         new_elem->next = elem->next;
                 elem->next = new_elem;
             }
     
                 list ->size  ;
         return 0;
     };
 
 int list_rem_next(List *list, ListElem *elem, void **data){
         ListElem *old_elem;
     
                 //no remove from empty
                         if (list_size(list)==0){
                 return -1;
             }
     
                 //remove
                         if (elem==NULL){
                 //from head
                         *data = list->head->data;
                 old_elem = list->head;
                 list->head = list->head->next;
         
                         if(list_size(list)==1){
                         list->tail = NULL;
                     }
         
                     } else{
               //remove  not from head
                         if (elem->next ==NULL){
                         return -1;
                     }
         
                         *data = elem->next->data;
                 old_elem = elem->next;
                 elem->next = elem->next->next;
         
                         if (elem->next ==NULL){
                         list->tail =elem;
                     }
         
                     }
     
                 free(old_elem);
         list->size--;
         return 0;
     
             };