# Digital Logic Simulator in C++

A console-based Digital Logic Simulator developed using C++ to simulate fundamental logic gates and combinational digital circuits.

This project was created to strengthen my C++ programming skills and deepen my understanding of digital electronics, Boolean algebra, and digital circuit design.

## Features

### Basic Logic Gates
- AND Gate
- OR Gate
- NOT Gate
- NAND Gate
- NOR Gate
- XOR Gate
- XNOR Gate
- BUFFER Gate

### Combinational Logic Circuits
- Half Adder
- Full Adder
- Half Subtractor
- Full Subtractor
- 2:1 Multiplexer
- 4-bit Ripple Carry Adder

### Additional Features
- Logic Gate Truth Table Generator
- Interactive menu using switch-case statements
- Binary input validation (0 and 1)
- Multiple operations without restarting the program

## Technologies Used

- **Programming Language:** C++
- **Development Environment:** Dev-C++ / Visual Studio
- **Application Type:** Console Application
- **Concepts:** Boolean Algebra, Digital Logic Design, Combinational Circuits

## Example: Full Adder

The Full Adder performs binary addition using three inputs: A, B, and Carry In.

**Boolean Expressions:**

- Sum = A XOR B XOR Cin
- Carry Out = (A AND B) OR (Cin AND (A XOR B))

**Example Output:**

```text
===== DIGITAL LOGIC SIMULATOR =====

Select an option: 10

Enter A (0 or 1): 1
Enter B (0 or 1): 1
Enter Carry In (0 or 1): 1

========== RESULT ==========

--- FULL ADDER ---
SUM       = 1
CARRY OUT = 1
```

## How to Run

1. Clone or download this repository.
2. Open `LogicGateSimulator.cpp` in Dev-C++ or Visual Studio.
3. Compile and run the program.
4. Select a logic gate or combinational circuit from the menu.
5. Enter binary input values (0 or 1).
6. View the calculated output in the terminal.

## Learning Outcomes

Through this project, I practiced:

- C++ functions and modular programming
- Switch-case statements
- Loops and conditional statements
- Arrays and logical operators
- Input validation
- Boolean logic implementation
- Binary arithmetic and digital circuit simulation

## Future Improvements

- 4-bit Carry Look-Ahead Adder
- 4:1 Multiplexer
- Decoder and Encoder circuits
- Arithmetic Logic Unit (ALU)
- Flip-Flops and Sequential Logic
- Graphical Logic Circuit Visualization

## Project Motivation

As an Electrical and Electronics Engineering student interested in digital hardware design, FPGA development, and VLSI/ASIC design, I developed this project to connect fundamental programming concepts with digital circuit operations.

The project provides a foundation for exploring more advanced digital systems and hardware architectures.
