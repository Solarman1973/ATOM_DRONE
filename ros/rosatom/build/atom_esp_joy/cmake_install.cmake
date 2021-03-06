# Install script for directory: /home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/src/atom_esp_joy

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/atom_esp_joy/msg" TYPE FILE FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/src/atom_esp_joy/msg/joydata.msg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/atom_esp_joy/cmake" TYPE FILE FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/build/atom_esp_joy/catkin_generated/installspace/atom_esp_joy-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/devel/include/atom_esp_joy")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/devel/share/roseus/ros/atom_esp_joy")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/devel/share/common-lisp/ros/atom_esp_joy")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/devel/share/gennodejs/ros/atom_esp_joy")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/devel/lib/python2.7/dist-packages/atom_esp_joy")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/devel/lib/python2.7/dist-packages/atom_esp_joy")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/build/atom_esp_joy/catkin_generated/installspace/atom_esp_joy.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/atom_esp_joy/cmake" TYPE FILE FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/build/atom_esp_joy/catkin_generated/installspace/atom_esp_joy-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/atom_esp_joy/cmake" TYPE FILE FILES
    "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/build/atom_esp_joy/catkin_generated/installspace/atom_esp_joyConfig.cmake"
    "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/build/atom_esp_joy/catkin_generated/installspace/atom_esp_joyConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/atom_esp_joy" TYPE FILE FILES "/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/src/atom_esp_joy/package.xml")
endif()

