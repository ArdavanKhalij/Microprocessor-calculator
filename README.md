# Logical-Design-calculator
The main file of the program calculator-avr-c.c:</br></br>
This is a C file created by the compiler itself and I wrote the operating programs and micro configuration in it. First, the library functions and other settings are written in it, and two other extension files (headers) are added to the main program so that the compiler realizes that we have written other project-related commands in these other two files, which we will explain below.</br></br>
### #include <keypad.h>
### #include <inputNum.h>
First, I defined a series of variables globally so that we could use them in other functions as well. Variable a is used to store the first number, variable b is used to store the second number, and variable ans is used to store the final result. The functions display1 to display4 are responsible for displaying information in different ways on the LCD.</br></br>
### Equal function:
If you press the = key immediately after entering the prime number, this function will be executed and the variable ans will be equal to a and will be displayed on the LCD.</br></br>
### May_error function:
This function is used to display this error message when the result of an operation is infinite.</br></br>
### Clear_var function:
This function is for resetting the main variables as well as clearing the LCD and preparing it. Note The code 0x0f, which is also available in the LCD datasheet, causes the character to blink.</br></br>
### Calculat_add function:
In this function, the input_digit function is called again to receive the second number from the user, and then a and b are added together and the result is displayed on the LCD.</br></br>
### Calculat_min, calculat_mul, and calculat_div functions:
These three functions have the same function as the addition function, only in the division function we set a condition for when b = 0 to display an infinite error.</br></br>
