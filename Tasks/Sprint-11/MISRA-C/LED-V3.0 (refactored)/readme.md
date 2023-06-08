## LED Sequence V3.0 

> * [Video](https://drive.google.com/file/d/1sK6WWZ589QJ7y2ME4nNi7r36fdIk8Wcp/view?usp=sharing)
> 
> * [Refactored Timer Driver](https://github.com/AalaaIbrahim/Automotive_Bootcamp/blob/main/Tasks/Sprint-11/MISRA-C/Timer%20(refactored)/project/MISRA_02/MCAL/TIM0/TIM_program.c)

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

In this task, the Timer driver is refactored to be compliant with the following MISRA Rules

>1.1: A compiler warning shall be produced for any instance of code that does not conform to the rules of the Standard.
>2.1: Assembly language shall be encapsulated and isolated.
>5.2: Expressions shall not be used as the controlling expression of an if statement or as the operand of a while or do-while statement.
>10.3: The value of a complex expression of integer type shall only be cast to a type that is narrower and of the same signedness as the underlying type of the expression.
>12.1: Only one break statement shall appear in the body of a switch statement.
>13.5: The operands of the && and || operators shall be of scalar type.
>14.2: All non-static functions shall have external linkage.
>14.3: A function shall not have multiple exit points.
>17.3: Type definitions shall not be used in the return types of functions.
>18.4: Unions shall not be used.
