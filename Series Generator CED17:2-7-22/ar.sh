#!/bin/bash
clear
# g++ series.cpp -o series
# ./series

# g++ `pkg-config --cflags gtk+-3.0` gui.cpp `pkg-config --libs gtk+-3.0`

# g++ `pkg-config --cflags gtk+-3.0` series.cpp `pkg-config --libs gtk+-3.0` -lpthread\

# gcc series.c -lpthread

gcc `pkg-config --cflags gtk+-3.0` main.c `pkg-config --libs gtk+-3.0` -rdynamic -lpthread
./a.out

# rm series
rm ./a.out
