//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 13/06/2022.
//

#include "rotate_around.h"
#include <hge/harpia_math.h>

using namespace Harpia;

namespace Jam {
    void RotateAround::Update() {
        _t += Time()->deltaTime;
        target->SetRotation(_t * speed.x * Math::Deg2Rad, {1, 0, 0});
        target->Rotate(_t * speed.y * Math::Deg2Rad, {0, 1, 0});
        target->Rotate(_t * speed.z * Math::Deg2Rad, {0, 0, 1});

        if(Input()->GetKeyDown(SDLK_F5)){
            SceneManager()->LoadScene(1);
        }
    }
}// namespace Jam