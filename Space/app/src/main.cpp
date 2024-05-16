#include "raylib.h"
#include "Game.hpp"
#include "Menu.hpp"
#include "HTP.hpp"

#include <iostream>
#include <vector>

int main() {
    
    int screenw = 1600;
    int screenh = 900;

    InitWindow(screenw, screenh, "Space");
    
    while(!WindowShouldClose()) {
        if (Menu() == 0) {
            break;
        } else if (Menu() == 1) {
            Play(screenw, screenh);
        } else if (Menu() == 2) {
            HTP();
        }
    }

    return 0;
}