/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Crates.cpp
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    April 27, 2025
*/

#pragma once
#include "Crates.h"
#include "../Engine/Engine.h"
#include "Mode1.h"

Crates::Crates(Math::vec2 position, int size) : CS230::GameObject(position) {
    switch (size) {
    case 1:
        AddGOComponent(new CS230::Sprite("Assets/Crates1.spt", this));

        //AddGOComponent(new CS230::Sprite("Assets/Crates1.spt"));
        //sprite.Load("Assets/Crates1.spt");
        break;
    case 2:
        AddGOComponent(new CS230::Sprite("Assets/Crates2.spt", this));

        //AddGOComponent(new CS230::Sprite("Assets/Crates2.spt"));
        //sprite.Load("Assets/Crates2.spt");
        break;
    case 3:
        AddGOComponent(new CS230::Sprite("Assets/Crates3.spt", this));

        //AddGOComponent(new CS230::Sprite("Assets/Crates3.spt"));
        //sprite.Load("Assets/Crates3.spt");
        break;
    case 5:
        AddGOComponent(new CS230::Sprite("Assets/Crates5.spt", this));

        //AddGOComponent(new CS230::Sprite("Assets/Crates5.spt"));
        //sprite.Load("Assets/Crates5.spt");
        break;
    }
}
