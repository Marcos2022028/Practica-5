#include <Keypad.h>
const int FILAS = 4;
const int COLUMNAS= 4;
const int buzz=13;
const int radar = 12;
int lee;
char keys[FILAS][COLUMNAS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFila[FILAS]={9,8,7,6};
byte pinesColumna[COLUMNAS]={5,4,3,2};
Keypad teclado=Keypad(makeKeymap(keys), pinesFila, pinesColumna,FILAS,COLUMNAS);
char teclaPrecionada;

char pass[7]="200523"; //Poner en el arreglo 1 posicion mas a la que tendra la contraseña correcta
char ingresaPass[7]; // tiene que tener el mismo tamaño del arreglo de la contraseña correcta
int indice=0;
#define salida(pin) pinMode(pin,OUTPUT);
#define entrada(pin) pinMode(pin,INPUT);
#define encen(pin) tone(pin,100);   
#define apag(pin) noTone(pin);
void setup()
{
	Serial.begin(9600);
  entrada(radar);
  salida(buzz);
  encen(buzz);
  apag(buzz);
}

void loop(){
  teclaPrecionada=teclado.getKey(); //detecta que en el teclado se pulso un boton
  if(teclaPrecionada){
    ingresaPass[indice]=teclaPrecionada; // le asigna lo que ingresamos a el arreglo que va a ser comparado
    indice++; //cambiara la posicion del arreglo para poder asignar los caracteres
    Serial.print(teclaPrecionada);
  }
   lee=digitalRead(radar);
  if (lee == 1)
  {
    encen(buzz);
  }

  if(indice==6){ //cuando se llegue al limite del arreglo verificara si esta correcta o no la contraseña
    if(strcmp(pass,ingresaPass)==0){ //Verifica que la contraseña esta correcta
      apag(buzz);
      Serial.println(" Pase Adelante ");
    }
    indice=0;
  }
}