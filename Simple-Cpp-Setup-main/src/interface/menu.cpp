#include <iostream>
#include <map>

#include "menu.hpp"

void display_menu_title();

const std::map<GAMES, std::string> games_name = {
    {GAMES::GUESS_THE_NUMBER, "Guess the Number"},
    {GAMES::HANGMAN, "Hangman"},
};

const std::map<GAMES, std::string> games_command = {
    {GAMES::GUESS_THE_NUMBER, "1"},
    {GAMES::HANGMAN, "2"},
};

constexpr std::initializer_list<GAMES> LIST_OF_GAMES = {
    GAMES::GUESS_THE_NUMBER,
    GAMES::HANGMAN,
};

void show_menu()
{
    display_menu_title();
    std::string menu = "What do you want to do ?\n";

    for (auto game : LIST_OF_GAMES) {
        menu += " " + games_command.at(game) + ". Play " + games_name.at(game) + "\n";
    }
    menu += " Q. Quit\n\n";

    std::cout << menu;
}

void display_menu_title()
{
    system("clear");
    std::cout << "########| MENU |########\n\n";
}