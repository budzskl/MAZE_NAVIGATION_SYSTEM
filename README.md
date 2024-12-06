# Maze Escape Project

This project implements a maze escape game where players must navigate through either a regular or twisty maze to collect three magical items: a Spellbook, a Potion, and a Wand. 

## Overview

The project consists of a grid-based maze system where each cell can contain magical items and connects to adjacent cells through cardinal directions (North, South, East, West). The goal is to find a valid path through the maze that collects all three required items.

## Components

### Core Classes

- **MazeCell**: Represents a single cell in the maze
  - Contains the item present ("", "Potion", "Spellbook", or "Wand")
  - Maintains pointers to adjacent cells (north, south, east, west)

- **Grid**: A templated class that manages the 2D grid structure
  - Supports dynamic sizing
  - Provides access to individual cells
  - Handles memory management for the grid structure

- **Maze**: Handles maze generation and manipulation
  - Creates both regular (grid-based) and twisty (non-grid) mazes
  - Places items strategically using distance algorithms
  - Generates unique mazes based on user NetID

### Key Files

1. `EscapeTheLabyrinth.h`
   - Contains the main solution logic
   - Defines the path validation function
   - Stores user-specific constants (NetID and solution paths)

2. `grid.h`
   - Implements the Grid template class
   - Handles 2D array management
   - Provides grid access and manipulation functions

3. `maze.h`
   - Contains maze generation algorithms
   - Implements path finding and distance calculations
   - Manages maze structure and item placement

4. Explorer files:
   - `ExploreTheRegularLabyrinth.cpp`: Tests regular maze solutions
   - `ExploreTheTwistyLabyrinth.cpp`: Tests twisty maze solutions

## Usage

1. Set your NetID in `EscapeTheLabyrinth.h`:
```cpp
const string kYourNetID = "your_netid_here";
```

2. Define your solution paths:
```cpp
const string kPathOutOfRegularMaze = "ESSSWENNNEESNWSSES";  // Example path
const string kPathOutOfTwistyMaze = "NSWWEEWNSS";          // Example path
```

3. Navigate using direction characters:
   - 'N': Move North
   - 'S': Move South
   - 'E': Move East
   - 'W': Move West

## Implementation Details

### Path Validation
The `isPathToFreedom` function validates maze solutions by:
1. Tracking collected items
2. Following the provided path
3. Checking for invalid moves
4. Ensuring all items are collected

### Maze Generation
- Regular mazes use a modified Kruskal's algorithm
- Twisty mazes use an Erdos-Renyi random graph model
- Items are placed using Floyd-Warshall shortest paths algorithm

### Memory Management
- Uses smart memory management with proper constructor/destructor patterns
- Prevents memory leaks through careful pointer handling
- Implements proper copy constructors and assignment operators

## Error Handling

The system handles various error conditions:
- Invalid moves (null pointers)
- Out-of-bounds grid access
- Invalid direction characters
- Incomplete item collection

## Tips for Success

1. Map out the maze structure before attempting to solve
2. Track collected items along your path
3. Ensure your path reaches all three required items
4. Verify that all moves are valid (no wall collisions)
5. Test your solution with the provided explorer programs

## Building and Testing

1. Compile all source files
2. Run the appropriate explorer program:
   - `ExploreTheRegularLabyrinth` for grid-based mazes
   - `ExploreTheTwistyLabyrinth` for non-grid mazes
3. Check the output to verify successful escape

The program will output "You escaped!" for valid solutions and "You have not escaped!" for invalid ones.
