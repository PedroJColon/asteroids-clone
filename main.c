#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>

#define SCREENWIDTH 640
#define SCREENHEIGHT 480
#define MAXASTEROIDMEMORY 50

struct Object
{
  Vector2 oPos;
  Vector2 oVelocity;
  int oSize; 
};

Vector2 WarpToridoal(float inputX, float inputY)
{
  Vector2 returnValue = {inputX,inputY};
  if (inputX < 0.0f)
  {
    returnValue.x = inputX + (float)SCREENWIDTH;
  }
  if (inputX >= (float)SCREENWIDTH)
  {
    returnValue.x = inputX - (float)SCREENWIDTH;
  }
  if (inputY < 0.0f)
  {
    returnValue.y = inputY + (float)SCREENHEIGHT;
  }
  if (inputY >= (float)SCREENHEIGHT)
  {
    returnValue.y = inputY - (float)SCREENHEIGHT;
  }
  
  return returnValue;
}

void Draw(int x, int y, int size)
{
  Vector2 floatDraw = WarpToridoal(x, y);
  DrawPixel(floatDraw.x, floatDraw.y , RED);
}

void GameLoop()
{
  struct Object* asteroids = (struct Object*)malloc(MAXASTEROIDMEMORY * sizeof(struct Object));
  asteroids[0] = (struct Object){100,100, 12,-12, (int)12 };
  asteroids[1] = (struct Object){200,300, 12,20, (int)50 };
  struct Object testAsteroid = asteroids[0];

  while (!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BLACK);
      for (int i = 0; i < 2; i++)
      {
        asteroids[i].oPos.x += asteroids[i].oVelocity.x * GetFrameTime();
        asteroids[i].oPos.y += asteroids[i].oVelocity.y * GetFrameTime();
        asteroids[i].oPos = WarpToridoal(asteroids[i].oPos.x, asteroids[i].oPos.y);
        for (int x = 0; x < asteroids[i].oSize; x++)
        {
          for (int y = 0; y < asteroids[i].oSize; y++)
          {
            Draw(asteroids[i].oPos.x + x, asteroids[i].oPos.y + y, asteroids[i].oSize);
          }
        }        
      }
      DrawText("Hello World!", SCREENWIDTH/2, SCREENHEIGHT/2, 16, RED);
    EndDrawing();
  }

  free(asteroids);
}

int main(int argc, char const *argv[])
{
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Asteroids Clone");
  SetTargetFPS(60);
  GameLoop();
  CloseWindow();
  return 0;
}
