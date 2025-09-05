//UART arduino CTF challenge
//Base64 by Xander Electronics used
#include <Base64.h>



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); //Serial class sends data over RX/TX pins, begin() begins serial communication w/ specified baud rate

  //challenge introduction message
  delay(100);
  Serial.write("[+] Sending encrypted data...stand by...");
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:


  //flag part 1
  char flagString0[] = "Flag{uart_";
  int flagLength0 = strlen(flagString0);
  
  int encodedLength0 = Base64.encodedLength(flagLength0);
  char encodedFlag0[encodedLength0 + 1];
  Base64.encode(encodedFlag0, flagString0, flagLength0);

  //flag part 2
  char flagString1[] = "encoded_co";
  int flagLength1 = strlen(flagString1);

  int encodedLength1 = Base64.encodedLength(flagLength1);
  char encodedFlag1[encodedLength1 + 1];
  Base64.encode(encodedFlag1, flagString1, flagLength1);

  //flag part 3
  char flagString2[] = "mmunication}";
  int flagLength2 = strlen(flagString2);

  int encodedLength2 = Base64.encodedLength(flagLength2);
  char encodedFlag2[encodedLength2 + 1];
  Base64.encode(encodedFlag2, flagString2, flagLength2);

  //Serial.write(encodedFlag); blueprint for sending flag parts

  //encoded noise
  char noise[] = "Bring it aarrooouunnddd town";
  int noiseLen = strlen(noise);
  
  int encodedNoiseLen = Base64.encodedLength(noiseLen);
  char encodedNoise[encodedNoiseLen + 1];
  Base64.encode(encodedNoise, noise, noiseLen);



  Serial.write("[+] Data being sent...");
  delay(30);
  Serial.write("Squidward I used your clarinet to unclog my toilet");
  Serial.write(encodedFlag0);
  Serial.write("Wat?");
  delay(50);
  Serial.write(encodedFlag1);
  Serial.write("Remember, licking doorknobs is illegal on other planets");
  delay(75);
  Serial.write(encodedNoise);
  Serial.write("Squidward I used your clarinet to unclog my toilet");
  Serial.write(encodedFlag2);

}


/*
References

https://docs.arduino.cc/learn/communication/uart/

*/