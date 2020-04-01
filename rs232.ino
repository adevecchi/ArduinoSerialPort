#define BT_PIN  2

#define LD1_PIN 13
#define LD2_PIN 12

#define LD1_ON  "LD1 ON"
#define LD1_OFF "LD1 OFF"
#define LD2_ON  "LD2 ON"
#define LD2_OFF "LD2 OFF"

int buttonState = 0;
int lastButtonState = 0;

String command;

void setup() 
{
    pinMode(BT_PIN, INPUT);

    pinMode(LD1_PIN, OUTPUT);
    pinMode(LD2_PIN, OUTPUT);

    digitalWrite(LD1_PIN, LOW);
    digitalWrite(LD2_PIN, LOW);

    Serial.begin(9600);
}

void loop() 
{
    if (Serial.available()) {
        command = Serial.readStringUntil('\n');
         
        if(command.equals(LD1_ON)){
            digitalWrite(LD1_PIN, HIGH);
            Serial.println("Led 1 On");
        }
        else if (command.equals(LD1_OFF)) {
            digitalWrite(LD1_PIN, LOW);
            Serial.println("Led 1 Off");
        }
        else if (command.equals(LD2_ON)) {
            digitalWrite(LD2_PIN, HIGH);
            Serial.println("Led 2 On");
        }
        else if (command.equals(LD2_OFF)) {
            digitalWrite(LD2_PIN, LOW);
            Serial.println("Led 2 Off");
        }
        else {
            Serial.print("Transmitted data: ");
            Serial.println(command);
        }
    }

    buttonState = digitalRead(BT_PIN);

    if (buttonState != lastButtonState) {
        if (buttonState == HIGH) {
            Serial.println("Button pressed");
        }
        else {
            Serial.println("Button not pressed");
        }
        delay(50);
    }
    
    lastButtonState = buttonState;
}