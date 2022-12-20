#define BLYNK_TEMPLATE_ID "TMPLZ0VuGnnp"
#define BLYNK_DEVICE_NAME "smoke detect"
#define BLYNK_AUTH_TOKEN "Z4soYXObLT0BGZfp9E35piePpIbjFjLl"
// Your WiFi Credentials.
// Set password to "" for open networks.
char ssid[] = "Galaxy";
char pass[] = "sahanrdxnk1";
const int Relay = 5;
const int ldrPin = A0;
const int pir = 14;
char auth[] = BLYNK_AUTH_TOKEN;
#define Relay      5
#define ldrpin      A0
#define VPIN_BUTTON_3    V3
#define pir      14
void setup() {


BLYNK_WRITE(VPIN_BUTTON_3){
  toggleState_3 = param.asInt();
  if(toggleState_2 == 1)
  {    
      
     
      digitalWrite(Relay, HIGH);
      
  }
  else{
       digitalWrite(Relay, LOW);
       //blinking led;
    }
}  

Serial.begin(9600);

pinMode(Relay, OUTPUT);
pinMode(Pir, INPUT);
pinMode(ldrPin, INPUT);
Blynk.virtualWrite(VPIN_BUTTON_3, toggleState_3);

void pirSensor() 
{ pirValue = digitalRead(PIR); 
if(pirValue==1) 
{
   digitalWrite(Relay, HIGH);
   Serial.println("Motion detected");//bulb is switched off after 5 min
   delay(500000);
   digitalWrite(Relay, LOW);
  } 
else
{
   digitalWrite(Relay, LOW);
  } 
  }




}

void loop() {

int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <=300) {

        pirSensor();

  }

  else {

  digitalWrite(Relay, HIGH);
  delay(60000);
  digitalWrite(Relay, LOW);
  Serial.println("Bulb is switched off after 60s");

  }

}
