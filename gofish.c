#include <stdio.h>
#include "card.h"
#include "player.h"
#include "deck.h"

int main(int args, char* argv[]) 
{
//shuffle deck
  shuffle();
//initialize players 
  struct player* user; 
  struct player* computer; 
  int play = 0; 
//deal players 
  deal_player_cards(user); 
  deal_player_cards(computer); 
while(play != 1){
  printf("Player 1's Hand - %s\n",(char*) user->card_list);  
  printf("Player 1's Book - %s\n", user->book); 
  printf("Player 2's Book - %s\n", computer->book);
  
 
  user_play(user); 
  while (check_add_book(user) != 0){
    printf("Player 1's Hand - %s\n", (char*) user->card_list); 
  printf("Player 1's Book - %s\n", user->book); 
  printf("Player 2's Book - %s\n", computer->book);
    user_play(user);
  }
    computer_play(computer); 
    while (check_add_book(computer) != 0){
      printf("Player 1's Hand - %s\n",(char*) user->card_list);  
  printf("Player 1's Book - %s\n", user->book); 
  printf("Player 2's Book - %s\n", computer->book);
      computer_play(computer); 
    }
    if(&game_over){
      printf("Player 1's Hand - %s\n", (char*) user->card_list); 
      printf("Player 1's Book - %s\n", user->book); 
      printf("Player 2's Book - %s\n", computer->book);
      printf("%s Wins! %s-%s\n", "LOL", user->book, computer->book);
      printf("\nDo you want to play again?", argv[1]);
      if (argv[1] == 'N'){
        play = 1;  
        printf("Exiting."); 
      }
    }
}

}
