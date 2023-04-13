
const int encoderIN = 2;
const int driveForwardR = 10;
const int driveForwardL = 11;
const int driveRevR = 3;
const int driveRevL = 4;



volatile long encVal = 0;
void setup()
{
  Serial.begin(9600);
  
  pinMode(driveForwardR, OUTPUT);
  pinMode(driveRevR, OUTPUT);
  pinMode(driveForwardL, OUTPUT);
  pinMode(driveRevL, OUTPUT);
  pinMode(encoderIN, INPUT_PULLUP);

 
  
  attachInterrupt(digitalPinToInterrupt(encoderIN), updateEncoder, RISING);
  Serial.println("Lets get nasty!");
  encVal = 0;
}

void loop() {
  
Serial.println(encVal);
  forWard();
  reVerse();
  spiNLft();
  spiNRt();
  turnLft();
  turnRt();
  stOp();
  



}
void updateEncoder()
{
    encVal++;
}

void forWard()
{ 
  digitalWrite(driveRevR, LOW);
  digitalWrite(driveRevL, LOW);
  digitalWrite(driveForwardR, HIGH);
  digitalWrite(driveForwardL, HIGH);
 
  delay(5000);
  Serial.println(encVal);
}

void reVerse()
{
  digitalWrite(driveForwardR, LOW);
  digitalWrite(driveForwardL, LOW);
  digitalWrite(driveRevR, HIGH);
  digitalWrite(driveRevL, HIGH);
  delay(10000);
  Serial.println(encVal);
}
void stOp()
{
  digitalWrite(driveForwardR, LOW);
  digitalWrite(driveRevR, LOW);
  digitalWrite(driveForwardL, LOW);
  digitalWrite(driveRevL, LOW);
  delay(5000);
  Serial.println(encVal);
}

void spiNLft()
{
   
  digitalWrite(driveRevR, LOW);
  digitalWrite(driveForwardL, LOW);
  
  digitalWrite(driveForwardR, HIGH);
  digitalWrite(driveRevL, HIGH);
  
  delay(10000);
  Serial.println(encVal);
}
void spiNRt()
{  
  digitalWrite(driveForwardR, LOW);
  digitalWrite(driveRevL, LOW);
  digitalWrite(driveRevR, HIGH);
  digitalWrite(driveForwardL, HIGH);
  delay(10000);
  Serial.println(encVal);
}
void turnLft()
{
  digitalWrite(driveRevL, LOW);
  digitalWrite(driveRevR, LOW);
  digitalWrite(driveForwardL, LOW);
  digitalWrite(driveForwardR, HIGH);
  delay(10000);
  Serial.println(encVal);
}
 void turnRt()
{
  digitalWrite(driveForwardR, LOW);
  digitalWrite(driveRevL, LOW);
  digitalWrite(driveRevR, LOW);
  digitalWrite(driveForwardL, HIGH);
  delay(10000);
  Serial.println(encVal);
}
  
  
