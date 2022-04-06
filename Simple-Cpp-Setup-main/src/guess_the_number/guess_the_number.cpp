#include <iostream>

#include "random.hpp"
#include "user_input.hpp"
#include "guess_the_number.hpp"

void display_guess_the_number_title();
void play_guess_the_number()
{
    bool game_over       = false;
    int  number_to_guess = rand<int>(0, 100);

    display_guess_the_number_title();
    do {
        int user_input = get_input_from_user<int>();

        display_guess_the_number_title();

        if (user_input == number_to_guess) {
            std::cout << "Congratulation ! You guessed it !\n";
            std::cout << "The mysterious number was " + std::to_string(number_to_guess) + ".\n";
            game_over = true;
        }
        else if (user_input < number_to_guess) {
            std::cout << "Greater...\n";
        }
        else {
            std::cout << "Smaller...\n";
        }
    } while (!game_over);

    std::cout << "\nSee you ;)\n";
}
void display_guess_the_number_title()
{
    system("clear");
    std::cout << "#### GUESS THE NUMBER ####\n\n";
}