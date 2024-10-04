# Hangman Game in C++

This is a simple implementation of the classic **Hangman** game written in C++. The player must guess the hidden word by suggesting letters within a limited number of attempts. The game ends when the player either correctly guesses the word or makes too many incorrect guesses, completing the hangman figure.

## Features
- Random word selection from a predefined set of words
- Player can guess letters to reveal hidden parts of the word
- A graphical representation of the hangman is displayed as the player makes incorrect guesses
- The game tracks incorrect guesses and ends when the hangman figure is fully draw

## How to Play
1. The game randomly selects a word from a predefined list.
2. The player guesses letters by typing them in.
3. For every incorrect guess, a part of the hangman is drawn.
4. The game ends when either the player guesses the word correctly or the hangman figure is completed after 22 incorrect guesses.

## Key Functions
- `clearScreen()`: Clears the screen for a better user experience
- `random_pass()`: Selects a random word from the word list
- `draw_pass()`: Draws the hidden word with guessed letters revealed
- `draw_hang_man()`: Displays the hangman figure as incorrect guesses increase
- `check_error()`: Checks if the guessed letter is in the word, updating the game state
- `game_over()`: Ends the game and displays the result
