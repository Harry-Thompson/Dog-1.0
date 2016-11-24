#!/bin/sh

cc main.c -O3 -o dog
ln -h dog /bin/dog
exit 0
