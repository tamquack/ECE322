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
  printf("Player 1's Hand - %c", user->card_list); 
  printf("\n"); 
  printf("Player 1's Book - %c", user->book);
  printf("\n"); 
  printf("Player 2's Book - %c", computer->book);
  printf("\n");
  
 
  user_play(user); 
  while (check_add_book(user) != 0){
    printf("Player 1's Hand - %c", user->card_list); 
  printf("\n"); 
  printf("Player 1's Book - %c", user->book);
  printf("\n"); 
  printf("Player 2's Book - %c", computer->book);
  printf("\n");
    user_play(user);
  }
    computer_play(computer); 
    while (check_add_book(computer) != 0){
      printf("Player 1's Hand - %c", user->card_list); 
  printf("\n"); 
  printf("Player 1's Book - %c", user->book);
  printf("\n"); 
  printf("Player 2's Book - %c", computer->book);
  printf("\n");
      computer_play(computer); 
    }
    if(game_over){
      printf("Player 1's Hand - %c", user->card_list); 
      printf("\n"); 
      printf("Player 1's Book - %c", user->book);
      printf("\n"); 
      printf("Player 2's Book - %c", computer->book);
      printf("\n");
      printf("%s Wins! %c-%c", game_over.winner, user->book, computer->book);
      printf("\n");
      printf("\n");
      printf("Do you want to play again?", argv[1]);
      if (argv[1] == "N"){
        play = 1;  
        printf("Exiting."); 
      }
    }
}

}
