# Rayon

## Description

Rayon is a Raylib abstraction in C++17.

API is currently fully documented and works currently on Raylib4.2 (A specific commit has been attached in the CMakeList.txt to ensure compatibility)

## WIP:

- Our shapes implementation had to be reworked completely so I removed it for now.
- Audio works but could have a better API.
- Vr is not encapsulated yet.
- It would be nice to have a `rl` or `raylib` namespace for anything in raylib.h like the `std::` namespace
- Builder pattern could be added for a lot of the encapsulations! (I really love this design pattern)
- Wiki with examples
- Transforming VectorX to RVectorX and adding implicit cast operator `operator VectorX()`

## Disclaimer:

Even though everything is not encapsulated yet, you can still use C style code for anything that is missing or added recently.

## Authors:

- Mattis DALLEAU (@HelifeWasTaken)
- Raphael Salaverria (@Tinoss)
- Alexis Cheron (@norech)
- Nicolas Salimina (@NicolasSalimina)
- Lenny Garnier (@GarnierLenny)
- Luidgi Parinet (@Din974)
