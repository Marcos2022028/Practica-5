#include <Keypad.h>
#define FILAS 4
#define COLUMNAS 4
const int  g = A5;
const int  f = A4;
const int  e = A3;
const int  d = A2;
const int  c = A1;
const int  b = A0;
const int  a = 10;
#define out(pin) pinMode(pin, OUTPUT)
#define encen(pin) digitalWrite(pin, HIGH)
#define apag(pin) digitalWrite(pin, LOW)

char keys[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

char key;
byte Filas[FILAS]={9,8,7,6};
byte Columnas[COLUMNAS] = {5,4,3,2};

Keypad teclado = Keypad(makeKeymap(keys),Filas, Columnas,FILAS,COLUMNAS);

void setup()
{
out(g);
out(f);
out(e);
out(d);
out(c);
out(b);
out(a);
}

void loop(){
  key = teclado.getKey();
  
  if(key){
  Serial.println(key);
  }

  switch(key){
  case '1':
apag(g);
apag(f);
apag(e);
apag(d);
encen(c);
encen(b);
apag(a);
  break;
    
   case '2':
encen(g);
apag(f);
encen(e);
encen(d);
apag(c);
encen(b);
encen(a);
  break;

    case '3':
encen(g);
apag(f);
apag(e);
encen(d);
encen(c);
encen(b);
encen(a);
  break;
   
    case 'A':
encen(g);
encen(f);
encen(e);
apag(d);
encen(c);
encen(b);
encen(a);
  break;

    case '4':
encen(g);
encen(f);
apag(e);
apag(d);
encen(c);
encen(b);
apag(a);
  break;

      case '5':
encen(g);
encen(f);
apag(e);
encen(d);
encen(c);
apag(b);
encen(a);
  break;

    case '6':
encen(g);
encen(f);
encen(e);
encen(d);
encen(c);
apag(b);
encen(a);
  break;

    case 'B':
encen(g);
encen(f);
encen(e);
encen(d);
encen(c);
apag(b);
apag(a);
  break;

    case '7':
apag(g);
apag(f);
apag(e);
apag(d);
encen(c);
encen(b);
encen(a);
  break;

    case '8':
encen(g);
encen(f);
encen(e);
encen(d);
encen(c);
encen(b);
encen(a);
  break;

  case '9':
encen(g);
encen(f);
apag(e);
encen(d);
encen(c);
encen(b);
encen(a);
  break;

    case 'C':
apag(g);
encen(f);
encen(e);
encen(d);
apag(c);
apag(b);
encen(a);
  break;

    case '*':
encen(g);
encen(f);
encen(e);
encen(d);
apag(c);
apag(b);
encen(a);
  break;

    case '0':
apag(g);
encen(f);
encen(e);
encen(d);
encen(c);
encen(b);
encen(a);
  break;

    case '#':
encen(g);
encen(f);
encen(e);
apag(d);
apag(c);
apag(b);
encen(a);
  break;

    case 'D':
encen(g);
apag(f);
encen(e);
encen(d);
encen(c);
encen(b);
apag(a);
  break;
  }
}