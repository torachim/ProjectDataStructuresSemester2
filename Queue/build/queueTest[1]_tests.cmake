add_test( Queue.enqueue_dequeue /home/odin/p/projekt123sts/Queue/build/queueTest [==[--gtest_filter=Queue.enqueue_dequeue]==] --gtest_also_run_disabled_tests)
set_tests_properties( Queue.enqueue_dequeue PROPERTIES WORKING_DIRECTORY /home/odin/p/projekt123sts/Queue/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( Queue.Size /home/odin/p/projekt123sts/Queue/build/queueTest [==[--gtest_filter=Queue.Size]==] --gtest_also_run_disabled_tests)
set_tests_properties( Queue.Size PROPERTIES WORKING_DIRECTORY /home/odin/p/projekt123sts/Queue/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( queueTest_TESTS Queue.enqueue_dequeue Queue.Size)
