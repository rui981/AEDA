#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <string>
#include "Vehicle.h"


void createVehicle_Test() {

    Car c1(1, "Datsun", "s30z", "RS-30-55", "Sports Coupe");
    Truck t1(2, "Scania", "650h", "25-AS-94", "Semi");
    Bike b1(3, "Bicla", "Cenas", "666");
    ASSERT_EQUAL(1, c1.getID());
    ASSERT_EQUAL("Datsun", c1.getBrand());
    ASSERT_EQUAL("s30z", c1.getModel());
    ASSERT_EQUAL("RS-30-55", c1.getLicensePlate());
    ASSERT_EQUAL("Sports Coupe", c1.getType());
    ASSERT_EQUAL("Semi", t1.getCategory());
    ASSERT_EQUAL("Bicla", b1.getBrand());
    ASSERT_EQUAL("Cenas", b1.getModel());
    ASSERT_EQUAL("666", b1.getLicensePlate());
}

void runSuite(){
    cute::suite s;
    //TODO add your test here
    s.push_back(CUTE(createVehicle_Test));
    cute::ide_listener lis;
    cute::makeRunner(lis)(s, "Oficina Test Suit");
}

int main(){
    runSuite();
    return 0;
}



