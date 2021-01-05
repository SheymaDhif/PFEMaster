#include "arduinoFFT.h"
#include <SoftwareSerial.h>


#define SAMPLES 128             //Must be a power of 2
#define SAMPLING_FREQUENCY 1000 //Hz, must be less than 10000 due to ADC
 
arduinoFFT FFT = arduinoFFT();

unsigned int sampling_period_us;
unsigned long microseconds;

SoftwareSerial ArduinoUno(7, 6); //RX, TX
 
double vReal[SAMPLES];
double vImag[SAMPLES];

int pot = A0;

void setup() {
    Serial.begin(9600);
  //  sampling_period_us = round(1000000*(1.0/SAMPLING_FREQUENCY));
}
 
void loop() {
    /*SAMPLING*/
  /*  for(int i=0; i<SAMPLES; i++)
    {
        microseconds = micros();    //Overflows after around 70 minutes!
     
        vReal[i] = analogRead(0);
        vImag[i] = 0;
     
        while(micros() < (microseconds + sampling_period_us)){
        }
    }*/
 
    /*FFT*/
   /* FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
 
    /*PRINT RESULTS*/
  /*  Serial.println(peak);     //Print out what frequency is the most dominant.
 
    for(int i=0; i<(SAMPLES/2); i++)
    {*/
      int var =25;
        if(ArduinoUno.available() > 0 ){
        ArduinoUno.write(var);
    delay(1000);
  
        }    }
 
        /*View all these three lines in serial terminal to see which frequencies has which amplitudes*/
         //freq_amplitudes
      /*  double freq_amplitudes = (i * 1.0 * SAMPLING_FREQUENCY) / SAMPLES ; */
      /*  Serial.print(freq_amplitudes, 1);
        Serial.print(",");
        //to visualize the bins 
        double bins = vReal[i];
        Serial.println(bins, 1);    //View only this line in serial plotter to visualize the bins
    }*/
   /* // we are going to send the most dominant frequency = peak
   // int var = analogRead(pot);
   int var = 25;


    delay(100);  //Repeat the process every second OR:
    while(1);       //Run code once
}*/
