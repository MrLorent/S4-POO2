#include "random.hpp"

int rand(unsigned min, unsigned max)
{
    static std::mt19937_64             generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

int head_or_tail()
{
    float random_value = std::rand() / float(RAND_MAX);

    if (random_value < 0.5) {
        return 0;
    }
    else {
        return 1;
    }
}

int throw_a_dice()
{
    float random_value = std::rand() / float(RAND_MAX);

    int i = 1;
    while (random_value > (i / 6.f) && i <= 6) {
        i++;
    }

    return i;
}

int random_choose(std::vector<int> universe, std::vector<float> probability)
{
    float random_value = std::rand() / float(RAND_MAX);

    int   i  = 0;
    float p1 = probability[0];
    while (random_value > p1 && i < int(universe.size())) {
        i++;
        p1 += probability[i];
    }

    return universe[i];
}