cmake_minimum_required(VERSION 3.25)

project(
	MYAudio
	VERSION 0.1.0
	DESCRIPTION "Low-level audio library"
	LANGUAGES CXX
)

# ---------------------------------------------------------------------------
# Options
# ---------------------------------------------------------------------------

option(
	MY_WARNINGS_AS_ERRORS
	"Treat compiler warnings as errors"
	ON
)

option(
	MY_ENABLE_CLANG_TIDY
	"Run clang-tidy during compilation"
	OFF
)

option(
	MY_ENABLE_ASAN
	"Enable AddressSanitizer"
	OFF
)

option(
	MY_ENABLE_UBSAN
	"Enable UndefinedBehaviorSanitizer"
	OFF
)

option(
	MY_ENABLE_TSAN
	"Enable ThreadSanitizer"
	OFF
)

# ---------------------------------------------------------------------------
# CMake modules
# ---------------------------------------------------------------------------

list(
	APPEND CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake"
)

include(CompilerWarnings)
include(Sanitisers)
include(StaticAnalysis)

# ---------------------------------------------------------------------------
# Source
# ---------------------------------------------------------------------------

add_executable(
	MYAudio
	include/MY/Debug.cpp
	src/AudioDecoder/AudioDecoder.cpp
	src/AudioDecoder/WAVDecoder.cpp
	src/AudioDevice/AudioDevice.cpp
	src/AudioSource/AudioSource.cpp
	src/AudioSource/BufferSource.cpp
	src/AudioSource/GeneratorSource.cpp
	src/AudioSource/StreamSource.cpp
	src/AudioBus.cpp
	src/AudioManager.cpp
	src/BusManager.cpp
	src/Channel.cpp
	src/ChannelManager.cpp
	src/Sound.cpp
	src/SoundManager.cpp
	src/main.cpp
)

target_include_directories(
	MYAudio
	PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (WIN32)
    target_sources(
        MYAudio
        PRIVATE
		src/AudioDevice/XAudio2Device.cpp
    )
elseif (APPLE)
    target_sources(
        MYAudio
        PRIVATE
    )
elseif (UNIX)
    target_sources(
        MYAudio
        PRIVATE
    )
endif ()

# ---------------------------------------------------------------------------
# Project configuration
# ---------------------------------------------------------------------------

target_compile_features(MYAudio PRIVATE cxx_std_23)

set_target_properties(
	MYAudio
	PROPERTIES
    CXX_EXTENSIONS OFF
)

target_compile_definitions(
    MYAudio
    PRIVATE
    $<$<CONFIG:Debug>:MY_DEBUG>
    $<$<CONFIG:Release>:MY_RELEASE>
)

# ---------------------------------------------------------------------------
# Warnings / sanitizers / static analysis
# ---------------------------------------------------------------------------

MY_configure_warnings(MYAudio)
MY_configure_sanitisers(MYAudio)
MY_configure_static_analysis(MYAudio)
