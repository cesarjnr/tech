#!/usr/bin/bash

## Variables

LANGUAGE=bash

## Output

echo "Welcome to the ${LANGUAGE} world!"

## Input

echo "What is your first name?"
read FIRST_NAME
echo "What is your last name?"
read LAST_NAME
echo "Hi $FIRST_NAME $LAST_NAME, nice to meet you!"

## You can use the value of a variable in the two ways above but it's preferable to use the one with the curly braces