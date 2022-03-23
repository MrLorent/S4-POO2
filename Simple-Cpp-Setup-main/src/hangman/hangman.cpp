#include <iostream>
#include <array>
#include <algorithm>

#include "random.hpp"
#include "user_input.hpp"

#include "hangman.hpp"

const std::string pick_random_word();
bool              player_is_alive(unsigned nb_lives);
bool              player_has_won(const std::vector<bool>& letters_guessed);
bool              word_contains(const char letter, const std::string& MYSTERY_WORD);

void display_hangman_title();
void display_number_of_lives(unsigned nb_lives);
void display_word_to_guess_with_holes(const std::string& MYSTERY_WORD, const std::vector<bool>& letters_guessed);

void play_hangman()
{
    // CONSTANTS
    const std::string MYSTERY_WORD = pick_random_word();

    // VARIABLES
    std::vector<bool> letters_guessed(MYSTERY_WORD.size(), false);
    unsigned          nb_lives = 8;

    while (player_is_alive(nb_lives) && !player_has_won(letters_guessed)) {
        display_hangman_title();
        display_number_of_lives(nb_lives);
        display_word_to_guess_with_holes(MYSTERY_WORD, letters_guessed);
        const char guess = get_input_from_user<char>(INPUT_TYPE::CHAR);
        std::cout << guess;
    }
}

const std::string pick_random_word()
{
    static constexpr std::array words_list = {
        "Theobar",
        "Flavos",
        "Tangos",
        "Lisouille",
        "Jordynateur",
        "Yayelle",
        "Chully",
        "Sosomaness",
    };

    return words_list[rand<size_t>(0, words_list.size() - 1)];
}

bool player_is_alive(unsigned nb_lives)
{
    return (nb_lives > 0);
}

bool player_has_won(const std::vector<bool>& letters_guessed)
{
    return (std::find(letters_guessed.begin(), letters_guessed.end(), false) == letters_guessed.end());
}

bool word_contains(const char letter, const std::string& MYSTERY_WORD)
{
    return (std::find(MYSTERY_WORD.begin(), MYSTERY_WORD.end(), letter) != MYSTERY_WORD.end());
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
            std::cout << toupper(MYSTERY_WORD.at(i));
        }
        else {
            std::cout << "_";
        }
    }
    std::cout << "\n\n";
}
