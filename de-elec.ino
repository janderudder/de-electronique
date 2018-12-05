/**
 * Un dé hexadécimal électronique avec
 * un afficheur 7 segments.
 */
#include "SevenSegmentDisplay.hpp"
using SevSeg = SevenSegmentDisplay;

// Broche de lecture logique
const int swPin = 10;

// Etat de la broche
int swState = LOW;
int swRead = LOW;


// Afficheur 7 segments
SevSeg sevSeg(SevSeg::COMCATHODE);



void setup()
{
  // Broche d'entrée pour le bouton poussoir
  pinMode(swPin, INPUT);
  
  // Connection des broches de l'arduino
  // aux broches de l'afficheur.
  sevSeg.initPin(SevSeg::SEG_A, 7);
  sevSeg.initPin(SevSeg::SEG_B, 8);
  sevSeg.initPin(SevSeg::SEG_C, 6);
  sevSeg.initPin(SevSeg::SEG_D, 4);
  sevSeg.initPin(SevSeg::SEG_E, 2);
  sevSeg.initPin(SevSeg::SEG_F, 5);
  sevSeg.initPin(SevSeg::SEG_G, 3);
  sevSeg.initPin(SevSeg::SEG_P, 9);

  // Initialisation d'un affichage éteint
  sevSeg.clear();

  Serial.begin(9600);

  delay(1800);
  Serial.println("Serial port is up...");
  delay(500);
}


void loop()
{
  swRead = digitalRead(swPin);

  if (swRead != swState) {
    swState = swRead;
    Serial.print("State changed to ");
    Serial.println(swState);
  }

  delay(100); 
}
