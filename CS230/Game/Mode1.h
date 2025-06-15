/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Mode1.h
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 13, 2025
*/

#pragma once
#include <raylib.h>
#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"
#include "../Game/Background.h"
#include "../Engine/Matrix.h"
#include "../Engine/GameObjectManager.h"
#include "../Game/Gravity.h"
#include "../Engine/Timer.h"
#include "../Engine/ShowCollision.h"
#include "../Engine/Particle.h"
#include "Particles.h"

class Cat;

class Mode1 : public CS230::GameState {
public:
    Mode1();
    void Load() override;
    void Update(double dt) override;
    void Unload() override;
    void Draw() override;

    std::string GetName() override {
        return "Mode1";
    }

    static constexpr double gravity = 800;
    static constexpr double floor = 80;

    static constexpr double timer_max = 60;

private:
    CS230::Texture texture;
    Cat* cat_ptr;

    CS230::Texture* timer_texture;
    int last_timer;
    void update_timer_text(int value);

    CS230::Texture* score_texture;
    int score;
    void update_score_text(int value);

    //Cat cat;
    //std::vector<Asteroid> asteroids;
    //CS230::Camera camera;
    //double timer;
    //CS230::GameObjectManager gameobjectmanager;
    //Background background;
};
