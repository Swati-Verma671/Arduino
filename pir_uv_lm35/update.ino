#define trigPin 7
#define echoPin 6
int temp=14;
#define pir 5

void setup () {

Serial.begin(9600);
}

void loop() {
long duration,cm,Temp,pirsensor;

pinMode(trigPin,OUTPUT);
digitalWrite(trigPin,LOW);
delay(2);
digitalWrite(trigPin,HIGH);
delay(10);
digitalWrite(trigPin,LOW);

pinMode(echoPin,INPUT);
duration=pulseIn(echoPin,HIGH);

cm=mstocm(duration);
Serial.print("Distance:");
Serial.print(cm);
Serial.print("cm");
float rvolt=analogRead(temp);//because analog input
float volts=(rvolt/1024.0)*5000;//converting raw votage to millivolts
Temp=volts/10;
Serial.print(" Temperature:");
Serial.print(Temp);
pirsensor=digitalRead(pir);//digital input
Serial.print(" Sensor:");
Serial.print(pirsensor);
Serial.println();
delay(100);

}
long mstocm(long time){
//speed of sound is 340m/s or 29 microseconds 
return time/29/2;
}