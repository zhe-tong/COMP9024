cmake_minimum_required(VERSION 3.19)
project(lab05 C)

set(CMAKE_C_STANDARD 11)

include_directories(complete_graphs)
include_directories(component_graphs)
include_directories(cyclical_graphs)

add_executable(lab05
        cyclical_graphs/cyclical.c
        cyclical_graphs/graph.c
        cyclical_graphs/graph.h
        cyclical_graphs/graph_driver.c
        cyclical_graphs/lib_graph.h)

add_executable(lab0501
        component_graphs/component.c
        component_graphs/graph.c
        component_graphs/graph.h
        component_graphs/graph_driver.c
        component_graphs/lib_graph.h)

