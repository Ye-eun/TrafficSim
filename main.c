#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <malloc/malloc.h>
#include <math.h>
#include "TrafficSim.h"
#include "csvparser.h"
#include "ll.h"
#include "SimulationParameters.h"

/*
works to do
1. longitudinal movement function
 --> based on CTM function
 --> function
    --> input : (N, maxN, vf, maxY, w{wave speed}, dt)
    --> output : y {array}

2. lateral movement function
 --> LC probability : logit function (~ speed diff. / vf)

3. vehicle transmission function
*/

int loop_limit;
int current_simtime;

int external_y = 10;
int valY_inlink[400];


int main() {
    // read data
    loop_limit = 100;

    // run simulation_step
    SimulationStep(loop_limit, &mylink, &mynode, &myveh);

    printf("Elapsed Time: %f\n", endTime - startTime);
    return 0;
}

void SimulationStep(int loop_limit, link l[], node n[], vehicle v[]) {
    // int tid = threadIdx.x;
    // int i = blockIdx.x * blockDim.x + tid;

    for (int current = 0; current < loop_limit; current++) {

        for (int cur_link = 0; cur_link < link_length; cur_link++) {
            // read vehicle from connectCell (i'th vehicle in global memory )
            //NextCoonectionCell에서 signal 정보 읽어오기 => link

            //Previous ConnectionCell에서 Input 읽어오기 => link

            // 각 링크l[i]별로 Mandatory LC 처리
            Evaluate_MLC(&l[cur_link]);

            // 각 링크l[i]별로 Optioanl LC 처리
            Evaluate_OLC(&l[cur_link]);

            //각 링크l[i]별로 CTM SIM 처리
            CFsim(&l[cur_link]);

            // 링크별 결과 전송

            //전체 차량들에대해 셀이동 처리
            Vehicle_Move(&l[cur_link]);

            // write vehicle in connectCell
        }
    }
}


void CFsim(link *l) {
//    double w = 15;  //wave speed
//
//    double L = l->CellLength;
//
//    int NoCell = NOCELL;
//    int NoLane = NOLANE;
//
//    double Lmin = l.Vf / 3.6 * dt;
//
//
//    for (int cell = 0; cell < NOCELL; cell++) {
//        for (int lane = 0; lane < NOLANE; lane++) {
//            l->Y[cell][lane] = MIN(MIN(Lmin / L[cell] * l.N[cell][lane], l.maxY[cell][lane]), MIN(l.maxY[cell][lane + 1], w * dt / L * (l.maxN[cell][lane] - l.N[cell][lane]));
//            // moveforward flag update
//
//        }
//    }

}


void Evaluate_MLC(link *l) {

    // --------------------------------------------------------------------------------------------------
    // Mandatory Lane Change 대상 차량 선정 및 차량 데이터베이스에 차로변경 플래그(veh.lanechange) 설정
    // --------------------------------------------------------------------------------------------------
//    for (int cell = 0; cell < NOCELL; cell++) {
//        for (int lane = 0; lane < NOLANE; lane++) {
//            for (int i = 0; i < 20; i++) {
//                vehicle veh = l->veh[cell][lane][i]; // 차량데이터 가지고 오기
//
//                int TargetLaneLeft = veh.targetLane1[veh.currentLinkOrder];  // 타겟 레인 하한 가지고 오기
//                int TargetLaneRight = veh.targetLane2[veh.currentLinkOrder];  // 타겟 레인 상한 가지고 오기
//
//                if (veh.currentLane < TargetLaneLeft) {
//                    veh.lanechange = 1;
//                    // l.LC_Left[veh.currentCell][veh.currentLane]=1
//                }     // 오른쪽으로 차로 변경이 필요
//                else if (veh.currentLane > TargetLaneRight) {
//                    veh.lanechange = -1;
//                    // l[veh.currentLink].LC_Righft[veh.currentCell][veh.currentLane]=1;}  // 왼쪽으로 차로 변경이 필요
//                    else (veh.lanechange = 0;)
//                }
//            }
//        }
//        // --------------------------------------------------------------------------------------------------
//    }
    return;
}

void Evaluate_OLC(link *l) {

    // --------------------------------------------------------------------------------------------------
    // Optional Lane Change 대상 차량 선정 및 차량 데이터베이스에 차로변경 플래그(veh.lanechange) 설정
    // --------------------------------------------------------------------------------------------------

    for (int cell = 0; cell < NOCELL; cell++) {
        for (int lane = 1; lane < NOLANE; lane++) {
            // l.LC_Left[cell][lane] += round((l.V[cell][lane - 1] - l.V[cell][lane]) / l.Vf);
        }
    }
    return;

}

void Vehicle_Move(link *l) {
//
//    for (int vehID = 0; vehID < sizeof(v); vehID++) {
//        vehcle veh = v[vehID]; // 차량데이터 베이스에서  가지고 오기
//        // --------------------------------------------------------------------------------------------------
//        // 차로변경이 있는 경우 차량의 현재 Cell과 링크를 업데이트 한다.
//        //--------------------------------------------------------------------------------------------------
//        if (veh.Lanechange = +1) {}    // Move vehicle to left lane
//        if (veh.Lanechange = -1) {}    // Move vehicle to Right lane
//        if (veh.moveforward = 1) {}     // Move vehicle to frent cell
//
//        // --------------------------------------------------------------------------------------------------
//
//
//        // --------------------------------------------------------------------------------------------------
//        // 차량이 다음셀로 전진하는 경우 차량의 현재 Cell과 링크를 업데이트 한다.
//        //--------------------------------------------------------------------------------------------------
//        if (veh.moveForward == 1) {
//
//            //글로벌 메모리의 Vehicle 정보를 업데이트
//
//            if ((veh.currentCell == l[veh.currentLink].NOLANE)) {
//                //connection Cell로 바꾸기
//
//                // 현재 셀이 링크의 마지막셀인 경우
//                veh.currentLinkOrder++; // Path의 현재 링크 순서를 1 증가
//                veh.currentLink = veh.path[currentLinkOrder];
//                veh.currentCell = 0;  // Cell position을 링크 시작점으로 \
//
//
//            } else {
//                // N Update
//
//
//                veh.currentCell++;   //마지막 셀이 아니면, 다음 셀로 차량을 옮긴다.
//            }
//        }
//    }
//    // --------------------------------------------------------------------------------------------------
    return;
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

double get_time_ms() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}