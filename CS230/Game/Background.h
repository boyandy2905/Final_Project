/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Background.h
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 30, 2025
*/

#pragma once
#include "../Engine/Texture.h"
#include "../Engine/Camera.h"
#include "../Engine/Component.h"

class Background : public CS230::Component {
public:
    void Add(const std::filesystem::path& texture_path, double speed);
    void Unload();
    void Draw(const CS230::Camera& camera);
    Math::ivec2 GetSize();

    // void Draw(Math::TransformationMatrix &camera_matrix);
private:
    struct ParallaxLayer {
        CS230::Texture* texture;
        double speed = 1;

        //CS230::Texture texture;
    };

    std::vector<ParallaxLayer> backgrounds;
};
