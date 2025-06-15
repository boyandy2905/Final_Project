/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Player.h
Project:    CS230 Game
Author:     Sehoon Kim, Chanwoong Moon
Created:    June 14, 2025
*/

#pragma once
#include "..\Engine\Camera.h"
#include "..\Engine\GameObject.h"
#include "GameObjectTypes.h"
#include "..\Engine\Timer.h"
#include "..\Game\Portal.h"
#include "..\Engine\Particle.h"
#include "..\Game\Particles.h"

class Player : public CS230::GameObject {
public:
    Player(Math::vec2 start_position);
    virtual void Update(double dt) override;
    const Math::vec2& GetPosition() const { return GameObject::GetPosition(); }
    GameObjectTypes Type() override { return GameObjectTypes::Player; }
    std::string TypeName() override { return "Player"; }
    bool CanCollideWith(GameObjectTypes other_object_type) override;
    void ResolveCollision(GameObject* other_object) override;
    void Draw(Math::TransformationMatrix camera_matrix) override;
    bool IsBoosting() const { return is_boosting; }

private:
    static constexpr double x_acceleration = 200;
    static constexpr double max_velocity = 400;
    static constexpr double min_velocity = 100;

    CS230::Timer* hurt_timer;
    static constexpr double hurt_time = 2.0;
    //static constexpr double hurt_velocity = 350;
    //static constexpr double hurt_acceleration = 300;

    CS230::Timer* boost_timer;
    CS230::Timer* boost_cooldown_timer;
    bool is_boosting = false;
    bool was_boosting = false;
    static constexpr double boost_time = 3.0;
    double exhaust_accumulator = 0.0;    // ���� qocnf �ð�
    static constexpr double exhaust_interval = 0.1;
};
