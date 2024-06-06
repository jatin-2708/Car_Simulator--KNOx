int steeringwheel=A0;
int accelerator=A1;
int brakes=A2;
void setup(){
  Serial.begin(9600);
}
int steeringvalue;
int acceleratorvalue;
int brakesvalue;
void loop(){
  steeringvalue=analogRead(steeringwheel);

  Serial.print("The value of steering wheel sensor is: ");
  Serial.println(steeringvalue);

  acceleratorvalue=analogRead(accelerator);
  int new_accvalue=map(acceleratorvalue,300,1024,0,255);
  //Serial.print("The value of accelerator sensor is: ");
  //Serial.println(acceleratorvalue);
  brakesvalue=analogRead(brakes);
  int new_brakevalue=map(brakesvalue,300,920,0,255);
  //Serial.print("The value of brake sensor is: "); 
  //Serial.println(brakesvalue);
  Serial.print("\n");
  delay(500);
}