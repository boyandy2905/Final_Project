/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Logger.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 6, 2025
Updated:    March 11, 2025
*/

#include <iostream>
#include "Logger.h"

CS230::Logger::Logger(Logger::Severity severity, bool use_console, std::chrono::system_clock::time_point last_tick) : min_level(severity), out_stream("Trace.log"), start_time(last_tick) {
    SetTraceLogLevel(LOG_NONE);
    if (use_console == true) {
        out_stream.set_rdbuf(std::cout.rdbuf());
    }
}

CS230::Logger::~Logger() {
    out_stream.flush();
    out_stream.close();
}

double CS230::Logger::seconds_since_start() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::duration<double>(now - start_time).count();
}

void CS230::Logger::log(CS230::Logger::Severity severity, std::string message) {
    if (severity >= min_level)
    {
        out_stream.precision(4); //here
        out_stream << "[" << std::fixed << seconds_since_start() << "]\t"; //here
        std::string severity_array[] = { "Verbose","Debug","Event","Error" };
        out_stream << severity_array[(int)severity] << '\t' << message << '\n';

        //switch (severity)
        //{
        //case CS230::Logger::Severity::Verbose:
        //    out_stream << "Verbose" << '\t' << message << '\n';
        //    break;
        //case CS230::Logger::Severity::Debug:
        //    out_stream << "Debug" << '\t' << message << '\n';
        //    break;
        //case CS230::Logger::Severity::Event:
        //    out_stream << "Event" << '\t' << message << '\n';
        //    break;
        //case CS230::Logger::Severity::Error:
        //    out_stream << "Error" << '\t' << message << '\n';
        //    break;
        //default:
        //    break;
        //}
    }
    return;
}