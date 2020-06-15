#include <Keypad.h>;
 
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
 
String senha = "123";
String tentativa;
int contador = 0;
 
String leStringSerial() {
  String conteudo = "";
  char caractere;
 
  while (Serial.available() > 0) {
    caractere = Serial.read();
    if (caractere != '\n') {
      conteudo.concat(caractere);
    }
    delay(10);
  }
 
  Serial.print("Recebi: ");
  Serial.println(conteudo);
 
  return conteudo;
}
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  while (contador < 3) {
    char keyStroke = customKeypad.getKey();
    if (keyStroke) {
      tentativa += keyStroke;
      Serial.println(tentativa);
      if (tentativa.length() == 3) {
        if (tentativa == senha) {
          delay(500);
          Serial.println("Acesso autorizado");
          delay(500);
        } else {
          Serial.print("Senha incorreta");
          tentativa = "";
          contador++;
        }
      }
    }
  }
  delay(500);
  Serial.println("Acesso bloqueado");
  delay(500);
 
  if (Serial.available() > 0) {
    if (leStringSerial() == "foobar") {
      contador = 0;
      Serial.print("Tente novamente, limite de 3 tentativas");
    } else {
      Serial.print("Digite foobar para tentar novamente");
    }
  }
}