# Mastermind-game

A computer vs player version of the board game [Mastermind](https://en.wikipedia.org/wiki/Mastermind_(board_game)).
The player has to guess the code set by the computer in 12 tries. The player is given hints in the form of red and white pegs which tells them if they have entered the right colour at the right place.
The names of the colours are coloured for a better look and feel and runs on Windows OS only.

## Installation

Clone this repository.
```bash
git clone link-of-this-repository
```
Using gcc, compile.
```bash
gcc -o game main.c func.c colours.c
```
Run the executable file named game.exe to play.
