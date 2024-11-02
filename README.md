# IIT-H Hospital Helpdesk Portal

## Project Overview
This Helpdesk Portal for IIT-H Hospital manages directories for doctors and patients, an appointment scheduling system, and feedback management to streamline hospital operations and improve patient care.

## Features

### 1. Directory of Doctors
   - **Details**: Includes Name, Department, Employment Type, Availability, Feedback Rating, Phone, Email, and Patient Count.
   - **Functions**:
     - **Add/Remove/Update Doctor**: Maintains sorted entries and prevents duplicates.
     - **Search**: Allows search by any field (e.g., Name, Phone).
  
### 2. Directory of Patients
   - **Details**: Includes Name, Department, Employment Type, Roll No., Phone, Email, Address, Appointment History, and Ethics Rating.
   - **Functions**:
     - **Add/Remove/Update Patient**: Sorted entries, no duplicates, and tracks past appointments.
     - **Search**: Search by any field (e.g., Name, Phone).

### 3. Appointment Management System
   - **Functions**:
     - **Record Visit**: Logs doctor-patient interactions.
     - **Schedule Appointment**: Checks doctor availability and schedules earliest available slots.
     - **View History**: Shows past appointments for specific doctors.

### 4. Feedback Management System
   - **Functions**:
     - **Collect Feedback**: Updates doctor ratings based on verified patient feedback.
     - **Ethics Rating**: Allows doctors to report unethical behavior, adjusting patient ethics rating.

## Key Methods

- **Add/Remove/Update Entry**: Maintains alphabetical order and prevents duplicates.
- **Search**: Flexible search across multiple fields.
- **Appointment Scheduling**: Allocates earliest available slots.
- **Feedback Update**: Validates appointments before adjusting ratings.

