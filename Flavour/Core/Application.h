#pragma once
#include "FlavourUtils.h"
#include "Log.h"

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

#include <iostream>
#include <chrono>
#include <thread>

namespace Flavour
{
    class API_EXPORTED Application
	{
    public:
        Application();

        ~Application();

        void Run();
    };

    Application *CreateApplication();
}