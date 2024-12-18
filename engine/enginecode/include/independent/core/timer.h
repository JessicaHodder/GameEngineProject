/** \file timer.h */
#pragma once

#include <chrono>

namespace Engine
{
	/**
	\class Time - cinterface timer class */

	class Timer
	{
	public:
		virtual void start() = 0;  //!< Start timer
		virtual void reset() = 0;  //!< Stop timer
		virtual float getElapsedTime() = 0;  //!< Get time elapsed since start or reset

	};


	/**
	\class ChronoTime - chrono timer class */

	class ChronoTimer : public Timer
	{
	public:
		virtual inline void start() override { m_startPoint = std::chrono::high_resolution_clock::now(); }
		virtual inline void reset() override { m_startPoint = std::chrono::high_resolution_clock::now(); }
		virtual float getElapsedTime() 
		{
			m_endPoint = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float, std::milli> elapsed = m_endPoint - m_startPoint;
			return elapsed.count() / 1000.f;
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startPoint;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_endPoint;
	};
}
