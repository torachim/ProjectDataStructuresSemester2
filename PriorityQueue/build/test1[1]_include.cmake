if(EXISTS "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/test1[1]_tests.cmake")
  include("/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/test1[1]_tests.cmake")
else()
  add_test(test1_NOT_BUILT test1_NOT_BUILT)
endif()
