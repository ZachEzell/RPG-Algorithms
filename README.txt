Deep Copy:

Overview: A deep copy is a method of duplicating an object, including all its properties and data members, so that the copied object is a completely separate and independent entity from the original.

Terms:

Dangling Pointer: A dangling pointer is a pointer that points to memory that is no longer valid, either because the memory has been freed or deallocated, or because the memory location has been reused for another purpose.

When working with objects that contain pointer members, a shallow copy can result in a dangling pointer. For example, consider a scenario where we have an object player1 that contains a pointer to an array of scores. If we create a copy of this object using the assignment operator (e.g. player2 = player1), and then delete the original object (player1), the copied object (player2) will still contain a pointer pointing to memory that no longer exists. This results in a dangling pointer, which can cause unpredictable behavior and crashes in the program.

To avoid this issue, a deep copy should be used to ensure that the copied object is a completely separate and independent entity from the original, with its own unique set of memory locations and properties. In the example above, a deep copy would involve allocating new memory for the scores array and copying the values from the original scores array into the new array, rather than simply creating a new pointer to the original scores array.

For example, in C++, a deep copy could be implemented using a copy constructor or an assignment operator that performs a deep copy. In other programming languages, other methods or libraries may be used to perform a deep copy.


Summary:

In the previous code, the assignment operator was not implemented, so when an object was assigned to another object, only the reference to the original object was copied, not the actual values. This resulted in shallow copying, where both objects would reference the same memory location, so any changes made to one object would affect the other.

To prevent this, the assignment operator '=' is overloaded to perform a deep copy, meaning that the values of the original object are copied to a new memory location for the new object. In the implementation, a new linked list is created and the values of the original linked list are copied to the new linked list. This ensures that changes made to one object will not affect the other.


Example:


#include <iostream>

class Player {
  public:
    Player(const Player &p) { // copy constructor
        name = p.name;
        score = new int[p.scoreSize];
        scoreSize = p.scoreSize;
        for (int i = 0; i < scoreSize; i++) {
            score[i] = p.score[i];
        }
    }
    
    // ... other members and functions ...

  private:
    std::string name;
    int *score;
    int scoreSize;
};

int main() {
    Player player1;
    // ... initialize player1 ...

    Player player2 = player1; // deep copy using copy constructor
    // ... manipulate player2 ...

    return 0;
}

In this example, the copy constructor Player(const Player &p) is used to perform a deep copy of the Player object. The deep copy involves creating a new int array score with the same size as the original score array, and copying the values from the original score array into the new array. By creating a new int array, we ensure that the copied object player2 has its own unique set of memory locations and properties, rather than simply creating a new pointer to the original score array.



Q/A:

How is "this" being used in: if(this!= &rhs)?


In the assignment operator overload, the this keyword refers to the current object. So, in the statement if (this != &rhs), the comparison this != &rhs checks if the current object and the object being assigned to it (rhs, which stands for "right hand side") are different instances. If they are the same instance (i.e., this == &rhs), there's no need to perform a deep copy, as both objects would already reference the same memory location. If they are different instances (i.e., this != &rhs), a deep copy is performed.

By using the this pointer, we can ensure that the assignment operator only performs a deep copy if it is assigning an object to a different instance, not when it is assigning an object to itself.




Tutorial Goal:


Add a functionality where

