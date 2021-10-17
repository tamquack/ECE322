#include <stdio.h>
#include "card.h"
#include "player.h"
#include "deck.h"
#include "gofish.h"
int main(int args, char* argv[]) {
     
     int turncounter = 1;
     int winner = 1;

     char Guess, GuessRank, bookcheck, Input, replay, YorN ;
     struct card fish;
     shuffle();
     deal_player_cards(&user);
     deal_player_cards(&computer);
     
     while (1 == 1){
	 hand(&user);
    	 book(&user);
     	 book(&computer);

	 if (1==1)
	 //if (game_over(&user) == 1 || game_over(&computer) == 1)
		{
		break;
		}
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

		   if (bookcheck != 0)
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
    if (game_over(&computer) == 1){
	winner = 2;
	}
    else{
	 winner = 1;
	}

	printf("Player %d Wins! %d-%d\nDo you want to play again[Y/N]:",winner,7,6);
	YorN = scanf("%c",replay);
      return 0;
    
}


void hand(struct player* target)
{
}

void book(struct player* target)
{
}
