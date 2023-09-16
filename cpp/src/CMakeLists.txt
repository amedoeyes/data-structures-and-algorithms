file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cpp)
add_library(dsa STATIC ${SRC_FILES})

target_include_directories(dsa PUBLIC ${CMAKE_SOURCE_DIR}/include)

