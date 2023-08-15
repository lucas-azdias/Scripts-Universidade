int sensor_read;
const int sensor_pin = 4;

void setup(){
  Serial.begin(9600);
}

void loop(){
  sensor_read = analogRead(sensor_pin);
  Serial.print("Moisture = ");
  Serial.print(100 - ( (sensor_read/4095.00) * 100 ));
  Serial.println("%");
  delay(1000);
}
