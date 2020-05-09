# text-based RPG game

Group no.: 148

#### Team members:
- Liu Lihua (3035690593)
- Jiang Xingjian (3035637759)

#### A game description whith game rule:
This game is an RPG game, in which player will act as an adventurer and try to defeat the monsters during the adventure. 
Player will have Hit Point (HP), Mana Point (MP) and Experience (EXP). Before the adventure, player can choose his skill from a given skill list. During the battle, player and monster will take turns taking action. In player’s turn, player have 3 choices: normal attack (cause a small amount of damage and won’t consume MP), rest (recover some MP), and using skill (consume MP, will cause lots of damage or recover some HP). After the battle, player will get EXP and choose to recover part of HP or MP. If player’s HP become less than 0, the adventure will end as a failure. After some battles, the adventure will end as a success.

#### A list of features / functions to implement:

1. Insert player's name
- File input/output:
  - Store players name in a file of player status. 

2. Display stage status
- File input/output:
  - Get the data and display from a file with monsters' status according to different game stages.
  - Get the data and display from a file with player's status.
- Data structures for storing game status:
  - Use 2-d array to store hp and attack power of every monster.
  - Use another array to store hp and mp of player. 
- Program codes in multiple files:
  - Display function will be stored in another file to be reused. 
- Dynamic memory management:
  - Release the storage of the array after displayed. Only store the data of current stage. 

3. Insert player's move
  - Player will choose between normal attack and skill. 
- Data structures for storing game status:
  - Will change the hp of a monster and store in the array. 
  - May change the mp of player and store in the array. 

4. Generate monster's move
- Generation of random game sets or events:
  - The monster will randomly choose a move. It will also choose skills when it has enough MP.
- Data structures for storing game status:
  - Will change the hp of player and store in the array. 
 

#### non-standard C/C++ libraries: 
No
#### Compilation and execution instructions:
1. Player needs to make a name for his adventurer (less than 20 letters)
2. Every turn the player needs to choose his move by typing 1,2,3 or 4,whose corresponding action is attack,rest, healing and skill attack.
Among them,healing and skill attack require for enough Mp.
3. After the end of the game,you can choose to replay the game.
4. Compile with "Make main" and run with "./main" in terminal.
