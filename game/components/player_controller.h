//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#ifndef INC_1JAMCHOICES_PLAYER_CONTROLLER_H
#define INC_1JAMCHOICES_PLAYER_CONTROLLER_H

#include "hge/component.h"

namespace Jam {
    class PlayerController : public Harpia::Component {
    public:
        float angleDelta = 230.0f;
        float maxAngle = 40.0f;
        float speed = 20.0f;
    private:
        Harpia::Transform *_playerTransform = nullptr;
        float _angle = 0;
    public:
        void Start() override;
        void Update() override;
        void CalculateAngle(float dt, int x);
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_PLAYER_CONTROLLER_H
