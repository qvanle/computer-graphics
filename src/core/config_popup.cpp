#include <OpenGL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "config_popup.hpp"


int ConfigPopup::getColor(){
    return selectedColor;
}

int ConfigPopup::getShape(){
    return selectedShape;
}

ConfigPopup::ConfigPopup(int width, int height) : width(width), height(height) {
    buttonWidth = 100;
    buttonHeight = 40;
    buttonX = (width / 2) - (buttonWidth / 2);
    buttonY = height - 50;
}

void ConfigPopup::display() {
    glColor3f(0.8, 0.8, 0.8);  // Gray background
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(width, 0);
    glVertex2i(width, height);
    glVertex2i(0, height);
    glEnd();

    glColor3f(0, 0, 0);

    int startX = 20;
    int startY = 40;
    int spacing = 30;

    // Draw shapes list
    for (size_t i = 0; i < shapes.size(); ++i) {
        glColor3f(i == selectedShape ? 1 : 0, 0, 0);  // Highlight in red
        glRasterPos2i(startX, startY + i * spacing);
        for (char c : shapes[i]) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        // draw a rectangle around the selected shape 
        if (i == selectedShape) {
            glBegin(GL_LINE_LOOP);
            glVertex2i(startX, startY + i * spacing - 5 - 20);
            glVertex2i(startX + 100, startY + i * spacing - 5 - 20);
            glVertex2i(startX + 100, startY + i * spacing + 20 + 5 - 20);
            glVertex2i(startX, startY + i * spacing + 20 + 5 - 20);
            glEnd();
        }
    }

    // Draw colors list
    int colorStartX = width / 2;
    startX = colorStartX;
    for (size_t i = 0; i < colors.size(); ++i) {
        glColor3f(i == selectedColor ? 1 : 0, 0, 0);
        glRasterPos2i(colorStartX, startY + i * spacing);
        for (char c : colors[i]) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        
        // draw a rectangle around the selected shape 
        if (i == selectedColor) {
            glBegin(GL_LINE_LOOP);
            glVertex2i(startX, startY + i * spacing - 5 - 20);
            glVertex2i(startX + 100, startY + i * spacing - 5 - 20);
            glVertex2i(startX + 100, startY + i * spacing + 20 + 5 - 20);
            glVertex2i(startX, startY + i * spacing + 20 + 5 - 20);
            glEnd();
        }

    }

    drawButton();
}

void ConfigPopup::drawButton() {
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex2i(buttonX, buttonY);
    glVertex2i(buttonX + buttonWidth, buttonY);
    glVertex2i(buttonX + buttonWidth, buttonY + buttonHeight);
    glVertex2i(buttonX, buttonY + buttonHeight);
    glEnd();

    glColor3f(0, 0, 0);
    glRasterPos2i(buttonX + 30, buttonY + 25);
    std::string buttonText = "Draw";
    for (char c : buttonText) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

int ConfigPopup::mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x >= buttonX && x <= buttonX + buttonWidth && y >= buttonY && y <= buttonY + buttonHeight) {
            std::cout << "Drawing " << shapes[selectedShape] << " in " << colors[selectedColor] << " color.\n";
            return 2;
        }
        int startX = 20;
        int startY = 40;
        int spacing = 30;
        
        for (size_t i = 0; i < shapes.size(); ++i) {
            if (x >= startX && x <= startX + 100 && y >= startY + i * spacing - 20 && y <= startY + i * spacing + 20 - 20) {
                selectedShape = i;
                return true;
            }
        }
    
        // Draw colors list
        int colorStartX = width / 2;
        startX = colorStartX;
        for (size_t i = 0; i < shapes.size(); ++i) {
            if (x >= startX && x <= startX + 100 && y >= startY + i * spacing - 20 && y <= startY + i * spacing + 20 - 20) {
                selectedColor = i;
                return true;
            }
        }
        

        return (x >= 0 && x <= width && y >= 0 && y <= height);
    }
    return false;
}


