_In this file:_

1. [About Catchphrase](https://github.com/halfling9/catchphrase#about-catchphrase)
2. [How To Play](https://github.com/halfling9/catchphrase#how-to-play)
3. [Gameplay](https://github.com/halfling9/catchphrase#gameplay)
   + [Scoring Points](https://github.com/halfling9/catchphrase#scoring-points)
4. [Scope](https://github.com/halfling9/catchphrase#scope)
5. [Limitations](https://github.com/halfling9/catchphrase#limitations)

# About Catchphrase
Catchphrase is a grid game based off of 2048 made purely out of Turbo C++ (including the graphics libraries) as a Highschool coding Project.

<img src="https://github.com/halfling9/catchphrase/blob/master/outputs/Screenshot%20(24).png?raw=true" />
<br>

# How To Play

The game is pretty straightforward. 

___OBJECTIVE_: You are given a 4x4 grid and you need to merge tiles until the missing letters in the given phrase are filled up.__

An _A_ tile can be merged with another _A_ tile to get a _B_ tile. Similarly, a _B_ tile merges with another _B_ tile to get a _C_ tile and so on.

<img src="https://github.com/halfling9/catchphrase/blob/master/outputs/Screenshot%20(26).png?raw=true" />
<br>

# Gameplay
  
- The player first encounters an empty grid with a single _A_ it. In every subsequent move, a new A appears on each tile of the grid.
- The player uses the keys W, A, S, D to move the entire grid around.


### Scoring Points

Each collision leads to some points being accumulated. For every _B_ tile formed, the player earns 2 points. For a _C_ tile he earns 4 points, _D_ tile he earns 8 and so on with the subsequent powers of 2.

<img src="https://github.com/halfling9/catchphrase/blob/master/outputs/Screenshot%20(44).png?raw=true" />

<br>

# Scope

The scope of the project would be to include more phrases and more difficult levels. The game can be made more interesting by adding different grid sizes like a 3x3 grid or even a 7x7 grid. To make the game more user friendly, there can also be different types of modes such as Timer (where the player’s moves are timed) or Rewind (where the player can be allowed to undo his previous moves). 

<br>

# Limitations

- The program is only made to calculate scores and check for tiles up to the alphabet ‘J’.
- The program will stop as soon as the player gets to the letter J.
- The game does not save progress.

<img src="https://github.com/halfling9/catchphrase/blob/master/outputs/Screenshot%20(45).png?raw=true" />
