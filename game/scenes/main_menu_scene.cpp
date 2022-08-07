//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#include "main_menu_scene.h"

#include "hge/application.h"
#include "hge/assets.h"
#include "hge/camera_component.h"
#include "hge/text_renderer_component.h"

namespace Jam {
    void MainMenuScene::Load(Application *application) {
        auto sizeV = 10;
        auto aspect = application->GetScreenAspect();
        auto sizeH = sizeV * aspect;

        auto camera = CreateSimpleOrthoCamera(sizeV);
        camera->SetClearColor(Color::blue);

        auto fontAtlas = LoadTextureAsset("assets/fonts/pixel.png");
        fontAtlas->_filter = TextureFilter::Nearest;
        auto fontShader = LoadShaderAsset("assets/shaders/text.vert", "assets/shaders/text.frag");
        auto fontMaterial = LoadMaterialAsset(fontShader);
        fontMaterial->SetTexture(fontAtlas);
        fontMaterial->SetColor(Color::white);
        fontMaterial->_transparent = true;

        CreateCenteredText("Choices Ships", fontMaterial, sizeV / 2, 1.5f);
        CreateCenteredText("Game by Ricardo Bustamante <ricardo@busta.dev>", fontMaterial, -sizeV+1, 0.65f);
    }

    Object *MainMenuScene::CreateCenteredText(const std::string &text, MaterialAsset *material, float y, float scale) {
        auto textObject = CreateObject("Text");
        auto textRenderer = textObject->AddComponent<TextRendererComponent>();
        textRenderer->SetFontMaterial(material, 7, 9);
        textRenderer->SetText(text);
        textObject->transform.SetPosition({(scale * -textRenderer->GetSize().x) / 2, y});
        textObject->transform.SetScale(scale);

        return textObject;
    }
}// namespace Jam