Online Voting System

This project is a simple command-line-based online voting system implemented in C. The system allows for voter registration, vote casting, and election results viewing. It features an admin panel for managing the voter list.

Features
Voter Registration: Admin can add voters to the system.
Vote Casting: Registered voters can cast their votes.
Admin Panel: Admin can view and update the voter list.
Election Results: Display the winner based on the votes cast.
Functions
void display(): Displays the list of registered voters.
void add_voter(): Adds a new voter to the system.
void admin_panel(): Provides options for the admin to manage the voter list.
void cast_vote(): Allows a registered voter to cast their vote.
int search(char ad[]): Searches for a voter by Aadhar number.
void winner(): Displays the election results and the winner.
int verify(char ad[]): Verifies if a voter has already cast their vote.
Usage
Compile the code using a C compiler.
Run the executable.
Follow the on-screen instructions to interact with the system.
Admin Panel
The admin panel can be accessed with a password (default: 1234). From the admin panel, you can:

Update the voter list by adding new voters.
Display the current list of voters.
Election Process
Voters need to be pre-registered by the admin.
Voters can cast their vote by verifying their Aadhar number.
Each voter can only vote once.
Election results can be viewed at any time.
Note
This is a simple implementation and does not include advanced security features. It is meant for educational purposes.
