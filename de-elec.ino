/**
 * Un dé hexadécimal électronique avec
 * un afficheur 7 segments.
 */
#include "DisplayModifier.hpp"
#include "SevenSegmentDisplay.hpp"
#include "Clock.hpp"

using D7 = SevenSegmentDisplay;
using ulong = unsigned long;
using time_t = decltype(millis());

const int ledPin = 10;    // Broche permettant la fonction lancé de dé
const int swPin = 11;     // Broche lisant l'appui sur le bouton

// Etat de la broche
int ledPinState = HIGH;


// Afficheur 7 segments
D7 d7(D7::COMCATHODE);

// Modifier
DisplayModifier d7Mod(d7);



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

  // Initialisation d'un affichage éteint
  d7.clear();
  //d7.display(D7::Predef::Val_B);

  // Initialisation de la broche de jeu
  digitalWrite(ledPin, ledPinState);

  //Serial.begin(9600);
  //delay(1800);
  
  randomSeed(analogRead(0));
}


// Clock
Clock clock;
time_t timer = 0;

// Random
int randomNumber;


void loop()
{
  auto loopTime = clock.update(millis()).getTime();

  if (digitalRead(swPin) == HIGH) {
    ledPinState = LOW;
    digitalWrite(ledPin, ledPinState);
    timer = 0;
    randomNumber = random(0, 16);
  }
  
  else {
    timer += loopTime;
    d7.display(randomNumber);
    if (digitalRead(swPin) == LOW) {
      ledPinState = HIGH;
      digitalWrite(ledPin, ledPinState);
    }
  }
  
  delay(16);
}
