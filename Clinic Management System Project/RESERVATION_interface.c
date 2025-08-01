#include "PATIENT_interface.h"
#include "RESERVATION_interface.h"
#include "STD_TYPES.h"
#include <stdio.h>
#include <string.h>

static u8 reservationTimeStr[MAX_RESERVATIONS_SLOTS][50];
static Reservation_t Reservations_List[MAX_RESERVATIONS_SLOTS];

void RESERVATION_voidInit() {
  strcpy(reservationTimeStr[0], "2pm to 2:30pm");
  strcpy(reservationTimeStr[1], "2:30pm to 3pm");
  strcpy(reservationTimeStr[2], "3pm to 3:30pm");
  strcpy(reservationTimeStr[3], "4pm to 4:30pm");
  strcpy(reservationTimeStr[4], "4:30pm to 5pm");
  // ADD CODE
  // handle any error inputs
  for (u16 i = 0; i < 5; i++) {
    Reservations_List[i].slotReserved = 0;
    Reservations_List[i].Patient = NULL;
  }
}

void RESERVATION_voidViewReservations() {
  // ADD CODE
  // handle any error inputs
  // you must print the id of the patient if the slot is used.
  for (u16 i = 0; i < 5; i++) {
    printf("%s ", reservationTimeStr[i]);
    if (Reservations_List[i].slotReserved) {
      printf("is Reserved to patient with Id: ");
      Patient_t *Patient = Reservations_List[i].Patient;
      printf("%s", Patient->id);
    } else
      printf("is not Reserved");
    printf("\n");
  }
  printf("\n");
}

u8 RESERVATION_u8AddReservation(Patient_t *Patient,
                                RESERVATIONS_SlotsTimes SlotTime) {
  if (Reservations_List[SlotTime - 1].slotReserved)
    return RESERVATION_ADD_SLOT_ERROR;
  Reservations_List[SlotTime - 1].slotReserved = 1;
  Reservations_List[SlotTime - 1].Patient = Patient;
  return RESERVATION_RESERVED;
}

u8 RESERVATION_u8CancelReservation(RESERVATIONS_SlotsTimes SlotTime) {
  if (!Reservations_List[SlotTime - 1].slotReserved)
    return RESERVATION_CANCEL_SLOT_ERROR;
  Reservations_List[SlotTime - 1].slotReserved = 0;
  Reservations_List[SlotTime - 1].Patient = NULL;
  return RESERVATION_UNRESERVED;
}
