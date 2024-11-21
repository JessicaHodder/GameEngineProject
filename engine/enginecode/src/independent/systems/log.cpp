#include "engine_pch.h"
#include "systems/log.h"

namespace Engine {

	std::shared_ptr<spdlog::logger> Log::m_consoleLogger = nullptr;
	std::shared_ptr<spdlog::logger> Log::m_fileLogger = nullptr;

	void Log::start(SystemSignal init, ...)
	{
		spdlog::set_pattern("%^[%T}: %v%$");
		spdlog::set_level(spdlog::level::trace);

		m_consoleLogger = spdlog::stdout_color_mt("Console");

		char filepath[256] = "logs/";
		char time[125];

		/*
		try
		{
			std::time_t t = std::time(nullptr);
			std::strftime(time, sizeof(time), " %d_%m_%y %I_%M_%S", std::localtime(&t));
			strcat_s(filepath, time);
			strcat_s(filepath, ".txt");
			m_fileLogger = spdlog::basic_logger_mt("File", filepath);
		}
		catch (const spdlog::spdlog_ex& e)
		{
			m_consoleLogger->error("Could not start file logger: {0}", e.what());
			m_fileLogger.reset();
		}
		*/  // to aviod creating too many files while testing
	}

	void Log::stop(SystemSignal close, ...)
	{
		m_consoleLogger->info("Stopping console logger");
		m_consoleLogger.reset();
	}
}

