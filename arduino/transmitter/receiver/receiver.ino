#define LDR_PIN A0
#define THRESHOLD 480
#define PERIOD 14

bool previous_state;
bool current_state;


void setup() {
  // put your setup code here, to run once:
  pinMode(LDR_PIN,INPUT);
  Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
   current_state = get_ldr();
   

}

bool get_ldr()
{
  int voltage = analogRead(LDR_PIN);
  return voltage > THRESHOLD ? true:false;
}

char get_byte(char my_byte)
{
  char buff[2];
  sprintf(buff, "%c", my_byte);
  Serial.print(buff);
}
