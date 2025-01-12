# Push_Swap

The **Push_Swap** project is a complex algorithmic challenge from the 42 School curriculum that tests your ability to implement efficient sorting algorithms with limited operations. The goal is to sort a stack of integers using two stacks and a predefined set of operations while minimizing the number of moves required.

### Objective
Create a program named `push_swap` that calculates and displays the smallest sequence of operations to sort a set of integers using the following operations:

Stack Operations:
- **sa**: Swap first 2 elements of stack A
- **sb**: Swap first 2 elements of stack B
- **ss**: sa and sb simultaneously
- **pa**: Push top element from stack B to stack A
- **pb**: Push top element from stack A to stack B
- **ra**: Rotate stack A up (first becomes last)
- **rb**: Rotate stack B up (first becomes last)
- **rr**: ra and rb simultaneously
- **rra**: Rotate stack A down (last becomes first)
- **rrb**: Rotate stack B down (last becomes first)
- **rrr**: rra and rrb simultaneously

## Installation and Compilation

```bash
# Clone the repository
git clone https://github.com/yoti1412/Push_Swap-42.git
cd Push_Swap-42

# Compile the main program
make

# Compile with bonus (checker)
make bonus

# Compile the move tracker
cd tracker && make
```

## Testing Suite

The project includes a comprehensive testing suite located in the `tests/` directory:

### 1. Simple Tests (`simple_test.sh`)
```bash
# Run basic test cases (3-5 numbers)
./tests/simple_test.sh
```
Tests basic sorting scenarios and edge cases with small stacks.

### 2. Middle Tests (`middle.sh`)
```bash
# Run medium-sized tests (100 numbers)
./tests/middle.sh
```
Verifies sorting efficiency for medium-sized stacks (100 elements).

### 3. Advanced Tests (`advanced.sh`)
```bash
# Run large-scale tests (500 numbers)
./tests/advanced.sh
```
Tests performance and efficiency with large stacks (500 elements).

### Running All Tests
```bash
# Execute all test suites
for test in tests/*.sh; do
    bash "$test"
done
```

## Move Tracker

The Move Tracker is a specialized tool for analyzing and optimizing the sorting algorithm's performance.

### Features
- Real-time operation counting
- Move sequence visualization
- Performance statistics
- Operation pattern analysis

### Usage
```bash
# Compile the move tracker
cd tracker && make

# Track moves for a specific input
./Moves_Tracker "4 67 3 87 23"

# Generate performance report
./Moves_Tracker -r "4 67 3 87 23" > analysis.txt
```

### Performance Targets
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations
- 500 numbers: ≤ 5500 operations

## Algorithm Implementation

### Sorting Strategy
1. **Initial Analysis**
   - Stack size determination
   - Pre-sorting optimization checks

2. **Small Stack Optimization**
   - Direct sorting for stacks ≤ 3 elements
   - Optimized sequences for 4-5 elements

3. **Large Stack Algorithm**
   - Chunk-based sorting
   - Rotation cost calculation
   - Optimal move selection

### Rotation Optimization
The project implements four main rotation strategies:
1. **rarb**: Simultaneous forward rotation
2. **rrarrb**: Simultaneous reverse rotation
3. **rarrb**: Mixed rotation (A forward, B reverse)
4. **rrarb**: Mixed rotation (A reverse, B forward)

## Error Handling

The program handles various error cases:
- Non-numeric input
- Duplicate numbers
- Integer overflow/underflow
- Memory allocation failures
- Invalid operations (checker)

## Performance Metrics

### Operation Limits
For optimal grades, aim for:
- 3 numbers: ≤ 3 moves
- 5 numbers: ≤ 12 moves
- 100 numbers: ≤ 700 moves
- 500 numbers: ≤ 5500 moves

### Memory Management
- Efficient stack implementation
- Proper memory allocation/deallocation
- No memory leaks

Happy Coding! 🚀📚
