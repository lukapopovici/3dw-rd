cmake_minimum_required(VERSION 3.14)
project(ECG_SharedMemory LANGUAGES CXX)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable warnings
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Source files for the SignalReceiver application
set(SOURCES
    signreceiver.cpp
    main.cpp
)

set(HEADERS
    pipeline.h
    ecgspecific.h
    receiver.h
)

add_executable(signal_receiver_demo ${SOURCES} ${HEADERS})

# Link POSIX libraries (for shm_open, mmap, etc.)
if(UNIX)
    target_link_libraries(signal_receiver_demo PRIVATE pthread rt)
endif()

# Output binaries to /bin inside build dir
set_target_properties(signal_receiver_demo
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
