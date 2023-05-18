int echo=;
int trig=;
long t,dist,dur;

void setup() {
Serial.begin(9600);
pinMode(echo,OUTPUT);
}

void loop() {
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(5);
digitalWrite(trig,LOW);

dur=pulseIn(echo,HIGH)

dist = dur*0.034/2;
serial.print("Distance: ");
Serial.println(distance);
}
