# Push Swap

This is the Push Swap project from the 42 school. The goal of this project is to sort a stack of numbers using a limited set of operations.

## Contents

1. [Description](#description)
2. [Requirements](#requirements)
3. [Compilation Instructions](#compilation-instructions)
4. [Usage](#usage)
5. [Available Operations](#available-operations)
6. [My Approach to the Algorithm](#my-approach-to-the-algorithm)
7. [Visualizer](#visualizer)

## Description

The `push_swap` program takes a stack of numbers as input and sorts the stack using the `swap`, `push`, and `rotate` operations. The objective is to sort the stack in ascending order using stack B as an auxiliary space.

## Requirements

- Operating System: macOS or Linux
- [GCC](https://gcc.gnu.org/) or another compatible C compiler

## Compilation Instructions

1. Clone this repository: `git clone https://github.com/YourUsername/push_swap.git`
2. Navigate to the repository directory: `cd push_swap`
3. Compile the program by running: `make`

## Usage

Run the `push_swap` program by passing the list of numbers you want to sort as command-line arguments. For example:

```
./push_swap 5 2 8 3 1
```

The program will print the sequence of operations required to sort the stack. You can use this sequence along with the visualizer to see the sorting process.

## Available Operations

The program operates on two stacks: A and B. The available operations are as follows:

- `sa`: Swap the first two elements at the top of stack A.
- `sb`: Swap the first two elements at the top of stack B.
- `ss`: Swap both stack A and stack B simultaneously.
- `pa`: Push the first element at the top of stack B onto stack A.
- `pb`: Push the first element at the top of stack A onto stack B.
- `ra`: Rotate stack A - move the first element to the bottom.
- `rb`: Rotate stack B - move the first element to the bottom.
- `rr`: Rotate both stack A and stack B simultaneously.
- `rra`: Reverse rotate stack A - move the bottom element to the top.
- `rrb`: Reverse rotate stack B - move the bottom element to the top.
- `rrr`: Reverse rotate both stack A and stack B simultaneously.

## My Approach to the Algorithm

My approach to solving the Push Swap problem involves the following steps:

- **Sorting Small Numbers:** I start by sorting small numbers such as 2, 3, 4, and 5. I prioritize all possible cases to make the algorithm as optimal as possible.
- **Using Chunks:** For larger sets of numbers (100 and 500), I utilize chunks. I collect the smallest 20 or 50 numbers from stack A, storing them in an array in descending order.
- **Determining Optimal Moves:** I traverse stack A from both ends simultaneously. If a number is found earlier from one direction than the other, I choose that number to move to the top. This helps optimize rotation movements.
- **Pushing to Stack B:** After determining the number to move to the top, I check where it should be pushed to in stack B. For the first chunk, I don't need to check, as the goal is to push these numbers to B without sorting.
- **Chunk Sorting:** This process is repeated until the first chunk (20 or 50 numbers) is pushed to stack B.
- **Repeating the Process:** The array of smallest numbers is then updated, emptied, and filled with the next smallest numbers from stack A. The same process is repeated, now considering the position for pushing to B.
- **Final Steps:** Once all chunks are in stack B, I manipulate both stack A and stack B to sort the blocks. This rearranges the stack B in descending order.
- **Final Sorting:** By pushing all elements from stack B to stack A, they get sorted in ascending order, achieving the desired result.

### Things Not Implemented

There are some aspects I didn't implement in my approach:

- **Not utilized rr and rrr:** While the `rr` and `rrr` operations can be used to check if the same movements can be applied to stack A and stack B to save moves, I found this optimization was not so good for my algorithm.
- **Missing Optimizations:** Many potential optimizations and ideas haven't been incorporated as they were challenging to implement or didn't fit well with my chosen approach. Not everything is at 100%. As a result, my final grade for the 42Cursus project is not a perfect score since it doesn't achieve the minimum number of possible moves. However, it is still more than satisfactory:
  - For 100 values:
    - 5 points for under 700 moves
    - 4 points for under 900 moves
    - 3 points for under 1100 moves
    - 2 points for under 1300 moves
    - 1 point for under 1500 moves
  - My project received 4 points here, as the average is around 750 moves with 100 numbers.
  - For 500 values:
    - 5 points for under 5500 moves
    - 4 points for under 7000 moves
    - 3 points for under 8500 moves
    - 2 points for under 10000 moves
    - 1 point for under 11500 moves
  - My project received 3 points here, as the average is around 7700 moves with 500 numbers.
- **Minimum Moves:** Of course, my algorithm handles cases of 3 and 5 numbers efficiently, with a maximum of 3 and 12 moves respectively.

## Visualizer

If you want to visualize the sorting process, you can use the [Push Swap Visualizer](https://github.com/YourUsername/push_swap_visualizer). This visualizer is a complementary tool that allows you to observe how the operations are executed in a graphical animation.

![Preview Push Swap Visualizer](https://camo.githubusercontent.com/b888f835f0a5219ea0c70e529770da4c2f39f2f65cb3bfdcd358cf1f27fe5f95/68747470733a2f2f692e696d6775722e636f6d2f7a7163735a66592e706e67)