# Fruit-Guessing-Game-in-C
A fun and interactive console-based game where players try to guess the name of a fruit by revealing letters one at a time.

🎮 Description

"Guess the Fruit" is a classic word-guessing game implemented in C where players attempt to discover a hidden fruit name by suggesting letters. The game features a clean console interface, randomized word selection, and tracking of attempted letters.
✨ Features

    Randomized Gameplay: 26 different fruits to guess from

    Interactive Interface: Clean console display with visual feedback

    Letter Tracking: Keeps record of already attempted letters

    Case Insensitive: Accepts both uppercase and lowercase letters

    File-based Word Bank: Reads from external file with fallback creation

    Cross-Platform: Works on both Windows and Unix-based systems

🚀 How to Play

    Run the executable or compile the program

    Select option "1 - Play" from the main menu

    Guess letters one at a time to reveal the hidden fruit name

    Type / to exit the current game

    Try to complete the word with the fewest attempts possible

🛠️ Compilation

Compile the game using any C compiler:
bash

gcc -o fruit_guess game.c

🎯 Game Functions

    main() - Program entry point and menu system

    start() - Initializes and controls game flow

    compare() - Handles letter comparison and game logic

    draw() - Displays the current game state

    lettersAlreadyTyped() - Shows attempted letters

    readFile() - Manages word bank file

    listWords() - Processes words into playable format

    💡 Tips

    Start with common vowels (A, E, I, O, U)

    Pay attention to the length of the word shown by underscores

    Use the displayed attempted letters to avoid重复 guesses

    The word bank includes fruits like Abacaxi, Banana, Manga, Morango, and Uva

Enjoy the game and test your knowledge of fruits! 🍎🍌🍇🍓🍊
