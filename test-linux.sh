#!/bin/bash

gcc -g -O0 -Wall -Wextra -Werror test.c fcaseopen.c -o test && ./test
