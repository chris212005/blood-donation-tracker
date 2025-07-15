#include "BloodDonation.h"
#include "VacationAccount.h"
#include "DateUtility.h"
#include <cassert>
#include <iostream>

using namespace std;
int main() {
   
     BloodDonation d1(123456, 45, 150.5, "01/01/2025");
     BloodDonation d2(123456, 45, 150.5, "07/10/2025");
     BloodDonation d3(123456, 45, 150.5, "01/10/2026");  // another 6+ months later
     VacationAccount acc(123456);
     
     // Test 1: Initial balance is 0
     assert(acc.getBalance() == 0.0);
     
     // Test 2: Add first valid donation
     assert(acc.addVacationToAccount(&d1) == true);
     assert(acc.getBalance() == 4.0);
     
     // Test 3: Add second donation (6+ months apart)
     assert(acc.addVacationToAccount(&d2) == true);
     assert(acc.getBalance() == 8.0);
     
     // Test 4: Add third donation (also 6 months apart)
     assert(acc.addVacationToAccount(&d3) == true);
     assert(acc.getBalance() == 12.0);
     
     // Test 5: Reject duplicate-date donation
     BloodDonation sameDay(123456, 45, 150.5, "01/01/2025");
     assert(acc.addVacationToAccount(&sameDay) == false);
     
     // Test 6: Reject too-soon donation (<6 months apart)
     BloodDonation tooSoon(123456, 45, 150.5, "03/01/2025");
     assert(acc.addVacationToAccount(&tooSoon) == false);
     
     // Test 7: Reject invalid ID (not 6 digits)
     BloodDonation invalidID(9999, 45, 150.5, "09/01/2025");
     assert(invalidID.getID() == -1);
     assert(acc.addVacationToAccount(&invalidID) == false);
     
     // Test 8: Reject invalid age
     BloodDonation tooYoung(123456, 18, 150.5, "09/01/2025");
     assert(tooYoung.getAge() == -1);
     assert(acc.addVacationToAccount(&tooYoung) == false);
     
     // Test 9: Reject invalid weight
     BloodDonation tooLight(123456, 45, 90.0, "09/01/2025");
     assert(tooLight.getWeight() == -1);
     assert(acc.addVacationToAccount(&tooLight) == false);
     
     // Test 10: Mismatched ID between account and donation
     BloodDonation differentID(654321, 45, 150.5, "09/01/2025");
     assert(acc.addVacationToAccount(&differentID) == false);
     
     // Print history at the end
     std::cout << "\nDonation History:\n";
     acc.printDonationHistory();
     
     std::cout << "\nAll tests passed successfully.\n";
     return 0;
        
}
     
