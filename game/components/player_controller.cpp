//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#include "player_controller.h"
#include "game_controller.h"
#include "hge/harpia_math.h"

using namespace Harpia;

namespace Jam {

    void PlayerController::Start() {
        _playerTransform = &GetObject()->transform;
    }

    void PlayerController::Update() {
        auto dt = Time()->deltaTime;

        if (_shootCooldown > 0) {
            _shootCooldown -= dt;
        }

        auto x = Input()->GetButtonAxis(SDLK_d, SDLK_a);
        if (x == 0) {
            x = Input()->GetButtonAxis(SDLK_RIGHT, SDLK_LEFT);
        }
        auto y = Input()->GetButtonAxis(SDLK_w, SDLK_s);
        if (y == 0) {
            y = Input()->GetButtonAxis(SDLK_UP, SDLK_DOWN);
        }
        auto pos = _playerTransform->GetPosition();
        pos.x += (float) x * speed * dt;
        pos.y += (float) y * speed * dt;
        pos.z = 0;

        CalculateAngle(dt, x);

        _playerTransform->SetPosition(pos);
        _playerTransform->SetRotation(_angle * Math::Deg2Rad,  Vector<3>::up);

        if (Input()->GetKeyIsDown(SDLK_SPACE) && _shootCooldown <= 0) {
            DebugLog("Pew");
            gameController->OnPlayerShoot(pos + Vector3{0, shootOffset, 0});
            _shootCooldown = shootMaxCooldown;
        }

        if (Input()->GetKeyDown(SDLK_ESCAPE)) {
            SceneManager()->LoadScene(1);
        }
    }

    void PlayerController::CalculateAngle(float dt, int x) {
        if (x > 0) {
            if (_angle < maxAngle) {
                _angle += angleDelta * dt;
            } else {
                _angle = maxAngle;
            }
        } else if (x < 0) {
            if (_angle > -maxAngle) {
                _angle -= angleDelta * dt;
            } else {
                _angle = -maxAngle;
            }
        } else if (_angle != 0) {
            _angle -= _angle * dt * 10;
            if (_angle < 0.01f && _angle > -0.01f) {
                _angle = 0;
            }
        }
    }
}// namespace Jam