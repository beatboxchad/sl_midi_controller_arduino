#define LED 13   // LED pin on Arduino board
#define button1 9              // 1st trigger button
#define button2 8               // 2nd trigger button
#define button3 7								// 3rd trigger button
#define switch1 6								// Toggle switch 1
#define switch2 5								// Toggle switch 2
#define switch3 4								// Toggle switch 3

//Variables
int button1LastState = 0;
int button1CurrentState = 0;

int button2LastState = 0;
int button2CurrentState = 0;

int button3LastState = 0;
int button3CurrentState = 0;

int switch1State = 0;
int switch2State = 0;
int switch3State = 0;

void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}


void blinkLed(byte num) { // Basic blink function
	for (byte i=0;i<num;i++) {
		digitalWrite(LED,HIGH);
		delay(50);
		digitalWrite(LED,LOW);
		delay(50);
	}
}

uint8_t checkSwitch() { // see what position the 5 position switch is 
	switch1State = digitalRead(switch1);
	switch2State = digitalRead(switch2);
	switch3State = digitalRead(switch3);

	uint8_t data2;
	if ((switch1State == HIGH) && (switch2State == LOW)) {
		data2 = 1;
		}
	if ((switch1State == HIGH) && (switch2State == HIGH)) {
		data2 = 2;
	}
	if ((switch1State == LOW) && (switch2State == HIGH)) {
		data2 = 3;
	}
	if ((switch2State == HIGH) && (switch3State == HIGH)) {
		data2 = 4;
	}
	if ((switch2State == LOW) && (switch3State == HIGH)) {
		data2 = 5;
	}
	return data2;
}	

void setup() {
pinMode(LED, OUTPUT);
pinMode(switch1,INPUT);
pinMode(switch2, INPUT);
pinMode(switch3, INPUT);
pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(button3, INPUT);
Serial.begin(115200);

blinkLed(3);

}


void loop() {
	
	button1CurrentState = digitalRead(button1);
	button2CurrentState = digitalRead(button2);
	button3CurrentState = digitalRead(button3);
	uint8_t switch_pos = checkSwitch();


	//The three buttons send different messages
	if (button1CurrentState == 1){
		if(button1LastState == 0){
			noteOn(0x90, switch_pos, 64);
//			blinkLed(1);
		}
	}

	button1LastState = button1CurrentState;
	if (button2CurrentState == 1){
		if(button2LastState == 0){
			noteOn(0x90, switch_pos + 5, 64);
			//blinkLed(2);
		}
	} 
	button2LastState = button2CurrentState;
	
	if (button3CurrentState == 1){
		if(button3LastState == 0){
			noteOn(0x90, switch_pos + 10, 64);
			//blinkLed(3);
		}
	}
	button3LastState = button3CurrentState;
}
