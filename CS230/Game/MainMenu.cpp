/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  MainMenu.cpp
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    May 6, 2025
*/

#include "../Engine/Engine.h"
#include "Fonts.h"
#include "States.h"
#include "MainMenu.h"

MainMenu::MainMenu() {

}

void MainMenu::Load() {
    mainmenu = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("CS230 Engine Test", 0xA181F7FF);

    mode1_sel = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Side Scroller", color1);
    mode2_sel = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Space Shooter", color1);
    mode3_sel = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Final Project", color1);
    exit_sel = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Exit", color1);

    mode1_un = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Side Scroller", color2);
    mode2_un = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Space Shooter", color2);
    mode3_un = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Final Project", color2);
    exit_un = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Exit", color2);
}

void MainMenu::Update([[maybe_unused]] double dt) {
    //if (mode1_b == true) {
    //    mode1 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Side Scroller", 0xFFFFFFFF);
    //    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Enter)) {
    //        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode1));
    //    }
    //    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Down)) {
    //        mode1 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Side Scroller", 0x91B238FF);
    //        mode1_b = false;
    //        mode2_b = true;
    //    }
    //    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up)) {
    //        mode1 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Side Scroller", 0x91B238FF);
    //        mode1_b = false;
    //        exit_b = true;
    //    }
    //}
    //else if (mode2_b == true) {
    //    mode2 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Space Shooter", 0xFFFFFFFF);
    //    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Enter)) {
    //        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode2));
    //    }
    //    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Down)) {
    //        mode2 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Space Shooter", 0x91B238FF);
    //        mode2_b = false;
    //        exit_b = true;
    //    }
    //    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up)) {
    //        mode2 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Space Shooter", 0x91B238FF);
    //        mode2_b = false;
    //        mode1_b = true;
    //    }
    //}
    //else if (exit_b == true) {
    //    exit = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Exit", 0xFFFFFFFF);
    //    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Enter)) {
    //        Engine::GetGameStateManager().ClearNextGameState();
    //    }
    //    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Down)) {
    //        exit = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Exit", 0x91B238FF);
    //        exit_b = false;
    //        mode1_b = true;
    //    }
    //    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up)) {
    //        exit = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Exit", 0x91B238FF);
    //        exit_b = false;
    //        mode2_b = true;
    //    }
    //}

    //bool change = false;
    //bool color_b[3] = { mode1_b, mode2_b, exit_b };
    //unsigned int color[3];
    //for (int i = 0; i < 3; ++i) {
    //    color[i] = (color_b[i] == true) ? color2 : color1;
    //}
    //if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Enter)) {
    //    if (mode1_b == true && mode2_b == false && exit_b == false) {
    //        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode1));
    //    }
    //    else if (mode1_b == false && mode2_b == true && exit_b == false) {
    //        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode2));
    //    }
    //    else if (mode1_b == false && mode2_b == false && exit_b == true) {
    //        Engine::GetGameStateManager().ClearNextGameState();
    //    }
    //}
    //if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up)) {
    //    if (mode1_b == true && mode2_b == false && exit_b == false) {
    //        mode1_b = false;
    //        exit_b = true;
    //    }
    //    else if (mode1_b == false && mode2_b == true && exit_b == false) {
    //        mode2_b = false;
    //        mode1_b = true;
    //    }
    //    else if (mode1_b == false && mode2_b == false && exit_b == true) {
    //        exit_b = false;
    //        mode2_b = true;
    //    }
    //    mode1 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Side Scroller", color[0]);
    //    mode2 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Space Shooter", color[1]);
    //    exit = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Exit", color[2]);
    //    change = true;
    //}
    //if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Down)) {
    //    if (mode1_b == true && mode2_b == false && exit_b == false) {
    //        mode1_b = false;
    //        mode2_b = true;
    //    }
    //    else if (mode1_b == false && mode2_b == true && exit_b == false) {
    //        mode2_b = false;
    //        exit_b = true;
    //    }
    //    else if (mode1_b == false && mode2_b == false && exit_b == true) {
    //        exit_b = false;
    //        mode1_b = true;
    //    }
    //    mode1 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Side Scroller", color[0]);
    //    mode2 = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Space Shooter", color[1]);
    //    exit = Engine::GetFont(static_cast<int>(Fonts::Outlined)).PrintToTexture("Exit", color[2]);
    //    change = true;
    //}
    //if (change == true) {
    //    for (int i = 0; i < 3; ++i) {
    //        delete null[i];
    //        null[i] = nullptr;
    //    }
    //}

    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Enter)) {
        if (mode1_b == true && mode2_b == false && mode3_b == false && exit_b == false) {
            Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode1));
        }
        else if (mode1_b == false && mode2_b == true && mode3_b == false && exit_b == false) {
            Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode2));
        }
        else if (mode1_b == false && mode2_b == false && mode3_b == true && exit_b == false) {
            Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode3));
        }
        else if (mode1_b == false && mode2_b == false && mode3_b == false && exit_b == true) {
            Engine::GetGameStateManager().ClearNextGameState();
        }
    }
    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up)) {
        if (mode1_b == true && mode2_b == false && mode3_b == false && exit_b == false) {
            mode1_b = false;
            exit_b = true;
        }
        else if (mode1_b == false && mode2_b == true && mode3_b == false && exit_b == false) {
            mode2_b = false;
            mode1_b = true;
        }
        else if (mode1_b == false && mode2_b == false && mode3_b == true && exit_b == false) {
            mode3_b = false;
            mode2_b = true;
        }
        else if (mode1_b == false && mode2_b == false && mode3_b == false && exit_b == true) {
            exit_b = false;
            mode3_b = true;
        }
    }
    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Down)) {
        if (mode1_b == true && mode2_b == false && mode3_b == false && exit_b == false) {
            mode1_b = false;
            mode2_b = true;
        }
        else if (mode1_b == false && mode2_b == true && mode3_b == false && exit_b == false) {
            mode2_b = false;
            mode3_b = true;
        }
        else if (mode1_b == false && mode2_b == false && mode3_b == true && exit_b == false) {
            mode3_b = false;
            exit_b = true;
        }
        else if (mode1_b == false && mode2_b == false && mode3_b == false && exit_b == true) {
            exit_b = false;
            mode1_b = true;
        }
    }
}

