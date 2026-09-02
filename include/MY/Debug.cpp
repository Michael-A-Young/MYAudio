/*
File:
	Debug.cpp
Summary:
	Logging and assertions.
*/

#if MY_DEBUG

// MY
#include "Debug.h"

// Standard Library
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

std::tm GetLocalTime(std::time_t time)
{
	std::tm localTime{};

#if MY_COMPILER_MSVC
	localtime_s(&localTime, &time);
#else
	localtime_r(&time, &localTime);
#endif // MY_COMPILER_MSVC

	return localTime;
}

std::string GetTime(const std::string& format)
{
	const auto currentTime = std::chrono::system_clock::now();
	const auto timeT = std::chrono::system_clock::to_time_t(currentTime);
	const auto localTime = GetLocalTime(timeT);

	std::ostringstream output;
	output << std::put_time(&localTime, format.c_str());

	return output.str();
}

void MYFormatLogMessage(std::string& message, MYLogLevel /*level*/,
		const char* caller, const char* file, long lineNum)
{
	constexpr char kRule[] = "--------------------------------------------------------------------------------";
	constexpr char kLineBreak = '\n';

	// Get time
	std::string time = GetTime("%T");

	message = time + ' ' + file + ':' + std::to_string(lineNum) + ' ' +
		caller + kLineBreak + message + kLineBreak + kRule + kLineBreak;
}

#endif // MY_DEBUG
