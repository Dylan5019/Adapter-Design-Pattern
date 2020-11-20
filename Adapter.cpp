#include <iostream>

using namespace std;

class GameCharacter { 
	
	public:
		virtual	void walk(std::string direction) = 0; 
		virtual void jump() = 0; 
}; 

class Player: public GameCharacter { 

	public:
		void walk(std::string direction) { 
			cout << "You move " << direction << "\n"; 
		} 
		void jump() { 
			cout << "leap high into the air "; 
		} 
}; 

class GameNPC { 

	public:
		virtual void stuck() = 0;
        
}; 

class ChefNPC: public GameNPC { 
	public:
		void stuck() { 
			cout << "due to being a chef you are eternaly bound to the ground\n"; 
		}

};

class GameCharacterAdapter: public GameNPC { 

	GameCharacter* gameCharacter; 

	public:
		GameCharacterAdapter(GameCharacter* new_gameCharacter) { 

			gameCharacter = new_gameCharacter; 
		} 

		void stuck() { 
	
			gameCharacter->jump(); 
		} 
};

int main() { 
	Player* player = new Player; 
	GameNPC* gameNPC = new ChefNPC; 

	
	GameNPC* gameCharacterAdapter = new GameCharacterAdapter(player); 



    bool alive = true;
    do {
    std::string direction;
    cout << "You are the Main Character free to roam the world and do as you like\n";
    cout << "What direction would you like to move in? (Forword, Backword, Left, Right)\n";
    cin >> direction;
    player->walk(direction);
    cout << "You Come across a chasm would you like to jump over it?(Yes or No)\n";
    std::string choice;
    cin >> choice;
    if (choice == "Yes"){
      cout << "You ";
      player->jump();
      cout << "landing on the other side of the chasm \n";
    } else {
        cout << "You Chose not to jump and therefore plumit to your untimely death\n";
        break;
    }
    cout << "On The other side of the chasm you run into a chef\n";
    cout << "After interacting with the chef ";
    cout << "He makes you a delicous meal and upon eating it you black out\n";
    cout << "When you wake up, You relize you are in the chef's body\nYou try to move but ";
    gameNPC->stuck();
    cout << "You peak up just in time to watch the chef ";
    gameCharacterAdapter->stuck();
    cout << "over the chasm and flee ";
    alive = false;
    
    
    } while (alive == true);
}
