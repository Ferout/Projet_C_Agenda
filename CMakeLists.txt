cmake_minimum_required(VERSION 3.24)
project(agenda_gomez C)

set(CMAKE_C_STANDARD 11)

add_executable(agenda_gomez main.c affichage.h contact.h fonction.h fonction.c contact.c affichage.c timer.c)
