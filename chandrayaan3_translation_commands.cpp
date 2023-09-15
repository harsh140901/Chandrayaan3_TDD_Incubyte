#include <bits/stdc++.h>
using namespace std;

class SpaceCraft
{

public:
    void forward(int &x, int &y, int &z, char &dir, char com)
    {
        if (dir == 'N')
            y++;
        else if (dir == 'S')
            y--;
        else if (dir == 'E')
            x++;
        else if (dir == 'W')
            x--;
        else if (dir == 'U')
            z++;
        else
            z--;
    }

    void backward(int &x, int &y, int &z, char &dir, char com)
    {
        if (dir == 'N')
            y--;
        else if (dir == 'S')
            y++;
        else if (dir == 'E')
            x--;
        else if (dir == 'W')
            x++;
        else if (dir == 'U')
            z--;
        else
            z++;
    }

};

int main()
{

    int initialX, initialY, initialZ;
    char initialDirection;

    cout << "Enter initial X coordinate: ";
    cin >> initialX;
    cout << "Enter initial Y coordinate: ";
    cin >> initialY;
    cout << "Enter initial Z coordinate: ";
    cin >> initialZ;
    cout << "Enter initial direction (N, S, E, W, U, D): ";
    cin >> initialDirection;

    vector<char> command;
    cout << "To stop input enter '/' :" << endl;
    while (true)
    {
        char com;
        cout << "Enter commands: " << endl;
        cin >> com;

        if (com == '/')
        {
            break; // Stop input when "/" is entered
        }

        command.push_back(com);
    }

    SpaceCraft chandrayan;
    char tempdir = initialDirection;

    for (int i = 0; i < command.size(); i++)
    {
        if (command[i] == 'f')
            chandrayan.forward(initialX, initialY, initialZ, initialDirection, command[i]);
        else if (command[i] == 'b')
            chandrayan.backward(initialX, initialY, initialZ, initialDirection, command[i]);
       
    }

    cout << "Final position will be : " << initialX << " " << initialY << " " << initialZ << endl;
    cout << "Final direction of Chandrayaan : " << initialDirection << endl;

    return 0;
}
