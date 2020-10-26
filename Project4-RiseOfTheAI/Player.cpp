

#include "Player.h"


Player::Player(GLuint textID, glm::vec3 position, float speed):
    Entity(EntityType::PLAYER, textID, position, speed) {}


void Player::ProcessPlayerInput() {
        movement = glm::vec3(0);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    // Move the player left
                    break;

                case SDLK_RIGHT:
                    // Move the player right
                    break;

                case SDLK_SPACE:
                    // Some sort of action
                    if (collidedBottom) { jump = true; }
                    break;
                }
                break; // SDL_KEYDOWN
            }
        }

        const Uint8* keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_LEFT]) {
            movement.x = -1.0f;
            animIndices = animLeft;
        }
        else if (keys[SDL_SCANCODE_RIGHT]) {
            movement.x = 1.0f;
            animIndices = animRight;
        }


        if (glm::length(movement) > 1.0f) {
            movement = glm::normalize(movement);
        }
	}

void Player::Update(float deltaTime, const std::vector<Entity*>& entitySets) {
    if (jump) {
        jump = false;
        velocity.y += jumpPower;
    }
    Entity::Update(deltaTime, entitySets);
}
