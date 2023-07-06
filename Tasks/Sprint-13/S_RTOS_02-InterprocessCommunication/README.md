# S_RTOS_02: Interprocess Communication

Use the files in each task to replace the corresponding files in the base project

## Task 1
    Use an existing RTOS project to write a program with two tasks. 
    A task to read a button state and a task to turn an LED on/off. 
    The LED shall toggle its state between ON/OFF with every press of the button. 
    The action of toggling the LED shall take place after the user presses the button once and releases it.
    
>### Video
>Google Drive [link](https://drive.google.com/file/d/1UoEfWzxN0p_R6qh3KeYXQA4JOxnqT_Ef/view?usp=sharing)


## Task 2
    Use an existing RTOS project to write a program with two tasks. 
    Both tasks are responsible for writing on UART any string 10 times each
    task cycle. The task cycles are, respectively, 100 ms and 500 ms.
    The task with cycle 500 ms shall have an empty loop that loops 100,000 times (To simulate heavy load)
    after every time a string is written on UART.
    Each writing to UART shall not be interrupted by the other task.
    
>### Video
>Google Drive [link](https://drive.google.com/file/d/107XX9xpxKbT-9aOiykR6rpqKkQ8B7_N7/view?usp=sharing)


## Task 3
    Use an existing RTOS project to write a program with four tasks. 
    Two tasks will detect rising and falling edges on two buttons. 
    Every edge is an event that will be sent to a consumer task to write on UART. 
    A task will send periodic string every 100 ms to consumer task to write on UART.
    
   >### Video 
   >Google Drive [link](https://drive.google.com/file/d/168-NWGcR6WlXnbNsFBPGchWHnPhrBdhy/view?usp=sharing)
