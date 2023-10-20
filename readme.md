# USE Skill Engine

The future of e-sports

## Installation

Using g++

 ```$> make```

  ```$> ./main```

  edit ```Makefile``` to fit your needs

## USElang syntax

### Write your own code
Nullary function ```PUNCH``` Punch.

Unary functions ```MOVE``` and ```PRINT```:
    MOVE takes a double parameter and moves the player along the x-axis.
    PRINT currently only takes POS as a parameter and prints the current player position.

Examples:

* ```MOVE 10 PUNCH PUNCH```: Moves the player and punches twice.

 * ```MOVE -15 PRINT POS SHOOT MOVE 20```: Moves the player, prints the position, moves the player again.

### Bind with premade .use files

 * ```/example1.use```: Reads the contents of the 1st example