#include "window.hpp"

int main() {
    // Create a fullscreen window with a title
    Window window("Fullscreen Test", 800, 800);
    
    // Run the window loop
    window.run();

    return 0;
}

