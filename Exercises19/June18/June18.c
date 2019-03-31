#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 250

//Detyre 1
int isDivisor(int d, int n, int *nR) {
    *nR = n;
    if ((d % n) == 0) {
        return 1;
    }
    return 0;
}

//Detyre 1.2a
struct STstartTime {
    uint8_t day;
    uint8_t month;
    unsigned int year;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    unsigned int msec;
};

struct STdataStream {
    unsigned int node_id;
    unsigned int stream_id;
    char stream_name[MAX_CHAR];
    struct STstartTime *start_time;
};

//Detyre 1.2b
void scheduleStream(unsigned int node_id, unsigned int stream_id, char stream_name[MAX_CHAR],
                    uint8_t day, uint8_t month, unsigned int year,
                    uint8_t hour, uint8_t min, uint8_t sec, unsigned int msec,
                    struct STdataStream *pStream) {
    
    
    struct STstartTime startTime;
    
    startTime.day = day;
    startTime.month = month;
    startTime.year = year;
    startTime.hour = hour;
    startTime.min = min;
    startTime.sec = sec;
    startTime.msec = msec;
    
    pStream->node_id = node_id;
    pStream->stream_id = stream_id;
    
    strcpy(pStream->stream_name, stream_name);
    pStream->start_time = &startTime;
}

int main(int argc, char *argv[]) {
    
    //Detyre 1
    int lnR;
    printf("A jane te plotepjestueshem 4 dhe 3: %d\n", isDivisor(4, 3, &lnR));
    
    //Detyre 1.2c
    uint8_t node_id = 100;
    uint16_t stream_id = 1024;
    uint8_t day = 30;
    uint8_t month = 9;
    unsigned int year = 2017;
    uint8_t hour = 16;
    uint8_t min = 1;
    uint8_t sec = 26;
    unsigned int msec = 123;
    char stream_name [MAX_CHAR] = "front-camera";
    
    struct STdataStream dataStream;
    
    scheduleStream(node_id, stream_id, stream_name, day, month, year, hour, min, sec, msec,
                   &dataStream);
    
    printf("node_id: %d\n", dataStream.node_id);
    printf("stream_id: %d\n", dataStream.stream_id);
    printf("stream_name: %s\n", dataStream.stream_name);
    printf("start_time: %d.%d.%d %d:%d:%d.%d\n", dataStream.start_time->day, dataStream.start_time->month, dataStream.start_time->year, dataStream.start_time->hour, dataStream.start_time->min, dataStream.start_time->sec, dataStream.start_time->msec);
    
    return 0;
}
