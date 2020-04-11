# text-based RPG game

Group no.: 148

Team members:
Liu Lihua (3035690593)
Jiang Xingjian ()

A game description with basic game rules

A list of features / functions to implement:

1. Insert player's name
  -File input/output:
    -Store players name in a file of player status. 

2. Display stage status
  -File input/output:
    -Get the data and display from a file with monsters' status according to different game stages.
    -Get the data and display from a file with player's status.
-Data structures for storing game status:
  -Use 2-d array to store hp and attack power of every monster.
  -Use another array to store hp and mp of player. 
-Program codes in multiple files:
  -Display function will be stored in another file to be reused. 
-Dynamic memory management:
  -Release the storage of the array after displayed. Only store the data of current stage. 

3. Insert player's move
  -Player will choose between normal attack and skill. 
-Data structures for storing game status:
  -Will change the hp of a monster and store in the array. 
  -May change the mp of player and store in the array. 

4. Generate monster's move
-Generation of random game sets or events:
  -The monster may have a larger possibility to choose normal attack and a smaller possibility to choose skill attack. 
-Data structures for storing game status:
  -Will change the hp of player and store in the array. 
