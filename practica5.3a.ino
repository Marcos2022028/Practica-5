#include <Adafruit_NeoPixel.h>
#include <Keypad.h>
#include <Servo.h>
#define tiempo() delay(1500)
#define FILAS 4
#define COLUMNAS 4

Adafruit_NeoPixel tira = Adafruit_NeoPixel(12,13);

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

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tira.begin();
  tira.show();
  servo.attach(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  key = teclado.getKey();

  if(key){
  Serial.println(key);
  }else{
    tira.clear();
  }
  switch(key){
    case '0':
      servo.write(0);
      tiempo();
    break;

    case '1':
      servo.write(20);
      tiempo();
    break;

    case '2':
      servo.write(40);
      tiempo();
    break;

    case '3':
      servo.write(60);
      tiempo();
    break;

    case '4':
      servo.write(80);
      tiempo();
    break;

    case '5':
      servo.write(100);
      tiempo();
    break;

    case '6':
      servo.write(120);
      tiempo();
    break;

    case '7':
      servo.write(140);
      tiempo();
    break;

    case '8':
      servo.write(160);
      tiempo();
    break;

    case '9':
      servo.write(180);
      tiempo();
    break;

    case 'A':
      for(int i = 0; i<12; i = i+2 ){
        tira.setBrightness(100);
        tira.setPixelColor(i, 10,230,200);
       tira.show();
        delay(100);
      }
    break;

    case 'B':
      for(int i = 12; i>=-1; i = i-4) {
        tira.setBrightness(100);
        tira.setPixelColor(i, 100,201,90);
        tira.show();
       delay(100);
     }
    break;

    case 'C':
     for(int i = 12; i>=-1; i = i-3) {
       tira.setBrightness(100);
        tira.setPixelColor(i, 10,10,255);
       tira.show();
       delay(100);
     } 
    break;

    case 'D':
      for(int i = 2; i<9; i++) {
       tira.setBrightness(100);
        tira.setPixelColor(i, 205,60,80);
        tira.show();
       delay(100);
     }
    break;

    case '*' :
      for(int i=0;i<7 ;i++){
          tira.setBrightness(100);
          tira.setPixelColor(i, 25,10,150);
          tira.show();
          delay(100);
      }
    break;

    case '#':
      for(int i = 0; i<12; i = i+5 ){
       tira.setBrightness(100);
       tira.setPixelColor(i, 230,250,5);
       tira.show();
        delay(100);
      }
    break;
}

}