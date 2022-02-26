#include "Game.h"


Game::Game(uint32_t _window_width, uint32_t _window_height) 
    : state{GAME_MAIN_MENU}, keys(), window_width{_window_width}, window_height{_window_height} {
    
}

Game::~Game() {

}

void Game::Init() {
    // Load shaders
    Resources::ResourceManager::LoadShader("Shaders/texture.vertex", "Shaders/texture.fragment", "sprite");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->window_width),
                                      static_cast<float>(this->window_height), 0.0f, -1.0f, 1.0f);
    
    Resources::Shader shader = Resources::ResourceManager::GetShader("sprite").Use();
    shader.SetInt("image", 0);
    shader.SetMat4("projection", projection);
    // Shader particle_shader = ResourceManager::GetShader("particle").Use();
    // particle_shader.SetMat4("projection", projection);

    this->sprite_renderer = new Resources::SpriteRenderer(shader);

    // Load textures
    Resources::ResourceManager::LoadTexture("Textures/background.jpeg", false, "background");

    // text_render = new TextRenderer(this->width, this->height);
    // text_render->Load("Fonts/OCRAEXT.TTF", 24);
}

void Game::Update(float dt) {

}

void Game::ProcessInput(float dt) {
 
}

void Game::Render() {
    Resources::Texture2D background = Resources::ResourceManager::GetTexture("background");
    sprite_renderer->DrawSprite(background, glm::vec2(0.0f, 0.0f), glm::vec2(this->window_width,
                                this->window_height), 0.0f);

    // if(this->state == GAME_MENU) { 
    //     text_render->RenderText("Press ENTER to start!", 
    //                             250.0f, this->height / 2.0f + 45.0f, 1.0f);
    //     text_render->RenderText("Press W or S to select level!", 
    //                             190.0f, this->height / 2.0f + 45.0f + 25.0f, 1.0f);
    // }
}
