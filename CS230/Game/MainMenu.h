/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  MainMenu.h
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    May 6, 2025
*/

#pragma once
#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"

class MainMenu : public CS230::GameState {
public:
    MainMenu();
    void Load() override;
    void Update(double dt) override;
    void Unload() override;
    void Draw() override;

    std::string GetName() override {
        return "MainMenu";
    }
private:
    CS230::Texture* mainmenu;

    CS230::Texture* mode1_sel;
    CS230::Texture* mode2_sel;
    CS230::Texture* mode3_sel;
    CS230::Texture* exit_sel;

    CS230::Texture* mode1_un;
    CS230::Texture* mode2_un;
    CS230::Texture* mode3_un;
    CS230::Texture* exit_un;

    bool mode1_b = true;
    bool mode2_b = false;
    bool mode3_b = false;
    bool exit_b = false;

    unsigned int color1 = 0xFFFFFFFF;
    unsigned int color2 = 0x91B238FF;
};
