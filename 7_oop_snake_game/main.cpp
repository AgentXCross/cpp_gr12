#include <iostream>
#include <raylib.h>
#include <deque>

using namespace std;

Color green = {173, 204, 96, 255};
Color dark_green = {43, 51, 24, 255}; //GUI Colors

int cell_size = 30;
int cell_count = 25; //Used to create an invisible grid

class Snake { //The snake will be represented as a deque, where elements can be easily removed or added in front and back like a vector array
    public:
        deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};

        void Draw() { //Draw the snake using rounded rectangles
            for(unsigned int i = 0; i < body.size(); i++) {
                float x = body[i].x;
                float y = body[i].y;
                Rectangle segment = Rectangle(x * cell_size, y * cell_size, (float)cell_size, (float)cell_size);
                DrawRectangleRounded(segment, 0.5, 6, dark_green);
            }
        }
};

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
    Snake snake = Snake();
    
    //Game Loop Components -> 1: Event Handling, 2: Updating Postitions, 3: Drawing Objects
    while(WindowShouldClose() == false) {
        BeginDrawing(); //blank canvas

        //Drawing
        ClearBackground(green);
        snake.Draw();
        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}