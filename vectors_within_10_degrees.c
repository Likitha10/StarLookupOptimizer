
#include <math.h>
#include <stdio.h>

// Function to calculate the dot product of two vectors
float dot_product(float v1[3], float v2[3]) {
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

// Function to calculate the squared magnitude of a vector
float squared_magnitude(float v[3]) {
    return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

// Function to check if two vectors are within 10 degrees of each other
int are_vectors_within_10_degrees(float v1[3], float v2[3]) {
    // Precompute the cosine of 10 degrees to ensure optimization
    const float cos_10_deg = cos(10.0 * M_PI / 180.0);
    
    // Compute the dot product of the two vectors
    float dot = dot_product(v1, v2);
    
    // Compute the squared magnitudes of the vectors
    float mag_v1_sq = squared_magnitude(v1);
    float mag_v2_sq = squared_magnitude(v2);
    
    // Check for zero magnitude to avoid division by zero
    if (mag_v1_sq == 0.0f || mag_v2_sq == 0.0f) {
        return 0;  // Vectors with zero magnitude cannot form a valid angle
    }
    
    // Compute the cosine of the angle between the vectors
    float cos_angle = dot / sqrt(mag_v1_sq * mag_v2_sq);
    
    // Check if the cosine of the angle is greater than or equal to the cosine of 10 degrees
    return cos_angle >= cos_10_deg;
}

// Example 
int main() {
    // Case 1: Vectors exactly aligned (0 degrees)
    float v1[3] = {1.0, 0.0, 0.0};
    float v2[3] = {1.0, 0.0, 0.0};

    if (are_vectors_within_10_degrees(v1, v2)) {
        printf("Case 1: The vectors are within 10 degrees of each other.\n");
    } else {
        printf("Case 1: The vectors are not within 10 degrees of each other.\n");
    }

    // Case 2: Vectors 10 degrees apart
    float v3[3] = {1.0, 0.0, 0.0};
    float v4[3] = {cos(10.0 * M_PI / 180.0), sin(10.0 * M_PI / 180.0), 0.0};

    if (are_vectors_within_10_degrees(v3, v4)) {
        printf("Case 2: The vectors are within 10 degrees of each other.\n");
    } else {
        printf("Case 2: The vectors are not within 10 degrees of each other.\n");
    }

    // Case 3: Vectors less than 10 degrees apart
    float v5[3] = {1.0, 0.0, 0.0};
    float v6[3] = {cos(5.0 * M_PI / 180.0), sin(5.0 * M_PI / 180.0), 0.0};

    if (are_vectors_within_10_degrees(v5, v6)) {
        printf("Case 3: The vectors are within 10 degrees of each other.\n");
    } else {
        printf("Case 3: The vectors are not within 10 degrees of each other.\n");
    }

    // Case 4: Vectors more than 10 degrees apart
    float v7[3] = {1.0, 0.0, 0.0};
    float v8[3] = {cos(15.0 * M_PI / 180.0), sin(15.0 * M_PI / 180.0), 0.0};

    if (are_vectors_within_10_degrees(v7, v8)) {
        printf("Case 4: The vectors are within 10 degrees of each other.\n");
    } else {
        printf("Case 4: The vectors are not within 10 degrees of each other.\n");
    }

    return 0;
}




//Summary of Optimizations:

//The cosine of 10 degrees is precomputed to avoid repetitive calculations.
//Small, specific functions like dot_product and squared_magnitude reducing function call overhead.
//Zero Magnitude check to prevent unnecessary calculations and potential division by zero.
//Single Calculation for Dot Product and Magnitudes to avoid redundant computations.
//Direct Cosine Comparison to simplify the comparison logic, reducing complexity.

