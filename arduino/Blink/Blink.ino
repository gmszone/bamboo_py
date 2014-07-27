int led = 13;

void setup() {                
  pinMode(led, OUTPUT);  
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
  String content = "";
  char character;

  while(Serial.available()) {
      character = Serial.read();
      content.concat(character);
  }

  Serial.println(content);
  if (content != "") {
    if(content == "U"){
       digitalWrite(led, HIGH);   
       delay(1000);               
       digitalWrite(led, LOW);    
       delay(1000);    
    }else if(content == "S"){
       digitalWrite(led, HIGH);   
       delay(1000);  
    }else if( content == "F"){
       digitalWrite(led, LOW);   
       delay(1000); 
    }      
  }
}
