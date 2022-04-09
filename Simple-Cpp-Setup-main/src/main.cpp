// INTERFACE
#include "menu.hpp"

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
            break;
        case static_cast<int>(menu_options::Hangman):
            play_hangman();
            break;
        default:
            quit = true;
            break;
        }
    }
}