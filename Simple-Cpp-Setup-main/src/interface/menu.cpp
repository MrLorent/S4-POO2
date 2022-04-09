#include <iostream>
#include <map>

#include "menu.hpp"

void display_menu_title();

void show_menu()
{
    display_menu_title();
    std::string menu = "What do you want to do ?\n";

    for (auto command : LIST_OF_COMMANDS) {
        menu += " " + COMMANDS_KEYS.at(command) + ". " + COMMANDS_LABELS.at(command) + "\n";
    }

    std::cout << menu + "\n";
}

void display_menu_title()
{
    system("clear");
    std::cout << "########| MENU |########\n\n";
}