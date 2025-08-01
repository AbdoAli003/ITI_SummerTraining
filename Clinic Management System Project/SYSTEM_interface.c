#define WIN32_LEAN_AND_MEAN
#include "PATIENT_interface.h"
#include "RESERVATION_interface.h"
#include "STD_TYPES.h"
#include "SYSTEM_interface.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

static System_t MyClinicSystem;
void ClearScreen() {
  HANDLE hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD count;
  DWORD cellCount;
  COORD homeCoords = {0, 0};

  hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hStdOut == INVALID_HANDLE_VALUE)
    return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
    return;
  cellCount = csbi.dwSize.X * csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords,
                                  &count))
    return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount,
                                  homeCoords, &count))
    return;

  /* Move the cursor home */
  SetConsoleCursorPosition(hStdOut, homeCoords);
}
void SYSTEM_voidInit() {
  // ADD CODE INIT The System Parts
  PATIENT_voidInit();
  RESERVATION_voidInit();
  strcpy(MyClinicSystem.password,
         "1234"); // copy the "1234" string to MyClinicSystem.password
  MyClinicSystem.SginType = User;
}
void SYSTEM_voidStartProgram() {
  SYSTEM_voidInit();
  u32 choice;
  u8 Response;
  while (1) {
    ClearScreen();
    printf("\n=== Clinic Reservation System ===\n");
    printf("1. Sign in as Admin\n");
    printf("2. Sign in as User\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) < 1) // to handle scanf errors hint: use it
    {
      scanf("%*[^\n]");
      choice = INVALID_CHOICE;
    }
    if (!SYSTEM_u8CheckNonDigit())
      choice = INVALID_CHOICE;
    switch (choice) {
    case 2:
      SYSTEM_u8SginIn(choice);
      break;
    case 1:
      Response = SYSTEM_u8SginIn(choice);
      if (Response == INVALID_LOGIN) {
        ClearScreen();
        printf("\n===You have used all three trials.have a nice day===\n");
        return;
      }
      SYSTEM_u8AdminIn();
      break;
    case 0:
      printf("Exiting program.\n");
      return;
    default:
      printf("Invalid Input!.");
      Sleep(800);
      break;
    }
  }
}
u8 SYSTEM_u8SginIn(SYSTEM_Sgin_t SginType) {
  // ADD CODE
  // handle any error inputs
  // sign in as Admin or user depending on the arg SginType
  if (SginType == Admin) {
    if (SYSTEM_u8CheckPassword() == VALID_PASSWORD) {
      return VALID_LOGIN;
    }
  }
  if (SginType == User) {
    SYSTEM_u8UserIn();
    return VALID_LOGIN;
  }
  return INVALID_LOGIN;
}
u8 SYSTEM_u8AdminIn() {
  u32 choice;
  u8 Response;

  while (1) {
    ClearScreen();
    printf("\n=== Clinic Reservation System ===\n");
    printf("===          AdminMode        ===\n");
    printf("1. Add patient record\n");
    printf("2. Edit patient record\n");
    printf("3. Book reservation\n");
    printf("4. Cancel reservation\n");
    printf("0. MainMenu\n");
    printf("Enter choice: ");

    // ADD CODE
    // handle any error inputs
    // Use the functions :
    if (scanf("%d", &choice) < 1) {
      scanf("%*[^\n]");
      choice = INVALID_CHOICE;
    }
    // in case user enter digits then non-digit input
    if (!SYSTEM_u8CheckNonDigit()) {
      choice = INVALID_CHOICE;
    }

    switch (choice) {
    case 1:
      SYSTEM_u8AddPatientInfo();
      break;
    case 2:
      SYSTEM_u8EditPatientInfo();
      break;
    case 3:
      SYSTEM_u8AddReservation();
      break;
    case 4:
      SYSTEM_u8CancelReservation();
      break;
    case 0:
      return VALID_LOGIN;
    default:
      printf("Invalid Choice!.");
      Sleep(800);
      break;
    }
  }
  return VALID_LOGIN;
}
u8 SYSTEM_u8CheckPassword() {
  u8 inputPassword[MAX_SYSTEM_PASS_LEN];
  u8 Response;
  Response = INVALID_PASSWORD;
  for (u8 Tests = 0; Tests < MAX_PASSWORD_TESTS; Tests++) {
    ClearScreen();
    printf("\n=== Clinic Reservation System ===\n");
    printf("===          AdminMode        ===\n");
    printf("Enter Password: ");
    scanf("%50s", inputPassword);
    scanf("%*[^\n]"); // flush excessive input.
    if (!strcmp(inputPassword, "1234")) {
      Response = VALID_PASSWORD;
      break;
    }
    printf("Invalid password!.");
    Sleep(800);
  }
  return Response;
}
u8 SYSTEM_u8UserIn() {
  u32 choice;
  u8 Response;
  while (1) {
    ClearScreen();
    printf("\n=== Clinic Reservation System ===\n");
    printf("===          UserMode         ===\n");
    printf("1. View patient record\n");
    printf("2. View today's reservations\n");
    printf("0. MainMenu\n");
    printf("Enter choice: ");
    u8 ret = scanf("%d", &choice);
    if (ret != 1 || (choice != 0 && choice != 1 && choice != 2)) {
      printf("=== Invalid Input! ===");
      scanf("%*[^\n]");
      Sleep(800);
      continue;
    }
    // in case user enter digits then non-digit input
    if (!SYSTEM_u8CheckNonDigit()) {
      printf("Invalid Input!");
      Sleep(800);
      continue;
    }
    switch (choice) {
    case 1:
      SYSTEM_u8DisplayPatientInfo();
      break;
    case 2:
      SYSTEM_voidDisplayReservationInfo();
      break;
    case 0:
      return VALID_LOGIN;
    }
  }
  return VALID_LOGIN;
}
u8 SYSTEM_u8DisplayPatientInfo() {
  // ADD CODE
  // handle any error inputs
  // Display the data in Patients_List using printf
  // user input id with scanf and printf id,name,age,gender
  u8 choice;
  u8 id[MAX_ID_SIZE];
  ClearScreen();
  printf("\n=== Clinic Reservation System ===\n");
  SYSTEM_u8ScanVaildateID(id, NO_ASSIGN);
  while (1) {
    Patient_t *Patient = PATIENT_xPGetPatientFromID(id);
    if (Patient == NULL) {
      printf("Patient with that ID was not found!\n");
      Sleep(800);
      return INVALID_PATIENT_ID;
    }
    ClearScreen();
    printf("\n=== Clinic Reservation System ===\n");
    printf("ID: %s\n", Patient->id);
    printf("Name: %s\n", Patient->name);
    printf("Age: %d\n", Patient->age);
    printf("Gender: ");
    if (Patient->gender == 'M' || Patient->gender == 'm')
      printf("MALE\n");
    else
      printf("FEMALE\n");
    printf("0. Return Back\nEnter Choice: ");
    u8 ret = scanf("%d", &choice);
    if (ret != 1 || choice != 0) {
      printf("Invalid Input!");
      scanf("%*[^\n]");
      Sleep(800);
      continue;
    }
    if (!SYSTEM_u8CheckNonDigit()) {
      printf("Invalid Input!");
      Sleep(800);
      continue;
    }
    return VALID_PATIENT_ID;
  }

  return VALID_PATIENT_ID;
}
void SYSTEM_voidDisplayReservationInfo() {
  // ADD CODE
  // handle any error inputs
  // Display the data in Reservations_List using printf hint: open
  // RESERVATION_interface use RESERVATION_voidViewReservations
  u16 choice;
  while (1) {
    ClearScreen();
    printf("\n=== Clinic Reservation System ===\n");
    RESERVATION_voidViewReservations();
    printf("0. Return Back\nEnter Choice: ");
    u8 ret = scanf("%d", &choice);
    if (ret != 1 || choice != 0) {
      printf("Invalid Input!.");
      scanf("%*[^\n]");
      Sleep(800);
      continue;
    }
    if (!SYSTEM_u8CheckNonDigit()) {
      printf("Invalid Input!");
      Sleep(800);
      continue;
    }
    return;
  }
}
u8 SYSTEM_u8AddPatientInfo() {
  // ADD CODE
  // handle any error inputs
  static u8 counter = 0; // number of occupied patient slots
  if (counter == MAX_PATIENTS_SLOTS) {
    ClearScreen();
    printf("=== No place for another patient ===");
    Sleep(800);
    return ERROR_MAX_PATIENT_CAPACITY;
  }
  u8 id[MAX_ID_SIZE];
  u8 name[MAX_NAME_SIZE];
  u32 age;
  u8 gender;
  ClearScreen();
  printf("\n=== Clinic Reservation System ===\n");
  if (SYSTEM_u8ScanVaildateID(id, ASSIGN) == INVALID_PATIENT_ID)
    return INVALID_PATIENT_ID;
  if (SYSTEM_u8ScanVaildateName(name) == INVALID_PATIENT_NAME)
    return INVALID_PATIENT_NAME;
  if (SYSTEM_u8ScanVaildateAge(&age) == INVALID_PATIENT_AGE)
    return INVALID_PATIENT_AGE;
  if (SYSTEM_u8ScanVaildateGender(&gender) == INVALID_PATIENT_GENDER)
    return INVALID_PATIENT_GENDER;
  counter = PATIENT_u8AddPatientInfo(id, name, age, gender);
  printf("====== Process Done ======\n");
  Sleep(800);
  return VALID_PATIENT_ADD;
}
u8 SYSTEM_u8EditPatientInfo() {
  // ADD CODE
  // handle any error inputs
  u8 id[MAX_ID_SIZE];
  u8 name[MAX_NAME_SIZE];
  u32 age;
  u8 gender;
  ClearScreen();
  printf("\n=== Clinic Reservation System ===\n");
  if (SYSTEM_u8ScanVaildateID(id, NO_ASSIGN) == INVALID_PATIENT_ID)
    return INVALID_PATIENT_ID;
  Patient_t *Patient = PATIENT_xPGetPatientFromID(id);
  if (Patient == NULL) {
    ClearScreen();
    printf("=== Error No patient with that ID ===");
    Sleep(800);
    return INVALID_PATIENT_ID;
  }
  if (SYSTEM_u8ScanVaildateName(name) == INVALID_PATIENT_NAME)
    return INVALID_PATIENT_NAME;
  if (SYSTEM_u8ScanVaildateAge(&age) == INVALID_PATIENT_AGE)
    return INVALID_PATIENT_AGE;
  if (SYSTEM_u8ScanVaildateGender(&gender) == INVALID_PATIENT_GENDER)
    return INVALID_PATIENT_GENDER;
  strcpy(Patient->name, name);
  Patient->age = age;
  Patient->gender = gender;
  printf("====== Process Done ======\n");
  Sleep(800);
  return VALID_PATIENT_EDIT;
}
u8 SYSTEM_u8AddReservation() {
  // ADD CODE
  // handle any error inputs
  u8 id[MAX_NAME_SIZE];
  RESERVATIONS_SlotsTimes SlotTime;
  ClearScreen();
  printf("\n=== Clinic Reservation System ===\n");
  RESERVATION_voidViewReservations();
  if (SYSTEM_u8ScanVaildateID(id, NO_ASSIGN) == INVALID_PATIENT_ID)
    return INVALID_PATIENT_ID;
  Patient_t *Patient = PATIENT_xPGetPatientFromID(id);
  if (Patient == NULL) // if no patient with that ID
  {
    ClearScreen();
    printf("=== No patient with that ID! ===\n");
    Sleep(800);
    return ERROR_PATIENT_ID_NOT_EXIST;
  }
  printf("Enter Time Slot To Book: ");
  u8 ret = scanf("%d", &SlotTime);
  if (ret != 1 || SlotTime < 1 || SlotTime > 5) // Invalid SlotTime
  {
    ClearScreen();
    printf("Invalid Choice!\n");
    Sleep(800);
    return ERROR_RESERVATION_SLOT_NOT_EXIST;
  }
  // handle if user enters non-digit after digits in SlotTime
  if (!SYSTEM_u8CheckNonDigit()) {
    ClearScreen();
    printf("=== Invalid Input ===");
    Sleep(800);
    return ERROR_RESERVATION_SLOT_NOT_EXIST;
  }
  if (RESERVATION_u8AddReservation(Patient, SlotTime) ==
      RESERVATION_ADD_SLOT_ERROR) { // Slot is already reserved
    ClearScreen();
    printf("=== Error This Reservation Already reserved! ===\n");
    Sleep(800);
    return ERROR_RESERVATION_SLOT_NOT_EXIST;
  }

  // Process is success
  printf("====== Process Done ======\n");
  Sleep(800);
  return VALID_RESERVATION_ADD;
}
u8 SYSTEM_u8CancelReservation() {
  // ADD CODE
  // handle any error inputs
  RESERVATIONS_SlotsTimes SlotTime;
  ClearScreen();
  printf("\n=== Clinic Reservation System ===\n");
  RESERVATION_voidViewReservations();
  printf("Enter Time Slot TO free: ");
  u8 ret = scanf("%d", &SlotTime);
  if (ret != 1 || SlotTime < 1 || SlotTime > 5) // Invalid SlotTime
  {
    ClearScreen();
    printf("Invalid Choice!\n");
    scanf("%*[^\n]");
    Sleep(800);
    return ERROR_RESERVATION_SLOT_NOT_EXIST;
  }
  // handle if user enters non-digit after digits in age label
  if (!SYSTEM_u8CheckNonDigit()) {
    ClearScreen();
    printf("=== Invalid Input ===");
    Sleep(800);
    return ERROR_RESERVATION_SLOT_NOT_EXIST;
  }
  // if reservation is already reserved
  if (RESERVATION_u8CancelReservation(SlotTime) ==
      RESERVATION_CANCEL_SLOT_ERROR) {
    ClearScreen();
    printf("=== Error That slot is already free ===");
    Sleep(800);
    return ERROR_RESERVATION_EMPTY;
  }
  printf("====== Process Done ======\n");
  Sleep(800);
  return VALID_RESERVATION_CANCEL;
}
u8 SYSTEM_u8ScanVaildateID(u8 *id, u8 flag) {
  u16 id_len = 0;
  printf("Enter ID: ");
  scanf("%50s", id);
  scanf("%*[^\n]"); // flush excessive input.
  // handle ID length exceeded
  id_len = strlen(id);
  if (id_len >= 50) {
    printf("=== Error Exceeded ID size! try again (max size = 50) === \n");
    Sleep(800);
    return INVALID_PATIENT_ID;
  }

  for (int i = 0; i < id_len; i++) // check if the id has symbols
  {
    if ((id[i] >= '0' && id[i] <= '9') || (id[i] >= 'A' && id[i] <= 'Z') ||
        (id[i] >= 'a' && id[i] <= 'z'))
      continue;
    ClearScreen();
    printf("=== Error The ID should not contain symbols!. try again ===\n");
    Sleep(800);
    return INVALID_PATIENT_ID;
  }
  if (PATIENT_s64GetPatientIndexById(id) != -1 &&
      flag == ASSIGN) { // Searching if ID already exists
    ClearScreen();
    printf("=== Error That ID already exists!. try again. ===\n");
    Sleep(800);
    return INVALID_PATIENT_ID;
  }

  return VALID_PATIENT_ID;
}
u8 SYSTEM_u8ScanVaildateName(u8 *name) {
  printf("Enter name: ");
  scanf("%50s", name);
  scanf("%*[^\n]"); // flush excessive input.

  // handle if name length exceeded
  u16 name_len = strlen(name);
  if (name_len >= 50) {
    ClearScreen();
    printf("Exceeded name size! try again (max size = 50) \n");
    Sleep(800);
    return INVALID_PATIENT_NAME;
  }

  for (int i = 0; i < name_len; i++) {
    if ((name[i] >= 'a' && name[i] <= 'z') ||
        (name[i] >= 'A' && name[i] <= 'Z'))
      continue;
    ClearScreen();
    printf("=== Error Name should contain only alphabetical characters! ===\n");
    Sleep(800);
    return INVALID_PATIENT_NAME;
  }
  return 1;
}
u8 SYSTEM_u8ScanVaildateAge(u32 *age) {
  s32 tmp_age; // to handle negative input
  printf("Enter age: ");
  u8 ret = scanf("%d", &tmp_age);
  if (ret != 1) {
    ClearScreen();
    printf("===Error Invalid Input! ===\n");
    scanf("%*[^\n]"); // flush excessive input.
    Sleep(800);
    return INVALID_PATIENT_AGE;
  }
  // handle if user enters non-digit after digits in age label
  if (!SYSTEM_u8CheckNonDigit()) {
    ClearScreen();
    printf("Invalid Input!");
    Sleep(800);
    return INVALID_PATIENT_AGE;
  }

  // handle age range
  if (tmp_age < 1 || tmp_age > 130) {
    ClearScreen();
    printf("=== Error age out of range 1 -> 130 ===\n");
    Sleep(800);
    return INVALID_PATIENT_AGE;
  }

  *age = tmp_age;

  return 1;
}
u8 SYSTEM_u8ScanVaildateGender(u8 *gender) {
  printf("Enter Gender (M for male, F for female): ");
  scanf(" %c", gender);
  u8 c = getchar();
  if (c != '\n') {
    ClearScreen();
    printf("=== Invalid Input ===\n");
    scanf("%*[^\n]"); // flush excessive input.
    Sleep(800);
    return INVALID_PATIENT_GENDER;
  }
  if (*gender != 'F' && *gender != 'M' && *gender != 'm' && *gender != 'f') {
    ClearScreen();
    printf("=== Invalid Input ===\n");
    Sleep(800);
    return INVALID_PATIENT_GENDER;
  }
  return 1;
}
u8 SYSTEM_u8CheckNonDigit() {
  u8 c;
  u8 counter = 0;
  while ((c = getchar())) // remove excessive input from buffer
  {
    if (c == '\n') // reached the end 'enter key'
    {
      if (counter) // that means there is still another non-digit input in
                   // buffer -> error
        return 0;
      else
        return 1; // the input was valid digits only -> success
    }
    counter++;
  }
  return 1;
}
