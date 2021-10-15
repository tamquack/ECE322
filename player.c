#include "player.h"

int add_card(struct player* target, struct card* new_card){
    struct hand* temp;  
    temp = (struct hand*)malloc(sizeof(struct hand));
    if (temp == NULL){ return -1; }
    struct card* val = &temp->top; 
    val = new_card; 
    temp->next = target->card_list;
    target->card_list = temp; 
    return 0; 
}
int remove_card(struct player* target, struct card* old_card){
    struct hand* iterator = target->card_list;
    struct hand* previous = NULL;
    if (iterator == NULL) { return 0; } /* Return false; list is empty */
    struct card* temp = &iterator->top;
    while ( temp != old_card) { /* Check if we found the item */
       previous = iterator;               /* Store pointer to previous item */
           iterator = iterator->next;        /* Look at next item in list */
       if (iterator == NULL)             /* Check if end of list */
        return 0;                       /* Return false; didn’t find item */ 
}
if (previous != NULL) 
       previous->next = iterator->next;	/* Remove item from list*/
    else {  
       target->card_list = iterator->next;         /* Set new front of list */
    }
    /* Free memory of item we are removing */
    free(iterator);
    return 1; /* Return true; we found and removed the item */ 
}
char check_add_book(struct player* target){
    int temp1 = 0, temp2 = 0 , temp3 = 0, temp4 = 0; 
    struct card list1[4];
    struct card list2[4];
    struct card list3[4];
    struct card list4[4];
for (int i = 0; i < (int) target->hand_size; i++){
    int j = 0,k = 0,l = 0,m = 0; 
    if(search(target->card_list->top.rank, 'C') == 1) {
     temp1++;
     list1[j] = target->card_list->top; 
     j++;
    } 
    if(search(target->card_list->top.rank, 'D') == 1) {
        temp2++;
        list2[k] = target->card_list->top; 
     k++;
    }
    if(search(target->card_list->top.rank, 'S') == 1){
        temp3++;
        list3[l] = target->card_list->top; 
     l++;
    }
    if(search(target->card_list->top.rank, 'H') == 1){
        temp4++;
        list4[m] = target->card_list->top; 
        m++;
    }
    if (temp1 == 4){
        for (int i = 0; i < j; i++){
        remove_card(target, &list1[i]);
        }
    }
        if (temp2 == 4){
            for (int i = 0; i < j; i++){
            remove_card(target, &list2[k]);
        }
    }
        if (temp3 == 4){
            for (int i = 0; i < j; i++){
            remove_card(target, &list3[l]);
        }
    }
        if (temp4 == 4){
            for (int i = 0; i < j; i++){
            remove_card(target, &list4[m]);
        }
    }


}
return 0; 
}
int search(struct player* target, char rank){
    struct hand* iterator = target->card_list; 
    struct card* temp = &iterator->top;
    while ( temp->rank != rank ) { /* Check if we found the item */
        temp = &iterator->next;
        if (temp == NULL)            
         return 0;                       
        iterator = iterator->next;        
    }
return 1; 
}
int transfer_cards(struct player* src, struct player* dest, char rank){
struct hand* iterator = src->card_list; 
struct card* temp = &iterator->top;
 int i = 0, x = 0;
 if (iterator == NULL || temp == NULL) { return -1;} 
    if (search(src, rank) == 1){
        while ( i != src->hand_size ) { /* Check if we found the item */
            temp = &iterator->next;
            if (temp->rank == rank){
                remove_card(src,temp);
                add_card(dest, temp); 
                x++;
            }
            if (temp == NULL)            
             return 0;                         
            iterator = iterator->next;  
            i++;      
        }
}
return x;
}
int game_over(struct player* target){
int x = 0; 
char arr[13] = {'2','3','4','5','6','7','8','9','10','J','Q','K','A'};
for (int i = 0; i < 7; i++){
    for (int j = 0; j < 13; j++){
    if(target->book[i] == arr[j]){
        x++;
    }
}
}
if (x == 7){
    return 1; 
}
return 0; 
}
int reset_player(struct player* target){
return 0; 
}
char computer_play(struct player* target){
return 0;
}
char user_play(struct player* target){
  return 0; 
}
