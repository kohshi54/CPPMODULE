#!/bin/bash

# Expects
test1_expect=$(echo -e "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0")
test2_expect=$(echo -e "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan")
test3_expect=$(echo -e "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0")

green="\033[32m"
red="\033[31m"
reset="\033[0m"

# INT 0
output=$(./convert 0)
if [ "$output" == "$test1_expect" ]; then
    echo -e "${green}Test 1 passed${reset}"
else
    echo "${red}Test 1 failed${reset}"
fi

# Double nan
output=$(./convert nan)
if [ "$output" == "$test2_expect" ]; then
    echo -e "${green}Test 2 passed${reset}"
else
    echo "${red}Test 2 failed${reset}"
fi

# Float 42.0f
output=$(./convert 42.0f)
if [ "$output" == "$test3_expect" ]; then
    echo -e "${green}Test 3 passed${reset}"
else
    echo "${red}Test 3 failed${reset}"
fi