void MainMenu::Unload() {
    delete mode1_sel;
    delete mode2_sel;
    delete mode3_sel;
    delete exit_sel;
    delete mode1_un;
    delete mode2_un;
    delete mode3_un;
    delete exit_un;
}

void MainMenu::Draw() {
    Engine::GetWindow().Clear(0x252439FF);

    mainmenu->Draw(Math::TranslationMatrix(Math::ivec2{ Engine::GetWindow().GetSize().x / 2 - 345, Engine::GetWindow().GetSize().y - 150 }) * Math::ScaleMatrix(Math::vec2{ 1.5, 1.5 }));
    if (mode1_b) {
        mode1_sel->Draw(Math::TranslationMatrix(Math::ivec2{ Engine::GetWindow().GetSize().x / 2 - 165, Engine::GetWindow().GetSize().y - 250 }));
    }
    else {
        mode1_un->Draw(Math::TranslationMatrix(Math::ivec2{ Engine::GetWindow().GetSize().x / 2 - 165, Engine::GetWindow().GetSize().y - 250 }));
    }
    if (mode2_b) {
        mode2_sel->Draw(Math::TranslationMatrix(Math::ivec2{ Engine::GetWindow().GetSize().x / 2 - 180, Engine::GetWindow().GetSize().y - 350 }));
    }
    else {
        mode2_un->Draw(Math::TranslationMatrix(Math::ivec2{ Engine::GetWindow().GetSize().x / 2 - 180, Engine::GetWindow().GetSize().y - 350 }));
    }
    if (mode3_b) {
        mode3_sel->Draw(Math::TranslationMatrix(Math::ivec2{ Engine::GetWindow().GetSize().x / 2 - 165, Engine::GetWindow().GetSize().y - 450 }));
    }
    else {
        mode3_un->Draw(Math::TranslationMatrix(Math::ivec2{ Engine::GetWindow().GetSize().x / 2 - 165, Engine::GetWindow().GetSize().y - 450 }));
    }
    if (exit_b) {
        exit_sel->Draw(Math::TranslationMatrix(Math::ivec2{ Engine::GetWindow().GetSize().x / 2 - 45, Engine::GetWindow().GetSize().y - 550 }));
    }
    else {
        exit_un->Draw(Math::TranslationMatrix(Math::ivec2{ Engine::GetWindow().GetSize().x / 2 - 45, Engine::GetWindow().GetSize().y - 550 }));
    }
}
