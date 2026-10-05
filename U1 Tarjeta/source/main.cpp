#ifndef NDEBUG
#include <vld.h> 
#endif

#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Tarjeta de Presentacion - Luciano Furlan");
    SetTargetFPS(60);

    Color fondo = { 20, 45, 20, 255 };
    Color colorTarjeta = { 50, 100, 50, 255 };
    Color doradoZelda = { 218, 165, 32, 255 };

    int centroX = 800 / 2;

    bool teclaPresionada = false;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            teclaPresionada = !teclaPresionada;
        }

        BeginDrawing();

        ClearBackground(fondo);

        DrawRectangle(150, 100, 500, 400, colorTarjeta);
        DrawRectangleLinesEx({ 150, 100, 500, 400 }, 3, doradoZelda);

        DrawCircle(centroX, 160, 35, doradoZelda);

        const char* miNombre = "LUCIANO FURLAN";
        int tamanoNombre = 32;
        int posXNombre = centroX - (MeasureText(miNombre, tamanoNombre) / 2);
        DrawText(miNombre, posXNombre, 220, tamanoNombre, WHITE);

        const char* subtitulo = "Estudiante de MAVI";
        int tamanoSub = 20;
        int posXSub = centroX - (MeasureText(subtitulo, tamanoSub) / 2);
        DrawText(subtitulo, posXSub, 265, tamanoSub, LIGHTGRAY);

        DrawLine(200, 310, 600, 310, doradoZelda);

        if (!teclaPresionada)
        {
            const char* msg1 = "Hola Hyrule!";
            int posXMsg1 = centroX - (MeasureText(msg1, 28) / 2);
            DrawText(msg1, posXMsg1, 360, 28, RAYWHITE);

            const char* inst1 = "[Presiona ESPACIO para cambiar]";
            int posXInst1 = centroX - (MeasureText(inst1, 22) / 2);
            DrawText(inst1, posXInst1, 430, 22, GRAY);
        }
        else
        {
            const char* msg2 = "Estoy aprendiendo en MAVI!";
            int posXMsg2 = centroX - (MeasureText(msg2, 28) / 2);
            DrawText(msg2, posXMsg2, 360, 28, GREEN);

            const char* inst2 = "[Presiona ESPACIO para volver]";
            int posXInst2 = centroX - (MeasureText(inst2, 22) / 2);
            DrawText(inst2, posXInst2, 430, 22, LIME);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
