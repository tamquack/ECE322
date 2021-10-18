#ifndef GOFISH_H
#define GOFISH_H

/*
   Define any prototype functions
   for gofish.h here.
*/

/*
* Instance variables(Pointers): Turn, Next_Turn 
*
* Points to which player's turn 
*/
struct player* Turn; 
struct player* Next_Turn;

/* Function p_loop
* ------------------
* print loop for player cards and books.
*/
void p_loop(); 


/*
* Function: hand
* ---------------------
*Prints the representations of the cards 
*in target player hand with a new line 
*
* target: human player
*/
void hand(struct player* target); 

/*
*  Function: book
* -----------------------
* Prints book of players, the ranks listed
* in each player's book with a new line
*
* target: The player 
*/
void book(struct player* target);

/*
* Function: DispResult 
* --------------------
* Displays Results from draw, when a card is transferred from one player to another
* it'll print the cards being transferred. 
*
* target: The Player who has the cards
*/
void DispResult(struct player* target, char rank);
#endif
