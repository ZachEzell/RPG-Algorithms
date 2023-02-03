I am going to implement operator overloading into the game.

Operator Overloading is when a user defines a function that changes
the behavior of an existing operator. 

For example, if I have two instances of a class "Player 1" and "Player 2",
and I want to be able to compare their health directly, we could overload the > symbol
to check if the health of one player is greater than the other.

e.g.

if (Player1 > Player2){ do something }

instead of 

if (Player1->health > player2->health){do something}


To do this, set up a function that describes what the return should look like:


<return type> <name> <operator>(const <Class> &opponent) const
{
    return health > opponent.health;
}


Goal:

Create an operator overload for the ">" operator. Use it after a player's health reaches 0 to check who won
and then use displayMoves function to show.


