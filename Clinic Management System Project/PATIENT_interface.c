#include "PATIENT_interface.h"
#include "STD_TYPES.h"
#include <stdio.h>
#include <string.h>

static Patient_t Patients_List[MAX_PATIENTS_SLOTS];

void PATIENT_voidInit() {
  // ADD CODE
  // handle any error inputs
  for (u16 i = 0; i < MAX_PATIENTS_SLOTS; i++)
    Patients_List[i].isUsed = 0;
}

u8 PATIENT_u8ViewPatientInfoByID(u8 *id) {
  // ADD CODE
  // handle any error inputs
  return 0;
}

s64 PATIENT_s64GetPatientIndexById(u8 *id) {
  // ADD CODE
  // handle any error inputs
  for (u16 i = 0; i < MAX_PATIENTS_SLOTS; i++) {
    if (!Patients_List[i].isUsed)
      continue;
    if (!strcmp(Patients_List[i].id, id))
      return i;
  }

  return -1;
}

u8 *PATIENT_u8PGetPatientID(Patient_t *Patient) {
  // ADD CODE
  // handle any error inputs
  return Patient->id;
}

u8 PATIENT_u8AddPatientInfo(u8 *id, u8 *name, u32 age, u8 gender) {
  // ADD CODE
  // handle any error inputs
  for (u16 i = 0; i < MAX_PATIENTS_SLOTS; i++) {
    if (Patients_List[i].isUsed)
      continue;
    strcpy(Patients_List[i].id, id);
    strcpy(Patients_List[i].name, name);
    Patients_List[i].age = age;
    Patients_List[i].gender = gender;
    Patients_List[i].isUsed = 1;
    return i + 1; // returns size of occupied slots
  }
  return 0;
}

u8 PATIENT_u8EditPatientInfo(u8 *id, u8 *name, u32 age, u8 gender) {
  // ADD CODE
  // handle any error inputs
  return 0;
}

Patient_t *PATIENT_xPGetPatientFromID(u8 *id) {
  // ADD CODE
  // handle any error inputs
  s64 index = PATIENT_s64GetPatientIndexById(id);
  if (index == -1)
    return NULL;
  return (Patients_List + index);
}
