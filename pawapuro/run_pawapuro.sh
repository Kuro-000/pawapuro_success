#!/usr/bin/env sh

for _ in `seq 1 300`
do
    g++ Pawapuro.cpp
    python create_loop.py
    ./a.out < loop.txt
done