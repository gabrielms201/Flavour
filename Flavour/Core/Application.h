#pragma once
#include "FlavourUtils.h"
#include "Log.h"

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

#include "stdafx.h"

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