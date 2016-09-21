Conway’s Game of Life Simulation – C
===


## Table of Contents

- [Synopsis](#synopsis)
- [Prerequisites](#prerequisites)
- [Compilation](#compilation)
- [Usage](#usage)
- [Example Input/Output](#example-input-output)
- [Specification](#specification)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>

Synopsis
---
Class project for CS 1412 Programming Principles II at Texas Tech University during the spring semester of 2016. Command-line program written in C that simulates [Conway’s game of life algorithm.](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) Seed data is provided in the form of a pgm image file. Subsequent passes in the simulation are output to the shell.

Prerequisites
---

1. A bash shell environment. If you use a different shell, you may need to use different commands than those shown in this document.
2. The [gcc compiler.](https://gcc.gnu.org)
3. A [pgm image file](http://netpbm.sourceforge.net/doc/pgm.html) in the form:
   
        P2
        M N
        1
        #1
        #2
        #3
        ...
        #M*N-1
        #M*N
   
   where `P2` marks the beginning of the file, `M` is the number of columns, `N` is the number of rows, and `#1`–`#M*N` are integers of either `1` or `0` encoding the values of each pixel in the image.

  This repository provides several sample pgm files in the directory `Sample_PGM_Files`.

Compilation
---

In your shell, navigate to the directory of the cloned repository and compile the project with gcc using the command:

```
gcc *.c -o <program>
```

where `<program>` is whatever name you wish to give to the compiled executable.

Usage
---

The program takes command-line arguments in the form:

```
./<executable> <seed> <frames>
```

where `<executable>` is the compiled program, `<seed>` is the path to the pgm seed file, and `<frames>` is the number of passes of the simulation to calculate and output to the shell. Example: `./program sample.pgm 10`

Example Input/Output
---

The contents of `Sample_PGM_Files/test.pgm` is given below:

> ##### Sample\_PGM_Files/test.pgm
> 
    P2
    3 3
    1
    0 1 0
    0 1 0
    0 1 0

The command `./program Sample_PGM_Files/test.pgm 3` should produce the following output:

> ##### Example Output for Sample\_PGM_Files/test.pgm
>
    Seed: 3 3
    O O O O O 
    O O X O O 
    O O X O O 
    O O X O O 
    O O O O O 
>      
    Frame: 1
    O O O O O 
    O O O O O 
    O X X X O 
    O O O O O 
    O O O O O 
>    
    Frame: 2
    O O O O O 
    O O X O O 
    O O X O O 
    O O X O O 
    O O O O O 
>    
    Frame: 3
    O O O O O 
    O O O O O 
    O X X X O 
    O O O O O 
    O O O O O 

Specification
---

Students were asked to write a C program simulating Conway's game of life algorithm.

### Simulation Specifications

Students would maintain internal state simulating a grid of "live" and "dead" cells. At each pass of the simulation, the following rules would be applied to alter program state:

> ##### Rules
>
1. Live cells bordered by fewer than two live neighbors would die.
2. Live cells bordered by two to three live neighbors would stay alive.
3. Live cells bordered by more than three live neighbors would die.
4. Dead cells bordered by three live neighbors would become alive.

### Input Specifications

Students were told they would be given seed data and the number of passes to simulate in the form of command line arguments. The seed data would be in the form of a path to a pgm file.

The `M`-width by `N`-height pgm file would represent the 'seed grid', in which white pixels (pixels with a value of `1`) are "live" cells and black pixels (pixels with a value of `0`) are "dead" cells, and `M` and `N` are the width and height of the grid respectively.

### Output Specifications

Representations of the state of the simulation were required to be output in the form of a grid of `X`s and `O`s, in which `X`'s represent live cells and `O`'s represent dead cells. Each cell was to be separated from another by a space The output grid, or "frame", was to be padded by a 1-cell thick border of `O`'s, representing the "walls" of the environment. Therefore, given the following pgm file:

> ##### Sample\_PGM\_Files/test.pgm
> 
    P2
    3 3
    1
    0 1 0
    0 1 0
    0 1 0

...it's proper representation for output would be:

> ##### String representation of Sample\_PGM\_Files/test.pgm
>
    O O O O O
    O O X O O
    O O X O O
    O O X O O
    O O O O O

Output was to be in two parts: (1) a 'seed frame' representing the data provided as input, and (2) an array of the frames representing the passes in the simulation. Each frame was to be separated by a blank line.

The seed frame was to be preceded by the line `Seed: M N`, where `M` and `N` were the width and height of the seed grid respectively. E.g.:

> ##### Example output for Sample\_PGM\_Files/test.pgm
>
    Seed: 3 3
    O O O O O
    O O X O O
    O O X O O
    O O X O O
    O O O O O

Each subsequent simulation frame was to be preceded by the line `Frame: N`, where `N` was the `N`th pass in the simulation starting at 1. E.g.:

> ##### Example output for Sample\_PGM\_Files/test.pgm
>
    Frame: 1
    O O O O O
    O O O O O
    O X X X O
    O O O O O
    O O O O O

Altogether, the output for seed frame Sample\_PGM\_Files/test.pgm and 2 passes in the simulation would look like this:

> ##### Example output for Sample\_PGM\_Files/test.pgm and 2 passes
>
    Seed: 3 3
    O O O O O
    O O X O O
    O O X O O
    O O X O O
    O O O O O
>
    Frame: 1
    O O O O O
    O O O O O
    O X X X O
    O O O O O
    O O O O O
>
    Frame: 2
    O O O O O
    O O X O O
    O O X O O
    O O X O O
    O O O O O