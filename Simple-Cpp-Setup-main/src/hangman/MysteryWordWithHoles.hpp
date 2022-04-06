#pragma once
#define MYSTERY_WORD_WITH_HOLES

#include <string>
#include <vector>

class MysteryWordWithHoles {
public:
    MysteryWordWithHoles(std::string_view word)
        : _word(word)
        , _letters_revealed(word.size(), false)
    {
    }

    // TODO: implement the methods required by the outside world

private:
    std::string       _word;
    std::vector<bool> _letters_revealed;
};