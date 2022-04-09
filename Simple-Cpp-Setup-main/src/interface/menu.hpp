#pragma once
#define MENU

enum class COMMANDS : char {
    GUESS_THE_NUMBER = '1',
    HANGMAN          = '2',
    QUIT             = 'Q',
};

const std::map<COMMANDS, std::string> COMMANDS_LABELS = {
    {COMMANDS::GUESS_THE_NUMBER, "Play Guess the Number"},
    {COMMANDS::HANGMAN, "Play Hangman"},
    {COMMANDS::QUIT, "Quit"},
};

const std::map<COMMANDS, std::string> COMMANDS_KEYS = {
    {COMMANDS::GUESS_THE_NUMBER, "1"},
    {COMMANDS::HANGMAN, "2"},
    {COMMANDS::QUIT, "Q"},
};

constexpr std::initializer_list<COMMANDS> LIST_OF_COMMANDS = {
    COMMANDS::GUESS_THE_NUMBER,
    COMMANDS::HANGMAN,
    COMMANDS::QUIT,
};

void show_menu();