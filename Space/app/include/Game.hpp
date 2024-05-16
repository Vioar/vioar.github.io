#include "raylib.h"
#include <iostream>
#include <vector>

int Play(int screenw, int screenh) {

    int ychange;
    float meteor_rotation = 0;

    bool hitboxy = false;

    int score = 0;
    int meteor = 0;

    std::vector<Vector2> strely;

    Font font = LoadFont("resources/SPACE MISSION.ttf");

    const char* back_text = "Back [ B or BACKSPACE]";
    Vector2 back_text_width = MeasureTextEx(font, back_text, 30.0f, 0.0f);

    Image strela_img = LoadImage("resources/strela.png");
    Texture2D strela_texture = LoadTextureFromImage(strela_img);
    UnloadImage(strela_img);

    Image background_img = LoadImage("resources/hvezdy.png");
    Texture2D backgroung_texture = LoadTextureFromImage(background_img);
    UnloadImage(background_img);

    Image meteor_1_img = LoadImage("resources/Meteroid_1.png");
    Texture2D meteor_1_texture = LoadTextureFromImage(meteor_1_img);
    UnloadImage(meteor_1_img);

    int meteor_1_x = screenw + meteor_1_texture.width;
    int meteor_1_y = rand() % int(900 - meteor_1_texture.height*0.35) + 0;
    Rectangle meteor_1_area = {float(meteor_1_x), float(meteor_1_y), float(meteor_1_texture.width*0.35), float(meteor_1_texture.height*0.35)};

    Texture2D cudl_texture = LoadTexture("resources/cudl.png");
    cudl_texture.width *= 3;
    float back_mult = 0.35f;
    Rectangle back_rect = {(1600/2)-((cudl_texture.width*back_mult)/2),
                            float((900/1.25)-((cudl_texture.height*back_mult)/2)),
                            (cudl_texture.width*back_mult),
                            (cudl_texture.height*back_mult)};

    Image lod_img = LoadImage("resources/Spaceship_01_BLUE.png");
    Texture2D lod_texture = LoadTextureFromImage(lod_img);
    UnloadImage(lod_img);

    int lody = screenh/2 - lod_texture.height/2;

    Rectangle lod_area = {float(screenw/7), float(lody), float(lod_texture.width*0.5), float(lod_texture.height*0.5)};

    SetTargetFPS(60);

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
        
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
            ychange = -5;
        } else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
            ychange = 5;
        } else {
            ychange = 0;
        }

        if (IsKeyPressed(KEY_SPACE)) {
            strely.push_back({float(screenw/7), lody+(float(lod_texture.width*0.5/2))});
        }

        if (IsKeyPressed(KEY_H)) {
            hitboxy = true;
        }

        if (lody <= -5) {
            ychange = 0;
            lody = 0;
        } else if (lody >= (screenh + 5 - lod_texture.height + 75)) {
            ychange = 0;
            lody = screenh - lod_texture.height + 75;
        }

        meteor_1_x -= 10;
        
        lod_area = {float(screenw/7-(lod_texture.height*0.5)), float(lody), float(lod_texture.height*0.5), float(lod_texture.width*0.5)};
        meteor_1_area = {float(meteor_1_x), float(meteor_1_y), float(meteor_1_texture.width*0.35), float(meteor_1_texture.height*0.35)};

        if (meteor_1_x <= -250) {
            meteor_1_x = screenw + meteor_1_texture.width;
            meteor_1_y = rand() % int(900 - meteor_1_texture.height*0.35) + 0;
            score += 1;
            meteor++;
        }

        for (size_t i = 0; i < strely.size(); ++i) {
            strely[i].x += 10;
            if (strely[i].x >= 1600) {
                strely.erase(strely.begin() + i);
            }
        }

        if (CheckCollisionRecs(meteor_1_area, lod_area)) {
            meteor_1_x = screenw + 20;
            meteor_1_y = rand() % int(900 - meteor_1_texture.height*0.35) + 0;
            score = 0;
            meteor++;
        }

        for (size_t i = 0; i < strely.size(); ++i) {
            if (CheckCollisionPointRec(strely[i], meteor_1_area)) {
                strely.erase(strely.begin() + i);
                meteor_1_x = screenw + 20;
                meteor_1_y = rand() % int(900 - meteor_1_texture.height*0.35) + 0;
                score++;
                break;
            }
        }

        lody += ychange;

        const char* score_text = TextFormat("Score: %0i", score);
        Vector2 score_textWidth = MeasureTextEx(font, score_text, 100.0f, 0.0f);
        float score_textX = (900 - score_textWidth.x);
        if (meteor == 4) {
            score--;
            meteor++;
        }
        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(backgroung_texture, screenw/2 - backgroung_texture.width/2, screenh/2 - backgroung_texture.height/2, WHITE);

        for (const auto& strela : strely) {
            DrawTextureEx(strela_texture, strela, 0.0f, 0.5f, WHITE);
        }

        DrawTextureEx(lod_texture, {float(screenw/7), float(lody)}, 90, 0.5f, WHITE);
        DrawTextureEx(meteor_1_texture, {float(meteor_1_x), float(meteor_1_y)}, meteor_rotation, 0.35f, WHITE);
        DrawTextEx(font, score_text, {score_textX, 30}, 100, 0.0f, WHITE);

        DrawTextureEx(cudl_texture, {back_rect.x, back_rect.y}, 0.0f, back_mult, WHITE);
        DrawTextEx(font, back_text, {(1600/2)-((back_text_width.x)/2), (900/1.25f)-((back_text_width.y)/2)}, 30.0f, 0.0f, WHITE);

        EndDrawing();
    }

    UnloadTexture(strela_texture);
    UnloadTexture(backgroung_texture);
    UnloadTexture(lod_texture);
    UnloadTexture(meteor_1_texture);
    UnloadFont(font);

    CloseWindow();

    return 0;
}
