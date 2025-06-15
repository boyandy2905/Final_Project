/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  OtherCarManager.h
Project:    CS230 Game
Author:     Sehoon Kim, Chanwoong Moon
Created:    June 14, 2025
*/

#pragma once
#include <vector>
#include "../Engine/GameObject.h"
#include "../Engine/Timer.h"
#include "../Game/GameObjectTypes.h"

class Mode3;

class OtherCarManager : public CS230::GameObject {
public:
    OtherCarManager(Mode3* mode);
    void Update(double dt) override;
    GameObjectTypes Type() override { return GameObjectTypes::OtherCarManager; }
    std::string TypeName() override { return "OtherCarManager"; }

private:
    CS230::Timer spawn_timer;
    Mode3* mode3_ptr;
    std::vector<double> y_positions = { 50, 175, 300, 425, 550 };
    int last_used_index = -1;
};