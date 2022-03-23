#include <iostream>
#include <array>
#include <algorithm>

#include "random.hpp"
#include "user_input.hpp"

#include "hangman.hpp"

const std::string pick_random_word();
bool              player_is_alive(unsigned lives_count);
bool              player_has_won(const std::vector<bool>& letters_guessed);
bool              word_contains(const char letter, const std::string& MYSTERY_WORD);
void              marks_as_guessed(const char letter, std::vector<bool>& letters_guessed, const std::string& MYSTERY_WORD);
void              remove_one_life(unsigned& lives_count);

void display_hangman_title();
void display_number_of_lives(unsigned lives_count);
void display_word_to_guess_with_holes(const std::string& MYSTERY_WORD, const std::vector<bool>& letters_guessed);
void display_success_feedback(const char right_letter);
void display_failure_feedback(const char wrong_letter);
void display_congrats_message();
void display_defeat_message(const std::string& MYSTERY_WORD);

void play_hangman()
{
    // CONSTANTS
    const std::string MYSTERY_WORD = pick_random_word();

    // VARIABLES
    std::vector<bool> letters_guessed(MYSTERY_WORD.size(), false);
    unsigned          lives_count = 8;

    display_hangman_title();
    display_number_of_lives(lives_count);
    display_word_to_guess_with_holes(MYSTERY_WORD, letters_guessed);
    while (player_is_alive(lives_count) && !player_has_won(letters_guessed)) {
        const char guess = get_input_from_user<char>(INPUT_TYPE::CHAR);
        if (word_contains(guess, MYSTERY_WORD)) {
            /*---- GAME ENGINE ----*/
            marks_as_guessed(guess, letters_guessed, MYSTERY_WORD);

            /*----- INTERFACE -----*/
            display_hangman_title();
            display_success_feedback(guess);
            display_number_of_lives(lives_count);
            display_word_to_guess_with_holes(MYSTERY_WORD, letters_guessed);
        }
        else {
            /*---- GAME ENGINE ----*/
            remove_one_life(lives_count);

            /*----- INTERFACE -----*/
            display_hangman_title();
            display_failure_feedback(guess);
            display_number_of_lives(lives_count);
            display_word_to_guess_with_holes(MYSTERY_WORD, letters_guessed);
        }
    }
    display_hangman_title();
    if (player_has_won(letters_guessed)) {
        std::cout << MYSTERY_WORD << "\n";
        display_congrats_message();
    }
    else {
        display_number_of_lives(lives_count);
        display_defeat_message(MYSTERY_WORD);
    }
}

const std::string pick_random_word()
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

bool player_has_won(const std::vector<bool>& letters_guessed)
{
    return (std::find(letters_guessed.begin(), letters_guessed.end(), false) == letters_guessed.end());
}

bool word_contains(const char letter, const std::string& MYSTERY_WORD)
{
    return MYSTERY_WORD.find(std::toupper(letter)) != std::string::npos;
}

void marks_as_guessed(const char letter, std::vector<bool>& letters_guessed, const std::string& MYSTERY_WORD)
{
    std::string rest_of_letters(MYSTERY_WORD);

    while (word_contains(letter, rest_of_letters)) {
        size_t letter_index           = rest_of_letters.find_last_of(std::toupper(letter));
        letters_guessed[letter_index] = true;
        rest_of_letters               = rest_of_letters.substr(0, letter_index);
    }
}

void remove_one_life(unsigned& lives_count)
{
    if (lives_count > 0) lives_count--;
}

void display_hangman_title()
{
    system("clear");
    std::cout << "###### MYSTERY WORD ######\n\n";
}

void display_number_of_lives(unsigned nb_lives)
{
    std::cout << "You have " << nb_lives << " lives left\n";
}

void display_word_to_guess_with_holes(const std::string& MYSTERY_WORD, const std::vector<bool>& letters_guessed)
{
    for (size_t i = 0; i < MYSTERY_WORD.size(); ++i) {
        if (letters_guessed[i]) {
            std::cout << char(std::toupper(MYSTERY_WORD.at(i)));
        }
        else {
            std::cout << "_";
        }
    }
    std::cout << "\n\n";
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
    std::cout << "Congratulations ! You found the mystery word !\n";
}

void display_defeat_message(const std::string& MYSTERY_WORD)
{
    std::cout << "\nYou lose... The world was " << MYSTERY_WORD << "\nMaybe next time !\n ";
}