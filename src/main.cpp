#include "window.hpp"

int main() {
    // Create a fullscreen window with a title
    Window window("Lab02", 800, 600);
    
    // Run the window loop
    window.run();

    return 0;
}

