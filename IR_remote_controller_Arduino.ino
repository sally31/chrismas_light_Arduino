#include <IRremote.h>

#define BUTTON_1 16753245
#define BUTTON_2 16736925
#define BUTTON_3 16769565
#define BUTTON_4 16720605
#define BUTTON_5 16712445
#define BUTTON_6 16761405
#define BUTTON_ok 16726215
#define BUTTON_7 16769055
#define BUTTON_8 16754775
#define BUTTON_9 16748655
#define BUTTON_0 16750695
#define BUTTON_ast 16738455
#define BUTTON_hash 16756815
#define BUTTON_up 16718055
#define BUTTON_down 16730805
#define BUTTON_right 16734885
#define BUTTON_left 16716015

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define yellow 6
#define blue 12
#define red 11
#define orange 10
#define green 9
#define clear 8
bool flashlightActive = false;

void setup(){
  Serial.begin(9600);

  // Enable IRremote control reception
  irrecv.enableIRIn();
 
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(clear, OUTPUT);
}

void loop(){
  // If an IR signal is received
  if (irrecv.decode(&results)){
    // Execute different actions based on the received IR code

    //if botton 1 is pressed
    if(results.value==BUTTON_1){
      Serial.println("key1");
      if(!flashlightActive){
        flashlightActive = true;
        illumiPattern1();
      }
    }
    //if botton 2 is pressed
    if(results.value==BUTTON_2){
      Serial.println("key2");
      digitalWrite(yellow, HIGH);
      digitalWrite(blue, HIGH);
      digitalWrite(red, HIGH);
      digitalWrite(orange, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(clear, HIGH);
    }

    //if botton 3 is pressed
    if(results.value==BUTTON_3){
      Serial.println("key3");
      if(!flashlightActive){
        flashlightActive = true;
        illumiPattern3();
      }
    }

    //if botton 4 is pressed
    if(results.value==BUTTON_4){
      Serial.println("key4");
      if(!flashlightActive){
        flashlightActive = true;
        illumiPattern4();
      }
    }

    //if botton 5 is pressed
    if(results.value==BUTTON_5){
      Serial.println("key5");
      if(!flashlightActive){
        flashlightActive = true;
        illumiPattern5();
      }
    }

    //if botton 6 is pressed
    if(results.value==BUTTON_6){
      Serial.println("key6");
      if(!flashlightActive){
        flashlightActive = true;
        illumiPattern6();
      }
    }
    if(results.value==BUTTON_7){
      Serial.println("key7");
    }
    if(results.value==BUTTON_8){
      Serial.println("key8");
    }
    if(results.value==BUTTON_9){
      Serial.println("key9");
    }
    if(results.value==BUTTON_0){
      Serial.println("key0");
    }
    if(results.value==BUTTON_ast){
      Serial.println("key*");
    }
    if(results.value==BUTTON_hash){
      Serial.println("key#");
    }

    //if botton ok is pressed
    if(results.value==BUTTON_ok){
      Serial.println("key OK");
      stopFlashlight();
      irrecv.resume();
    }
    if(results.value==BUTTON_up){
      Serial.println("key UP");
    }
    if(results.value==BUTTON_right){
      Serial.println("key RIGHT");
    }
    if(results.value==BUTTON_down){
      Serial.println("key DOWN");
    }
    if(results.value==BUTTON_left){
      Serial.println("key LEFT");
    }

  Serial.println(results.value, HEX);
  Serial.println(results.value);
  // Resume IR reception
  irrecv.resume();
    
  }
}

// different Flashlight pattern 1-6
void illumiPattern1(){
  while (flashlightActive){
    digitalWrite(yellow, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(orange, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(clear, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(green, LOW);
    digitalWrite(clear, LOW);
    delay(1000);
    
    // If a different IR code is received
    if(irrecv.decode(&results)){
      if(results.value != BUTTON_1){
        //stop the pattarn1
        flashlightActive = false;
      }
      irrecv.resume();
    }
  }
}

void illumiPattern3(){
  while (flashlightActive){
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(clear, HIGH);
    delay(100);
    digitalWrite(clear, LOW);

    if(irrecv.decode(&results)){
      if(results.value != BUTTON_3){
        flashlightActive = false;
      }
      irrecv.resume();
    }
  }
}

void illumiPattern4(){
  while (flashlightActive){
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(orange, HIGH);
    digitalWrite(clear, HIGH);
    delay(1000);
    digitalWrite(blue, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(clear, LOW);

    if(irrecv.decode(&results)){
      if(results.value != BUTTON_4){
        flashlightActive = false;
      }
      irrecv.resume();
    }
  }
}

void illumiPattern5(){
  while (flashlightActive){
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(clear, HIGH);
    delay(100);
    digitalWrite(clear, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);

    if(irrecv.decode(&results)){
      if(results.value != BUTTON_5){
        flashlightActive = false;
      }
      irrecv.resume();
    }
  }
}

void illumiPattern6(){
  while (flashlightActive){
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(clear, HIGH);
    delay(100);
    digitalWrite(clear, LOW);
    delay(100);
    digitalWrite(green, LOW);
    delay(100);
    digitalWrite(orange, LOW);
    delay(100);
    digitalWrite(red, LOW);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);
    digitalWrite(yellow, LOW);
    delay(100);


    if(irrecv.decode(&results)){
      if(results.value != BUTTON_6){
        flashlightActive = false;
      }
      irrecv.resume();
    }
  }
}



// Function to stop the flashlight
void stopFlashlight(){
  flashlightActive = false;
  digitalWrite(yellow, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(orange, LOW);
  digitalWrite(green, LOW);
  digitalWrite(clear, LOW);
}

