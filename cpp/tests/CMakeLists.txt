file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS *.cpp)
add_executable(dsa_tests ${TEST_FILES})

target_include_directories(dsa_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(dsa_tests PRIVATE dsa Catch2::Catch2WithMain)

set_target_properties(
    dsa_tests
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/
)

add_test(NAME dsa_tests COMMAND dsa_tests)
