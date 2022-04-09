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
        const char user_choice = get_input_from_user<char>();
        std::cout << user_choice;
        // TODO: handle the different possible values of command with a switch
        // NB: don't forget to handle the case of an invalid command!
    }
}