//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 26/08/2022.
//

#ifndef INC_1JAMCHOICES_PROJECTILE_CONTROLLER_H
#define INC_1JAMCHOICES_PROJECTILE_CONTROLLER_H

#include "hge/component.h"

namespace Jam {
    class ProjectileController : public Harpia::Component {
    public:
        void Initialize();
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_PROJECTILE_CONTROLLER_H
