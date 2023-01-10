#define trigPin 7
#define echoPin 6

void setup () {
Serial.begin(9600);
}

void loop() {
long duration,cm;
// TODO: put your main code here, to run repeatedly:
pinMode(trigPin,OUTPUT);
digitalWrite(trigPin,LOW);
delay(2);
digitalWrite(trigPin,HIGH);
delay(10);
digitalWrite(trigPin,LOW);

pinMode(echoPin,INPUT);
duration=pulseIn(echoPin,HIGH);

cm=mstocm(duration);
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(1000);

}
long mstocm(long time){
return time/29/2;
}