#define vmin 60                                   // on définit la valeur de la vitesse minimale à 60
#define vmax 200                                  // on définit la valeur de la vitesse minimale à 200

int enA = 10;                                     // ENA sur le PIN10
int in1 = 9;                                      // IN1 sur le PIN9
int in2 = 8;                                      // IN2 sur le PIN8
        
const char MARCHE_AVANT   = 'F';                  // MARCHE_AVANT est une constante
const char MARCHE_ARRIERE = 'B';                  // MARCHE_ARRIERE est une constante

int vitesse;                                      // vitesse est une variable de type int             

void setup() 
{
  pinMode(enA, OUTPUT);                           // ENA est une sortie
  pinMode(in1, OUTPUT);                           // IN1 est une sortie
  pinMode(in2, OUTPUT);                           // IN2 est une sortie
}


void loop() 
{
  change_sens_rotation(MARCHE_AVANT);              // moteur tournera dans un sens

  for(vitesse=vmin ; vitesse<vmax ; vitesse++) {   // incrémentation de vitesse
    change_vitesse(vitesse);                       // moteur accélère jusqu'à atteindre vitesse max
    delay(20);                                     // pause de 20ms lors du changement de vitesse
  }
  
  for(vitesse=vmax ; vitesse>vmin ; vitesse--) {   // décrémentation de vitesse
    change_vitesse(vitesse);                       // moteur décélère
    delay(20);                                     // pause de 20ms lors du changement de vitesse
  }

  change_vitesse(0);                               // moteur s'arrête
  delay(1000);                                     // délai de 1s
  
  change_sens_rotation(MARCHE_ARRIERE);     // moteur tournera dans le sens inverse

  for(vitesse=vmin ; vitesse<vmax ; vitesse++) {   // incrémentation de vitesse
    change_vitesse(vitesse);                       // moteur accélère
    delay(20);                                     // pause de 20ms lors du changement de vitesse
  }
  for(vitesse=vmax ; vitesse>vmin ; vitesse--) {   // décrémentation de vitesse
    change_vitesse(vitesse);                       // moteur décélère    
    delay(20);                                     // pause de 20ms lors du changement de vitesse
  } 
  change_vitesse(0);                               // moteur s'arrête
  delay(1000);                                     // délai de 1s
}

void change_sens_rotation(char SENS_ROTATION)      // fonction changement de sens de rotation du moteur
{
  if(SENS_ROTATION == MARCHE_AVANT) {              // si sens de rotation est MARCHE_AVANT
    digitalWrite(in1, HIGH);                       // IN1 est état haut -> le moteur tourne
    digitalWrite(in2, LOW);                        // IN2 est état bas 
  }  
  if(SENS_ROTATION == MARCHE_ARRIERE) {            // si sens de rotation est MARCHE_ARRIERE       
    digitalWrite(in1, LOW);                        // IN1 est état bas -> le moteur tourne dans le sens inverse
    digitalWrite(in2, HIGH);                       // IN2 est état haut
  }
}

void change_vitesse(int NOUVELLE_VITESSE)          // fonction changement de vitesse de rotation du moteur
{
  analogWrite(enA, NOUVELLE_VITESSE);              // ENA prend la nouvelle valeur de vitesse 
}
