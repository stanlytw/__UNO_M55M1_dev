int Led=D8;
int Knock=D10;
int val;
void setup()
{
    pinMode(Led,OUTPUT);
    pinMode(Knock,INPUT);
}
void loop()
{
    val=digitalRead(Knock);
    if(val==HIGH)
        digitalWrite(Led,LOW);
    else
        digitalWrite(Led,HIGH);
}