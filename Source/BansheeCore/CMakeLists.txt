# Source files and their filters
include(CMakeSources.cmake)

# Packages
find_package(nvtt REQUIRED)

# Includes
set(BansheeCore_INC 
	"./" 
	"../BansheeUtility")

if(WIN32)
	set(BansheeCore_INC ${BansheeCore_INC} "Win32")
endif()

include_directories(${BansheeCore_INC})	

# Target
add_library(BansheeCore SHARED ${BS_BANSHEECORE_SRC})

# Defines
target_compile_definitions(BansheeCore PRIVATE -DBS_CORE_EXPORTS)

# Libraries
## External lib: NVTT
target_link_libraries(BansheeCore PRIVATE ${nvtt_LIBRARIES})	

## Local libs
target_link_libraries(BansheeCore PUBLIC BansheeUtility)	
	
## OS libs
if(WIN32)
	target_link_libraries(BansheeCore PRIVATE Winmm dinput8 xinput9_1_0 dxguid.lib)
elseif(APPLE) # MacOS
	target_link_framework(BansheeCore CoreServices)
	target_link_framework(BansheeCore IOKit)
	target_link_framework(BansheeCore AppKit)
	target_link_framework(BansheeCore Carbon)
endif()

# IDE specific
set_property(TARGET BansheeCore PROPERTY FOLDER Layers)

# Install
install(
	DIRECTORY .
	DESTINATION include
	FILES_MATCHING PATTERN "*.h"
	PATTERN "Private" EXCLUDE
)

install(
	TARGETS BansheeCore
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)