//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#include "init_scene.h"
#include "hge/assets.h"
#include "init_game.h"

using namespace Harpia;

namespace Jam {
    void InitScene::Load(Application *application) {
        auto camera = CreateSimpleOrthoCamera(10);
        camera->SetClearColor(Color::darkGray);

        auto fontAtlas = LoadTextureAsset("assets/fonts/pixel.png");
        fontAtlas->_filter = TextureFilter::Nearest;
        auto fontShader = LoadShaderAsset("assets/shaders/text.vert", "assets/shaders/text.frag");
        auto fontMaterial = LoadMaterialAsset(fontShader);
        fontMaterial->SetTexture(fontAtlas);
        fontMaterial->SetColor(Color::white);
        fontMaterial->_transparent = true;

        auto textObject = CreateObject("Text");
        auto textRenderer = textObject->AddComponent<TextRendererComponent>();
        textRenderer->SetFontMaterial(fontMaterial, 7, 9);
        textRenderer->SetText("loading...");
        textObject->transform.SetPosition({-textRenderer->GetSize().x/2,-textRenderer->GetSize().y/2});

        auto controllerObject = CreateObject("Controller Object");
        controllerObject->AddComponent<InitGame>();
    }
} // Jam