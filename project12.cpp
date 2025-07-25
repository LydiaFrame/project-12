/*
    Author: Lydia Frame
    Date: July 25, 2025
    Description:
        This C++ application creates a vector of 50 Circle objects, each with a randomly 
        generated integer radius. It displays the unsorted list, then sorts the Circles 
        using a templated two-parameter insertion sort (based on Section 7.2.1 of the textbook), 
        and finally displays the sorted list.
*/

#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iomanip>  // For formatting output

// ----------------------------
// Circle class definition
// ----------------------------
class Circle {
private:
    int radius;

public:
    // Constructor with default value
    Circle(int r = 0) : radius(r) {}

    // Getter for radius
    int getRadius() const {
        return radius;
    }

    // Method to print circle information
    void display() const {
        std::cout << "Circle(radius = " << radius << ")\n";
    }

    // Overload < operator to compare Circles by radius
    bool operator<(const Circle& other) const {
        return this->radius < other.radius;
    }
};

// ----------------------------
// Insertion Sort Template
// ----------------------------
// Two-parameter version as described in section 7.2.1 of the textbook
template<typename Iterator>
void insertionSort(Iterator begin, Iterator end) {
    for (Iterator i = begin + 1; i < end; ++i) {
        auto key = *i;
        Iterator j = i;
        while (j > begin && key < *(j - 1)) {
            *j = *(j - 1);
            --j;
        }
        *j = key;
    }
}

// ----------------------------
// Display Circles in a vector
// ----------------------------
void displayCircles(const std::vector<Circle>& circles, const std::string& title) {
    std::cout << "\n" << title << "\n";
    std::cout << "--------------------------\n";
    for (const auto& c : circles) {
        c.display();
    }
}

// ----------------------------
// Main function
// ----------------------------
int main() {
    // Seed random number generator with current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<Circle> circles;

    // Generate 50 Circle objects with random radii between 1 and 100
    for (int i = 0; i < 50; ++i) {
        int radius = 1 + std::rand() % 100;
        circles.emplace_back(radius);
    }

    // Display the unsorted list
    displayCircles(circles, "Unsorted Circles");

    // Sort using insertion sort template
    insertionSort(circles.begin(), circles.end());

    // Display the sorted list
    displayCircles(circles, "Sorted Circles");

    return 0;
}