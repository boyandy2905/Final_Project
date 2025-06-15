/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  GameStateManager.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 13, 2025
*/

#pragma once
#include "GameState.h"
#include <vector>

namespace CS230 {
    class GameStateManager {
    public:
        GameStateManager();
        void Update(double dt);

        void AddGameState(GameState& gamestate);
        void SetNextGameState(int index);
        void ClearNextGameState();
        void ReloadState();
        bool HasGameEnded() const; // const need or needless

        template<typename T>
        T* GetGSComponent() { return current_gamestate->GetGSComponent<T>(); }
         
    private:
        enum class Status {
            STARTING,
            LOADING,
            UPDATING,
            UNLOADING,
            STOPPING,
            EXIT
        };

        Status status;
        std::vector<GameState*> gamestates;
        GameState* current_gamestate;
        GameState* next_gamestate;
    };
}
