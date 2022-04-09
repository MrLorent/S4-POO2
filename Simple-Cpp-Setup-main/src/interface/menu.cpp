#include <iostream>

#include "menu.hpp"

void display_menu_title();

bool menu_command_contains(const char command)
{
    for (auto command_name : list_of_options) {
        if (command == options_commands.at(command_name) || command == char(options_commands.at(command_name) + ('a' - 'A'))) return true;
    }

    return false;
}

void show_menu()
{
    display_menu_title();
    std::string menu = "What do you want to do ?\n";

    for (auto command : list_of_options) {
        menu += " ";
        menu += options_commands.at(command);
        menu += ". " + options_labels.at(command) + "\n";
    }

    std::cout << menu + "\n";
}

void display_menu_title()
{
    system("clear");
    std::cout << "########| MENU |########\n\n";
}