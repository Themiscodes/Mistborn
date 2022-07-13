# Mistborn: RPG written in C++
Mistborn is a terminal-based role-playing game I created with the purpose of taking full advantage of the object oriented features of C++. The magic system, along with the worldbuilding, is based on the Mistborn fantasy novels by Brandon Sanderson.

## Compilation & Execution 
* To build the game:
`$ make`

* To start the game: 
`$ ./mistborn`

## Screenshot

![mist](https://user-images.githubusercontent.com/73662635/168314721-3f391686-06bc-49ae-b59b-698c961c5ad8.png)

## Implementation
Αs my focus was in using the concepts of inheritance, polymorphism, dynamic memory allocation, function overloading and data abstraction that C++ provides I separated the program files in the following way:

* The basic structure of a round is in main.cpp and the functions responsible for the user interaction in messages.cpp. 

* The rest of the files contain the objects of the game in separate classes that inherit from each other accordingly. 

### Gameplay
Mistborn being a text-based strategy game the player is presented with options in each round. They can move through the grid, encounter monsters and battle them, access their inventory or map, equip themselves with a weapon or armour, take potions and visit a market to buy or sell items. 

The heroes move across a 19X19 grid (the dimensions of a Go board) except for a few blocks that are unavailable to them. The goal of the game is to simply to survive as long as possible and reach the highest level.

### Economy
In terms of the game economy I chose to have a realistic, but rather simple model for the markets. Each market has a storage where only up to a certain number of weapons, armours, potions and spells are kept. 

When the player purchases an item they acquire not a copy or a reference to it, but the item itself. Also, the heroes can sell what they already own from their inventory. Finally, to simulate the stores' supply chain, periodically each market is resupplied with a new stock of items.

### Battle
The battles are turn-based, in the fashion of role-playing games like Persona, where the team of heroes and monsters alternate turns till one is defeated. Aiming to make the game difficult enough to be enjoyable, but at the same time not impossible, to defeat the enemies aside from basic attacks it is vital for the player to cast spells strategically. 

As the heroes level up they encounter higher level enemies. These can only be defeated with buying more expensive weapons and since the only revenue of the player is through winning battles, they have to strike a balance between what they spend their money on and in picking their battles.
