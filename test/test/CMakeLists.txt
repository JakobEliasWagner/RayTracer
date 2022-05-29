
# Sudoku Class
add_executable(test-running "")

target_sources(test-running
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test.cpp
        )

target_link_libraries(test-running
        PRIVATE
        gtest_main
        )

enable_testing()

add_test(
        NAME google_test
        COMMAND $<TARGET_FILE:test-running>
)