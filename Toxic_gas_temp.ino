float temp;
float tempC1;
int MQ2pin = A2;

unsigned long myChannelNumber = 1174816;
const char * myWriteAPIKey = "C6WMBN0TXQ8HTPMS";

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  // temp sensor
  temp = analogRead(A0);
  tempC1 = temp * 0.488;
  Serial.print("The temperature in celcius: ");
  Serial.print(tempC1);
  Serial.print("*C\n");
  Serial.println();
  if (tempC1 >= 38)
  {
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  } 
  
  // Gas sensor
  float sensorValue;
  sensorValue = analogRead(MQ2pin);  
  if(sensorValue >= 220){
    digitalWrite(3,HIGH);
    Serial.println("Unhealthy breathing environment");
  }
  else{
    digitalWrite(3,LOW);
    Serial.println("Suitable breathing environment");
  } 
  delay(1000);
}
