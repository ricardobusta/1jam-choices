//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#include "game_config.h"
#include "scenes/init_scene.h"
#include "scenes/main_menu_scene.h"
#include "scenes/game_scene.h"

#include <SDL.h>

namespace Jam {
    void GameConfig::Configure(Harpia::Configuration &configuration) {
        configuration.game.title = "Space Game";
        configuration.game.frameRateCap = 0;

        configuration.window.position = Harpia::Vector2Int (2350, 000);
        configuration.window.overridePosition = true;
        configuration.window.size = Harpia::Vector2Int(800, 600);
        configuration.window.resizeable = true;
        configuration.window.vsync = true;

        configuration.input.mappedKeys.insert(configuration.input.mappedKeys.end(), {
                SDLK_UP, SDLK_DOWN, SDLK_LEFT, SDLK_RIGHT, SDLK_w, SDLK_a, SDLK_s, SDLK_d
        });

        configuration.game.scenes.insert(configuration.game.scenes.end(), {
                new InitScene(),
                new MainMenuScene(),
                new GameScene(),
        });
    }
} // Jam