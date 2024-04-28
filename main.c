#include <raylib.h>

#define SCREENWIDTH 640
#define SCREENHEIGHT 480

void GameLoop()
{
  while (!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BLACK);
      DrawText("Hello World!", SCREENWIDTH/2, SCREENHEIGHT/2, 16, RED);
    EndDrawing();
  }

}

int main(int argc, char const *argv[])
{
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Asteroids Clone");

  SetTargetFPS(60);
  GameLoop();
  CloseWindow();
  return 0;
}
