#include "raylib.h"

void HTP() {
    
    Font font = LoadFont("resources/SPACE MISSION.ttf");

    const char* htp_text = "Navigate your ship using [ UP or DOWN] or [ W or S]\n\n\nand shoot down all the meteors using [ SPACE]";
    Vector2 htp_text_width = MeasureTextEx(font, htp_text, 50.0f, 0.0f);

    const char* back_text = "Back [ B or BACKSPACE]";
    Vector2 back_text_width = MeasureTextEx(font, back_text, 30.0f, 0.0f);

    Texture2D cudl_texture = LoadTexture("resources/cudl.png");
    cudl_texture.width *= 3;
    float back_mult = 0.35f;
    Rectangle back_rect = {(1600/2)-((cudl_texture.width*back_mult)/2),
                            float((900/1.25)-((cudl_texture.height*back_mult)/2)),
                            (cudl_texture.width*back_mult),
                            (cudl_texture.height*back_mult)};

    while (!WindowShouldClose()) {

        back_rect = {(1600/2)-((cudl_texture.width*back_mult)/2),
                    float((900/1.25)-((cudl_texture.height*back_mult)/2)),
                    (cudl_texture.width*back_mult),
                    (cudl_texture.height*back_mult)};

        if (CheckCollisionPointRec(GetMousePosition(), back_rect)) {
            back_mult = 0.40f;
        } else {
            back_mult = 0.35f;
        }

        if ((IsKeyPressed(KEY_B) || IsKeyPressed(KEY_BACKSPACE)) || (CheckCollisionPointRec(GetMousePosition(), back_rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
            break;
        }

        BeginDrawing();

        ClearBackground({0, 0, 30, 0});

        DrawTextEx(font, htp_text, {(1600/2)-(htp_text_width.x/2), (900/2)-(htp_text_width.y/2)}, 50.0f, 0.0f, WHITE);

        DrawTextureEx(cudl_texture, {back_rect.x, back_rect.y}, 0.0f, back_mult, WHITE);
        DrawTextEx(font, back_text, {(1600/2)-((back_text_width.x)/2), (900/1.25f)-((back_text_width.y)/2)}, 30.0f, 0.0f, WHITE);

        EndDrawing();
    }

    UnloadFont(font);
    UnloadTexture(cudl_texture);
}