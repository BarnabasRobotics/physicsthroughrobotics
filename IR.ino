float starttime;
float endtime;
float falltime;

float y=0.22;

void drop(){
  starttime=millis();
}

void gate(){
  endtime=millis();
  falltime=(endtime-starttime)/1000;
  Serial.print("fall time =");Serial.print(falltime);Serial.println(" seconds");
  dropcalc();
  
}

void dropcalc(){
  float g=(2*y)/sq(falltime);
  Serial.print("The calculated value for g =");Serial.println(g);
}

void setup() {
  pinMode(7,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(7,HIGH);
  attachInterrupt(digitalPinToInterrupt(2),gate,FALLING);
  attachInterrupt(digitalPinToInterrupt(3),drop,RISING);

}

void loop() {
  //Null statement
}
