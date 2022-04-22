#include "Log.h"

namespace Flavour 
{

	std::shared_ptr<spdlog::logger> Log::_flavourLogger;
	std::shared_ptr<spdlog::logger> Log::_clientLogger;

	void Log::Init(bool verbose)
	{
		if (!verbose)
		{
			spdlog::set_pattern("%^[%l] [%Y-%m-%d %H:%M:%S] %n: %v%$");
		}
		else
		{
			spdlog::set_pattern("%^[%P | %t] [%l]: [%Y-%m-%d %H:%M:%S.%e] %n: %v%$");
		}
		_flavourLogger = spdlog::stdout_color_mt("FLAVOUR");
		_flavourLogger->set_level(spdlog::level::trace);

		_clientLogger = spdlog::stderr_color_mt("APPLICATION");
		_clientLogger->set_level(spdlog::level::trace);

	}
	Log::Log()
	{
	}
	Log::~Log()
	{
	}
}