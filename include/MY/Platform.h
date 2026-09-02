/*
File:
	Platform.h
Summary:
	Platform preprocessor definitions.
*/

#ifndef MY_PLATFORM_H
#define MY_PLATFORM_H

// WINDOWS
#if defined(_WIN32) || defined(_WIN64)

	#define MY_PLATFORM_WINDOWS 1
	#define WIN32_LEAN_AND_MEAN 1

#else

	#define MY_PLATFORM_WINDOWS 0

#endif // defined(_WIN32) || defined(_WIN64)

// MACOS/IOS
#if defined(__APPLE__)

	#define MY_PLATFORM_MACOS 1
	#define MY_PLATFORM_IOS 1
	#error "Are we on macOS or iOS?"

#else

	#define MY_PLATFORM_MACOS 0
	#define MY_PLATFORM_IOS 0

#endif // defined(__APPLE__)

// LINUX
#if defined(__linux__)

	#define MY_PLATFORM_LINUX 1

#else

	#define MY_PLATFORM_LINUX 0

#endif // defined(__linux__)

// ANDROID
#if defined(__ANDROID__)

	#define MY_PLATFORM_ANDROID 1

#else

	#define MY_PLATFORM_ANDROID 0

#endif // defined(__ANDROID__)

// XBOX
#if defined(_XBOX)

	#define MY_PLATFORM_XBOX 1

#else

	#define MY_PLATFORM_XBOX 0

#endif // defined(_XBOX)

// OTHER
#if !MY_PLATFORM_WINDOWS && \
    !MY_PLATFORM_MACOS   && \
	!MY_PLATFORM_IOS     && \
	!MY_PLATFORM_LINUX   && \
	!MY_PLATFORM_ANDROID && \
	!MY_PLATFORM_XBOX

	#error "Unknown Platform!"

#endif // MY_PLATFORM_*

#endif // MY_PLATFORM_H
