#pragma once
#include "PlatformExport.h"
#include "Log.h"
#include <iostream>
#include <chrono>
#include <thread>


namespace Flavour {
    class Application {
    public:
        Application();

        ~Application();

        void Run();
    };

    Application *CreateApplication();
}