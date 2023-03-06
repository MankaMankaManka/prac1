#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include "Player.h"


class Referee
{
	public:
	Referee();
	Player*refGame(Player*player1, Player*player2);
	char m1;
	char m2;
};

Referee::Referee(){
	
}

Player* Referee::refGame(Player*player1, Player*player2){
	m1 = player1->makeMove();
	m2 = player2->makeMove();
	
	if (m1=='R'){
		
		if (m2=='R'){
			return nullptr;
		}else if (m2=='P'){
			return player2;
		}else if (m2=='S'){
			return player1;
		}else return nullptr;
		
	}else if (m1=='P'){
		
		if (m2=='R'){
			return player1;
		}else if (m2=='P'){
			return nullptr;
		}else if (m2=='S'){
			return player2;
		}else return nullptr;
	
	}else if (m1=='S'){
		
		if (m2=='R'){
			return player2;
		}else if (m2=='P'){
			return player1;
		}else if (m2=='S'){
			return nullptr;
		}else return nullptr;
		
	}else return nullptr;
}


int main(){
 Referee a;
 Human b= Human("jeff");
 Computer c;
 Player*player1= &b;
 Player*player2=&c;
 Player*winner= a.refGame(player1,player2);
 if (winner== player1 || winner==player2){
		std::cout << winner->name <<"\n";
 } else{
		std::cout << "It's a Tie\n";
 }
 return 0;
}