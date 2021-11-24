#pragma once
#include "PlatformExport.h"
namespace Flavour
{
	class Application
	{
	public:
		Application();
		~Application();
		void Run();
	};

	Application* CreateApplication();
}
