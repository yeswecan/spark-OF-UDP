
#pragma once

typedef struct {
    unsigned char packetType;       // 0 = discovery 1=heartbeat  2=color  3=LFO
    float ofPacketSentOutTime;
    int ofIp;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    int argument1, argument2;             // 0 = instantaneous :) (argument =
    // for type 2 (color) argument1 is transition time and argument2 is nothing
    // for type 3 (LFO) argument1 is rate and 2 is a shape (0 for sine and 255 for saw)
    int packetCount;                // each packet will be sent in order.  maybe we can drop packets that are old, etc.
} ofToSparkyPacket;



//spark send back to OF
typedef struct {
    unsigned long millisRunning;
    float ofPacketSentOutTime;
    int ipSpark;
    float sparkDataFrameRate;               // how many packets per second are we getting
    float missedPacketPerSecond;                  // how many times did we get a packet that was not numerically synchronized.
    float outOfOrderPerSecond;              // how many packets came in a wrong order?
    unsigned char uuid[24];
    
} sparkyToOFPacket;
