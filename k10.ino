#define B D3
#define G D2
#define R D1

void setup(){
w_setup();
    pinMode(B,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(R,OUTPUT);

  }

void loop(){
 w_loop();
  }




void setNeoColor(String value){
  String hexstring = value;
  int number = (int) strtol( &hexstring[1], NULL, 16);
  int r = number >> 16;
  int g = number >> 8 & 0xFF;
  int b = number & 0xFF;
  analogWrite(R,r );
  analogWrite(G,g );
  analogWrite(B,b );
}
void shutDown(){
  digitalWrite(R,LOW);
          digitalWrite(G,LOW);
              digitalWrite(B,LOW);}
