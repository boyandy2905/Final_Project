/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Cat.h
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 22, 2025
*/

#pragma once
#include "..\Engine\Input.h"
#include "..\Engine\Camera.h"
#include "..\Engine\Matrix.h"
#include "..\Engine\GameObject.h"
#include "GameObjectTypes.h"
#include "..\Engine\Timer.h"
#include "..\Game\Portal.h"
#include "..\Engine\Particle.h"
#include "..\Game\Particles.h"

//#include "..\Engine\Sprite.h"
//#include "..\Engine\Vec2.h"

class Cat : public CS230::GameObject {
public:
    Cat(Math::vec2 start_position, GameObject* first_platform = nullptr);
    virtual void Update(double dt) override;
    const Math::vec2& GetPosition() const { return GameObject::GetPosition(); }
    GameObjectTypes Type() override { return GameObjectTypes::Cat; }
    std::string TypeName() override { return "Cat"; }
    bool CanCollideWith(GameObjectTypes other_object_type) override;
    void ResolveCollision(GameObject* other_object) override;
    void Draw(Math::TransformationMatrix camera_matrix) override;

    //void Load();
    //virtual void Draw(Math::TransformationMatrix camera_matrix) override;
    //const Math::vec2& GetPosition() const { return position; };
    //Cat(Math::vec2 start_position, const CS230::Camera& camera);

private:
    //CS230::Sprite sprite;
    //Math::vec2 position;
    //Math::vec2 velocity;
    //Math::vec2 start_position;
    //bool jumping = false;   // false : standing, true : jumping
    //bool going_up = false;  // false : falling, true : going up
    //Math::TransformationMatrix object_matrix;
    //bool flipped = false;    // false : Right, true : Left
    //const CS230::Camera& camera;
    //class State {
    //public:
    //    virtual void Enter(Cat* cat) = 0;
    //    virtual void Update(Cat* cat, double dt) = 0;
    //    virtual void CheckExit(Cat* cat) = 0;
    //    virtual std::string GetName() = 0;
    //};
    //State* current_state = nullptr;
    //void change_state(State* new_state);

    static constexpr double x_acceleration = 200;  // min 100 max 600
    static constexpr double x_drag = 450;               // min 001 max 200
    static constexpr double max_velocity = 300;    // min 100 max 600
    static constexpr double jump_velocity = 650;
    double start_y_position = 80;

    CS230::Timer* hurt_timer;
    static constexpr double hurt_time = 2.0;
    static constexpr double hurt_velocity = 350;
    static constexpr double hurt_acceleration = 300;

    static constexpr double bounce_velocity = 700;
    static constexpr double pop_velocity = 400;
    GameObject* standing_on;

    static constexpr double LargeFallHeight = 250.0;
    double fall_start_y_position = 0;

    void update_x_velocity(double dt);

    enum class Animations {
        Idle,
        Running,
        Jumping,
        Falling,
        Skidding
    };

    class State_Jumping : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Jumping"; }
    };

    State_Jumping state_jumping;

    class State_Idle : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Idle"; }
    };

    State_Idle state_idle;

    class State_Falling : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Falling"; }
    };

    State_Falling state_falling;

    class State_Running : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Running"; }
    };

    State_Running state_running;

    class State_Skidding : public CS230::GameObject::State {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Skidding"; }
    };

    State_Skidding state_skidding;
};