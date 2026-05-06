#include <iostream>
using namespace std;

 
class Player {
public:
    int playerID;
    int score;
    Player* next;

    Player(int id) {
        playerID = id;
        score = 0;
        next = nullptr;
    }
};

 
class Game {
private:
    Player* current;

public:
    Game() {
        current = nullptr;
    }

   
    void addPlayer(int id) {
        Player* newPlayer = new Player(id);

        if (!current) {
            current = newPlayer;
            newPlayer->next = newPlayer; // circular link
        }
        else {
            Player* temp = current;

             
            while (temp->next != current) {
                temp = temp->next;
            }

            temp->next = newPlayer;
            newPlayer->next = current;
        }

        cout << "Player added!\n";
    }

    
    void removePlayer(int id) {
        if (!current) return;

        Player* temp = current, * prev = nullptr;

        // only one player
        if (current->next == current && current->playerID == id) {
            delete current;
            current = nullptr;
            cout << "Game Over\n";
            return;
        }

        do {
            if (temp->playerID == id) {

                 
                if (temp == current)
                    current = current->next;

                
                if (prev == nullptr) {
                    Player* last = current;
                    while (last->next != temp)
                        last = last->next;
                    prev = last;
                }

                prev->next = temp->next;
                delete temp;

                cout << "Player removed!\n";
                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != current);
    }

   
    void nextTurn() {
        if (current) {
            current = current->next;
            cout << "Player " << current->playerID << " turn\n";
        }
    }

     
    void skipTurn() {
        if (current) {
            current = current->next->next;
            cout << "Skipped! Now Player " << current->playerID << " turn\n";
        }
    }

   
    void checkWinner() {
        if (current && current->next == current) {
            cout << "Winner is Player " << current->playerID << endl;
        }
    }

  
    void display() {
        if (!current) {
            cout << "No players\n";
            return;
        }

        Player* temp = current;

        do {
            cout << "Player " << temp->playerID
                << " | Score: " << temp->score << endl;
            temp = temp->next;
        } while (temp != current);
    }
};

 
int main() {

    Game g;

    g.addPlayer(1);
    g.addPlayer(2);
    g.addPlayer(3);
    g.addPlayer(4);

    g.display();

    g.nextTurn();
    g.skipTurn();

    g.removePlayer(2);
    g.display();

    g.checkWinner();

    return 0;
}