#include "random.hpp"

int head_or_tail()
{
    float random_value = rand<float>(0.0, 1.0);

    if (random_value < 0.5) {
        return 0;
    }
    else {
        return 1;
    }
}

int throw_a_dice()
{
    float random_value = rand<float>(0.0, 1.0);

    int i = 1;
    while (random_value > (i / 6.f) && i <= 6) {
        i++;
    }

    return i;
}

int random_choose(std::vector<int> universe, std::vector<float> probability)
{
    float random_value = rand<float>(0.0, 1.0);

    int   i  = 0;
    float p1 = probability[0];
    while (random_value > p1 && i < int(universe.size())) {
        i++;
        p1 += probability[i];
    }

    return universe[i];
}