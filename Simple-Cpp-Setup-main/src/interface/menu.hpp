#pragma once
#define MENU

enum class GAMES : char {
    GUESS_THE_NUMBER = '1',
    HANGMAN          = '2',
};

void show_menu();