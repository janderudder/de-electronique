/**
 * Un dé hexadécimal électronique 
 * tirant des nombres de 0 à F,
 * avec un afficheur 7 segments.
 */
#include "SevenSegmentDisplay.hpp"

using D7 = SevenSegmentDisplay;
using time_t = decltype(millis());

// Brochage
const int ledPin = 10;    // Broche permettant la fonction lancé de dé
const int swPin = 11;     // Broche lisant l'appui sur le bouton

// Afficheur 7 segments
D7 d7(D7::COMCATHODE);


void setup()
{
  // Broche d'entrée pour le bouton poussoir
  pinMode(ledPin, OUTPUT);
  pinMode(swPin, INPUT);
  
  // Connection des broches de l'arduino
  // aux broches de l'afficheur.
  d7.initPin(D7::Seg_A, 7);
  d7.initPin(D7::Seg_B, 8);
  d7.initPin(D7::Seg_C, 6);
  d7.initPin(D7::Seg_D, 4);
  d7.initPin(D7::Seg_E, 2);
  d7.initPin(D7::Seg_F, 5);
  d7.initPin(D7::Seg_G, 3);
  d7.initPin(D7::Seg_P, 9);
  
  // Initialisation de l'aléatoire  
  randomSeed(analogRead(0));
}



// Random
int randomNumber = 0;


void loop()
{
  if (digitalRead(swPin) == HIGH) {
    digitalWrite(ledPin, LOW);
    randomNumber = random(0xF + 1);
  }
  
  else {
    d7.display(randomNumber);
    if (digitalRead(swPin) == LOW) {
      digitalWrite(ledPin, HIGH);
    }
  }
}
