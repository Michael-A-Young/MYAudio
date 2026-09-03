/*
File:
	Arch.h
Summary:
	Target CPU architecture preprocesssor definitions.
*/

#ifndef MY_ARCH_H
#define MY_ARCH_H

// ARM64
#if defined(__aarch64__) || defined(_M_ARM64)

    #define MY_ARCH_ARM 1
    #define MY_ARCH_64BIT  1

// ARM
#elif defined(__arm__) || defined(_M_ARM)

    #define MY_ARCH_ARM 1
    #define MY_ARCH_32BIT  1

// X86_64
#elif defined(__x86_64__) || defined(_M_X64)

    #define MY_ARCH_X86 1
    #define MY_ARCH_64BIT  1

// X86
#elif defined(__i386__) || defined(_M_IX86)

    #define MY_ARCH_X86 1
    #define MY_ARCH_32BIT  1

#endif // MY_ARCH_*

#ifndef MY_ARCH_ARM
	#define MY_ARCH_ARM 0
#endif // !MY_ARCH_ARM

#ifndef MY_ARCH_X86
	#define MY_ARCH_X86 0
#endif // !MY_ARCH_X86

#ifndef MY_ARCH_64BIT
	#define MY_ARCH_64BIT 0
#endif // !MY_ARCH_64BIT

#ifndef MY_ARCH_32BIT
	#define MY_ARCH_32BIT 0
#endif // !MY_ARCH_32BIT

// OTHER
#if (!MY_ARCH_ARM && !MY_ARCH_X86) || \
    (!MY_ARCH_64BIT && !MY_ARCH_32BIT)

	#error "Unknown target CPU architecture!"

#endif // !MY_ARCH_*

#endif // MY_ARCH_H

