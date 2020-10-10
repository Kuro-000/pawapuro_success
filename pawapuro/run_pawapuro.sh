#!/usr/bin/env sh

g++ Pawapuro.cpp
python create_loop.py

for _ in `seq 1 300`
do
    ./a.out < loop.txt
done