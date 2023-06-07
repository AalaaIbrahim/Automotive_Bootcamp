## LED Sequence V1.0 

> [Video](https://drive.google.com/file/d/1lZ8cKttkaq5X1-wFCvSyR9ggjNhiiFgd/view?usp=sharing)
> [Refactored Timer Driver]()

### Description 

The software is designed to implement a certain sequence using 4 LEDs and a push button.

<details>
  <summary>Expand for detailed LED sequence </summary>

1.   The sequence is described below
1.   Initially (OFF, OFF, OFF, OFF)
2.   Press 1 (BLINK_1, OFF, OFF, OFF)
3.   Press 2 (BLINK_1, BLINK_1, OFF, OFF)
4.   Press 3 (BLINK_1, BLINK_1, BLINK_1, OFF)
5.   Press 4 (BLINK_1, BLINK_1, BLINK_1, BLINK_1)
6.   Press 5 (OFF, BLINK_1, BLINK_1, BLINK_1)
7.   Press 6 (OFF, OFF, BLINK_1, BLINK_1)
8.   Press 7 (OFF, OFF, OFF, BLINK_1)
9.   Press 8 (OFF, OFF, OFF, OFF)
10. Press 9 (BLINK_1, OFF, OFF, OFF)

2.   When BUTTON1 has pressed the blinking on and off durations will be changed 
1.   No press → BLINK_1 mode (ON: 100ms, OFF: 900ms)
2.   First press → BLINK_2 mode (ON: 200ms, OFF: 800ms)
3.   Second press → BLINK_3 mode (ON: 300ms, OFF: 700ms)
4.   Third press → BLINK_4 mode (ON: 500ms, OFF: 500ms)
5.   Fourth press → BLINK_5 mode (ON: 800ms, OFF: 200ms)
6.   Fifth press → BLINK_1 mode

></details>

In this task, the Timer driver is refactored to be compliant with the following MISRA Rules

>1. Rule 14.7, requires that functions with variable-length argument lists should not be called.
>2. Rule 18.1, requires that all declarations should be at the top of the function or file scope.
>3. Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
>4. Rule 17.4, prohibits the use of the comma operator.
>5. Rule 13.2, which requires that all conditional statements should have a Boolean expression as the controlling expression.
>6. Rule 12.2, which requires that all switch statements should have a default case.
