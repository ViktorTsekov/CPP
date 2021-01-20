#include "MagazineSubscription.h"

int main() {
    Person person("Viktor", "Ivaylov", "Tsekov", 3500.24, 8000.00, "0893284282");
    Date startDate(13, 6, 2020);
    Date expirationDate(20, 6, 2020);
    MagazineSubscription subscription(person, startDate, expirationDate);

    subscription.displayCustomer();
}