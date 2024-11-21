/* \file log.h*/
#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include "systems/system.h"
#include <spdlog/fmt/ostr.h>


namespace Engine
{
	/* \class log
	* class for logger system
	*/

	class Log : public System
	{
	public:
		void start(SystemSignal init = SystemSignal::None, ...) override;  //!< start the logger
		void stop(SystemSignal close = SystemSignal::None, ...) override;  //!< stop the logger
		template<typename ...Args>
		static void info(Args&&... args);  //!< info output
		template<typename ...Args>
		static void warn(Args&&... args);  //!< warn output
		template<typename ...Args>
		static void error(Args&&... args);  //!< error output
		template<typename ...Args>
		static void file(Args&&... args);  //!< output

	private:
		static std::shared_ptr<spdlog::logger> m_consoleLogger;
		static std::shared_ptr<spdlog::logger> m_fileLogger;
	};



	template<typename ...Args>
	static void Log::info(Args&&... args)
	{
		m_consoleLogger->info(std::forward<Args>(args) ...);
	}

	template<typename ...Args>
	static void Log::warn(Args&&... args)
	{
		m_consoleLogger->warn(std::forward<Args>(args) ...);
	}

	template<typename ...Args>
	static void Log::error(Args&&... args)
	{
		m_consoleLogger->error(std::forward<Args>(args) ...);
	}

	template<typename ...Args>
	static void Log::file(Args&&... args)
	{
		
		if (m_fileLogger) m_fileLogger->error(std::forward<Args>(args) ...);
	}
}