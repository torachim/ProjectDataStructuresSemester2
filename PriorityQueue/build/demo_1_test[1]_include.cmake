if(EXISTS "/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/demo_1_test[1]_tests.cmake")
  include("/Users/torgerau/Desktop/Uni Stuff/POOSE/projekt123sts/PriorityQueue/build/demo_1_test[1]_tests.cmake")
else()
  add_test(demo_1_test_NOT_BUILT demo_1_test_NOT_BUILT)
endif()
