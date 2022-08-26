//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#ifndef INC_1JAMCHOICES_GAME_CONTROLLER_H
#define INC_1JAMCHOICES_GAME_CONTROLLER_H

#include "hge/component.h"
#include "projectile_controller.h"
#include "enemy_controller.h"
#include "hge/pool.h"

namespace Jam {
    class GameController : public Harpia::Component {
    private:
        std::list<ProjectileController*> _projectiles;
        std::list<EnemyController*> _enemies;

        Harpia::Pool<ProjectileController> _projectilePool;

    public:
        void Start() override;
        void Update() override;

        void OnPlayerShoot();
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_GAME_CONTROLLER_H
