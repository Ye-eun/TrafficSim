//
// Created by 경민기 on 2018. 4. 9..
//
#include "SimulationParameters.h"


#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define NOLANE 4
#define NOCELL 4
#define VEH_MAX 20

typedef struct {
    int N[NOCELL][NOLANE];  		// 2D Array [NoCell	,NoLane]
    int MaxN[NOCELL][NOLANE];		// 2D Array [NoCell	,NoLane]
    int LC_Left[NOCELL][NOLANE]; 		// 2D Array [NoCell	,NoLane]
    int LC_Right[NOCELL][NOLANE]; 		// 2D Array [NoCell	,NoLane]
    double V[NOCELL][NOLANE];		// 2D Array [NoCell	,NoLane]
    double Y[NOCELL+1][NOLANE];		// 2D Array [NoCell+1	,NoLane]
    double MaxY[NOCELL+1][NOLANE];		// 2D Array [NoCell	,NoLane]
    double CellLength[NOCELL];
    double Vf;// Free flow speed

    // 재고
    int veh[NOCELL+2][NOLANE][VEH_MAX];		// vehID per each cell (include buffer cell)
    int vehLetLC[NOCELL+2][NOLANE][VEH_MAX];
    int vehReftLC[NOCELL+2][NOLANE][VEH_MAX];
    int vehMLC[NOCELL+2][NOLANE][VEH_MAX];
    int vehMoveForward[NOCELL+2][NOLANE][VEH_MAX];


    // 시그널 넣기
    // Vehicle 속성중에서 MLC 관련 속성 넣기
    // 글로벌 메모리를 잘 쓰자 -- 글로벌 메모리에서 링크 MLC 결정을 위한 차량보

    int NextConnectionCell;
    int PreviousConnectionCell;
} link;

typedef struct {
    int nodeID;
    int type;       // intersection, source, sink
    int speedlimit;
    int intersection_type;
    //connection_info
} node;

typedef struct {
    // current position
    int currentLane;
    int currentCell;      // 현재 cell, 링크 시작점이 0,
    int currentLink;      // 현재 링크 ID
    int currentLinkOrder; // path[]에서 현재 링크 순서
    // int distanceToNode;

    int type;

    int MandatoryLC;
    int moveForward;  // 1이면 시뮬레이션 시 다음셀로 차량을 이동할 필요

//	int freeflowspeed;
//	int minSpacing;
//	int reactionTime;
//	int driving_moment;

    int lanechange;  // 1이면 오른쪽으로 차로변경, -1이면 왼쪽으로 변경이 필요

    int path[20];  // Array of Link IDs EX) [15, 17, 19,...,0,0]
    int NoLinksinPath;  //size of array path path[NoLinksinPath]  path 의 데이터 크기
    int targetLane1[20]; // minimum Target Lane  EX) 2  타겟 레인의 하한값 설정
    int targetLane2[20]; // max Target Lane  Ex) 3   타겟 레인 가안 값 설정


} vehicle;

typedef struct {
    int NoLane;
    int fromLink;
    int toLink;
    int connectN[NOLANE + 2];

} cennection_cell;

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
void CFsim(link* l);
void Evaluate_MLC(link *l);
void Evaluate_OLC(link *l);
void Vehicle_Move(link *l);


void SimulationStep(int loop_limit, link *l, node *n, vehicle *v);
double get_time_ms();
int readRoadData();

// time variables
double startTime, endTime;

int dt = 5;     //time step

int maxNconst = 20;
double maxYconst = 1800;
double Vfconst = 50;
double CellLengthconst = 100;
int link_length = 100;

link mylink[] = {

};

node mynode[] = {

};

vehicle myveh[] = {

};
