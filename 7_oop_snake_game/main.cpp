#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

using namespace std;

Color green = {173, 204, 96, 255};
Color dark_green = {43, 51, 24, 255}; //GUI Colors

int cell_size = 24;
int cell_count = 25; //Used to create an invisible grid
int offset = 75; //Extra border

double last_update_time = 0; //Keep track of time after last snake movement

bool element_in_deque(Vector2 element, deque<Vector2> deque) { //Ensure the food/apple doesn't spawn on grid spots already occupied by the snake
    for(unsigned int i = 0; i < deque.size(); i++) {
        if(Vector2Equals(deque[i], element)) {
            return true;
        }
    }
    return false;
}

bool event_triggered(double interval) { //Used to slow the movement of the snake
    double current_time = GetTime();
    if(current_time - last_update_time >= interval) {
        last_update_time = current_time;
        return true;
    }
    return false;
}

class Snake { //The snake will be represented as a deque, where elements can be easily removed or added in front and back like a vector array
    public:
        deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
        Vector2 direction = {1, 0};
        bool add_segment = false;

        void Draw() { //Draw the snake using rounded rectangles
            for(unsigned int i = 0; i < body.size(); i++) {
                float x = body[i].x;
                float y = body[i].y;
                Rectangle segment = Rectangle(offset + x * cell_size, offset + y * cell_size, (float)cell_size, (float)cell_size);
                DrawRectangleRounded(segment, 0.5, 6, dark_green);
            }
        }

        void Update() { //update grid placements as the snake moves in a direction by adding vectors
            body.push_front(Vector2Add(body[0], direction)); //Add one piece to snake in current facing direction   
            if(add_segment == true) {
                add_segment = false;
            } else {
                body.pop_back(); //remove back of snake
            }
        }

        void Reset() { //Reset position if game over
            body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
            direction = {1, 0};
        }
};

class Food { //Class to represent the snake food
    public:
        Vector2 position; //position.x, position.y
        Texture2D texture;
    
        Food(deque<Vector2> snake_body) { //Constructor function to load apple image
            Image image = LoadImage("food.png"); //path to image
            texture = LoadTextureFromImage(image); //Store pixel data
            UnloadImage(image);
            position = generate_random_pos(snake_body);
        }

        ~Food() { //Destructor function
            UnloadTexture(texture);
        }

    void Draw() {
        //DrawTexture(texture, position.x * cell_size, position.y * cell_size, WHITE); Tutorial version
        Vector2 position_pixels = {offset + position.x * cell_size, offset + position.y * cell_size};
        float scale = (float)cell_size / texture.width; // Assumes square image
        DrawTextureEx(texture, position_pixels, 0.0f, scale, WHITE);
    }

    Vector2 generate_random_cell() {
        float x = GetRandomValue(0, cell_count - 1);
        float y = GetRandomValue(0, cell_count - 1);
        return Vector2{x, y};
    }

    Vector2 generate_random_pos(deque<Vector2> snake_body) {
        Vector2 postion = generate_random_cell();
        while(element_in_deque(position, snake_body)) {//Ensure new spawns not on the snake
            position = generate_random_cell();
        }
        return position;
    }
};

class Game {
    public:
        Snake snake = Snake();
        Food food = Food(snake.body);
        bool running = true;
        int score = 0;

        void Draw() {
            food.Draw();
            snake.Draw();
        }

        void Update() {
            if(running){
                snake.Update();
                check_collision_with_food();
                check_collision_with_edges();
                check_collision_with_tail();
            }
        }

        void check_collision_with_food() { //A collision occurs when the head of the snake is on the food grid vector
            if(Vector2Equals(snake.body[0], food.position)) {
                food.position = food.generate_random_pos(snake.body);
                snake.add_segment = true;
                score++;
            }
        }

        void check_collision_with_edges() {
            if(snake.body[0].x == cell_count || snake.body[0].x == -1) {
                game_over(); //End game if the snake moves out
            }
            if(snake.body[0].y == cell_count || snake.body[0].y == -1) {
                game_over();
            }
        }

        void game_over() { //End game
            snake.Reset();
            food.position = food.generate_random_pos(snake.body);
            running = false;
            score = 0;
        }

        void check_collision_with_tail() { //Check if the head hits any of the body vectors
            deque<Vector2> headless_body = snake.body;
            headless_body.pop_front();
            if(element_in_deque(snake.body[0], headless_body)) {
                game_over();
            }
        }
};

int main() {

    cout << "Starting the game ... " << endl;
    InitWindow(2 * offset + cell_size * cell_count, 2 * offset + cell_size * cell_count, "RETRO SNAKE"); //750 by 750 pixels. The origin (0,0) is at the top left. Margins are created using offset
    SetTargetFPS(60); //60 Frames per second

    Game game = Game();
    
    //Game Loop Components -> 1: Event Handling, 2: Updating Postitions, 3: Drawing Objects
    while(WindowShouldClose() == false) {
        BeginDrawing(); //blank canvas

        if(event_triggered(0.2)) {
            game.Update();
        }
        
        //Key pressing functions to change direction while also ensuring the player cannot 180
        if(IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) { 
            game.snake.direction = {0, -1};
            game.running = true;
        }
        
        if(IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) { 
            game.snake.direction = {0, 1};
            game.running = true;
        }

        if(IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) { 
            game.snake.direction = {-1, 0};
            game.running = true;
        }

        if(IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) { 
            game.snake.direction = {1, 0};
            game.running = true;
        }

        //Drawing
        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cell_size * cell_count + 10, (float)cell_size * cell_count + 10}, 5, dark_green);
        DrawText("RETRO SNAKE", offset - 5, 20, 40, dark_green);
        DrawText(TextFormat("%i", game.score), offset - 5, offset + cell_count * cell_size + 10, 40, dark_green);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}