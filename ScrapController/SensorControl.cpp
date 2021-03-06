#include "SensorControl.h"

void SensorControl::senseOpponent(uint16_t& distances[8]){
    // Get distance from sensor
  //unsigned int distance1 = sensor1.getDist();
  distances[0] = sensor1.getDist();
  distances[1] = sensor2.getDist();
  distances[2] = sensor3.getDist();
  distances[3] = sensor4.getDist();
  distances[4] = sensor5.getDist();
  distances[5] = sensor6.getDist();
  distances[6] = sensor7.getDist();
  distances[7] = sensor8.getDist();
  }

int SensorControl::getLocation( uint16_t& OppR, int OppQ){
  int degrees[8]={0,45,90,135,180,225,270,315};
  // Print minimum IR
  uint16_t min_Dist = 10000;
  uint16_t low_Dist = 10000;
  uint16_t high_Dist = 10000;
  int min_IR = 10;
  int low_IR = 10;
  int high_IR = 10;
    for (int i = 0; i < 8; i++) {
      if(distances[i] < min_Dist){
        min_Dist = distances[i];
        min_IR = i;
        }
      else if(distances[i] > min_Dist){
        high_Dist = distances[i];
        }
      else if (distances[i] < high_Dist){
        low_Dist = distances[i];
        low_IR = i;
        }
    }
  OppR = (min_Dist+low_Dist)/2;
  OppQ = min_IR;
  Serial.println("Distance: ",OppR,"  Angle:" ,OppQ);
  return degrees[OppQ];
}
