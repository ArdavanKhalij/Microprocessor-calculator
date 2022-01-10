/*****************************************************
Header  : keypad driver routines
Version : 1.0
Date    : 07/05/2010 1388/02/17
Author  : SEYD MOHSEN GHASEMIAN
           
 EXP: key = keypad();         
*****************************************************/

 #include <delay.h>
 #define c1 PINB.4 
 #define c2 PINB.5 
 #define c3 PINB.6 
 #define c4 PINB.7
 #define c5 PINA.0
 #define c6 PINA.1
 
  unsigned char scan[4]={0XFE,0XFD,0XFB,0XF7};
  char arrkey[24]={
  'c','7','8','9',
  'n','4','5','6','-','m',
  '1','2','3','+','d',
  '0','=','+','i'};
   
 unsigned char keypad(){
  unsigned char r,c,k;
   DDRB=0X0F;
   PORTB=0XFF;
   DDRA=0X00;
   PORTA=0X0F; 
   
      while(1){
        for (r=0; r<4; r++){
         c=6;
         PORTB=scan[r];
         delay_us(10);
         if(c1==0) c=0;
         if(c2==0) c=1;
         if(c3==0) c=2;
         if(c4==0) c=3;
         if(c5==0) c=4;
         if(c6==0) c=5;
         
          if (!(c==6)){
           k=arrkey[(r*6)+c];
           while(c1==0);
           while(c2==0);
           while(c3==0);
           while(c4==0);
           while(c5==0);
           while(c6==0);
           delay_ms(50);
           return k;
          }
        }
      } 
 }
