/*
File:
	Debug.h
Summary:
	Logging and assertions.
*/

#ifndef MY_DEBUG_H
#define MY_DEBUG_H

#if MY_DEBUG

// Standard Library
#include <csignal>
#include <cstdint>
#include <cstdio>
#include <print>
#include <string>
#include <utility>

#if MY_COMPILER_MSVC
#define MY_TRAP()                                                             \
	do                                                                        \
	{                                                                         \
		__debugbreak();                                                       \
	} while (false)
#elif MY_COMPILER_CLANG
#define MY_TRAP()                                                             \
	do                                                                        \
	{                                                                         \
		__builtin_debugtrap();                                                \
	} while (false)
#elif MY_COMPILER_GCC
#define MY_TRAP()                                                             \
	do                                                                        \
	{                                                                         \
		__builtin_trap();                                                     \
	} while (false)
#else
#define MY_TRAP()                                                             \
	do                                                                        \
	{                                                                         \
		std::raise(SIGABRT);                                                  \
	} while (false)
#endif // MY_COMPILER_*

enum class MYLogLevel : uint8_t
{
	Info,
	Warning,
	Error,
	Debug
};

void MYFormatLogMessage(std::string& message, MYLogLevel level,
	const char* caller, const char* file, long lineNum);

template <typename... Args>
void MYLogFunc(MYLogLevel level, const char* caller,
		const char* file, long lineNum,
		std::format_string<Args...> message,
		Args&&... args)
{
	std::string logMessage = std::format(message, std::forward<Args>(args)...);

	MYFormatLogMessage(logMessage, level, caller, file, lineNum);

	std::print("{}", logMessage);
}

#define MY_LOG_MESSAGE(severity, message, ...)                                \
	do                                                                        \
	{                                                                         \
		MYLogFunc(severity, __FUNCTION__, __FILE__, __LINE__,                 \
				message __VA_OPT__(,) __VA_ARGS__);                           \
	} while (false)

#define MY_LOG(message, ...)                                                  \
	do                                                                        \
	{                                                                         \
		MY_LOG_MESSAGE(MYLogLevel::Info,                                      \
				message __VA_OPT__(,) __VA_ARGS__);                           \
	}  while (false)

#define MY_ASSERT(expression, message, ...)                                   \
	do                                                                        \
	{                                                                         \
		if (!(expression)) [[unlikely]]                                       \
		{                                                                     \
			if constexpr (message)                                            \
			{                                                                 \
				MY_LOG_MESSAGE(MYLogLevel::Error,                             \
						message __VA_OPT__(,) __VA_ARGS__);                   \
			}                                                                 \
			MY_TRAP();                                                        \
		}                                                                     \
	} while (false)

#define MY_EXPECT(expression, message, ...)                                   \
	do                                                                        \
	{                                                                         \
		if (!(expression)) [[unlikely]]                                       \
		{                                                                     \
			if constexpr (message)                                            \
			{                                                                 \
				MY_LOG_MESSAGE(LogLevel::Error,                               \
						message __VA_OPT__(,) __VA_ARGS__);                   \
			}                                                                 \
		}                                                                     \
	} while (false)

#else

#define MY_LOG(severity, message, ...)
#define MY_TRAP()
#define MY_ASSERT(expression, message, ...)
#define MY_EXPECT(expression, message, ...)

#define NDEBUG 1
#define assert(...)

#endif // MY_DEBUG

#endif // MY_DEBUG_H
