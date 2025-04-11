#include <iostream>
#include <string>
using namespace std;

//initialize the seats array
void SeatFunc(string Seats[8][5]) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 5; col++) {
            Seats[row][col] = char('A' + col) + to_string(row + 1);
        }
    }
}

// print the 2D array
void PrintSeats(string Seats[8][5]) {
    cout << "Current Seats:" << endl;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 5; col++) {
            cout << Seats[row][col] << " ";
        }
        cout << endl;
    }
}

//  seat input from the user
void SeatInput(int &SeatRow, int &SeatColumn) {
    char userInput;

    // Input for Seat Row
    while (true) {
        cout << "Please enter desired seat row (1-8): ";
        cin >> SeatRow;

        if (SeatRow >= 1 && SeatRow <= 8) {
            break; //
        } else {
            cout << "Invalid: Please enter a number between 1 and 8." << endl;
        }
    }

    // Input for Seat Column
    while (true) {
        cout << "Please enter desired seat column in row (A-E): ";
        cin >> userInput;
        userInput = toupper(userInput); // Convert to uppercase

        // Map the input to the SeatColumn variable
        switch (userInput) {
            case 'A':
                SeatColumn = 1;
                break;
            case 'B':
                SeatColumn = 2;
                break;
            case 'C':
                SeatColumn = 3;
                break;
            case 'D':
                SeatColumn = 4;
                break;
            case 'E':
                SeatColumn = 5;
                break;
            default:
                cout << "Invalid: Please enter A, B, C, D, or E." << endl;
                continue; // Repeat the loop for invalid input
        }
        break; // Valid input, exit the loop
    }
}

// Function to get membership status and calculate price
int MembershipStatus() {
    string Membership; //define memebership variable
    int price = 0; // define price variable
    while (true) { // function loop
        cout << "Please enter desired membership (Gold, Silver, None): ";
        cin >> Membership;
        // Convert input to lowercase for case-insensitive comparison
        for (char &c : Membership) {
            c = tolower(c);
        }
        //assign dollar value to price
        if (Membership == "gold") {
            price = 22;
            break;
        } else if (Membership == "silver") {
            price = 20;
            break;
        } else if (Membership == "none") {
            price = 18;
            break;
        } else {
            cout << "Invalid: Please try again." << endl;
        }
    }

    return price;
}

// replace seat with "X" if it's not already filled
void SeatReplacement(int SeatRow, int SeatColumn, string Seats[8][5]) { //parameters in
    if (Seats[SeatRow - 1][SeatColumn - 1] != "X") {
        Seats[SeatRow - 1][SeatColumn - 1] = "X"; // Replace the seat with X
    }
}

double CalculatePercentage(string Seats[8][5]) {
    int TotalSeats = 8 * 5; // Total number of seats in the array
    int Count = 0; // Counter for "X" values

    // Iterate through the array
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 5; col++) {
            if (Seats[row][col] == "X") {
                Count++; // Increment the counter if the seat is "X"
            }
        }
    }

    // Calculate the percentage of "X" values
    double percentage = (static_cast<double>(Count) / TotalSeats) * 100;
    return percentage;
}

int main() { //main function
    //defind variables
    string Seats[8][5];
    int SeatRow, SeatColumn;
    int totalPrice = 0;
    char continueBooking;
    double percentage;

    // start the seats array
    SeatFunc(Seats);

    do {
        // Print the current state of the seats
        PrintSeats(Seats);

        // Get seat input from the user
        SeatInput(SeatRow, SeatColumn);

        // Check if the seat is already taken
        if (Seats[SeatRow - 1][SeatColumn - 1] == "X") {
            cout << "Seat is already taken. Please choose another seat." << endl;
            continue;
        }

        // Get membership status and calculate price
        int price = MembershipStatus();
        totalPrice += price; // Add to the running total

        // Replace the selected seat with "X"
        SeatReplacement(SeatRow, SeatColumn, Seats);



        // Ask the user if they want to book another seat
        cout << "Do you want to book another seat? (Y/N): ";
        cin >> continueBooking;
        continueBooking = toupper(continueBooking); // Convert to uppercase

    } while (continueBooking == 'Y');

    // Display the final state of the seats and the total price
    cout << "Final Seats:" << endl;
    PrintSeats(Seats);
    cout << "Total Price: $" << totalPrice << endl;

    double Percentage = CalculatePercentage(Seats);

            // Output the result
            cout << "Percentage of 'X' values: " << Percentage << "%" << endl;

    return 0;
}
