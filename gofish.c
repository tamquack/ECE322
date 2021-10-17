#include <stdio.h>
#include "card.h"
#include "player.h"
#include "deck.h"
#include "gofish.h"
int main(int args, char* argv[]) {
     
     int turncounter = 1;
     int winner = 0;
     char bookcheck;
     char Guess, GuessRank;
     char Input;
     struct card fish;
     shuffle();
     deal_player_cards(&user);
     deal_player_cards(&computer);
     
     while (winner == 0){
	 if (game_over(&user) == 1 || game_over(&computer) == 1){
		break;}
	 printHand(&user);
    	 printBooks(&user);
     	 printBooks(&computer);
	
         if (turncounter % 2 == 1) // PLAYER TURN
         {
	    printf("Player 1's turn, enter a Rank: ");
	    GuessRank = scanf("%c",Input); // Change these 2 lines to user_play
	    char Guess = search(&computer,GuessRank);// Guess = 1 if found
	      if (Guess == 0)

		 {
	           printf("   - Player 2 has no %cs",GuessRank);
		   fish = deck_instance.list[deck_instance.top_card];
		   add_card(&user,next_card());
		   printf("   - Go Fish, Player 1 draws %c%c%c",fish.rank[0],fish.rank[1],fish.suit);			   bookcheck = check_add_book(&user);

		   if (bookcheck == 1)
		       {
		        printf("   - Player 1 books %c\n  - Player 1 gets another turn", bookcheck);
		       }
		   else{
			printf("   - Player 2's turn");
			turncounter++;

			}
		   
		
	  	  }

	      else
		  {
	           DispResult(GuessRank); 
		   transfer_cards(&computer,&user,GuessRank);
		   check_add_book(&user);
		   if (bookcheck == 1)
		       {
		        printf("   - Player 1 books %c\n  - Player 1 gets another turn", bookcheck);
		       }
		   else{
			printf("   - Player 2's turn");
			turncounter++;

			}
		  }
	  }


	 else{ // COMPUTER TURN
		GuessRank = computer_play(&user);
		if (Guess == 0)
		 {
	           printf("   - Player 1 has no %cs",GuessRank);
		   fish = deck_instance.list[deck_instance.top_card];
		   add_card(&computer,next_card());
		   printf("   - Go Fish, Player 2 draws %c%c%c",fish.rank[0],fish.rank[1],fish.suit);			   bookcheck = check_add_book(&computer);

		   if (bookcheck == 1)
		       {
		        printf("   - Player 2 books %c\n  - Player 2 gets another turn", bookcheck);
		       }
		   else{
			printf("   - Player 1's turn");
			turncounter++;

			}
		   
		
	  	  }

	        else
		   {
	            DispResult(GuessRank); 
		    transfer_cards(&user,&computer,GuessRank);
		    check_add_book(&computer);
		    if (bookcheck == 1)
		        {
		         printf("   - Player 2 books %c\n  - Player 2 gets another turn", bookcheck);
		        }
		    else{
			 printf("   - Player 1's turn");
			 turncounter++;

			}
		  }
	  }


	      

    } // close the while loop
      return 0;
    
 }
