## LED Sequence V3.0 

> [Video](https://drive.google.com/file/d/1sSYOZr4kZuifZRUjBmKqcdoNc-xjbM28/view?usp=sharing)

### Description 

The software is designed to implement a certain sequence using 4 LEDs and two push buttons.

<details>
  <summary>Expand for application details <br></br></summary>

1.   The LED sequence is described below
>1.   Initially (OFF, OFF, OFF, OFF)
>2.   Press 1 (BLINK_1, OFF, OFF, OFF)
>3.   Press 2 (BLINK_1, BLINK_1, OFF, OFF)
>4.   Press 3 (BLINK_1, BLINK_1, BLINK_1, OFF)
>5.   Press 4 (BLINK_1, BLINK_1, BLINK_1, BLINK_1)
>6.   Press 5 (OFF, BLINK_1, BLINK_1, BLINK_1)
>7.   Press 6 (OFF, OFF, BLINK_1, BLINK_1)
>8.   Press 7 (OFF, OFF, OFF, BLINK_1)
>9.   Press 8 (OFF, OFF, OFF, OFF)
>10. Press 9 (BLINK_1, OFF, OFF, OFF)

2.   When BUTTON1 has pressed the blinking on and off durations will be changed 
>1.   No press → BLINK_1 mode (ON: 100ms, OFF: 900ms)
>2.   First press → BLINK_2 mode (ON: 200ms, OFF: 800ms)
>3.   Second press → BLINK_3 mode (ON: 300ms, OFF: 700ms)
>4.   Third press → BLINK_4 mode (ON: 500ms, OFF: 500ms)
>5.   Fourth press → BLINK_5 mode (ON: 800ms, OFF: 200ms)
>6.   Fifth press → BLINK_1 mode

<br></br>
</details>

In this task, the application is refactored to be compliant with the following MISRA Rules

>1. Rule 1.1. A compiler warning shall be produced for any instance of code that does not conform to the rules of the Standard.
>2. Rule 2.1. Assembly language shall be encapsulated and isolated.
>3. Rule 5.2. Expressions shall not be used as the controlling expression of an if statement or as the operand of a while or do-while statement.<details><summary>Expand</summary>  Rule 14.4 of the MISRA C:2012 guidelines states that "The controlling expression of an 'if' statement and the 'while' and 'do-while' expressions shall not contain persistent side effects." The guideline recommends that expressions used in these statements should be simple, and that any complex expressions should be broken down into simpler expressions or assigned to a temporary variable before being used in the statement.</details>
>4.  Rule 10.3, The value of a complex expression of integer type shall only be cast to a type that is narrower and of the same signedness as the underlying type of the expression.
>5.  Rule 12.1. Only one break statement shall appear in the body of a switch statement. <details><summary>Expand</summary> (Rule 15.2 of the MISRA C:2012 guidelines) The guideline recommends that switch statements should be structured with a single break statement at the end of each case block, and that additional break statements should not be used.</details>
>6.  Rule 13.5. The operands of the && and || operators shall be of scalar type.
>7.  Rule 14.2. All non-static functions shall have external linkage. <details><summary>Expand</summary> (Rule 8.4 of the MISRA C:2012 guidelines) The guideline recommends that all non-static functions should be declared with the extern keyword to ensure that they have external linkage. This helps to ensure that the functions are accessible from other translation units, which can be important in modular software architectures.</details>
>8.  Rule 14.3. A function shall not have multiple exit points.
>9.  Rule 17.3. Type definitions shall not be used in the return types of functions. (Advisory)
>10. Rule 18.4. Unions shall not be used.
