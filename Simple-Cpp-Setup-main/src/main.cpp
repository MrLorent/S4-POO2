// INTERFACE
#include "user_input.hpp"
#include "menu.hpp"

// GAMES
#include "guess_the_number.hpp"
#include "hangman.hpp"

int main()
{
    bool quit = false;
    while (!quit) {
        show_menu();
        char user_choice = get_input_from_user<char>();

        while (!menu_command_contains(user_choice)) {
            show_menu();

            std::string error_message = "Error : ";
            error_message += user_choice;
            error_message += " isn't an option.";

            std::cout << error_message + "\n";
            user_choice = get_input_from_user<char>();
        };

        const char command = user_choice;

        switch (command) {
        case static_cast<int>(menu_options::Guess_the_number):
            play_guess_the_number();
            break;
        case static_cast<int>(menu_options::Hangman):
            play_hangman();
            break;
        default:
            quit = true;
            break;
        }
    }
    std::cout << "See you ;)\n";
}