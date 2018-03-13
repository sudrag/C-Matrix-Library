set(GTEST_SHUFFLE 1)
add_executable(
    matrix-test
    main.cpp
    test.cpp
)

target_include_directories(matrix-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(matrix-test PUBLIC gtest)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
