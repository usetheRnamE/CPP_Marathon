#pragma once
#include <chrono>
#include "Print.h"

namespace tmr
{
	class  Timer
	{
	public:
		Timer()
		{
			startTimePoint = std::chrono::high_resolution_clock::now();
		}
		~Timer()
		{
			StopTime();
		}

		void StopTime()
		{
			auto endTimePoint = std::chrono::high_resolution_clock::now();

			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

			auto duration = end - start;

			double ms = duration * .001;

			prt::Print(duration);
			prt::Print(ms);
		}

	private:
		std::chrono::time_point<std::chrono::steady_clock> startTimePoint;
	};
}