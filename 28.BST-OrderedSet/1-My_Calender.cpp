#include <iostream>
#include <map>
using namespace std;

class MyCalendar {
private:
    map<int, int> bookings; // Stores {start_time -> end_time}

public:
    MyCalendar() {} // Constructor

    bool book(int start, int end) {
        // Find the first event that starts at or after `start`
        auto next = bookings.lower_bound(start);

        // Check if the new event overlaps with the next event
        if (next != bookings.end() && next->first < end) {
            return false; // ß Overlap detected → Booking rejected
        }

        // Check if the new event overlaps with the previous event
        if (next != bookings.begin()) {  
            auto prevIt = prev(next); // Move iterator one step back
            if (prevIt->second > start) {
                return false; // Overlap detected → Booking rejected
            }
        }

        // ✅ No overlap → Insert the new booking
        bookings[start] = end;
        return true;
    }
};

int main() {
    MyCalendar myCalendar;

    // Test Cases
    cout << myCalendar.book(10, 20) << endl; // Output: 1 (Success)
    cout << myCalendar.book(15, 25) << endl; // Output: 0 (Overlap)
    cout << myCalendar.book(20, 30) << endl; // Output: 1 (Success)

    return 0;
}
