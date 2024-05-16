#include "raylib.h"
#include <iostream>

int Menu() {
    Font font = LoadFont("resources/SPACE MISSION.ttf");

    int rtrn = 0;

    Image cudl_image = LoadImage("resources/cudl.png");
    Texture2D cudl_texture = LoadTextureFromImage(cudl_image);
    UnloadImage(cudl_image);

    const char* play_text = "Play [ P]";
    Vector2 play_text_width = MeasureTextEx(font, play_text, 30, 0.0f);
    float play_mult = 0.35f;
    Rectangle play_rect = {(1600/3)-((cudl_texture.width*play_mult)/2),
                            float(900/2)-((cudl_texture.height*play_mult)/2),
                            (cudl_texture.width*play_mult),
                            (cudl_texture.height*play_mult)};

    const char* quit_text = "Quit [ Q]";
    Vector2 quit_text_width = MeasureTextEx(font, quit_text, 30, 0.0f);
    float quit_textX = 900 - (quit_text_width.x / 2);
    float quit_mult = 0.35f;
    int quit_text_pos_mult = 6;
    Rectangle quit_rect = {((1600/3)*2)-((cudl_texture.width*quit_mult)/2),
                            float(900/2)-((cudl_texture.height*quit_mult)/2),
                            (cudl_texture.width*quit_mult),
                            (cudl_texture.height*quit_mult)};

    const char* htp_text = "How To Play [ H]";
    Vector2 htp_text_width = MeasureTextEx(font, htp_text, 30, 0.0f);
    float htp_mult = 0.35f;
    Texture2D htp_cudl_texture = cudl_texture;
    htp_cudl_texture.width = htp_cudl_texture.width*1.75;
    Rectangle htp_rect = {(1600/2)-((htp_cudl_texture.width*htp_mult)/2),
                            float((900/2)-((htp_cudl_texture.height*htp_mult)/2)),
                            (htp_cudl_texture.width*htp_mult),
                            (htp_cudl_texture.height*htp_mult)};
    

    const char* jmeno = "SPACE";
    Vector2 jmeno_width = MeasureTextEx(font, jmeno, 200.0f, 0.0f);
    float jmeno_widthX = 900 - (jmeno_width.x / 2);

    std::cout << jmeno_width.x;

    while (!WindowShouldClose()) {

        htp_rect = {(1600/2)-((htp_cudl_texture.width*htp_mult)/2),
                    float((900/2)-((htp_cudl_texture.height*htp_mult)/2)),
                    (htp_cudl_texture.width*htp_mult),
                    (htp_cudl_texture.height*htp_mult)};

        quit_rect = {((1600/3)*2)-((cudl_texture.width*quit_mult)/2),
                    float(900/2)-((cudl_texture.height*quit_mult)/2),
                    (cudl_texture.width*quit_mult),
                    (cudl_texture.height*quit_mult)};

        play_rect = {(1600/3)-((cudl_texture.width*play_mult)/2),
                    float(900/2)-((cudl_texture.height*play_mult)/2),
                    (cudl_texture.width*play_mult),
                    (cudl_texture.height*play_mult)};

        if (CheckCollisionPointRec(GetMousePosition(), play_rect)) {
            play_mult = 0.40f;
        } else {
            play_mult = 0.35f;
        }

        if (CheckCollisionPointRec(GetMousePosition(), quit_rect)) {
            quit_mult = 0.40f;
            quit_text_pos_mult = 8;
        } else {
            quit_mult = 0.35f;
            quit_text_pos_mult = 6;
        }

        if (CheckCollisionPointRec(GetMousePosition(), htp_rect)) {
            htp_mult = 0.40f;
        } else {
            htp_mult = 0.35f;
        }

        if (IsKeyPressed(KEY_Q) || (CheckCollisionPointRec(GetMousePosition(), quit_rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
            rtrn = 0;
            break;
        }
        
        if (IsKeyPressed(KEY_P) || (CheckCollisionPointRec(GetMousePosition(), play_rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
            rtrn = 1;
            break;
        }

        if (IsKeyPressed(KEY_H) || (CheckCollisionPointRec(GetMousePosition(), htp_rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
            rtrn = 2;
            break;
        }

        BeginDrawing();

        ClearBackground({0, 0, 30, 0});

        DrawTextEx(font, jmeno, {jmeno_widthX, 50}, 200.0f, 0.0f, WHITE);

        DrawTextureEx(cudl_texture, {(1600/3)-((cudl_texture.width*play_mult)/2), float(900/2)-((cudl_texture.height*play_mult)/2)}, 0.0f, play_mult, WHITE);
        DrawTextEx(font, play_text, {(1600/3)-((play_text_width.x)/2), float(900/2)-((play_text_width.y)/2)}, 30, 0.0f, WHITE);

        DrawTextureEx(htp_cudl_texture, {((1600/3)*2)-((htp_cudl_texture.width*htp_mult)/2), float(900/2)-((htp_cudl_texture.height*htp_mult)/2)}, 0.0f, htp_mult, WHITE);
        DrawTextEx(font, htp_text, {((1600/3)*2)-((htp_text_width.x)/2), float(900/2)-((htp_text_width.y)/2)}, 30, 0.0f, WHITE);

        DrawTextureEx(cudl_texture, {(1600/2)-((cudl_texture.width*quit_mult)/2), float((900/2)-((cudl_texture.height*quit_mult)/2))}, 0.0f, quit_mult, WHITE);
        DrawTextEx(font, quit_text, {(1600/2)-((quit_text_width.x)/2), float((900/2)-((quit_text_width.y)/2))}, 30, 0.0f, WHITE);

        EndDrawing();
    }

    UnloadTexture(cudl_texture);
    UnloadFont(font);
    return rtrn;
}