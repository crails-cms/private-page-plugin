cmake_minimum_required(VERSION 3.5)

project(crails-cms-private-page-plugin)

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")

find_package(PkgConfig)
pkg_check_modules(CRAILS_CMS REQUIRED
  libcrails-cms>=2.0.0
  libcrails-templates>=2.0.0
  libcrails-json-views>=2.0.0
  libcrails-html-views>=2.0.0
  libcrails-paginator>=2.0.0
  libcrails-signin>=2.0.0
)

include_directories(. ../.. ${CRAILS_CMS_INCLUDE_DIRS})
link_directories(../../build)

set(ENV{CRAILS_CMS_INCLUDE_DIRS} "${CRAILS_CMS_INCLUDE_DIRS}")
execute_process(COMMAND ./prebuild.sh WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE plugin_files
  app/*.cpp app/*.cxx
  lib/*.cpp lib/*.cxx)

add_library(private-page SHARED ${plugin_files})
add_definitions(-DWITH_ODB)
set_target_properties(private-page PROPERTIES ENABLE_EXPORTS ON)
set_target_properties(private-page PROPERTIES PREFIX "")
target_link_libraries(private-page
  ${CRAILS_CMS_LIBRARIES}
  crails-app)
