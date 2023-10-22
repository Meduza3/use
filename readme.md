# USE Skill Engine

The future of e-sports

## Installation

Install SFML.

On Arch Linux:

  ```$> yay -S sfml```

Using g++

 ```$> make```

  ```$> ./main```

  edit ```Makefile``` to fit your needs

## USElang syntax

### Write your own code
Nullary function ```PUNCH```:
    Punch.

Unary function ```PRINT```:
    PRINT currently only takes POS as a parameter and prints the current player position.

Binary function ```MOVE```:
    MOVE takes X, Y or Z as the first parameter and then a double value for the distance.

Examples:

* ```MOVE X 10 PUNCH PUNCH```: Moves the player and punches twice.

 * ```MOVE Y -15 PRINT POS PUNCH MOVE Z 20```: Moves the player, prints the position, punches and moves the player again.

### Bind with premade .use files

 * ```/uselang_examples/example1.use```: Reads the contents of the 1st example
 * Without input examples 0 and 1 are automaticaly loaded to their respective UseInputs.
