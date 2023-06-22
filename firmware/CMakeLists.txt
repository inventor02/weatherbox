cmake_minimum_required(VERSION 3.12)
set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
string(TIMESTAMP BUILD_TIMESTAMP "%Y%m%d.%H%M%S" UTC)

set(PRJ_NAME "weatherbox")
set(PRJ_VERSION "0.1.0")
set(PICO_BOARD "pico_w")

# Wireless options
set(CFG_WIFI_SSID "default_ssid" CACHE STRING "The SSID to connect to")
set(CFG_WIFI_PASSWORD "default_wifi_pw" CACHE STRING "The WiFi password")

if(NOT CMAKE_BUILD_TYPE)
  message("Defaulting to CMAKE_BUILD_TYPE=Debug")
  set(CMAKE_BUILD_TYPE "Debug")
endif()

include(lib/pico-sdk/pico_sdk_init.cmake)

project(${PRJ_NAME} VERSION ${PRJ_VERSION})
pico_sdk_init()

add_executable(${PRJ_NAME})
pico_add_extra_outputs(${PRJ_NAME})

pico_set_program_name(${PRJ_NAME} ${PRJ_NAME})
pico_set_program_description(${PRJ_NAME} "${PRJ_NAME} binary")
pico_set_program_url(${PRJ_NAME} "https://github.com/inventor02/${PRJ_NAME}")
pico_set_program_version(${PRJ_NAME} ${CMAKE_PROJECT_VERSION})

target_link_libraries(${PRJ_NAME}
  pico_stdlib
  pico_cyw43_arch_lwip_threadsafe_background
  pico_mbedtls
  pico_lwip_mbedtls
  hardware_rtc
)

target_compile_definitions(${PRJ_NAME} PRIVATE
  BUILD_VERSION="${CMAKE_PROJECT_VERSION}"
  CFG_WIFI_SSID="${CFG_WIFI_SSID}"
  CFG_WIFI_PASSWORD="${CFG_WIFI_PASSWORD}"
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  target_compile_definitions(${PRJ_NAME} PRIVATE
    BUILD_DEBUG
  )
endif()

add_subdirectory(src)
add_subdirectory(include)