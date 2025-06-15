/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Engine.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 13, 2025
*/

#pragma once
#include "Engine.h"

Engine::Engine() :
    last_tick(std::chrono::system_clock::now()),
#ifdef _DEBUG
    logger(CS230::Logger::Severity::Debug, true, last_tick)
#else
    logger(CS230::Logger::Severity::Event, false, last_tick)
#endif
{
}

void Engine::Start(std::string window_title) {
    logger.LogEvent("Engine Started");

    unsigned int seed = static_cast<unsigned int>(time(NULL));
    srand(seed);
    logger.LogEvent(std::to_string(seed));

    window.Start(window_title);
    //Start other services
    last_test = last_tick;
}

void Engine::Stop() {
    //Stop all services
    logger.LogEvent("Engine Stopped");
}

void Engine::Update() {
    logger.LogVerbose("Engine Update");

    //Update other services
    now = std::chrono::system_clock::now();
    double dt = std::chrono::duration<double>(now - last_tick).count();

    if (dt >= 1.0 / TargetFPS) {
        logger.LogVerbose("Engine Update");
        last_tick = now;

        frame_count++;
        if (frame_count >= FPSTargetFrames) {
            double actual_time = std::chrono::duration<double>(now - last_test).count();
            logger.LogDebug("FPS: " + std::to_string(frame_count / actual_time));

            frame_count = 0;
            last_test = now;
        }

        gamestatemanager.Update(dt);
        input.Update();
        window.Update();
    }
}

bool Engine::HasGameEnded() {
    if (GetGameStateManager().HasGameEnded() == true || window.IsClosed()) {
        return true;
    }
    return false;
}

void Engine::AddFont(const std::filesystem::path& file_name) {
    CS230::Font new_font(file_name);
    fonts.push_back(std::move(new_font));
}
