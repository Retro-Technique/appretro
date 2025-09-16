find_package(boost_property_tree CONFIG REQUIRED)

set(INCROOT "${PROJECT_SOURCE_DIR}/include/appretro/api")
set(SRCROOT "${PROJECT_SOURCE_DIR}/src/appretro/api")

set(SRC
	"${SRCROOT}/pch.cpp"
	"${SRCROOT}/pch.h"
	"${SRCROOT}/project.cpp"
	"${SRCROOT}/map.cpp"
	"${SRCROOT}/layer.cpp"
	"${SRCROOT}/layer_group.cpp"
	"${SRCROOT}/object_group.cpp"
	"${SRCROOT}/object.cpp"
)

add_library(${PROJECT_NAME}-api
	SHARED
		${SRC}
)

target_include_directories(${PROJECT_NAME}-api
	PUBLIC 
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME}-api 
	PRIVATE 
		Boost::property_tree
)

target_compile_options(${PROJECT_NAME}-api
	PRIVATE 
		$<$<CXX_COMPILER_ID:MSVC>:${MSVC_WARNINGS}>
		$<$<CXX_COMPILER_ID:GNU>:${GCC_WARNINGS}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU>>:${GCC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_RELEASE_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:GNU>>:${GCC_RELEASE_OPTIMISATION}>
)

target_precompile_headers(${PROJECT_NAME}-api
	PRIVATE
		"${SRCROOT}/pch.h"
)

target_compile_definitions(${PROJECT_NAME}-api
	PRIVATE
		APPRETRO_API_EXPORTS
)