const int buzzer = 8;
const int trig_pin = 9;
const int echo_pin = 10;
const int led = 6;
float timing = 0.0;
float distance = 0.0;
void setup() {
  // put your setup code here, to run once:
pinMode(echo_pin, INPUT);
pinMode(trig_pin, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);

digitalWrite(trig_pin, LOW);
digitalWrite(buzzer, LOW);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig_pin, LOW);
delay(2);

digitalWrite(trig_pin, HIGH);
delay(10);
digitalWrite(trig_pin, LOW);

timing = pulseIn(echo_pin, HIGH);
distance = (timing * 0.034)/2;

Serial.print("distance: ");
Serial.print(distance);
Serial.print("cm | ");
Serial.print(distance/2.54);
Serial.println("in");

if (distance >= 50){
    tone(buzzer, 500);
    digitalWrite(led, HIGH);
} else {
    noTone(buzzer);
    digitalWrite(led, LOW);
}
delay(100);
}