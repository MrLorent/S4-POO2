#include <iostream>
#include <array>

#include "random.hpp"
#include "user_input.hpp"

#include "MysteryWord.hpp"
#include "word_contains.hpp"
#include "hangman.hpp"

/*------| PROTOTYPES |------*/
const std::string_view pick_random_word();
bool                   player_is_alive(unsigned lives_count);
void                   remove_one_life(unsigned& lives_count);

void display_hangman_title();
void display_number_of_lives(unsigned lives_count);
void display_success_feedback(const char right_letter);
void display_failure_feedback(const char wrong_letter);
void display_congrats_message();
void display_defeat_message(const std::string_view MYSTERY_WORD);

void play_hangman()
{
    // CONSTANTS
    MysteryWord mystery_word(pick_random_word());

    // VARIABLES
    unsigned lives_count = 8;

    display_hangman_title();
    display_number_of_lives(lives_count);
    mystery_word.display_with_holes();
    while (player_is_alive(lives_count) && !mystery_word.is_guessed()) {
        const char guess = get_input_from_user<char>();
        if (word_contains(guess, mystery_word.get_word())) {
            /*---- GAME ENGINE ----*/
            mystery_word.marks_as_guessed(guess);

            /*----- INTERFACE -----*/
            display_hangman_title();
            display_success_feedback(guess);
            display_number_of_lives(lives_count);
            mystery_word.display_with_holes();
        }
        else {
            /*---- GAME ENGINE ----*/
            remove_one_life(lives_count);

            /*----- INTERFACE -----*/
            display_hangman_title();
            display_failure_feedback(guess);
            display_number_of_lives(lives_count);
            mystery_word.display_with_holes();
        }
    }
    display_hangman_title();
    if (mystery_word.is_guessed()) {
        std::cout << mystery_word.get_word() << "\n";
        display_congrats_message();
    }
    else {
        display_number_of_lives(lives_count);
        display_defeat_message(mystery_word.get_word());
    }
}

// FREE FUNSTIONS

const std::string_view pick_random_word()
{
    static constexpr std::array words_list = {
        "THEOBAR",
        "FLAVOS",
        "TANGOS",
        "LISOUILLE",
        "JORDYNATEUR",
        "YAYELL",
        "CHULLY",
        "SOSOMANESS",
    };

    return words_list[rand<size_t>(0, words_list.size() - 1)];
}

bool player_is_alive(unsigned lives_count)
{
    return (lives_count > 0);
}

void remove_one_life(unsigned& lives_count)
{
    if (lives_count > 0) lives_count--;
}

// GRAPHICS
void display_hangman_title()
{
    system("clear");
    std::cout << "###### MYSTERY WORD ######\n\n";
}

void display_number_of_lives(unsigned nb_lives)
{
    std::cout << "You have " << nb_lives << " lives left\n";
}

void display_success_feedback(const char right_letter)
{
    std::cout << "Yes ! '" << char(std::toupper(right_letter)) << "' was a good guess !\n\n";
}

void display_failure_feedback(const char wrong_letter)
{
    std::cout << "No, '" << char(std::toupper(wrong_letter)) << "' isn't in the word, sorry\n\n";
}

void display_congrats_message()
{
    std::cout << "\nCongratulations ! You found the mystery word !\n";
}

void display_defeat_message(const std::string_view MYSTERY_WORD)
{
    std::cout << "\nYou lose... The world was " << MYSTERY_WORD << "\nMaybe next time !\n ";
}