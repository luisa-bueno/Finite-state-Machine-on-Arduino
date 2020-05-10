
// Defining the states of the state machine
#define state_0 0
#define state_1 1
#define state_2 2
#define state_3 3

//control key to indicate which state the user is in.
volatile char control;

//defining the pins of the buttons (tips is the button to ask for a tip)
const int button1 = 3;
const int button2 = 4;
const int button3 = 5;
const int tips = 2;

//"cleaning" the 'states and wantTip' variables.
int state1 = 0;
int state2 = 0;
int state3 = 0;
int wantTip = 0;

void setup(){
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(tips, INPUT);
  
  Serial.begin(9600);
  
  control = state_0;
  state1 = 0;
  state2 = 0;
  state3 = 0;
  wantTip = 0;
  
}

void stateMachine(){

//  checking what state the variable "control" is in
  switch(control){
    case state_0:
    {
      if(state1 == HIGH){
//       if the button1 is pressed, then "control" is going to the next stage.
        control = state_1;
      }else{
        if(wantTip == HIGH){
          Serial.println("Try to press button1...");
          wantTip = LOW;
          delay(1000);
        }
      }
      break;
    }
    case state_1:
    {
      if(state2 == HIGH){
//       if the button2 is pressed, then "control" is going to the next stage.        
        control = state_2;
      }else{
        if(wantTip == HIGH){
          Serial.println("Try to press button2...");
          wantTip = LOW;
          delay(1000);
        }
      }
      break;
    }
    case state_2:
    {
      if(state3 == HIGH){
        control = state_3;
//    state_3 is the final state, so a message of accomplishment is sent.        
        Serial.println("You finished it!");
      }else{
        if(wantTip == HIGH){
          Serial.println("Try to press button3...");
          wantTip = LOW;
          delay(1000);
        }
      }
      break;
    }
    case state_3:
    {
      if(wantTip == HIGH){
        Serial.println("You finished it!");
        wantTip = LOW;
        delay(1000);
      }
      break;
    }
  }
  
}

void loop(){

  if(digitalRead(button1) == HIGH){
    state1 = HIGH;
  }
  if(digitalRead(button2) == HIGH){
    state2 = HIGH;
  }
  if(digitalRead(button3) == HIGH){
    state3 = HIGH;
  }
  
  if(digitalRead(tips) == HIGH){
    wantTip = HIGH;
  }
  
  stateMachine();
  
}
