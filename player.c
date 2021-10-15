#include "player.h"
#include <stdio.h>

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
    char arr[13] = {'2','3','4','5','6','7','8','9','10','J','Q','K','A'};
    struct hand* iterator = target->card_list; 
    struct card* temp = &iterator->top;
for (int i = 0; i < 13; i++){
    if (i == 8){
        target->card_list->top.rank[1] = '1'; 
    }
    int x = 0; 
    if(search(target, arr[i]) == 1){
        while(temp != NULL){
            temp = &iterator->next;
            iterator = iterator->next; 
            if (temp->rank == (char*) arr[i]){
                x++;
            }
        }
        if (x == 4){
            return arr[i];
            while(temp != NULL){
                temp = &iterator->next;
                iterator = iterator->next; 
                if (temp->rank == (char*) arr[i]){
                    remove_card(target, temp); 
                } 
        }
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
            if (temp->rank == (char) rank){
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
        if (j == 8){
            target->card_list->top.rank[1] = '1'; 
        }
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
    free(target->card_list); 
    for(int i = 0; i <sizeof(target->book); i++){
        target->book[i] = ""; 
    } 
return 0; 
}
char computer_play(struct player* target){
    char arr[13] = {'2','3','4','5','6','7','8','9','10','J','Q','K','A'};
    char possible[4]; 
    int x = 0; 
    for (int i = 0; i < 13; i++){
        if (i == 8){
            target->card_list->top.rank[1] = '1'; 
        }
       if( search(target, arr[i]) == 1){
           possible[x] = arr[i]; 
           x++;
       } 
    } 
    int y = rand() % x; 
    return possible[y];
}
char user_play(struct player* target){
    int x = 0; 
    while(x == 0){
    char c = getchar(); 
    if (search (target, c) == 0){
        printf("Error = must have at least one card from rank to play");
     
    } else x = 1; 
}
  return 0; 
}
