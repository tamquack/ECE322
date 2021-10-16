#include <stdio.h>
#include "card.h"
#include "player.h"
#include "deck.h"

int main(int args, char* argv[]) 
{
shuffle(); 
struct player* pt_user;
struct player user; 
pt_user = &user;   
deal_player_cards(pt_user); 

}
