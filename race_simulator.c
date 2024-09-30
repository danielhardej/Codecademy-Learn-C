#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

// Print functions section
void printIntro() {
  printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");
};

void printCountDown() {
  printf("Racers Ready! In...\n");
  printf("5\n");
  printf("4\n");
  printf("3\n");
  printf("2\n");
  printf("1\n");
  printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %i: ", race.currentLap);
  printf("First place is %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCurrentLapTime(struct RaceCar* raceCar1Ptr, struct RaceCar* raceCar2Ptr) {
  printf("%s current lap time: %i\n", raceCar1Ptr->driverName, raceCar1Ptr->totalLapTime);
  printf("%s current lap time: %i\n", raceCar2Ptr->driverName, raceCar2Ptr->totalLapTime);
}

void printCongratulations(struct Race race) {
  printf("Let's all congratulate %s in the %s race car for an amazing performance!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
  printf("It truly was a great race and everybody have a goodnight!");
}

// Logic functions section
int calculateTimeToCompleteLap() {
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* racePtr, struct RaceCar* raceCar1Ptr, struct RaceCar* raceCar2Ptr) {
  if (raceCar1Ptr->totalLapTime < raceCar2Ptr->totalLapTime) {
    racePtr->firstPlaceDriverName = raceCar1Ptr->driverName;
    racePtr->firstPlaceRaceCarColor = raceCar1Ptr->raceCarColor;
  } else if (raceCar1Ptr->totalLapTime > raceCar2Ptr->totalLapTime) {
    racePtr->firstPlaceDriverName = raceCar2Ptr->driverName;
    racePtr->firstPlaceRaceCarColor = raceCar2Ptr->raceCarColor;
  } else {
    printf("It's a tie! Let's go another lap to determine the winner!\n");
  }
}

void startRace(struct RaceCar* raceCar1Ptr, struct RaceCar* raceCar2Ptr) {
  struct Race race = {
    .numberOfLaps = 5,
    .currentLap = 1,
    .firstPlaceDriverName = "",
    .firstPlaceRaceCarColor = ""
  };

  for (int lap = 0; lap < race.numberOfLaps; lap++) {
    updateRaceCar(raceCar1Ptr);
    updateRaceCar(raceCar2Ptr);
    updateFirstPlace(&race, raceCar1Ptr, raceCar2Ptr);
    printFirstPlaceAfterLap(race);
    printCurrentLapTime(raceCar1Ptr, raceCar2Ptr);
    race.currentLap++; 
  }
  printCongratulations(race);
}

int main() {
	srand(time(0));

  struct RaceCar raceCar1 = {"Dan", "Blue", 0};
  struct RaceCar raceCar2 = {"Anne", "Pink", 0};

  printIntro();
  printCountDown();
  startRace(&raceCar1, &raceCar2);
  
};