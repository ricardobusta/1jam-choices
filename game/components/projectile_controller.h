//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 26/08/2022.
//

#ifndef INC_1JAMCHOICES_PROJECTILE_CONTROLLER_H
#define INC_1JAMCHOICES_PROJECTILE_CONTROLLER_H

#include "hge/component.h"

namespace Jam {
    class GameController;

    class ProjectileController : public Harpia::Component {
    public:
        float lifeTime;
        float speed = 50;

        void Restart();
        void Initialize(float lifeTime, const Harpia::Vector3 &pos, Harpia::MeshAsset *mesh, Harpia::MaterialAsset *material, int layerMask);
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_PROJECTILE_CONTROLLER_H
