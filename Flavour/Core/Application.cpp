#include "Application.h"

namespace Flavour 
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
    
	void Application::Run()
	{
		FLAVOUR_CORE_INFO("Flavour Engine Speaking! Hello World! ");
		while (true)
		{
            for (int i = 0; i <= 10; i++)
            {
                std::cout << "Up and running  - " <<   i  << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            std::cout << std::endl;
		}
	}
}
