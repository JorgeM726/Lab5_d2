//Variables del jugador 1 (PINS en Tiva)
const int J1_1 = 2;
const int J1_2 = 3;
const int J1_3 = 4;
const int J1_4 = 5;
const int J1_5 = 6;
const int J1_6 = 7;
const int J1_7 = 8;
const int J1_8 = 9;

//Variables del jugador 2 (PINS en Tiva)
const int J2_1 = 11;
const int J2_2 = 12;
const int J2_3 = 13;
const int J2_4 = 33;
const int J2_5 = 34;
const int J2_6 = 35;
const int J2_7 = 36;
const int J2_8 = 37;

char mode = 0;
char sas;
char con1 = 0;
char con2 = 0;
char buffer[10];

void setup() {
  // put your setup code here, to run once:
  pinMode(PUSH1, INPUT_PULLUP);                         //Se declaran los push como inputs con pullups y los leds como outputs
  pinMode(PUSH2, INPUT_PULLUP);
  //
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  //Pines jugadores
  pinMode(J1_1, OUTPUT);
  pinMode(J1_2, OUTPUT);
  pinMode(J1_3, OUTPUT);
  pinMode(J1_4, OUTPUT);
  pinMode(J1_5, OUTPUT);
  pinMode(J1_6, OUTPUT);
  pinMode(J1_7, OUTPUT);
  pinMode(J1_8, OUTPUT);
  pinMode(J2_1, OUTPUT);
  pinMode(J2_2, OUTPUT);
  pinMode(J2_3, OUTPUT);
  pinMode(J2_4, OUTPUT);
  pinMode(J2_5, OUTPUT);
  pinMode(J2_6, OUTPUT);
  pinMode(J2_7, OUTPUT);
  pinMode(J2_8, OUTPUT);

  //Interrupciones para botones
  attachInterrupt(digitalPinToInterrupt(PUSH1), J1, CHANGE);    
  attachInterrupt(digitalPinToInterrupt(PUSH2), J2, CHANGE);
  
}

void loop() {
switch(mode){
  case 0:
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  break;
  
  case 1:
    digitalWrite(RED_LED, HIGH);
    delay(1000);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    delay(1000);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    delay(500);
    mode = 2;                                 //A mitad del semáforo verde se entra al modo 2 para que puedan comenzar a aumentar los contadores
    delay(500);
    digitalWrite(GREEN_LED, LOW);
  
  break;

  
  case 2:

    J1_state();
    J2_state();
    
  break;
  
}
 
  while(con1 >= 8){                           //cuando alguno de los jugadores llegue a 9, se pone en verde o azul y termina el juego
    digitalWrite(GREEN_LED, HIGH);
  }
  while(con2 >= 8){
    digitalWrite(BLUE_LED, HIGH);
  }
  
  
}

void J1(){
  char state1 = digitalRead(PUSH1);
  if(state1 == LOW){                          //Solo se toma la interrupción cuando se oprime, no cuando se suelta
    if(mode == 0){                            //Si está en el modo 0, cualquiera de los push lleva a iniciar el semáforo
      mode = 1;
    }
    if(mode == 2){
      con1++;                                //En el modo 2 se incrementan los contadores
 sas = 1;
    }
  }
  return;
}

void J2(){
  char state2 = digitalRead(PUSH2);
  if(state2 == LOW){
    if(mode == 0){
      mode = 1;
    }
    if(mode == 2){
      con2++;
       sas = 1;
    }
  }
  return;
}

void J1_state() {

  switch (con1){
    case 1:
    digitalWrite(J1_1, HIGH);
    break;
    case 2:
    digitalWrite(J1_1, LOW);
    digitalWrite(J1_2, HIGH);
    break;
    case 3:
    digitalWrite(J1_2, LOW);
    digitalWrite(J1_3, HIGH);
    break;
    case 4:
    digitalWrite(J1_3, LOW);
    digitalWrite(J1_4, HIGH);
    break;
    case 5:
    digitalWrite(J1_4, LOW);
    digitalWrite(J1_5, HIGH);  
    break;
    case 6:
    digitalWrite(J1_5, LOW);
    digitalWrite(J1_6, HIGH); 
    break;
    case 7:
    digitalWrite(J1_6, LOW);
    digitalWrite(J1_7, HIGH); 
    break;
    case 8:
    digitalWrite(J1_7, LOW);
    digitalWrite(J1_8, HIGH);
    break;
  }
  
}

void J2_state() {
  switch (con2){
    case 1:
    digitalWrite(J2_1, HIGH);
    break;
    case 2:
    digitalWrite(J2_1, LOW);
    digitalWrite(J2_2, HIGH);
    break;
    case 3:
    digitalWrite(J2_2, LOW);
    digitalWrite(J2_3, HIGH);
    break;
    case 4:
    digitalWrite(J2_3, LOW);
    digitalWrite(J2_4, HIGH);
    break;
    case 5:
    digitalWrite(J2_4, LOW);
    digitalWrite(J2_5, HIGH);  
    break;
    case 6:
     digitalWrite(J2_5, LOW);
    digitalWrite(J2_6, HIGH);  
    break;
    case 7:
    digitalWrite(J2_6, LOW);
    digitalWrite(J2_7, HIGH); 
    break;
    case 8:
    digitalWrite(J2_7, LOW);
    digitalWrite(J2_8, HIGH);  
    break;
  
 
     
 }
}
