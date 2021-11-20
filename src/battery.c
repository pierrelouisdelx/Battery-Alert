#include <stdio.h>
#include <string.h>

int energyFullDesign() 
{
    FILE *f;
    
    char *file = "/sys/class/power_supply/BAT0/energy_full_design";
    int energy;

    f = fopen(file, "r");

    fscanf(f, "%d", &energy);
    fclose(f);

    return energy;
}

int energyNow() 
{
    FILE *fp;
    
    char *file = "/sys/class/power_supply/BAT0/energy_now";
    int energy_now;

    fp = fopen(file, "r");

    fscanf(fp, "%d", &energy_now);
    fclose(fp);

    return energy_now;
}

int charging() 
{
    FILE *f;
    
    char *file = "/sys/class/power_supply/BAT0/status";
    char status[15];

    f = fopen(file, "r");

    fscanf(f, "%s", &status);
    fclose(f);
    
    if(strcmp(status, "Charging"))
        return 0;
    return 1;
}
