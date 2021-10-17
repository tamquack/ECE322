#include "player.h"
#include <stdio.h>

int add_card(struct player* target, struct card* new_card){
    /* Allocate space for new element */
    struct hand* temp = target->card_list;
    int i; 
    if(target->hand_size == 0){
    temp = (struct hand*)malloc(sizeof(struct hand));
    // if (temp == NULL) { return -1; }
    /* Initialize new element */ 
    temp->top = *new_card; 
    temp->next = NULL;
    
    /* Set list to temp, the new front of list*/
    target->card_list = temp;  
    } else{ 
        for(i = 0; i < target->hand_size-1; i++){
            temp = temp->next; 
        }
     if (temp == NULL || i != target->hand_size -1) { return -1; }
    /* Initialize new element */ 
    temp->next = (struct hand*)malloc(sizeof(struct hand));
    temp->next->top = *new_card; 
    temp->next->next = NULL; 
    }
    target->hand_size++;

    return 0; 
}
int remove_card(struct player* target, struct card* old_card){
    int i = 0, card = 0; 
    struct hand* iterator = target->card_list;
    struct hand* previous = NULL; 
    if (iterator == NULL) {return -1; } /* Return false; list is empty */
    while(i < target->hand_size){
        if(iterator->top.suit == old_card->suit 
            && iterator != NULL
            && iterator->top.rank[0] == old_card->rank[0]
            && iterator->top.rank[1] == old_card->rank[1]){
            card = 1; 
            break; 
        }
        previous = iterator; 
        iterator = iterator->next;
        i++;
    }
     
    if(card == 0){return -1;}
     /* Found item; break out of loop */
     if (previous == NULL || previous->top.suit == '\0'){
         target->card_list = target->card_list->next;
       target->hand_size--;	
       return 0; 
       }  else if(iterator == NULL || iterator->top.suit == '\0') { 
        return -1;        
     } else {
         previous->next = iterator->next; 
         target->hand_size--; 
         free(iterator);
         return 0; 
     }
     return -1; 
 }
char check_add_book(struct player* target){
    struct hand* temp = target->card_list;
    struct card card1; 
    struct card card2;
    struct card card3; 
    int counter = 0, i = 0, n = 0;  
    while (counter < target->hand_size - 1 && temp->next != NULL){
        temp = temp->next; 
        counter++; 
    }
    struct card last_card = temp->top;
    struct hand* last_hand = target->card_list; 
    char c[2], d[2]; 
    for (int j = 0; j < 2; j++){ 
        c[j]= last_card.rank[j];
        }
    while(i < target->hand_size - 1 && last_hand != NULL){
        for (int j = 0; j < 2; j++){ 
            d[j]= last_hand->top.rank[j];
            }
            i++;
            last_hand = last_hand->next; 
            if (i >= target->hand_size-1 || last_hand == NULL){
                return 0; 
            }
                if(n == 1 && c[0] == d[0] && c[1] == d[1]){
                    card1= last_hand->top; 
                } else if (n == 2 && c[0] == d[0] && c[1] == d[1]){
                    card2 = last_hand->top;
                }
                else if (n == 3 && c[0] == d[0] && c[1] == d[1]){
                    card3 = last_hand->top;
                    n++; 
                }
                else{return 0; }
                if (c[0] == d[0] && c[1] == d[1]){n++;}

    }
    if (n == 4){
        char rank[2]; 
        rank[0] = card1.rank[0]; 
        rank[1] = card1.rank[1]; 
        for (i = 0; i < 7; i++){
            if(target->book[i] == '\0'){
                target->book[i] = rank[0]; 
                break; 
            }
        }      
    remove_card(target, &card1);
    remove_card(target, &card2);
    remove_card(target, &card3);
    remove_card(target, &last_card);

    return rank[0]; 
    }

    return 0; 
}
int search(struct player* target, char rank){
    struct hand* iterator = target->card_list; 
    if (iterator == NULL){return 0;}
    while ( iterator->top.rank[0] != rank ) { /* Check if we found the item */
        iterator = iterator->next; 
        if (iterator == NULL){ return 0;}                               
    }
return 1; 
}
int transfer_cards(struct player* src, struct player* dest, char rank){
struct hand* iterator = src->card_list; 
 int i, x = 0;
 if (search(src, rank) == 0) {return 0; }
 for (i = 0; iterator != NULL; i++){
     
     if(iterator->top.rank[0] == rank){
        add_card(dest, &iterator->top);
         remove_card(src, &iterator->top);
         x++; 
     }
     
     iterator = iterator->next;

 }
 if (i != src->hand_size){
     return -1; 
 }
 return x; 
}
int game_over(struct player* target){
    int x = 0; 
    for (int i = 0; i < 7; i++){
        if (target->book[i] != '\0'){
            x++;
        }
    }
    if (x == 7){
        return 1; 
    }
    return 0; 
}
int reset_player(struct player* target){
    struct card* temp = &target->card_list->top; 
  while(target->card_list != NULL){
      remove_card(target, temp); 
  }
  int i; 
  for ( i = 0; i <7; i++){
      target->book[i] = '\0'; 
  }
  if (i != 7 || target->hand_size != 0 || target->card_list != NULL){
      return -1; 
  }
  return 0; 
}
char computer_play(struct player* target){
    int len = rand() % target->hand_size; 
    struct hand* play = target->card_list; 
    for(int i = 0; i <= len; i++){
        play = play->next; 
    }
    return play->top.rank[0];
}
char user_play(struct player* target){
     char letter; 
     int x = 0; 
     while(x == 0){
         printf("Player 1's turn, enter a rank: ");
         char list[4] = ""; 
         scanf("%3s", list);
         while(getchar() != '\n');

         if(list[1] == '\0'){
             letter = list[0];
             x = 1;  
         }
         else {
             printf("Error - must have at least one card from rank to play\n");
             continue;
         }
         printf("Error - must have at least one card from rank to play\n");
        }
        return letter; 
}
