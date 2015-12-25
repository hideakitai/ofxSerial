void setup()
{
    Serial.begin(9600, SERIAL_8E2);
}

void loop()
{
    while (Serial.available())
    {
        Serial.println("got message!");
        Serial.println((int)Serial.read());
    }
}
