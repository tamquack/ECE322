#include "player.h"
#include <stdio.h>

int add_card(struct player* target, struct card* new_card){
    /* Allocate space for new element */
    struct hand* temp = target->card_list;
    int i; 
    if(target->hand_size == 0){
    target->card_list = (struct hand*)malloc(sizeof(struct hand));
     if (temp == NULL) { return -1; }
    /* Initialize new element */ 
    temp->top = *new_card; 
    temp->next = NULL;
    
    /* Set list to temp, the new front of list*/
   //  target->card_list = temp; 
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
    int card = 0;  
    struct hand* temp = target->card_list;
    struct hand* previous = target->card_list; 
    if(target->hand_size <= 0){return -1;}
    while(temp != NULL){
        if(temp->top.suit == old_card->suit && temp->top.rank[0] == old_card->rank[0] && temp->top.rank[1] == old_card->rank[1]){
            card = 1;  
        }
        previous = temp; 
        temp = temp->next; 
    }
    if (card == 0){return -1;}
    if(previous == NULL || previous->top.suit == '\0') {
        target->card_list = target->card_list->next;
        free(temp); 
        target->hand_size--; 
        return 0; 
    } else if (temp == NULL || temp->top.suit == '\0'){
        return -1; 
    } else {
        previous->next = temp->next;
        free(temp); 
        target->hand_size--;
        return 0; 
    }
return -1;
}
char check_add_book(struct player* target){
    char arr[13] = {'2','3','4','5','6','7','8','9','10','J','Q','K','A'};
    struct hand* iterator = target->card_list; 
    if (iterator == NULL){return 0;}
for (int i = 0; i < 13; i++){
    int x = 0; 
    if(search(target, arr[i]) == 1){
        while(iterator != NULL){
            iterator = iterator->next; 
            if (iterator->top.rank[0] == arr[i]){
                x++;
            }
        }
        if (x == 4){
            return arr[i];
            while(iterator != NULL){
                iterator = iterator->next; 
                if (iterator->top.rank[0] == arr[i]){
                    remove_card(target, iterator); 
                } 
        }
    } 
}
}
 
return 0; 
}
int search(struct player* target, char rank){
    struct hand* iterator = target->card_list; 
    if (iterator == NULL){return 0;}
    while ( iterator->top.rank != rank ) { /* Check if we found the item */
        iterator = iterator->next; 
        if (iterator == NULL)            
         return 0;                               
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
                add_card(dest, temp);
                remove_card(src,temp);
               x++;
            }
            if (temp == NULL) {return -1;}                       
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
    if(target->book[i] == arr[j]){x++;}
    }
  }
if (x == 7){return 1;}

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
    if(possible[y] == '10'){ printf( '10\n');}
      else{printf('%c\n', possible[y]);}

    return possible[y];
}
char user_play(struct player* target){
    int x = 0;
    char c;  
    char list[3] = ""; 
    while(x == 0){
     c = scanf("%3s",list); 
    while(getchar != '\n'); 
    if (search (target, c) == 0){
        printf("Error = must have at least one card from rank to play"); 
    }else if(list[0] == ""){
        printf("Error = must have at least one card from rank to play");
    } else x = 1; 
}
  return c; 
}
