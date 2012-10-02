#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <string>
#include "Veiculo.h"


void createVehicle_Test() {

    Carro c1(1, "Datsun", "s30z", "RS-30-55", "Sports Coupe");
    Camiao t1(2, "Scania", "650h", "25-AS-94", "Semi");
    Bicicleta b1(3, "Bicla", "Cenas", "666");
    ASSERT_EQUAL(1, c1.getID());
    ASSERT_EQUAL("Datsun", c1.getMarca());
    ASSERT_EQUAL("s30z", c1.getModelo());
    ASSERT_EQUAL("RS-30-55", c1.getMatricula());
    ASSERT_EQUAL("Sports Coupe", c1.getTipo());
    ASSERT_EQUAL("Semi", t1.getCategoria());
    ASSERT_EQUAL("Bicla", b1.getMarca());
    ASSERT_EQUAL("Cenas", b1.getModelo());
    ASSERT_EQUAL("666", b1.getMatricula());
}

void runSuite(){
    cute::suite s;
    //TODO add your test here
    s.push_back(CUTE(createVehicle_Test));
    cute::ide_listener lis;
    cute::makeRunner(lis)(s, "Suite de testes da oficina");
}

int main(){
    runSuite();
    Veiculo v1(1, "Porsche", "964", "QO-60-88");
//    cout << v1;
    return 0;
}



