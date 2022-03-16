// we need String in other to publish data to the webhook

String temperature;

// in Setup() we don't really need anything although you can set up a print serial first and print it to your command prompt via CLI before you upload the data to check if the data is correct
void setup()
{
    
}

void loop() 
{
    //read the raw value
    int value = analogRead(A1);
    
    // this eqaution derive from the (3.3v/1024)*100. this is because we are inputing 3.3v into the sensor and the FM16 only have range of 1024. 
    float temp_val = (value * 0.3); 
    
    // we devide this by 10 becuase we get about 1 degree celsius for each 10mV
    temp_val = (temp_val/10);
    
    // we convert the temperature into a String ising a String(...) getting it ready for publish
    temperature = String(temp_val);
    
    /*
        this is a method of publishing data to the web. in the parameter we need to specific where the distanation is and then the second value has to be a string.
        Optionally we can make the data publish private by providing a PRIVATE key work after the comma.
    */ 
    Particle.publish("temp", temperature);
    delay(10000);
}

