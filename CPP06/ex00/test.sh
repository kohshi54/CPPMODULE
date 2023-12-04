#!/bin/bash

# Expects
test1_expect=$(echo -e "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0")
test2_expect=$(echo -e "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan")
test3_expect=$(echo -e "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0")
test4_expect=$(echo -e "char: Non displayable\nint: 127\nfloat: 127.0f\ndouble: 127.0")
test5_expect=$(echo -e "char: impossible\nint: 2147483647\nfloat: 2147483648.0f\ndouble: 2147483647.0")
# test6_expect=$(echo -e "Int: 2147483648; stoi: out of range")

green="\033[32m"
red="\033[31m"
reset="\033[0m"

# INT 0
echo "Testing input 0..."
output=$(./convert 0)
echo -e "$output"
if [ "$output" == "$test1_expect" ]; then
    echo -e "${green}Test 1 passed${reset}"
else
    echo "${red}Test 1 failed${reset}"
fi

echo -e "=============="

# Double nan
echo "Testing input nan..."
output=$(./convert nan)
echo -e "$output"
if [ "$output" == "$test2_expect" ]; then
    echo -e "${green}Test 2 passed${reset}"
else
    echo "${red}Test 2 failed${reset}"
fi

echo -e "=============="

# Float 42.0f
echo "Testing input 42.0f..."
output=$(./convert 42.0f)
echo -e "$output"
if [ "$output" == "$test3_expect" ]; then
    echo -e "${green}Test 3 passed${reset}"
else
    echo -e "${red}Test 3 failed${reset}"
fi

echo -e "=============="

# Char Non displayable
echo "Testing input 127..."
output=$(./convert 127)
echo -e "$output"
if [ "$output" == "$test4_expect" ]; then
    echo -e "${green}Test 4 passed${reset}"
else
    echo -e "${red}Test 4 failed${reset}"
fi

echo -e "=============="

# Int max
echo "Testing input 2147483647..."
output=$(./convert 2147483647)
echo -e "$output"
if [ "$output" == "$test5_expect" ]; then
    echo -e "${green}Test 5 passed${reset}"
else
    echo -e "${red}Test 5 failed${reset}"
fi

# Int max + 1
# output=$(./convert 2147483648)
# if [ "$output" == "$test6_expect" ]; then
#     echo -e "${green}Test 6 passed${reset}"
# else
#     echo -e "${red}Test 6 failed${reset}"
# fi