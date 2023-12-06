cmake_minimum_required(VERSION 3.24)
project(agenda_gomez C)

set(CMAKE_C_STANDARD 11)

add_executable(agenda_gomez main.c affichage.h models.h fonction.h fonction.c models.c affichage.c timer.c)
