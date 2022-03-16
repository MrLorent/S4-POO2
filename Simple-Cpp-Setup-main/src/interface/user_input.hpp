#pragma once
#define USER_INPUT

enum INPUT_TYPE {
    INT    = 0,
    CHAR   = 1,
    STRING = 2,
};

template<typename T>
T get_input_from_user(const unsigned type_required)
{
    T           input;
    std::string message_to_user = "Please enter ";

    switch (type_required) {
    case INPUT_TYPE::INT:
        message_to_user += "an integer number :";
        break;
    case INPUT_TYPE::CHAR:
        message_to_user += "a single character :";
        break;
    case INPUT_TYPE::STRING:
        message_to_user += "a character chain :";
        break;
    default:
        std::cout << "Error : no input type specified\n";
        break;
    }

    while (std::cout << (message_to_user + "\n") && !(std::cin >> input)) {
        std::cin.clear();                                                   //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Error : Invalid input type.\n\n";
    }

    return input;
}