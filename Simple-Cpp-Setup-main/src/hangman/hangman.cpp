#include <iostream>
#include <array>

#include "random.hpp"
#include "hangman.hpp"

const std::string pick_random_word();

void play_hangman()
{
    const std::string MYSTERY_WORD = pick_random_word();

    system("clear");
    std::cout << "#### GUESS THE NUMBER ####\n\n";
    std::cout << MYSTERY_WORD << "\n";
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