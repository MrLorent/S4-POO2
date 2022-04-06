#include "guess_the_number.hpp"

int  get_int_from_user();
void display_guess_the_number_title();

void play_guess_the_number()
{
    bool game_over       = false;
    int  number_to_guess = rand(0, 100);

    display_guess_the_number_title();
    do {
        int user_input = get_int_from_user();

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

int get_int_from_user()
{
    int input;

    while (std::cout << "Please enter a number :\n" && !(std::cin >> input)) {
        std::cin.clear();                                                   //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        display_guess_the_number_title();
        std::cout << "Error : Invalid input type.\n";
    }

    return input;
}

void display_guess_the_number_title()
{
    system("clear");
    std::cout << "#### GUESS THE NUMBER ####\n\n";
}