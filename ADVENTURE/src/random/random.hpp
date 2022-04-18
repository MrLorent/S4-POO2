#include <time.h>
#include <random>
#include <vector>

template<typename T>
T rand(T min, T max)
{
    static std::mt19937_64           generator(std::random_device{}());
    std::uniform_int_distribution<T> distribution(min, max);

    return distribution(generator);
}

int head_or_tail();
int throw_a_dice();
int random_choose(std::vector<int> universe, std::vector<float> probability);