## LED Sequence V1.0 

> []()

### Description 

The software is designed to implement a certain sequence using 4 LEDs and a push button.

<details>
  <summary>Expand for detailed LED sequence </summary>

The LED sequence is as described below 
>1. Initially (OFF, OFF, OFF, OFF)
2. Press 1 (ON, OFF, OFF, OFF)
3. Press 2 (ON, ON, OFF, OFF)
4. Press 3 (ON, ON, ON, OFF)
5. Press 4 (ON, ON, ON, ON)
6. Press 5 (OFF, ON, ON, ON)
7. Press 6 (OFF, OFF, ON, ON)
8. Press 7 (OFF, OFF, OFF, ON)
9. Press 8 (OFF, OFF, OFF, OFF)
10. Press 9 (ON, OFF, OFF, OFF)

></details>

In this task, the DIO driver is refactored to be compliant with the following MISRA Rules

>1. Rule 14.7, requires that functions with variable-length argument lists should not be called.
2. Rule 18.1, requires that all declarations should be at the top of the function or file scope.
3. Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
4. Rule 17.4, prohibits the use of the comma operator.
5. Rule 13.2, which requires that all conditional statements should have a Boolean expression as the controlling expression.
6. Rule 12.2, which requires that all switch statements should have a default case.