#include "player.h"

int add_card(struct player* target, struct card* new_card){
    struct hand* temp;  
    temp = (struct hand*)malloc(sizeof(struct hand));
    if (temp == NULL){ return -1; }
    temp = new_card; 
    temp->next = target->card_list;
    target->card_list = temp; 
}
int remove_card(struct player* target, struct card* old_card){
    struct hand* iterator = target->card_list;
    struct hand* previous = NULL; 
    if (iterator == NULL) { return 0; } /* Return false; list is empty */
    while ( iterator != old_card) { /* Check if we found the item */
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
    int temp1, temp2, temp3, temp4; 
    char list1[4], list2[4], list3[4], list4[4]; 
for (int i = 0; i < (int) target->hand_size; i++){
    int j,k,l,m = 0; 
    if(search(target->card_list->next, "C" == 1)) {
     temp1++;
     list1[j] = target->card_list->next; 
     j++;
    } 
    if(search(target->card_list->next, "D" == 1)) {
        temp2++;
        list2[k] = target->card_list->next; 
     k++;
    }
    if(search(target->card_list->next, "S" == 1)){
        temp3++;
        list3[l] = target->card_list->next; 
     l++;
    }
    if(search(target->card_list->next, "H" == 1)){
        temp4++;
        list4[m] = target->card_list->next; 
        m++;
    }
    if (temp1 == 4){
        for (int i = 0; i < j; i++){
        remove_card(target, list1[i]);
        }
    }
        if (temp2 == 4){
            for (int i = 0; i < j; i++){
            remove_card(target, list2[k]);
        }
    }
        if (temp3 == 4){
            for (int i = 0; i < j; i++){
            remove_card(target, list3[l]);
        }
    }
        if (temp4 == 4){
            for (int i = 0; i < j; i++){
            remove_card(target, list4[m]);
        }
    }


}
return 0; 
}
int search(struct player* target, char rank){
    struct hand iterator;
if (strstr(target->card_list->top.rank, rank ) != NULL){
    return 1; 
}
return 0; 
}
int transfer_cards(struct player* src, struct player* dest, char rank){

}
int game_over(struct player* target){

}
int reset_player(struct player* target){

}
char computer_play(struct player* target){

}
char user_play(struct player* target){
    
}
