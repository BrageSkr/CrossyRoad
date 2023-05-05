# Crossy road using threepp (placeholder content)

## Description

This code creates a simple 3D scene using the Threepp and ImGui libaries. It includes a player sphere, a grid helper,
and multiple randomly generated obstacles The program initializes a 3D scene and adds a player sphere, a grid helper,
and multiple randomly generated obstacles. The player can be moved using the wasd keys, and the obstacles (no hitbox
yet..) will move as a group across the screen.

## Dependencies

- Threepp library
- ImGui library
- Call CMake with `-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake`

## Usage

1. Ensure that the Threepp and ImGui libraries are properly installed and linked.
2. Compile the code.
3. Run the executable file.

## How to play
- You can move the player by using the wasd or arrow keys, and r to reset the position of the player. 
- You earn points by passing a line of obstalces.
- If you collide with an obstacle, your score will be reset,but you can still see your Hi-score from your attempts.
- If you make it to 20 points, the player will reset to the start position, but your score willnot reset. 
- There is also a button for changing the camera position for a harder but more imersive game. 
- You can also change the color of the player, using the imgui element above the camera button. 

### Screenshots
![Demo](doc/screenshots/crossy_road_demo.png)
