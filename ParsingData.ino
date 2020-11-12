String myNim = "1418001";
byte greenLed = 5;
byte redLed = 3;
String incomingMsg;
byte inputData = 2;
int inputDataVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLed,OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(inputData, INPUT);
}

void loop() {
  if(Serial.available()>0){
    Serial.print("Masukkan NIM anda: ");
    incomingMsg=Serial.readStringUntil("\n");
    
    Serial.print(incomingMsg);
    if(incomingMsg.compareTo(myNim)==13){
      //Serial.println(incomingMsg.compareTo(myNim));
      Serial.println("Status: Green LED On\n");
      digitalWrite(greenLed, HIGH);
      delay(2000);
      digitalWrite(greenLed, LOW);
    }
    else{
      //Serial.println(incomingMsg.compareTo(myNim));
      Serial.println("Status: Red LED On\n");
      digitalWrite(redLed,HIGH);
      delay(2000);
      digitalWrite(redLed,LOW);
    }

    Serial.print("Digital Input: ");
    inputDataVal = digitalRead(inputData);
    Serial.println(inputDataVal);

    if(inputDataVal == 1){
      Serial.print("Message: OK\n");
      Serial.println(" ");
      Serial.println(" ");
      delay(2000);  
    }
    else{
      Serial.print("Message: NOT OK\n\n");
      Serial.println(" ");
      Serial.println(" ");
      delay(2000);
    }
  }
}
