//
// Created by 경민기 on 2018. 4. 9..
//

#ifndef TRAFFICSIM_TRAFFICSIM_H
#define TRAFFICSIM_TRAFFICSIM_H

typedef struct {
    // 152 byte
    // about link
    int id;
    int linkID;
    int fromNode;
    int toNode;
    int speedlimit;
    int roadlevel;  // 고속국도, 국도, 지방도
    int road_type;

    // about section
    int sectionID;
    int no_lanes;
    int cell_id;

    int speed;
    int numberOfVehicle;
    int length;

    int nextSectionID;
    int startSectionID;
    int endSectionID;
    int distanceToNode;
    int busLane;

    // yin
    int y_in;
    int vehicle_list[20];
    // lane_change
    // int lane_change;             // no need
    // insert vehicle
} lane_cell;


typedef struct {
    int nodeID;
    int type;       // intersection, source, sink
    int speedlimit;
    int intersection_type;
    //connection_info
} node;

/*
typedef struct {
    // current position
    int currentLane;
    int currentSection;
    int currentLink;
    int distanceToNode;

    int type;
    int freeflowspeed;
    int minSpacing;
    int reactionTime;

    int driving_moment;
    int lane_change;
    int path[10];
} vehicle;
*/

typedef struct  {
    int veh_id;
    int type;
    int insert_link;
    int insert_time;
} vehicle;

typedef struct {
    int startLinkID;
    int startSectionID;
    int startLaneID;
    int endLinkID;
    int endSectionID;
    int endLaneID;

    int greenTime;
    int LeftTime;
    int yellowTime;
    int redTime;
    int offset;
} turning_info;


// functions
void SimulationStep(lane_cell c[], turning_info turn[], vehicle veh[], int time);
double get_time_ms();
int readRoadData();

// time variables
double startTime, endTime;

// basic function
double get_time_ms()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

#endif //TRAFFICSIM_TRAFFICSIM_H
