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
### Calculat_squ function:
This function will take the square root of the variable a if it is not negative and the result will be displayed. Note The code 0xE8 is for displaying the square root. (Lcd datasheet)</br></br>
### Inc_memory and dec_memory functions:
This function is used to store the calculation in the variable M where the variable M will be added with the new value. And you do the same with the dec function, except it subtracts instead of addition.</br></br>
### Calculat_percent function:
This function is used to get the percentage by writing 2% 50 micro, 2% takes the number 50 and displays it on the LCD.</br></br>
### Memory_clear function:
This function is used to clear the global variable M as memory.</br></br>
### Main function:
The main function of the program in which the LCD is configured as a column of 20 and the zeroing function is called and finally enters the infinite loop in which the first number a with the type of op operation is received from the keyboard and using From the switch command, the type of operation is detected and one of the above functions is called. For the next calculation at the end will be op = 0.</br></br>
### InputNum.h file:
The task of the command written in this add-on file is to receive the numbers as a single digit from the keyboard and store them in the array, and finally convert these digits into an integer integer and put it in the variable n, and finally this Return the variable. In this add-on file, the input_digit function is defined as a return type, the commands of which are explained below:</br></br>
char op, last_op, dis, buffer [40];</br>
float ans;</br></br>
In this section, the global variables defined in file C that are required in this function are rewritten. (This is because the function is in a header file)</br></br>
Within the function, we have defined a series of local variables, each of which we will describe below:</br></br>

1. key: The value of the key pressed is inside this variable.
2. k: The value inside the key is converted to an integer at 0f and placed in k.
3. count and count2: Used to count the number of digits entered.
4. i and t: are temporary variables for counting and betting ...
5. indigt: is a 10-member array in which the entered digits are placed.
6. neg: To understand that the left-key is pressed, it means that the input number is negative, and in the final step, the variable n is negative. picpars
7. ashar: This variable is also used to understand the user wants to enter a decimal number, which we explain below.
8. n, n2: Also used to store the final integer. (n2 temporary)
9. dis: By unifying this variable, we have given permission to delete the lcd so that after pressing the first lcd key, the result of the last calculation will be displayed in the second line.</br></br>

From the if (op) command lcd_putchar (op); Used to get the second number, if we have an op, that op will be displayed on the lcd. In the following, we have a label that this label is used only to get the decimal part of the desired number. The variables required to get the number become zero and we enter the infinite conditional loop.</br></br>
The condition of this loop is a problem with op, that is, as long as we have op = 0, we stay in the loop, and as soon as one of the operation keys is pressed, op opari will be a value, and the condition of this loop will disappear and lead to exit. It will. First, the keypad function will be called and the value of the pressed key will be measured. The count is copied to count2 for the final steps. If the numbers are not 0 to 9, one of the operation keys is certainly pressed, so this operation is placed in the corresponding variable op.</br></br>
If the + - key is pressed, we neg = 1 and zero op so that the condition of the loop is still valid and we get the number and also the - sign is displayed. The same is true for the decimal key.</br></br>
Finally, after leaving the loop of the variable count, if it is not zero, one unit is subtracted and we put a copy of it in t. Now, using a for loop, we paste the array of digits together and put them in the variable n, where i starts from zero and continues up to t. We convert to an integer.</br></br>
If ashar = 1, the if condition is established and we assign the number 2 to ashar again and temporarily store the correct value in n2 and jump to the lable address to get the value of decimal numbers this time. And finally, because we previously made ashar = 2, this time the corresponding if condition is established, and according to the last value of the variable i, we divide n by the coefficient determined by i, and until the decimal part is obtained, and now with n2 We used to add the correct value and create our input decimal number, and finally copy in n to return.</br></br>
If the value is count2 = 0, it means that only one of the operation keys is pressed, then the answer of the last calculation, which is in ans, is placed as a prime number in a, and the Ans string is also displayed on the display.</br></br>
### Keypad.h file:
In this file, commands have been written whose task is to scan the port and read the pressed key, which we have explained on the 4 × 4 keyboard. Below, in the related content section, which can be done by referring to this article. read. The only difference here is that our keyboard has been increased from 16 keys to 24 keys and with minor changes, most of the numbers have been replaced by 4 to 6.</br></br>
