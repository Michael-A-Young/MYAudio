/*
File:
	Compiler.h
Summary:
	Compiler preprocessor definitions.
*/

#ifndef MY_COMPILER_H
#define MY_COMPILER_H

#if defined(_MSC_VER)

// MSVC
#define MY_COMPILER_MSVC 1

#else

#define MY_COMPILER_MSVC 0

#endif // defined(_MSC_VER)

// CLANG/APPLECLANG
#if defined(__clang__)

#define MY_COMPILER_CLANG 1

#else

#define MY_COMPILER_CLANG 0

#endif // defined(__clang__)

// GCC
#if defined(__GNUC__)

#define MY_COMPILER_GCC 1

#else

#define MY_COMPILER_GCC 0

#endif // defined(__GNUC__)

// OTHER
#if !MY_COMPILER_MSVC &&  \
	!MY_COMPILER_CLANG && \
	!MY_COMPILER_GCC

#error "Unknown compiler!"

#endif // !MY_COMPILER_*

#endif // MY_COMPILER_H
