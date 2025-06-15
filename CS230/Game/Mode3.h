/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Mode3.h
Project:    CS230 Game
Author:     Sehoon Kim, Chanwoong Moon
Created:    June 14, 2025
*/

#pragma once
#include <raylib.h>
#include <vector>
#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"
#include "../Game/Background.h"
#include "../Engine/GameObjectManager.h"
#include "../Engine/Particle.h" 
#include "../Engine/Timer.h"



class Player;

class Mode3 : public CS230::GameState {
public:
    Mode3();
    void Load() override;
    void Update(double dt) override;
    void Unload() override;
    void Draw() override;

    std::string GetName() override {
        return "Mode3";
    }

    static constexpr double timer_max = 40;

private:
    CS230::Texture texture;
    Player* player_ptr = nullptr;              // 초기화
    static constexpr double car_timer = 4.5;
    double last_time = 0.0;                  // 초기화

    CS230::Texture* timer_texture = nullptr;   // 초기화
    int last_timer = 0;                    //초기화
    void update_timer_text(int value);

    //CS230::ParticleManager<Smoke>* smoke_manager = nullptr;

    CS230::Texture* distance_texture = nullptr;              // 초기화
    double total_distance = 0.0;                  //  초기화
    int last_distance = 0;                    // 거리 변경 시 업데이트
    void update_distance_text(int distance);
};
