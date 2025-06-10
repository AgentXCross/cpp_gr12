#include <iostream>
#include <raylib.h>

using namespace std;

Color green = {173, 204, 96, 255};
Color dark_green = {43, 51, 24, 255}; //GUI Colors

int cell_size = 30;
int cell_count = 25; //Used to create an invisible grid

class Food { //Class to represent the snake food
    public:
        Vector2 position; //position.x, position.y
        Texture2D texture;
    
        Food() { //Constructor function to load apple image
            Image image = LoadImage("food.png"); //path to image
            texture = LoadTextureFromImage(image); //Store pixel data
            UnloadImage(image);
            position = generate_random_pos();
        }

        ~Food() { //Destructor function
            UnloadTexture(texture);
        }

    void Draw() {
        //DrawTexture(texture, position.x * cell_size, position.y * cell_size, WHITE); Tutorial version
        Vector2 position_pixels = {position.x * cell_size, position.y * cell_size};
        float scale = (float)cell_size / texture.width; // Assumes square image
        DrawTextureEx(texture, position_pixels, 0.0f, scale, WHITE);
    }

    Vector2 generate_random_pos() {
        float x = GetRandomValue(0, cell_count - 1);
        float y = GetRandomValue(0, cell_count - 1);
        return Vector2(x, y);
    }
};

int main() {

    cout << "Starting the game ... " << endl;
    InitWindow(cell_size * cell_count, cell_size * cell_count, "RETRO SNAKE"); //750 by 750 pixels. The origin (0,0) is at the top left.
    SetTargetFPS(60); //60 Frames per second

    Food food = Food();
    
    //Game Loop Components -> 1: Event Handling, 2: Updating Postitions, 3: Drawing Objects
    while(WindowShouldClose() == false) {
        BeginDrawing(); //blank canvas

        //Drawing
        ClearBackground(green);
        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}