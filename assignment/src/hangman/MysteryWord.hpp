#pragma once
#define MYSTERY_WORD_WITH_HOLES

#include <iostream>

#include <string>
#include <vector>

class MysteryWord {
public:
    /*------| CONSTRUCTORS |------*/
    MysteryWord(const std::string_view word)
        : _word(word)
        , _letters_guessed(word.size(), false)
    {
    }

    /*------| DESTRUCTORS |------*/
    ~MysteryWord() {}

    /*------| GETTERS |------*/
    const std::string_view get_word() const { return _word; }

    /*------| SETTERS |------*/

    /*------| METHODS |------*/
    // ENGINE
    bool is_guessed() const;
    void marks_as_guessed(const char letter_guessed);

    // GRAPHICS
    void display_with_holes() const;

private:
    std::string       _word;
    std::vector<bool> _letters_guessed;
};