# Crossy road using threepp

## Description
This code creates a simple 3D scene using the Three++ library. It includes a player sphere, a grid helper, and multiple randomly generated obstacles that move towards the player. The player can be moved around using mouse controls, and a text display at the top of the canvas shows the amount of time that has elapsed.

## Dependencies
- Three++ library
- ImGui library

## Usage
1. Ensure that the Three++ and ImGui libraries are properly installed and linked.
2. Compile the code.
3. Run the executable file.

## Functionality
The program initializes a 3D scene and adds a player sphere, a grid helper, and multiple randomly generated obstacles. The player can be moved around using mouse controls. The obstacles move towards the player, and the player must avoid them. The text display at the top of the canvas shows the amount of time that has elapsed.

## How to Customize
To customize the scene, the following can be modified:
- The size and color of the grid helper can be adjusted by modifying the parameters in the `GridHelper::create` function.
- The number of obstacles generated can be adjusted by modifying the for-loop parameters in the `main` function.
- The speed at which the obstacles move can be adjusted by modifying the value in the `group1->position.z += 5.f *dt;` line in the `canvas.animate` function.
- The text displayed can be modified by changing the string passed to the `textHandle.setText` function in the `canvas.animate` function.
