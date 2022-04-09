// INTERFACE
#include "menu.hpp"
#include "user_input.hpp"

// GAMES
#include "guess_the_number.hpp"
#include "hangman.hpp"

int main()
{
    bool quit = false;
    while (!quit) {
        show_menu();
        const char command = get_command_from_user();

        switch (command) {
        case static_cast<int>(menu_options::Guess_the_number):
            play_guess_the_number();
            wait_for_any_key_pressed();
            break;
        case static_cast<int>(menu_options::Hangman):
            play_hangman();
            wait_for_any_key_pressed();
            break;
        default:
            quit = true;
            system("clear");
            std::cout << "See you ;)\n";
            break;
        }
    }
}