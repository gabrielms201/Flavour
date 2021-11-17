#pragma once
#include "PlatformExport.h"
namespace Flavour{
    class EXPORTED Application
    {
    public:
        Application();
        ~Application();
        void Run();
    };

    Application* CreateApplication();
}
