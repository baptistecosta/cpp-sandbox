#include <stdio.h>
#include "core/math/vector.h"
#include "core/container/shared_pointer.h"
#include "core/string.h"

using namespace BCosta::Core;
using namespace BCosta::Core::Container;
using namespace BCosta::Core::Math;

int main() {

    String helloWorld("Hello world!");

    Vector3 arrow(1, 5, 3);

    SharedPtr<int> ptr;

    printf(helloWorld.cStr());

    return 0;
}