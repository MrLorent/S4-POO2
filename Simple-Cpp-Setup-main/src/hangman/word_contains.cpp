#include "word_contains.hpp"

bool word_contains(const char letter, const std::string_view word)
{
    return word.find(std::toupper(letter)) != std::string::npos;
}
