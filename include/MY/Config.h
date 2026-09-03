/*
File:
	Config.h
Summary:
	Build config preprocessor definitions.
*/

#ifndef MY_CONFIG_H
#define MY_CONFIG_H

// DEBUG
#ifndef MY_DEBUG
	#define MY_DEBUG 0
#endif // !MY_DEBUG

// RELEASE
#ifndef MY_RELEASE
	#define MY_RELEASE 0
#endif // !MY_RELEASE

#if !MY_DEBUG && !MY_RELEASE
	#error "Unknown build config!"
#endif // !MY_DEBUG && !MY_RELEASE

#endif // MY_CONFIG_H

