cmake_minimum_required(VERSION 3.10)
project(TrafficSim C)

set(CMAKE_C_STANDARD 99)

add_executable(TrafficSim main.c TrafficSim.h csvparser.c csvparser.h SimulationParameters.h)