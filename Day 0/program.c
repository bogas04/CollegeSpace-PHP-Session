#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char boolean;

#define BUFFER_SIZE 100
#define true 1
#define false 0

char peopleIKnow[BUFFER_SIZE][BUFFER_SIZE];                  
int totalPeopleIKnow = 0;

// Prototypes
void init();              // Initializes `peopleIKnow`

boolean isKnown(char*);   // Checks if I know given person

int main(void) {

  FILE* fptr = fopen("names.txt", "r");

  char* name = (char*) malloc(BUFFER_SIZE);        

  float knowledge = 0.0f;

  int knownPeople = 0, totalPeople = 0;

  boolean doIKnowThisPerson = false;

  // Initialize names
  init();

  // For each person in names.txt
  while(fgets(name, BUFFER_SIZE, fptr)) {
    totalPeople++;

    // If I know this person
    if((doIKnowThisPerson = isKnown(name)) == true) {
      knownPeople++;
    }

    // Print result
    printf("I %s know %s \n", doIKnowThisPerson ? "do" : "don't", name);
  }

  // Etiquettes
  fclose(fptr);
                  
  // If names.txt has some names  
  if(totalPeople != 0) {
    knowledge = 100 * (knownPeople/(1.0 * totalPeople));
  }

  printf("I have %0.2f %% knowledge of people around me.\n", knowledge);

  return 0;
}                 


/*
===================================
  Initializes `peopleIKnow` array  
===================================
*/

void init() {

  FILE* fptr = fopen("peopleiknow.txt", "r");
  char* name = (char*) malloc(BUFFER_SIZE);

  // For each person in peopleiknow.txt
  while(fgets(name, BUFFER_SIZE, fptr)) {
    // Save at totalPeopleIKnow++ index of `peopleIKnow` array
    strcpy(peopleIKnow[totalPeopleIKnow++], name);
  }
  
  // Etiquettes 
  fclose(fptr);
}

/*
============================================
  Searches for given name in `peopleIKnow`  
============================================
*/

boolean isKnown(char* name) {

  int i, result = false;

  for(i = 0; !result && i < totalPeopleIKnow; i++) {
    if(strcmp(name, peopleIKnow[i]) == 0) {
      result = true;
    }
  }

  return result;
}

