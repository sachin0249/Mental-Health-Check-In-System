#include <iostream>
using namespace std;

#define SIZE 10

struct Entry {
    int entryID;
    int moodScore;
    int stressLevel;
    string timestamp;
    int next;
};

Entry table[SIZE];

// Initialize table
void init() {
    for(int i = 0; i < SIZE; i++) {
        table[i].entryID = -1;
        table[i].next = -1;
    }
}

// Hash function
int hashFunc(int id) {
    return id % SIZE;
}

// Insert entry
void insertEntry() {
    Entry e;
    cout << "Enter EntryID MoodScore StressLevel Timestamp: ";
    cin >> e.entryID >> e.moodScore >> e.stressLevel >> e.timestamp;
    e.next = -1;

    int index = hashFunc(e.entryID);

    if(table[index].entryID == -1) {
        table[index] = e;
    } else {
        int i = index;

        while(table[i].next != -1)
            i = table[i].next;

        int j;
        for(j = 0; j < SIZE; j++) {
            if(table[j].entryID == -1)
                break;
        }

        if(j == SIZE) {
            cout << "Table Full!\n";
            return;
        }

        table[j] = e;
        table[i].next = j;
    }

    cout << "Entry Added!\n";
}

// Search entry
void searchEntry() {
    int id;
    cout << "Enter Entry ID: ";
    cin >> id;

    int index = hashFunc(id);

    if(table[index].entryID == -1) {
        cout << "Not Found\n";
        return;
    }

    int i = index;
    while(i != -1) {
        if(table[i].entryID == id) {
            cout << "Found:\n";
            cout << "ID: " << table[i].entryID
                 << " Mood: " << table[i].moodScore
                 << " Stress: " << table[i].stressLevel
                 << " Time: " << table[i].timestamp << endl;
            return;
        }
        i = table[i].next;
    }

    cout << "Not Found\n";
}

// Display table
void display() {
    cout << "\nHash Table:\n";
    for(int i = 0; i < SIZE; i++) {
        cout << i << " -> ";
        if(table[i].entryID != -1) {
            cout << table[i].entryID << " (" << table[i].next << ")";
        }
        cout << endl;
    }
}

int main() {
    init();

    int choice;
    do {
        cout << "\n1.Insert\n2.Search\n3.Display\n4.Exit\nChoice: ";
        cin >> choice;

        switch(choice) {
            case 1: insertEntry(); break;
            case 2: searchEntry(); break;
            case 3: display(); break;
        }

    } while(choice != 4);

    return 0;
}
