int val;// Variable to store temp data
int tempPin = 1; // Initialize analog pin A1 to read temp

void setup() {
  Serial.begin(9600);// Start serial port at baud rate 9600
}

void loop() {
  val = analogRead(tempPin);
  // read analog volt from sensor and save to variable temp
  float mv = (val / 1024.0) * 5000;
  float cel = mv / 10;
  float farh = (cel * 9) / 5 + 32; // convert the analog volt to its temperature equivalent

  Serial.print("Temperature = ");
  Serial.print(cel);
  Serial.print("*c");
  Serial.println();
  delay(1000); // update sensor reading each one second
}
