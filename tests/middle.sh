#!/bin/sh

# Number of tests to run
NUM_TESTS=200

# Range of random numbers and count
MIN=0
MAX=500
COUNT=100

# Initialize score
TOTAL_SCORE=0

echo "Running $NUM_TESTS tests with $COUNT random numbers each..."
echo

i=1
while [ $i -le $NUM_TESTS ]; do
    # Generate 100 random numbers
    ARG=$(shuf -i $MIN-$MAX -n $COUNT | tr '\n' ' ')

    # Run push_swap and checker_OS
    RESULT=$(.././push_swap $ARG | .././checker $ARG)
    INSTRUCTION_COUNT=$(.././push_swap $ARG | wc -l)

    # Output results
    echo "Test $i:"
    echo "Checker result: $RESULT"
    echo "Instruction count: $INSTRUCTION_COUNT"

    # Check if checker is "OK" and assign points
    if [ "$RESULT" = "OK" ]; then
        if [ "$INSTRUCTION_COUNT" -lt 700 ]; then
            echo "Points: 5"
            TOTAL_SCORE=$((TOTAL_SCORE + 5))
        elif [ "$INSTRUCTION_COUNT" -lt 900 ]; then
            echo "Points: 4"
            TOTAL_SCORE=$((TOTAL_SCORE + 4))
        elif [ "$INSTRUCTION_COUNT" -lt 1100 ]; then
            echo "Points: 3"
            TOTAL_SCORE=$((TOTAL_SCORE + 3))
        elif [ "$INSTRUCTION_COUNT" -lt 1300 ]; then
            echo "Points: 2"
            TOTAL_SCORE=$((TOTAL_SCORE + 2))
        elif [ "$INSTRUCTION_COUNT" -lt 1500 ]; then
            echo "Points: 1"
            TOTAL_SCORE=$((TOTAL_SCORE + 1))
        else
            echo "Points: 0 (Too many instructions)"
        fi
    else
        echo "Checker failed (KO). No points for this test."
    fi

    echo

    i=$((i + 1))
done

# Output total score
echo "Total score: $TOTAL_SCORE out of $((NUM_TESTS * 5))"

