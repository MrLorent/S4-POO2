// INTERFACE
#include "menu.hpp"
#include "user_input.hpp"

#include <p6/p6.h>

// GAMES
#include "guess_the_number.hpp"
#include "hangman.hpp"

int main()
{
    // bool quit = false;
    // while (!quit) {
    //     show_menu();
    //     const char command = get_command_from_user();

    //     switch (command) {
    //     case static_cast<int>(menu_options::Guess_the_number):
    //         play_guess_the_number();
    //         wait_for_any_key_pressed();
    //         break;
    //     case static_cast<int>(menu_options::Hangman):
    //         play_hangman();
    //         wait_for_any_key_pressed();
    //         break;
    //     default:
    //         quit = true;
    //         system("clear");
    //         std::cout << "See you ;)\n";
    //         break;
    //     }
    // }

    try {
        // Create the Context by giving the initial size and name of our window
        auto ctx = p6::Context{{1280, 720, "p6 Basic Example"}};
        // Define the update function. It will be called repeatedly.
        ctx.update = [&]() {
            // Clear the objects that were drawn during the previous update
            ctx.background({0.5f, 0.3f, 0.8f});
            // Draw a circle
            ctx.circle(p6::Center{ctx.mouse()}, // Centered on the current position of the mouse
                       p6::Radius{0.3f});       // With a given radius
        };
        // Start the program
        ctx.start();
    }
    // Log any error that might occur
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}