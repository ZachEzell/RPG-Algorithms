#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>


using namespace std;

class Move
{
    public: 
    Move *next;
    int damage;
    Move(int d){
        damage = d;
        next = NULL;
    }
};

class Player
{
public:
    Move *head;
    int health;
    int attackPower;
    string name;

    Player(int h, int ap, string n)
    {
        health = h;
        attackPower = ap;
        name = n;
    }

    void attack(Player &enemy)
    {
        int damage = rand() % attackPower + 1;
        enemy.health -= damage;

        Move *newMove = new Move(damage);
        newMove->next = head;
        head = newMove;
    }

    void displayMoves()
    {
        Move *current;
        current = head;

        while (current != NULL)
        {   
            cout << name << "did this damage:" << endl;
            cout << current->damage << endl;
            current= current->next;
        }
    }
    
};

int main()
{

    Player player1(100, 20, "Binks"), player2(100, 20, "Stinker");

    while (player1.health > 0 && player2.health > 0) {
        player1.attack(player2);
        player2.attack(player1);
        cout << "Player 1 health: " << player1.health << endl;
        cout << "Player 2 health: " << player2.health << endl;
    }

    if (player1.health <= 0) {
        cout << "Player 2 wins!" << endl;
        player2.displayMoves();
    }
    else {
        cout << "Player 1 wins!" << endl;
        player1.displayMoves();
    }

    return 0;
}