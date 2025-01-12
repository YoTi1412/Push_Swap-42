#!/bin/sh

# Path to the checker binary
CHECKER=".././checker"

# Function to test a single ARG value
test_push_swap() {
    ARG=$1
    EXPECTED_MAX=$2

    # Run push_swap and checker_OS
    if [ -x "$CHECKER" ]; then
        RESULT=$(.././push_swap $ARG | $CHECKER $ARG)
        INSTRUCTION_COUNT=$(.././push_swap $ARG | wc -l)
    else
        echo "Error: checker_OS not found or not executable."
        exit 1
    fi

    # Output results
    echo "Test with ARG=\"$ARG\":"
    echo "Checker result: $RESULT"
    echo "Instruction count: $INSTRUCTION_COUNT"

    # Check if the result is OK and the instruction count is within limits
    if [ "$RESULT" = "OK" ] && [ "$INSTRUCTION_COUNT" -le "$EXPECTED_MAX" ]; then
        echo "Test passed."
        return 0
    else
        echo "Test failed."
        return 1
    fi
}

# Run tests
echo "Running Simple Push_Swap Tests..."
echo

# Test 1: ARG="2 1 0"
test_push_swap "2 1 0" 3 || exit 1

# Test 2: ARG with 0-3 random values
RANDOM_ARG=$(shuf -i 0-3 -n $(shuf -i 1-3 -n 1) | tr '\n' ' ')
test_push_swap "$RANDOM_ARG" 3 || exit 1

# Test 3: ARG="1 5 2 4 3" (max 12 instructions)
test_push_swap "1 5 2 4 3" 12 || exit 1

# Test 4: ARG with 5 random values (max 12 instructions)
for i in 1 2 3 4 5; do
    RANDOM_ARG=$(shuf -i 0-100 -n 5 | tr '\n' ' ')
    test_push_swap "$RANDOM_ARG" 12 || exit 1
done

echo
echo "All tests passed!"
