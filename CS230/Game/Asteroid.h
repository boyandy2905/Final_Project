/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Asteroid.h
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 26, 2025
*/

#pragma once
#include "..\Engine\Matrix.h"
#include "..\Engine\GameObject.h"
#include "GameObjectTypes.h"
//#include "..\Engine\Sprite.h"
//#include "..\Engine\Vec2.h"

class Asteroid : public CS230::GameObject {
public:
    Asteroid(Math::vec2 start_position);
    GameObjectTypes Type() override { return GameObjectTypes::Asteroid; }
    std::string TypeName() override { return "Asteroid"; }
    bool CanCollideWith(GameObjectTypes type) override;
    void ResolveCollision(GameObject* other_object) override;

    //virtual void Update(double dt) override;
    //void Load();
    //virtual void Draw(Math::TransformationMatrix object_matrix) override;

private:
    //CS230::Sprite sprite;
    //Math::vec2 start_position;
    //Math::vec2 position;
    //Math::vec2 velocity;
    //Math::TransformationMatrix object_matrix;

    //class State {
    //public:
    //    virtual void Enter(Asteroid* asteroid) = 0;
    //    virtual void Update(Asteroid* asteroid, double dt) = 0;
    //    virtual void CheckExit(Asteroid* asteroid) = 0;
    //    virtual std::string GetName() = 0;
    //};
    //State* current_state = nullptr;
    //void change_state(State* new_state);

    static constexpr double bounce_velocity = 500;
    //double start_y_position = 80;

    enum class Animations {
        None,
        Land
    };

    class State_Bouncing : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Bounce"; }
    };

    State_Bouncing state_bouncing;

    class State_Landing : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Land"; }
    };

    State_Landing state_landing;
};
