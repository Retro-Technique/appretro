find_package(boost_log CONFIG REQUIRED)
find_package(boost_log_setup CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)
find_package(Boost REQUIRED COMPONENTS json)

set(SRCROOT "${PROJECT_SOURCE_DIR}/src/appretro/engine")

set(SRC
	"${SRCROOT}/main.cpp"
	"${SRCROOT}/pch.cpp"
	"${SRCROOT}/pch.h"
	"${SRCROOT}/engine.cpp"
	"${SRCROOT}/engine.h"
	"${SRCROOT}/command_line_info.h"
)

add_executable(${PROJECT_NAME}
	${SRC}
)

target_include_directories(${PROJECT_NAME}
	PUBLIC 
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME} 
	PRIVATE 
		Boost::log
		Boost::log_setup
		Boost::program_options
		Boost::json
		${PROJECT_NAME}-api
)

target_compile_options(${PROJECT_NAME}
	PRIVATE 
		$<$<CXX_COMPILER_ID:MSVC>:${MSVC_WARNINGS}>
		$<$<CXX_COMPILER_ID:GNU>:${GCC_WARNINGS}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU>>:${GCC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_RELEASE_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:GNU>>:${GCC_RELEASE_OPTIMISATION}>
)

target_precompile_headers(${PROJECT_NAME}
	PRIVATE
		"${SRCROOT}/pch.h"
)

target_compile_definitions(${PROJECT_NAME}
	PRIVATE
		APPRETRO_VERSION="${PROJECT_VERSION}"
		TILED_MAP_EDITOR_VERSION="${TILED_MAP_EDITOR_VERSION}"
)