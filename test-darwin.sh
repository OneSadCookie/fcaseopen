#!/bin/bash

gcc -g -O0 -Wall -Wextra -Wnewline-eof -Werror test.c fcaseopen.c -o test && ./test
