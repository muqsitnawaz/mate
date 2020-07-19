set(CMAKE_FOLDER "${CMAKE_FOLDER}/algebra")

mate_add_test(test.alb.group alb.group group.cpp)
mate_add_test(test.alb.quotient_group alb.quotient_group quotient_group.cpp)
mate_add_test(test.alb.ring alb.ring ring.cpp)