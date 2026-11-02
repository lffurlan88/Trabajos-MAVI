#include "raylib.h"
#include <string>

Color ColorRandom() {
    return Color{
        (unsigned char)GetRandomValue(0, 255), 
        (unsigned char)GetRandomValue(0, 255), 
        (unsigned char)GetRandomValue(0, 255), 
        100                                     
    };
}

int main() {
    const int screenWidth = 1024;
    const int screenHeight = 768;
    InitWindow(screenWidth, screenHeight, "La esfera viajera - Luciano Furlan");

    float radio = 30.0f;

    Vector2 posicion = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 velocidad = { 350.0f, 250.0f };

    Color colorEsfera = ColorRandom();

    int contadorRebotes = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime(); 
        posicion.x += velocidad.x * deltaTime;
        posicion.y += velocidad.y * deltaTime;

        if (posicion.x + radio >= screenWidth) {
            posicion.x = screenWidth - radio;
            velocidad.x *= -1.0f;
            contadorRebotes++;
            colorEsfera = ColorRandom();
        }

        else if (posicion.x - radio <= 0) {
            posicion.x = radio;
            velocidad.x *= -1.0f;
            contadorRebotes++;
            colorEsfera = ColorRandom();
        }

        if (posicion.y + radio >= screenHeight) {
            posicion.y = screenHeight - radio;
            velocidad.y *= -1.0f;
            contadorRebotes++;
            colorEsfera = ColorRandom();
        }

        else if (posicion.y - radio <= 0) {
            posicion.y = radio;
            velocidad.y *= -1.0f;
            contadorRebotes++;
            colorEsfera = ColorRandom();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircleV(posicion, radio, colorEsfera);

        DrawText("Resolucion: 1024x768", 20, 20, 20, DARKGRAY);

        std::string textoPosicion = "Posicion: (" + std::to_string((int)posicion.x) + ", " + std::to_string((int)posicion.y) + ")";
        DrawText(textoPosicion.c_str(), 20, 50, 20, DARKGRAY);

        std::string textoRebotes = "Rebotes: " + std::to_string(contadorRebotes);
        DrawText(textoRebotes.c_str(), 20, 80, 20, DARKGRAY);

        EndDrawing(); 
    }

    CloseWindow(); 
    return 0;
}