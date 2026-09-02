include_guard(GLOBAL)

function(MY_setup_platform TARGET)

	if (MSVC)

	    target_compile_options(
			${TARGET}
			PRIVATE
			/FI${CMAKE_CURRENT_SOURCE_DIR}/include/MY/MY.h
		)

	else ()

	    target_compile_options(
			${TARGET}
		    PRIVATE
			-include ${CMAKE_CURRENT_SOURCE_DIR}/include/MY/MY.h
		)

	endif ()

    if(WIN32)

        target_sources(
            ${TARGET}
            PRIVATE
			src/AudioDevice/XAudio2Device.cpp
        )

		target_link_libraries(
            ${TARGET}
            PRIVATE
            XAudio2
        )

    elseif(APPLE)

        target_sources(
            ${TARGET}
            PRIVATE
        )

    elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")

        find_package(PkgConfig REQUIRED)

        pkg_check_modules(
            PIPEWIRE
            REQUIRED
            IMPORTED_TARGET
            libpipewire-0.3
        )

        target_sources(
            ${TARGET}
            PRIVATE
			src/AudioDevice/PipeWireDevice.cpp
        )

        target_link_libraries(
            ${TARGET}
            PRIVATE
            PkgConfig::PIPEWIRE
        )

    endif()

endfunction()
