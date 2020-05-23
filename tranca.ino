#include <Keypad.h>;
#include <string.h>;

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {7, 6, 5};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);

}

String senha = "123";
String tentativa;

void loop(){
  char keyStroke = customKeypad.getKey();
  
  if(keyStroke) {
    tentativa += keyStroke;
    Serial.println(tentativa);
    if(tentativa == senha){
    delay(500);
    Serial.println("Acesso autorizado");
    delay(500);
  } 
  }
  
}