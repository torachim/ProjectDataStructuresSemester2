# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/_deps/googletest-src"
  "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/_deps/googletest-build"
  "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
