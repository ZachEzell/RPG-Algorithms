#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Move {
    public:
        int damage;
        Move *next;

        Move(int d) {
            damage = d;
            next = NULL;
        }
};

class Player {
    public:
        int health;
        int attackPower;
        Move *head;

        Player(int h, int a) {
            health = h;
            attackPower = a;
            head = NULL;
        }

        void attack(Player &opponent) {
            int damage = rand() % attackPower + 1;
            opponent.health -= damage;

            Move *newMove = new Move(damage);
            newMove->next = head;
            head = newMove;

            cout << "Player dealt " << damage << " damage to opponent." << endl;
        }

        bool operator>(const Player &opponent) const {
            return health > opponent.health;
        }

        Player& operator=(const Player &rhs) {
            if (this != &rhs) {
                health = rhs.health;
                attackPower = rhs.attackPower;

                Move *current = rhs.head;
                Move *tail = NULL;
                head = NULL;
                while (current != NULL) {
                    Move *temp = new Move(current->damage);
                    if (head == NULL) {
                        head = temp;
                    }
                    else {
                        tail->next = temp;
                    }
                    tail = temp;
                    current = current->next;
                }
            }
            return *this;
        }

        void displayMoves() {
            Move *current = head;
            while (current != NULL) {
                cout << current->damage << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    srand(time(0));

    Player player1(100, 20), player2(100, 20);

    cout << "Player 1 health: " << player1.health << endl;
    cout << "Player 2 health: " << player2.health << endl;

    while (player1.health > 0 && player2.health > 0) {
        player1.attack(player2);
        player2.attack(player1);
        cout << "Player 1 health: " << player1.health << endl;
        cout << "Player 2 health: " << player2.health << endl;
    }

    Player winner(0,0);
    if (player1 > player2) {
        cout << "Player 1 wins!" << endl;
        winner = player1;
    }
    else {
        cout << "Player 2 wins!" << endl;
        winner = player2;
    }

    cout << "Moves performed by the winner: " << endl;
    winner.displayMoves();

    return 0;
}
