/*****************************************************
This program was produced by the
Settlor

Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <lcd.h>
#include <stdio.h>
#include <math.h>
#include <keypad.h>
#include <inputNum.h>
#include <delay.h>
#define xtal 8000000
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
//--------------------------
    char op,last_op,dis;
    float ans,a,b;
    char buffer[40];
     float M;
//--------------------------
    char ma_error[]="Ma ERROR";
    //char syn_error[]="Syntax ERROR";
//--------------------------

 void display1 (){
    lcd_clear();
    sprintf(buffer,"%f\n%f",a,ans);
    lcd_puts(buffer);
    dis=1;
 }
  
 void display2 (){
    op=last_op;
    lcd_clear();
    sprintf(buffer,"%.2f%c%.2f\n%f",a,op,b,ans);
    lcd_puts(buffer);
    dis=1;
 }
 
  void display3 (unsigned char sign_char){
    lcd_clear();
    lcd_write_byte(0x80,sign_char);
    sprintf(buffer,"%f\n%f",a,ans);
    lcd_puts(buffer);
    dis=1;
 }
 
  void display4 (float m){
    lcd_clear();
    sprintf(buffer,"MEMORY\nM=%f",m);
    lcd_puts(buffer);
    dis=1;
 }
  
 void equal(){
   ans=a;
   display1();
 }
 
  void may_error(){
      lcd_clear();
      lcd_gotoxy(6,0);
      lcd_puts(ma_error);
      dis=1;
 }
 
 void clear_var(){
    ans=a=b=op=last_op=0;
    lcd_clear();
    lcd_gotoxy(19,1);
    lcd_putchar('0');
    lcd_gotoxy(0,0);
    _lcd_ready();
    _lcd_write_data(0x0f);
 } 
 
 void calculat_add(){
  b=input_digit();
  ans=a+b; 
  display2();
 }  

 void calculat_min(){
  b=input_digit();
  ans=a-b;
  display2();
 }  
  void inc_memory(){
  M+=ans;
  display4(M);
 }
 
 void dec_memory(){
  M-=ans;
  display4(M);
 }
 

 void memory_clear(){
  M=0;
  display4(M);
 }
 
   
 void main(void){
    lcd_init(20); 
    clear_var();
    
   while (1){
    a=input_digit();
    last_op=op;
    
     switch(op){
       case '=': 
       equal();
       break;
       
       case 'c': 
       clear_var();
       break;
       
       case '+': 
       calculat_add();
       break;
       
       case '-': 
       calculat_min();
       break;
       
       case 'i': //increment memory
       inc_memory();
       break;
       
       case 'd': //decrement memory
       dec_memory();
       break;
       
       case 'm': //show memory
       memory_clear();
       break;
       
     } 
     op=0;
   }
 } 
