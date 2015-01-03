#!/bin/bash
./parser -o < "$1"
spim -f "code.asm"
