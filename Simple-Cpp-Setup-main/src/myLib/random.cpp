#include "random.hpp"

int rand(unsigned min, unsigned max)
{
    static std::mt19937_64             generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}