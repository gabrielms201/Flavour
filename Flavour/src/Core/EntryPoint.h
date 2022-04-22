#pragma once
#include "Application.h"
extern Flavour::Application *Flavour::CreateApplication();

int main(int argc, char **argv) 
{
    Flavour::Application *app = Flavour::CreateApplication();
    Flavour::Log::Init();
    FLAVOUR_CORE_INFO("Log Initialized!");
    FLAVOUR_INFO("Log Initialized!");
    app->Run();
    delete app;
}