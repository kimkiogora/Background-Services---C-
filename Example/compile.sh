g++ -Wall -std=c++11 example.cpp `mysql_config --cflags` `mysql_config --libs` -o test -lpthread 
