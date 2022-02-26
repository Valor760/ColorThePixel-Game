#pragma once

#include <stdint.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Resources/ResourceManager.h"
#include "../Resources/SpriteRenderer.h"


enum GameState {
    GAME_MAIN_MENU,
    GAME_ACTIVE,

    GAME_STATE_COUNT
};

class Game {
    public:
        bool keys[1024];
        bool processed_keys[1024];
        uint32_t window_width, window_height;
        GameState state;

        Resources::SpriteRenderer* sprite_renderer;

        Game(uint32_t _window_width, uint32_t _window_height);
        ~Game();
        void Init();
        void ProcessInput(float dt);
        void Update(float dt);
        void Render();

};