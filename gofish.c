#include <stdio.h>
#include "card.h"
#include "player.h"
#include "deck.h"
#include "gofish.h"
int main(int args, char* argv[]) {
     
     int turncounter = 1;
     int winner = 1;

     char Guess, GuessRank,GuessR, bookcheck;
     char replay[20] ;if(replay==NULL) {return -1;} 
     struct card fish;
	 shuffle();
	 do{
	 reset_player(&user);
	 reset_player(&computer); 
     deal_player_cards(&user);
     deal_player_cards(&computer);
	 int counter1 = 0;
	 int counter2 = 0; 
     
     while (1 == 1){
	 hand(&user);
	 printf("\nPlayer 1's Book: "); 
	 book(&user);
	 printf("\n");
	 hand(&computer); 
	 printf("\nPlayer 2's Book: "); 
     	 book(&computer);

	 //if (1==1)
	 	if (game_over(&user) == 1 || game_over(&computer) == 1)
			{
			break;
			}
		if (turncounter % 2 == 1) // PLAYER TURN
		{
			GuessRank = user_play(&user); 
			if (search(&computer,GuessRank) == 0)// Guess = 1 if found
			//if (Guess == 0)
			{
				printf("   - Player 2 has no %cs\n",GuessRank);
				fish = deck_instance.list[deck_instance.top_card];
				add_card(&user,next_card());
				printf("   - Go Fish, Player 1 draws %c%c%c\n",fish.rank[1],fish.rank[0],fish.suit);
				if (fish.rank[0] == GuessRank)
				{
					if (user.book[counter1] != '\0')
				{
					bookcheck = user.book[counter1]; 
					counter1++;
					printf("   - Player 1 books %c\n", bookcheck);
				}
					printf("\n  - Player 1 gets another turn {Fishpath}\n");
					continue;
				}			   

				if (user.book[counter1] != '\0')
				{
				    bookcheck = user.book[counter1]; 
					counter1++;
					printf("   - Player 1 books %c\n", bookcheck);
						printf("\n  - Player 1 gets another turn\n");
				} 
				//if fish.rank[]  //Create this edge case
				else
					{
						printf("   - Player 2's turn\n");
						turncounter++;
					}			
			}

			else
			{
			printf("Player 1 Has: ");
			DispResult(&user, GuessRank);
			printf("Player 2 Has: ");
			DispResult(&computer, GuessRank);
				transfer_cards(&computer,&user,GuessRank);
				bookcheck = check_add_book(&user);

				if (user.book[counter1] != '\0')
				{ bookcheck = user.book[counter1]; 
					counter1++; 
				printf("   - Player 1 books %c\n", bookcheck);
				}
				printf("   - Player 1 gets another turn\n");
				
			}
		} // end of player turn


		else
		{ // COMPUTER TURN
			GuessR = computer_play(&computer); //should be computer_play
			printf("   - Player 2's turn, enter a Rank:%c \n",GuessR);
			if (search(&user,GuessR) == 0)// Guess = 1 if found
			{
				printf("   - Player 1 has no %cs\n",GuessR);
				fish = deck_instance.list[deck_instance.top_card];
				add_card(&computer,next_card());
				printf("   - Go Fish, Player 2 draws %c%c%c\n",fish.rank[1],fish.rank[0],fish.suit);
				if (fish.rank[0] == GuessRank)			   
				{if(computer.book[counter2] != '\0'){
						bookcheck = computer.book[counter2]; 
						printf("   - Player 2 books %c\n", bookcheck);
						counter2++;
					}
					printf("\n  - Player 2 gets another turn {Fishpath}\n"); 
					
					continue; 
				}

				if (computer.book[counter2] != '\0')
				{
					bookcheck = computer.book[counter2]; 
					printf("   - Player 2 books %c\n  - Player 2 gets another turn\n", bookcheck);
					counter2++;
				}
				else
				{
				printf("   - Player 1's turn\n");
				turncounter++;
				}
			
			
			}

				else
			{
				printf("   - Player 2 Has: " );
					DispResult(&computer, GuessR); 
				printf("   - Player 1 Has: ");
				    DispResult(&user, GuessR); 
				transfer_cards(&user,&computer,GuessR);
				 
				if (computer.book[counter2] != '\0')
					{
						bookcheck = computer.book[counter2]; 
						counter2++;
					printf("   - Player 2 books %c\n", bookcheck); 
					}
				printf("   - Player 2 gets another turn\n");

				
			}
		}


	if(deck_size() == 52){
		break; 
	}		

	} // close the while loop
	if (game_over(&computer) == 1)
	{
	winner = 2;
	}
	else
	{
	winner = 1;
	}

	printf("Player %d Wins! %d-%d\nDo you want to play again[Y/N]:\n",winner,7,6);
	scanf("%s",replay);
	while(replay != 'Y' || replay != 'N'){
		if (replay == 'N'){
			break; 
		}
		else if(replay == 'Y'){
			shuffle();
			break;
		}
		else{
			printf("Please enter Y/N:\n");

		}
	}
if (replay == 'N'){
	break; 
} 
    
}while(1);

}

void hand(struct player* target){
	struct hand* temp = target->card_list; 
	printf("\nPlayer 1's Hand:");
	if (target->hand_size == 0 || target == NULL ){
		printf("\n");
		return; 
	}
for (int i = 0; i < target->hand_size; i++){
	printf(" %c%c%c",temp->top.rank[1], temp->top.rank[0], temp->top.suit );
	temp = temp->next;
}
}
void book(struct player* target)
{
	for(int i = 0; i < 7 && target->book[i] != '\0'; i ++){
		printf("%c ", target->book[i]); 
	}
	printf("\n"); 
	return; 
}
void DispResult(struct player* target, char rank){
	int n = 0; 
	struct hand* playerH = target->card_list; 
	for (int i = 0; i < target->hand_size; i ++){
		if (playerH->top.rank[0] == rank && n == 0){
			printf("%c%c%c",playerH->top.rank[1], playerH->top.rank[0], playerH->top.suit);
			n++; 
		}
		else if(playerH->top.rank[0] == rank){
			printf(", %c%c%c",playerH->top.rank[1], playerH->top.rank[0], playerH->top.suit);
		}
		playerH = playerH->next;
	}
	printf("\n");
	return; 
}
 