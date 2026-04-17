# Boolean Truth Table Simulator

Name: Myat Noe Kyi Phyu
Student Number: 40490958

## Overview

This project is a C++ program using OOP concepts that allows users to enter a boolean expression containing a maximum of three variables (A, B, C) and 3 boolean operations to generate a truth table based on the user input. It also explains the operators used in the expression, evaluates the expression then displays a truth table with all possible input-output combinations including the intermediate steps. It allows the user to save the output to a file based on their choice.

## Functionality

- Accepts boolean expressions using variables A, B, and C  
- Supports operators such as AND, OR, XOR, NAND, NOR, and NOT (maximum of 3 operations)
- Generates a truth table for all possible combinations  
- Shows step-by-step evaluation of the expression  
- Displays explanations for the operators used  
- Option to save the output to a file  

## Process

1. The user enters a boolean expression  
2. The program checks if the expression is valid  
3. The expression is evaluated step by step  
4. A truth table is generated for all combinations of A, B, and C  
5. The output is displayed with explanations
6. The user can choose to save the output to a file 

## Files

- expression.h / .cpp - handles parsing and evaluation of expressions  
- operator.h / .cpp - defines boolean operators  
- operator_factory.h / .cpp - manages operator usage  
- truth_table.h / .cpp - generates the truth table  
- file_manager.h / .cpp - handles saving output to a file  
- main.cpp - main program and user interaction

## Compilation and Execution

- To compile the program, run:
g++ -std=c++17 main.cpp expression.cpp expression_input.cpp expression_parser.cpp truth_table.cpp file_manager.cpp operator_factory.cpp operator.cpp -o truth_table_simulator

- Then run the program:
./truth_table_simulator

Note: run using truth_table_simulator.exe on Windows