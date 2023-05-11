# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\FTPServer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FTPServer_autogen.dir\\ParseCache.txt"
  "FTPServer_autogen"
  "test\\CMakeFiles\\FTPServerTest_autogen.dir\\AutogenUsed.txt"
  "test\\CMakeFiles\\FTPServerTest_autogen.dir\\ParseCache.txt"
  "test\\FTPServerTest_autogen"
  )
endif()
