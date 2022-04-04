#pragma once
#include <memory>

#include "PlatformExport.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Flavour 
{
	class EXPORTED Log 
	{
	public:
		static void Init(bool verbose = false);
		inline static std::shared_ptr<spdlog::logger>& GetFlavourLogger() { return _flavourLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _clientLogger; }
		Log();
		~Log();

	private:
		static std::shared_ptr<spdlog::logger> _flavourLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
	};
}

// Flavour (Core) Log Macros
#define FLAVOUR_CORE_INFO(...)   ::Flavour::Log::GetFlavourLogger()->info(__VA_ARGS__)
#define FLAVOUR_CORE_TRACE(...)  ::Flavour::Log::GetFlavourLogger()->trace(__VA_ARGS__)
#define FLAVOUR_CORE_WARN(...)   ::Flavour::Log::GetFlavourLogger()->warn(__VA_ARGS__)
#define FLAVOUR_CORE_ERROR(...)  ::Flavour::Log::GetFlavourLogger()->error(__VA_ARGS__)
#define FLAVOUR_CORE_FATAL(...)  ::Flavour::Log::GetFlavourLogger()->critical(__VA_ARGS__)

// Application Log Macros
#define FLAVOUR_INFO(...)        ::Flavour::Log::GetClientLogger()->info(__VA_ARGS__)
#define FLAVOUR_TRACE(...)       ::Flavour::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FLAVOUR_WARN(...)        ::Flavour::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FLAVOUR_ERROR(...)       ::Flavour::Log::GetClientLogger()->error(__VA_ARGS__)
#define FLAVOUR_FATAL(...)       ::Flavour::Log::GetClientLogger()->critical(__VA_ARGS__)