#include "MysteryWord.hpp"

#include <algorithm>

#include "word_contains.hpp"

bool MysteryWord::is_guessed() const
{
    return (std::find(_letters_guessed.begin(), _letters_guessed.end(), false) == _letters_guessed.end());
}

void MysteryWord::marks_as_guessed(const char letter_guessed)
{
    std::string rest_of_letters(_word);

    while (word_contains(letter_guessed, rest_of_letters)) {
        size_t letter_index            = rest_of_letters.find_last_of(std::toupper(letter_guessed));
        _letters_guessed[letter_index] = true;
        rest_of_letters                = rest_of_letters.substr(0, letter_index);
    }
}

/*------| GRAPHICS |------*/

void MysteryWord::display_with_holes() const
{
    for (size_t i = 0; i < _word.size(); ++i) {
        if (_letters_guessed[i]) {
            std::cout << char(std::toupper(_word.at(i)));
        }
        else {
            std::cout << "_";
        }
    }
    std::cout << "\n\n";
}