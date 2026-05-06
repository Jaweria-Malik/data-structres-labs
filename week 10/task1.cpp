#include <iostream>
using namespace std;

 
class Song {
public:
    int songID;
    string songName;
    float duration;
    Song* next;
    Song* prev;

    Song(int id, string name, float dur) {
        songID = id;
        songName = name;
        duration = dur;
        next = prev = nullptr;
    }
};

 
class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current; // for next/previous navigation

public:
    Playlist() {
        head = tail = current = nullptr;
    }

     
    void addSong(int id, string name, float duration) {
        Song* newSong = new Song(id, name, duration);

        if (!head) {
            head = tail = current = newSong;
        }
        else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

        cout << "Song added successfully!\n";
    }

     
    void deleteSong(string name) {
        if (!head) {
            cout << "Playlist is empty!\n";
            return;
        }

        Song* temp = head;

        while (temp) {
            if (temp->songName == name) {

                
                if (head == tail) {
                    head = tail = current = nullptr;
                }
                 
                else if (temp == head) {
                    head = head->next;
                    head->prev = nullptr;
                }
                 
                else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                 
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }

                if (current == temp)
                    current = temp->next;

                delete temp;
                cout << "Song deleted successfully!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Song not found!\n";
    }

  
    void playNext() {
        if (!current) {
            cout << "Playlist is empty!\n";
            return;
        }

        if (current->next) {
            current = current->next;
            cout << "Now Playing: " << current->songName << endl;
        }
        else {
            cout << "Already at last song!\n";
        }
    }

    
    void playPrevious() {
        if (!current) {
            cout << "Playlist is empty!\n";
            return;
        }

        if (current->prev) {
            current = current->prev;
            cout << "Now Playing: " << current->songName << endl;
        }
        else {
            cout << "Already at first song!\n";
        }
    }

   
    void reversePlaylist() {
        if (!head) return;

        Song* curr = head;
        Song* temp = nullptr;

        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp)
            head = temp->prev;

        cout << "Playlist reversed!\n";
    }

 
    void display() {
        if (!head) {
            cout << "Playlist is empty!\n";
            return;
        }

        Song* temp = head;

        cout << "\n--- Playlist ---\n";
        while (temp) {
            cout << temp->songID << " | "
                << temp->songName << " | "
                << temp->duration << " mins\n";
            temp = temp->next;
        }
    }
};


 
int main() {

    Playlist p;

    p.addSong(1, "Shape of You", 4.2);
    p.addSong(2, "Blinding Lights", 3.5);
    p.addSong(3, "Perfect", 4.0);

    p.display();

    cout << "\n-- Navigation --\n";
    p.playNext();
    p.playNext();
    p.playPrevious();

    cout << "\n-- Delete Song --\n";
    p.deleteSong("Blinding Lights");
    p.display();

    cout << "\n-- Reverse Playlist --\n";
    p.reversePlaylist();
    p.display();

    return 0;
}