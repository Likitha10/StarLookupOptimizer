# StarLookupOptimizer

This project focuses on efficiently storing and querying a database of stars, optimized for devices with constrained memory and processing power. The implementation leverages a spherical grid with hashing to enable fast lookups of stars within 10 degrees of a given 3D vector.

## Key Features
- **Efficient Spatial Querying**: Finds stars within 10 degrees of a given 3D vector using optimized algorithms.
- **Memory Efficiency**: Employs compact data structures to ensure minimal memory usage.
- **Scalable Design**: Handles databases with 10,000 stars distributed across a spherical grid.
- **C Implementation**: Provides an optimized C program with modular functions.

## Repository Contents
- **`report.pdf`**: Detailed explanation of the algorithm, database design, and calculations.
- **`vectors_within_10_degrees.c`**: C implementation of the algorithm, including optimized data structures and functions.
- **`README.md`**: Overview of the project (this file).

## Algorithm Overview
1. **Database Design**:
   - The celestial sphere is divided into 648 grid cells (18 latitude x 36 longitude divisions), each representing a specific region.
   - A hash table maps grid cells to the stars they contain, minimizing memory overhead.
2. **Query Process**:
   - Convert the query vector's Cartesian coordinates to spherical coordinates to locate the relevant cell.
   - Include neighboring cells in the search to ensure coverage of the 10-degree range.
   - Calculate the angular distance using the dot product and filter stars within 10 degrees.
3. **Optimizations**:
   - Precompute cosine values for 10 degrees.
   - Minimize redundant calculations by storing intermediate results.

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/StarLookupOptimizer.git
   ```
2. Compile the C code:
   ```bash
   gcc -o star_database vectors_within_10_degrees.c -lm
   ```
3. Run the executable with test inputs:
   ```bash
   ./star_database
   ```
