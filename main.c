#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <malloc/malloc.h>
#include "TrafficSim.h"
#include "csvparser.h"
#include "ll.h"

lane_cell mydata[] = {
        {1, 1, 1, 1, 60, 1, 1, 1, 1, 1, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {2, 1, 1, 1, 60, 1, 1, 1, 1, 2, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {3, 1, 1, 1, 60, 1, 1, 1, 1, 3, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {4, 1, 1, 1, 60, 1, 1, 1, 1, 4, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {5, 1, 1, 1, 60, 1, 1, 2, 1, 1, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {6, 1, 1, 1, 60, 1, 1, 2, 1, 2, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {7, 1, 1, 1, 60, 1, 1, 2, 1, 3, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {8, 1, 1, 1, 60, 1, 1, 2, 1, 4, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {9, 1, 1, 1, 60, 1, 1, 3, 1, 1, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {10, 1, 1, 1, 60, 1, 1, 3, 1, 2, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {11, 1, 1, 1, 60, 1, 1, 3, 1, 3, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {12, 1, 1, 1, 60, 1, 1, 3, 1, 4, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {13, 1, 1, 1, 60, 1, 1, 4, 1, 1, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {14, 1, 1, 1, 60, 1, 1, 4, 1, 2, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {15, 1, 1, 1, 60, 1, 1, 4, 1, 3, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {16, 1, 1, 1, 60, 1, 1, 4, 1, 4, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},

        {17, 2, 1, 1, 60, 1, 1, 1, 1, 1, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {18, 2, 1, 1, 60, 1, 1, 1, 1, 2, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {19, 2, 1, 1, 60, 1, 1, 1, 1, 3, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {20, 2, 1, 1, 60, 1, 1, 1, 1, 4, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {21, 2, 1, 1, 60, 1, 1, 2, 1, 1, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {22, 2, 1, 1, 60, 1, 1, 2, 1, 2, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {23, 2, 1, 1, 60, 1, 1, 2, 1, 3, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {24, 2, 1, 1, 60, 1, 1, 2, 1, 4, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {25, 2, 1, 1, 60, 1, 1, 3, 1, 1, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {26, 2, 1, 1, 60, 1, 1, 3, 1, 2, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {27, 2, 1, 1, 60, 1, 1, 3, 1, 3, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {28, 2, 1, 1, 60, 1, 1, 3, 1, 4, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {29, 2, 1, 1, 60, 1, 1, 4, 1, 1, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {30, 2, 1, 1, 60, 1, 1, 4, 1, 2, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {31, 2, 1, 1, 60, 1, 1, 4, 1, 3, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {32, 2, 1, 1, 60, 1, 1, 4, 1, 4, 50, 10, 1, 1, 1, 1, 1, 1, 0,
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},

};

        turning_info myturn[] = {
        {1, 4, 1, 2, 1, 1, 30, 0, 0, 30, 0},
        {1, 4, 2, 2, 1, 2, 30, 0, 0, 30, 0},
        {1, 4, 3, 2, 1, 3, 30, 0, 0, 30, 0},
        {1, 4, 4, 2, 1, 4, 30, 0, 0, 30, 0},
};

vehicle myveh[] = {
        {1, 1, 1, 0},
        {1, 1, 1, 5},
        {1, 1, 1, 10},
        {1, 1, 1, 15},
        {1, 1, 1, 20},
        {1, 1, 1, 25},
        {1, 1, 1, 30},
        {1, 1, 1, 35},
        {1, 1, 1, 40},
        {1, 1, 1, 45},
};

int whole_simtime;
int current_simtime;

int external_y = 10;
int valY_inlink[400];


int main() {
    // read data
    whole_simtime = 100;

    for(int i=0; i < 400; i++)
        valY_inlink[i]=1;

    // run simulation_step
    SimulationStep(&mydata, &myturn, &myveh, whole_simtime);

    printf("Elapsed Time: %f\n", endTime - startTime);
    return 0;
}

void SimulationStep(lane_cell lc[], turning_info turn[], vehicle veh[], int simtime) {
    for (int cur_time = 0; cur_time <= simtime; cur_time += 5) {

        // load traffic signal
        for (int ts_cur = 0; ts_cur < sizeof(turn) / sizeof(turning_info); ts_cur++) {
            external_y = 10; // link 1 -> 2 가능한 차량 댓수
        }


        for (int i = 0; i < sizeof(mydata) / sizeof(lane_cell); i++) {

            // load vehicle & check source_node
            // insert car in link1,section1,lane4
            /*
            for (int veh_cur; veh_cur < sizeof(veh) / sizeof(veh[0]); veh_cur++) {

                if (veh[veh_cur].insert_time == cur_time && lc[i].linkID == 1&& lc[i].sectionID == 1 && lc[i].cell_id==4) {
                    lc[i].vehicle_list[0] = veh[veh_cur].veh_id;
                    lc[i].y_in++;
                }
                printf("veh: %d, time:%d", veh[veh_cur].veh_id, veh[veh_cur].insert_time);
            }
             */

            // load previous link veh data
            if (lc[i].sectionID == 1)
                lc[i].y_in = valY_inlink[4*cur_time/5+lc[i].cell_id % 4];
                //lc[i].y_in=1;
            else
                lc[i].y_in=1;
            printf("%d", lc[i].y_in);

#if DEBUG
            for (int i=0; i<4; i++)
                printf("%d ", valY_inlink[i]);
#endif

            // lane: calc n
            lc[i].numberOfVehicle = lc[i].numberOfVehicle + lc[i].y_in;

            // lane: calc speed
            lc[i].speed = 50;

            // lane: calc lane_change
            // go random


            // next lane and connection_info
            if (lc[i].sectionID % 4 != 0) {
                lc[i + 1].y_in = 1;
                lc[i].numberOfVehicle--;
            }
            else    {
                //lc[i].y_in=0;
                valY_inlink[4*cur_time/5+lc[i].cell_id % 4]=1;
                lc[i].numberOfVehicle--;

                //if (lc[i].linkID == 2) {
                //    lc[i].numberOfVehicle--;
                //}
            }



            // check sink_node


            // export n, speed, veh
            //if (lc[i].sectionID == 4) {
            printf("[%d] %d,%d,%d:\t n: %d, speed: %d, y_in:%d\n", cur_time, lc[i].linkID, lc[i].sectionID,
                   lc[i].cell_id,
                   lc[i].numberOfVehicle, lc[i].speed, lc[i].y_in);

            //}

#if DEBUG
            for (int i=0; i<sizeof(valY_inlink)/16; i++)
                printf("%d ", valY_inlink[i]);
            printf("\n");
#endif
        }
    }
}

int readRoadData() {
    int i = 0;
    CsvParser *csvparser = CsvParser_new("/Users/MinGiKYUNG/CLionProjects/TrafficSim/roadnetworks.csv", ",", 1);
    CsvRow *header;
    CsvRow *row;

    header = CsvParser_getHeader(csvparser);
    if (header == NULL) {
        printf("%s\n", CsvParser_getErrorMessage(csvparser));
        return 1;
    }

    // CsvParser_destroy_row(header); -> causes error in current version
    while ((row = CsvParser_getRow(csvparser))) {
        //printf("NEW LINE:\n");
        char **rowFields = CsvParser_getFields(row);
        for (i = 0; i < CsvParser_getNumFields(row); i++) {
            printf("FIELD %d: %s\n", i, rowFields[i]);
            // lane_cell lc
            /*
            switch (i)  {
                case 0:
                    printf("FIELD: %s\n", rowFields[i]);
                case 1:
                    printf("FIELD: %s\n", rowFields[i]);
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
            }*/
        }
        CsvParser_destroy_row(row);
    }
    CsvParser_destroy(csvparser);

    return 0;
}