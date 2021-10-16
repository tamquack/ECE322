#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int shuffle(){
    struct deck deck_instance; 
    struct deck temp; 
    char num[13] = {'2','3','4','5','6','7','8','9','10','J','Q','K','A'};
    char Suit[4] = {'C','S','H','D'};
    struct card cards; 
    struct card cardT; 
    int incs = 0;
    int inc = -1; 
    for(int i = 0; i < 52; i++){
        if(i % 13 == 0){
            incs = 0; 
            inc++; 
        }
         if(incs == 8){
          cards.rank[1] = '1'; 
}
        cards.rank[0] = num[incs];
         cards.suit = Suit[inc];
        temp.list[i] = cards;
        cards.rank[1]=NULL; 
  incs++;
    }
 deck_instance = temp; 

 srand(time(NULL));

 for(int i = 51; i >= 0; i--){
     int j = rand() % (i+1);
     cardT = deck_instance.list[i];
     deck_instance.list[i] = deck_instance.list[j];
     deck_instance.list[j] = cardT; 

 }
 {
    for (int k = 0; k < 52; k++)
        printf("%c%c%c ", deck_instance.list[k].rank[1],deck_instance.list[k].rank[0],deck_instance.list[k].suit);
    printf("\n");
 }
 return 0; 
}
int deal_player_cards(struct player* target){ 
struct deck deck_instance;  
struct card* temp; 
int i = 0, x = 0; 
size_t size = target->hand_size;
while ( i < size){
    while( temp == NULL){
    temp = &deck_instance.list[x];
    x++; 
    }
    add_card(target, temp);
    temp = NULL; 
i++;
}
struct hand* iterator;
iterator = &target->hand_size; 
printf("\nPlayer1 Cards: ");
printf("\n"); 
while(iterator != NULL){

    printf("%c%c%c ", iterator->top.rank[1],iterator->top.rank[0],iterator->top.suit);
iterator = iterator->next;
}
{
    for (int k = 0; k < 52; k++)
        printf("%c%c%c ", deck_instance.list[k].rank[1],deck_instance.list[k].rank[0],deck_instance.list[k].suit);
    printf("\n");
 }
return 0; 
}
struct card* next_card() {
struct deck deck_instance;
struct card temp; 
int len = sizeof(deck_instance.list) / sizeof(temp);
for (int i= 1; i < deck_size(); i++){
deck_instance.list[i] = deck_instance.list[i]; 
} 
deck_instance.list[deck_size() - 1] = temp; 

for (int k = 0; k < 52; k++)
        printf("%c%c%c ", deck_instance.list[k].rank[1],deck_instance.list[k].rank[0],deck_instance.list[k].suit);
    printf("\n");
return 0;
}

size_t deck_size(){
   struct deck deck_instance;
   size_t deck_size = sizeof(deck_instance.list)/sizeof(deck_instance.list[0]);
   return deck_size; 
}

