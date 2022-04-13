#include <iostream>
#include "Tests/Tests.h"
#include "UI/UI.h"

int main() {
    Test::testAll();
    UserInterface console;
    console.run();
    return 0;
}
