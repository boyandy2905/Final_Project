/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Timer.h
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    May 12, 2025
*/

#pragma once
#include "../Engine/Component.h"

namespace CS230 {
    class Timer : public Component {
    public:
        Timer(double time_remaining) {
            Set(time_remaining);
        }
        void Set(double time_remaining) {
            timer_max = time_remaining;
            Reset();
            blink = false;
        }
        void Reset() {
            timer = timer_max;
        }
        void Update(double dt) override {
            if (timer >= 0) {
                timer -= dt;
                if (timer < 0) {
                    timer = 0;
                }
            }
            blink = !blink;
        }
        double Remaining() {
            return timer;
        }
        int RemainingInt() {
            return static_cast<int>(timer);
        }
        bool TickTock() {
            return blink;
        }

        //Timer(double value) : timer(value) {}
        //double GetValue() { return timer; }
        //void Update(double dt) { timer -= dt; }

    private:
        double timer;
        double timer_max;
        bool blink = false; // pendulum
    };
}