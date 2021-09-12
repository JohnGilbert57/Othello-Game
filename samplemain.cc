/*****************************************************
This is a sample of what the main should like for the first phase of the
Othello game.
	John Dolan	Ohio University		Fall 2019
*************************************************************/
#include<iostream>
#include "othello.h"
using namespace std;
using namespace main_savitch_14;


int main(){
  Othello mygame;
	game::who winner;
	winner=mygame.play();
	if (winner == game::HUMAN){
	  std::cout<<"YOU WIN!\n";
  }
	else if(winner == game::COMPUTER){
		std::cout<<"YOU LOSE! TECHNOLOGY IS SUPERIOR TO HUMAN INTELLECT\n";
  }
  else{
    std::cout<<"THE GAME IS A TIE! \n";
  }
  
return 0;
}

