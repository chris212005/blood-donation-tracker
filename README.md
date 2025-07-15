# Blood Donation Tracker 🩸

A C++ project that models blood donations and calculates vacation time based on donation history. Donors accumulate hours if their donations are valid, spaced at least six months apart, and meet eligibility criteria.

---

## ✅ Features

- `BloodDonation` class:
  - Validates ID (6-digit), age (21–65), and weight (≥ 101 lbs)
  - Stores donation date

- `VacationAccount` class:
  - Tracks donation history for a specific donor
  - Adds 4 hours vacation per valid donation
  - Rejects donations that are:
    - Less than 6 months apart
    - On the same day
    - From a mismatched donor

- `DateUtility`:
  - Validates MM/DD/YYYY format
  - Checks if dates are 6+ months apart
  - Compares for same-day duplicates

- `main.cpp` includes:
  - Full unit tests using `assert()`
  - Printout of donation history

---

## 🛠 How to Compile and Run

```bash
g++ -std=c++11 main.cpp BloodDonation.cpp VacationAccount.cpp DateUtility.cpp -o donation
./donation
