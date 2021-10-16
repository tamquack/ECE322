#include <stdio.h>
#include "card.h"
#include "player.h"
#include "deck.h"
#include "gofish.h"
int main(int args, char* argv[]) {
     shuffle();
    


     for(int s =0; s<52; s++) {
      printf("%c%c%c\n", deck_instance.list[s].rank[0],deck_instance.list[s].rank[1], deck_instance.list[s].suit );
             struct card* cardA = next_card();
             struct card cardV = *cardA;
             printf("%c%c%c %u\n", cardV.rank[0],cardV.rank[1], cardV.suit, deck_size());
            printf("%u\n", deck_size());

    }
     return 0;
    
 }