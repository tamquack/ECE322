#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int shuffle(){
    //struct deck deck_instance; 
    deck_instance = *(struct deck*)malloc(sizeof(struct deck));

    char num[14] = {'2','3','4','5','6','7','8','9','0','J','Q','K','A'};
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
        deck_instance.list[i] = cards;
        cards.rank[1]='\0'; 
  incs++;
    }
deck_instance.list[0].rank[1] = '\0';
 srand(time(NULL));

 for(int i = 51; i >= 0; i--){
     int j = rand() % (i+1);
     cardT = deck_instance.list[i];
     deck_instance.list[i] = deck_instance.list[j];
     deck_instance.list[j] = cardT; 

 }
 
 deck_instance.top_card = 0; 
 printf("Shuffling deck...\n");
 return 0; 
}


int deal_player_cards(struct player* target){ 
    int i = 0;
struct card* card; 
while (i < 7){
        card = next_card(); 
        if (card == NULL){
            return -1; 
        }
        add_card(target, card);
        i++;  
}
struct hand* iterator = target->card_list; 
if (iterator == NULL){
    printf("\nRIP"); 
} 
return 0; 
}
struct card* next_card() {
    if (deck_instance.top_card < 51)
    {
        //deck_instance.top_card++;
        return &deck_instance.list[deck_instance.top_card++];
    }
    else
        printf("finished deck");
        return NULL;
}

size_t deck_size(){
    if (deck_instance.top_card >= 51){
        return 51; 
    }
   return deck_instance.top_card; 
}
