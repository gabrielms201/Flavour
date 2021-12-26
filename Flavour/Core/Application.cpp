#include "Application.h"
#include <iostream>
#include <chrono>
#include <thread>

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
        std::cout << "Flavour Engine Speaking" <<  std::endl << "Hello World!" << std::endl  << std::endl;
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
