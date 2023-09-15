#include <bits/stdc++.h>
using namespace std;

class SpaceCraft
{

public:
    void forward(int &x, int &y, int &z, char &dir, char com)
    {
        // for moving spacecraft in forward direction with respect to current facing direction of spacecraft
        // dir : current direction
        // com : current given command
        
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
        // for moving spacecraft in backward direction with respect to current facing direction of spacecraft
        // dir : current direction
        // com : current given command
        
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

    char left(int &x, int &y, int &z, char &dir, char com, char &tempdir)
    {
        // for changing direction of spacecraft towards left from current facing direction of spacecraft
        // dir : current direction
        // com : current given command
        // tempdir : stores facing direction of spacecraft
        
        if (dir == 'N')
            dir = 'W';
        else if (dir == 'W')
            dir = 'S';
        else if (dir == 'S')
            dir = 'E';
        else if (dir == 'E')
            dir = 'N';
        else if (dir == 'U')
        {
            dir = left(x, y, z, tempdir, com, tempdir);
            tempdir = dir;
        }
        else
        {
            dir = left(x, y, z, tempdir, com, tempdir);
            tempdir = dir;
        }
        return dir;
    }
    char right(int &x, int &y, int &z, char &dir, char com, char &tempdir)
    {
        // for changing direction of spacecraft towards right from current facing direction of spacecraft
        // dir : current direction
        // com : current given command
        // tempdir : stores facing direction of spacecraft

        if (dir == 'N')
            dir = 'E';
        else if (dir == 'W')
            dir = 'N';
        else if (dir == 'S')
            dir = 'W';
        else if (dir == 'E')
            dir = 'S';
        else if (dir == 'U')
        {
            dir = right(x, y, z, tempdir, com, tempdir);
            tempdir = dir;
        }
        else
        {
            dir = right(x, y, z, tempdir, com, tempdir);
            tempdir = dir;
        }
        return dir;
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
        else if (command[i] == 'l')
            chandrayan.left(initialX, initialY, initialZ, initialDirection, command[i], tempdir);
        else if (command[i] == 'r')
            chandrayan.right(initialX, initialY, initialZ, initialDirection, command[i], tempdir);
     
    }

    cout << "Final position will be : " << initialX << " " << initialY << " " << initialZ << endl;
    cout << "Final direction of Chandrayaan : " << initialDirection << endl;

    return 0;
}
