#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

#define MAX_CHAR 32

//Detyre 1
struct STtimestamp {
    uint8_t day;
    uint8_t month;
    unsigned int year;
    uint8_t hour, min, sec;
    unsigned int msec;
};
struct STmessage {
    unsigned int node_id;
    unsigned int message_id;
    char description[MAX_CHAR];
    struct STtimestamp *timestamp;
};

void GenerateMessage(unsigned int node_id, unsigned int message_id, char description[MAX_CHAR],
                     uint8_t day, uint8_t month, unsigned int year, uint8_t hour, uint8_t min, uint8_t sec,
                     unsigned int msec, struct STtimestamp *timestamp) {
    
    struct STmessage message;
    
    message.node_id = node_id;
    message.message_id = message_id;
    strcpy(message.description, description);
    
    timestamp->day = day;
    timestamp->month = month;
    timestamp->year = year;
    timestamp->hour = hour;
    timestamp->min = min;
    timestamp->sec = sec;
    timestamp->msec = msec;
    
    message.timestamp = timestamp;
}

int main(int argc, char * argv[]) {
    
    //Detyre 1
    struct STtimestamp timestamp;
    
    GenerateMessage(100, 19999, "provimi_ne_programim_sistemor", 24, 8, 2017, 16, 00, 00, 000, &timestamp);
    
    printf("Day: %d\n", timestamp.day);
    printf("Month: %d\n", timestamp.month);
    printf("Year: %d\n", timestamp.year);
    printf("Hour: %d\n", timestamp.hour);
        
    return 0;
}