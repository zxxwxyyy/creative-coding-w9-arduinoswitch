
// ----- Creative Coding Week9 Arduino Switch
// ----- Liqian Zhang
// ----- Reference: Arduino built in examples - Blink; Button;
// ----- Creating a sensor to detect if user is standing on the right spot, if not, the orange light blink; if yes, green light on with Breath effect.
// ----- With this idea, I created 2 individual circuits, and another one for button. 

// ----- preset variables for each set of pin. 
const int buttonPin = 12;  
const int blinkledPin = 13;  
const int greenLight = 14;

// ----- follow Arduino built-in example to set up buttonState variable for reading "button" status
int buttonState = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(blinkledPin, OUTPUT);
  pinMode(buttonPin, INPUT);// ----- set button pinmode as input. 
  digitalWrite(greenLight, LOW);// ----- I want to give the green light a "breath" effect, just like my laptop! So I preset the light at LOW in the setup. reference from: https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/;

}

// the loop function runs over and over again forever
// ----- Because the blink indicates warning, so I changed the delay to 100(0.1 seconds) to warn user that they are standing in the wrong spot.
void loop() {
  // ----- follow the example, use this function to read the state of pushbutton value. 
  buttonState = digitalRead(buttonPin);
  Serial.println(digitalRead(buttonPin));


  // ----- using if statement here. If user stands in wrong spot, the orange light will blink; otherwise green light keeps on with the "breath" effect. 
  // ----- when my switch close, the electic will go directly to the ground, which means the input will equal to 0 (LOW)
  // ----- reference: https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/
  if(buttonState == LOW){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  }else{
  // ----- creating the "breath" effect by using for loop and analogWrite function. Reference from:https://www.arduino.cc/reference/en/language/structure/control-structure/for/; https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
 for (int i = 0; i <= 255; i++) {
    analogWrite(greenLight, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(greenLight, i);
    delay(10);

  }
  }

}
