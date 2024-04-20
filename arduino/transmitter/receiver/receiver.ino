
#define LDR_PIN A2
#define LED 3
#define SAMPLING_TIME 100



//Declaration
bool led_state = false;
bool previous_state = true;
bool current_state = true;
char buff[64];
void setup() 
{
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  
}

void loop() 
{
  current_state = get_ldr(); 
  if(!current_state && previous_state)
  {
    sprintf(buff, "%c", get_byte());
    Serial.print(buff);
  }
  digitalWrite(LED, current_state);
  previous_state = current_state;

  int ldrValue = analogRead(LDR_PIN); 
  // Serial.print("LDR Value: ");
  // Serial.print(ldrValue); 
}
bool get_ldr()
{
  bool val = analogRead(LDR_PIN) > 90 ? true : false;
  digitalWrite(LED, val);
  return val;
}

char get_byte()
{
  char data_byte = 0;
  delay(SAMPLING_TIME * 1.5);
  for(int i = 0; i < 8; i++)
  {
    data_byte = data_byte | (char)get_ldr() << i;
    delay(SAMPLING_TIME);
  }
  return data_byte;
}