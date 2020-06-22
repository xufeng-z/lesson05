#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define LT 6
#define BT 7

#define S1 8
#define S2 9
#define S3 10
#define S4 11

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  
  pinMode(LT, OUTPUT);
  pinMode(BT, OUTPUT);
  
  digitalWrite(LT, HIGH);
  digitalWrite(BT, HIGH);
  
  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  digitalWrite(S4, HIGH);
  

  
  Serial.begin(9600);
}
byte income=0;
void loop()
{
  if(Serial.available()>0){
    digitalWrite(S1, LOW);
    income=Serial.read();
    income=income-'0';
    digitalWrite(2, income&0x1);
    digitalWrite(3, (income>>1)&0x1);
    digitalWrite(4, (income>>2)&0x1);
    digitalWrite(5, (income>>3)&0x1);
    delay(10);
    digitalWrite(S1, HIGH);
  }
}