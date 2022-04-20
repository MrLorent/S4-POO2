#pragma once
#define MENU_HPP

#include <map>

enum class menu_options : char {
    Guess_the_number    = '1',
    Hangman             = '2',
    Noughts_and_crosses = '3',
    Quit                = 'q',
};

const std::map<menu_options, std::string> options_labels = {
    {menu_options::Guess_the_number, "Play Guess the Number"},
    {menu_options::Hangman, "Play Hangman"},
    {menu_options::Noughts_and_crosses, "Play Noughts and Crosses"},
    {menu_options::Quit, "Quit"},
};

const std::map<menu_options, char> options_commands = {
    {menu_options::Guess_the_number, '1'},
    {menu_options::Hangman, '2'},
    {menu_options::Noughts_and_crosses, '3'},
    {menu_options::Quit, 'Q'},
};

constexpr std::initializer_list<menu_options> list_of_options = {
    menu_options::Guess_the_number,
    menu_options::Hangman,
    menu_options::Noughts_and_crosses,
    menu_options::Quit,
};

void show_menu();
char get_command_from_user();