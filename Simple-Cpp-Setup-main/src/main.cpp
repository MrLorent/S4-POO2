#include <iostream>
#include "random.hpp"

int get_int_from_user();

int main()
{
    get_int_from_user();
}

int get_int_from_user()
{
    int input;

    while (std::cout << "Please enter a number :\n" && !(std::cin >> input)) {
        std::cin.clear();                                                   //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Error : Invalid input type.\n";
    }

    return input;
}