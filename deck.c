#include "deck.h"
int shuffle(){
    struct deck deck_instance; 
    struct deck temp; 
    char num[13] = {2,3,4,5,6,7,8,9,10,"J","Q","K","A"};
    char Suit[4] = {"C","S","H","D"};
    struct card cards; 
    struct card cardT; 
    int inc, incs = 0; 
    for(int i = 0; i < 52; i++){
        if(i % 13 == 0){
            incs = 0; 
            inc++; 
        }
        cards.rank[0] = num[incs];
        cards.suit = Suit[inc];
        temp.list[i] = cards; 
    }
 deck_instance = temp; 
 srand(time(NULL)); 
 for(int i = 51; i > 0; i--){
     int j = rand() % (i+1);
     cardT = deck_instance.list[i];
     deck_instance.list[i] = deck_instance.list[j];
     deck_instance.list[j] = cardT; 

 }
 return 0; 
}
int deal_player_cards(struct player* target){

}
struct card* next_card(){

}
size_t deck_size(){

}

