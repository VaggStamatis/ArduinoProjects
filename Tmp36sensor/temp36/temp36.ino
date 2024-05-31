void setup() {
  // put your setup code here, to run once:
  pinMode(A0 , INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //take the reading multiply by voltage and divide by the ADC
  float voltage = analogRead(A0) * 5/1024.0;
  float cel = (voltage - 0.49699) * 100;
  Serial.println(String(cel) + "C");
  delay(2000);


}
