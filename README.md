# Week 01: 2D Physics - Elastic Collision & Gravity Engine

## Description
This project is the first entry of my "One Project Every Week" challenge. It is a 2D physics simulator built in C++ using the SDL2 library. The goal was to implement a functional environment where multiple objects interact through elastic collisions and dynamic forces.

## Features
- **Dynamic Circle Collisions**: Real-time detection and impulse resolution.
- **Overlap Correction**: Prevents objects from getting stuck inside each other.
- **Gravity System**: Toggleable vertical and horizontal gravity forces.
- **Air Resistance**: Simulated friction to gradually slow down objects.
- **Cross-Platform**: Compatible with both Linux and Windows.

## Controls
- [J] : Toggle Vertical Gravity (HB)
- [L] : Toggle Horizontal Gravity (GD)
- [K] : Invert Vertical Gravity
- [M] : Invert Horizontal Gravity
- [B] : Toggle All Gravity forces
- [N] : Toggle Air Resistance (Friction)

## Technical Stack
- Language: C++
- Graphics: SDL2
- Math: Linear Algebra (Vectors)
