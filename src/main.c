#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WINDOW 5


float temp_buffer[WINDOW] = {0};
float volt_buffer[WINDOW] = {0};
int temp_index = 0;
int volt_index = 0;


int overheat_flag = 0;
int voltage_flag = 0;


float get_temperature() {
    return 25 + rand() % 70; // 25°C to 95°C
}


float get_voltage() {
    return 3.0 + (rand() % 40) / 10.0; // 3.0V to 7.0V
}


float moving_average(float new_val, float *buffer, int *index) {
    buffer[*index] = new_val;
    *index = (*index + 1) % WINDOW;

    float sum = 0;
    for (int i = 0; i < WINDOW; i++) {
        sum += buffer[i];
    }

    return sum / WINDOW;
}


void detect_fault(float temp, float volt) {

    char *status = "NORMAL";

    // Overheat
    if (temp > 80) {
        status = "OVERHEAT WARNING";
    }

    // Voltage spike
    if (volt > 5.5) {
        status = "VOLTAGE SPIKE";
    }

    printf("STATUS: %s | ", status);
}

void print_timestamp(int t) {
    printf("[T+%02ds] ", t);
}

int main() {
    srand(time(0));

    int time_counter = 0;

    while (1) {
        float temp = get_temperature();
        float volt = get_voltage();

        temp = moving_average(temp, temp_buffer, &temp_index);
        volt = moving_average(volt, volt_buffer, &volt_index);

        print_timestamp(time_counter);
        printf("TEMP: %.2fC | VOLT: %.2fV | ", temp, volt);

        detect_fault(temp, volt);

        printf("\n");

        sleep(1);
        time_counter++;
    }

    return 0;
}