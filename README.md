# Game-Of-Life

The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead. Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1. Any live cell with fewer than two live neighbours dies, as if by loneliness.
2. Any live cell with more than three live neighbours dies, as if by overcrowding.
3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
4. Any dead cell with exactly three live neighbours comes to life.

The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed - births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.) The rules continue to be applied repeatedly to create further generations.

## Problem:
The below inputs provide the pattern or initial cells in the universe, especially their (x,y) co-ordinates. The output is the state of the system in the next tick (one run of the application of all the rules) , represented in the same format - i.e. x,y coordinates of all the alive cells after one tick

Input A:
(Block pattern - Still life)

![](https://i.imgur.com/FjNdFkf.png)

Input B
(Boat pattern - Still life)

![](https://i.imgur.com/Dm6iG5G.png)

Input C
(Blinker pattern - oscillator)

![](https://i.imgur.com/zRocQ2O.png)

Input D
(Toad pattern - two phase oscillator)

![](https://i.imgur.com/aTplc3Z.png)

