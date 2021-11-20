#include <stdio.h>
#include "gtk.h"
#include "battery.h"

int main() {
    int full = energyFullDesign();
    int now = energyNow();

    double percent = (double) now / (double)full * 100;
    
    if(percent < 20.0 && !charging())
        showAlert();

    return 0;
}
