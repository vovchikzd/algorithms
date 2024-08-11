cmake_minimum_required(VERSION 3.28)

add_executable(isort)
target_sources(isort PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_custom_command(TARGET isort 
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:isort> ${CMAKE_CURRENT_SOURCE_DIR})
