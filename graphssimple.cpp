#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int DestinationVertexID;
    int weight;
    Edge()
    {
    }
    Edge(int destVID, int w)
    {
        DestinationVertexID = destVID;
        weight = w;
    }
    void setEdgeValues(int destVID, int w)
    {
        DestinationVertexID = destVID;
        weight = w;
    }
    void setWeight(int w)
    {
        weight = w;
    }
    int getDestinationVertexID()
    {
        return DestinationVertexID;
    }
    int getWeight()
    {
        return weight;
    }
};

class Vertex
{
public:
    int id;
    string name;
    list<Edge> edgelist;
    Vertex()
    {
        id = 0;
        name = "";
    }
    Vertex(int iid, string sname)
    {
        id = iid;
        name = sname;
    }
    int getID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    void setID(int iid)
    {
        id = iid;
    }
    void setName(string sname)
    {
        name = sname;
    }
    list<Edge> getEdgeList()
    {
        return edgelist;
    }
    void printEdgelist()
    {
        cout << "[";
        for (auto it = edgelist.begin(); it != edgelist.end(); it++)
        {
            cout << it->getDestinationVertexID() << "(" << it->getWeight() << ") -->";
        }
        cout << "]" << endl;
    }
};

class Graph
{
public:
    vector<Vertex> vertices;
    Vertex getID(int vid)
    {
        Vertex temp;
        for (int i = 0; i < vertices.size(); i++)
        {
            temp = vertices.at(i);
            if (temp.getID() == vid)
            {
                return temp;
            }
        }
        return temp;
    }
    bool checkIfVertexExistByID(int vid)
    {
        bool flag = false;
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getID() == vid)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
    bool checkIfEdgeExistByID(int fromVertex, int toVertex)
    {
        Vertex v = getID(fromVertex);
        list<Edge> e;
        e = v.getEdgeList();
        bool flag = false;
        for (auto it = e.begin(); it != e.end(); it++)
        {
            if (it->getDestinationVertexID() == toVertex)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
    void addVertex(Vertex newVertex)
    {
        bool check = checkIfVertexExistByID(newVertex.getID());
        if (check == true)
        {
            cout << "Vertex already exists." << endl;
        }
        else
        {
            vertices.push_back(newVertex);
            cout << "Vertex added successfully" << endl;
        }
    }
    void updateVertex(int oldvid, string vname)
    {
        bool check = checkIfVertexExistByID(oldvid);
        if (check == true)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).getID() == oldvid)
                {
                    vertices.at(i).setName(vname);
                    break;
                }
            }
        }
        cout << "Vertex updated successfully" << endl;
    }
    void addEdgeByID(int fromVertex, int toVertex, int weight)
    {
        bool check1 = checkIfVertexExistByID(fromVertex);
        bool check2 = checkIfVertexExistByID(toVertex);
        if ((check1 && check2) == true)
        {
            bool check3 = checkIfEdgeExistByID(fromVertex, toVertex);
            if (check3 == true)
            {
                cout << "Edge Between " << getID(fromVertex).getName() << "(" << fromVertex << ") and " << getID(toVertex).getName() << "(" << toVertex << ") already exists." << endl;
            }
            else
            {
                for (int i = 0; i < vertices.size(); i++)
                {
                    if (vertices.at(i).getID() == fromVertex)
                    {
                        Edge e(toVertex, weight);
                        vertices.at(i).edgelist.push_back(e);
                    }
                    else if (vertices.at(i).getID() == toVertex)
                    {
                        Edge e(fromVertex, weight);
                        vertices.at(i).edgelist.push_back(e);
                    }
                }
                cout << "Edge Between " << fromVertex << "and " << toVertex << "created." << endl;
            }
        }
        else
        {
            cout << "Invalid Vertex ID entered." << endl;
        }
    }
    void updateEdgeByID(int fromVertex, int toVertex, int newWeight)
    {
        bool check = checkIfEdgeExistByID(fromVertex, toVertex);
        if (check == true)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).getID() == fromVertex)
                {
                    for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                    {
                        if (it->getDestinationVertexID() == toVertex)
                        {
                            it->setWeight(newWeight);
                            break;
                        }
                    }
                }
                else if (vertices.at(i).getID() == toVertex)
                {
                    for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                    {
                        if (it->getDestinationVertexID() == fromVertex)
                        {
                            it->setWeight(newWeight);
                            break;
                        }
                    }
                }
            }
            cout << "Edge Weight updated successfully" << endl;
        }
        else
        {
            cout << "Edge between " << getID(fromVertex).getName() << "(" << fromVertex << ") and " << getID(toVertex).getName() << "(" << toVertex << ") Doesn't Exist" << endl;
        }
    }
    void deleteEdgeByID(int fromVertex, int toVertex)
    {
        bool check = checkIfEdgeExistByID(fromVertex, toVertex);
        if (check == true)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).getID() == fromVertex)
                {
                    for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                    {
                        if (it->getDestinationVertexID() == toVertex)
                        {
                            vertices.at(i).edgelist.erase(it);
                            break;
                        }
                    }
                }
                if (vertices.at(i).getID() == toVertex)
                {
                    for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                    {
                        if (it->getDestinationVertexID() == fromVertex)
                        {
                            vertices.at(i).edgelist.erase(it);
                            break;
                        }
                    }
                }
            }
            cout << "Edge Between " << fromVertex << " and " << toVertex << " Deleted Successfully." << endl;
        }
    }
    void deleteVertexByID(int vid)
    {
        int vIndex = 0;
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getID() == vid)
            {
                vIndex = i;
            }
        }
        for (int i = 0; i < vertices.size(); i++)
        {
            for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
            {
                if (it->getDestinationVertexID() == vid)
                {
                    vertices.at(i).edgelist.erase(it);
                    break;
                }
            }
        }
        vertices.erase(vertices.begin() + vIndex);
        cout << "Vertex Deleted Successfully" << endl;
    }
    void getAllNeighboursByID(int vid)
    {
        cout << getID(vid).getName() << " (" << getID(vid).getID() << ") -->";
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getID() == vid)
            {
                cout << "[";
                for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                {
                    cout << it->getDestinationVertexID() << "(" << it->getWeight() << ") -->";
                }
                cout << "]";
            }
        }
    }
    void printGraph()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            Vertex temp = vertices.at(i);
            cout << temp.getName() << " (" << temp.getID() << ") -->";
            temp.printEdgelist();
        }
    }
};
int main()
{
    int option, id1, id2, w;
    Graph g;
    string sname;
    bool check;
    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Update Vertex" << endl;
        cout << "3. Delete Vertex" << endl;
        cout << "4. Add Edge" << endl;
        cout << "5. Update Edge" << endl;
        cout << "6. Delete Edge" << endl;
        cout << "7. Check if 2 Vertices are Neigbors" << endl;
        cout << "8. Print All Neigbors of a Vertex" << endl;
        cout << "9. Print Graph" << endl;
        cout << "10. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        Vertex v1;

        switch (option)
        {
        case 0:

            break;

        case 1:
            cout << "Add Vertex Operation -" << endl;
            cout << "Enter ID :";
            cin >> id1;
            cout << "Enter Name :";
            cin >> sname;
            v1.setID(id1);
            v1.setName(sname);
            g.addVertex(v1);

            break;

        case 2:
            cout << "Update Vertex Operation -" << endl;
            cout << "Enter State of Vertex to update :";
            cin >> id1;
            cout << "Enter Name :";
            cin >> sname;
            g.updateVertex(id1, sname);

            break;

        case 3:
            cout << "Delete Vertex Operation -" << endl;
            cout << "Enter ID of Vertex to Delete : ";
            cin >> id1;
            g.deleteVertexByID(id1);

            break;

        case 4:
            cout << "Add Edge Operation -" << endl;
            cout << "Enter ID of Source Vertex: ";
            cin >> id1;
            cout << "Enter ID of Destination Vertex: ";
            cin >> id2;
            cout << "Enter Weight of Edge: ";
            cin >> w;
            g.addEdgeByID(id1, id2, w);

            break;

        case 5:
            cout << "Update Edge Operation -" << endl;
            cout << "Enter ID of Source Vertex: ";
            cin >> id1;
            cout << "Enter ID of Destination Vertex: ";
            cin >> id2;
            cout << "Enter UPDATED Weight of Edge: ";
            cin >> w;
            g.updateEdgeByID(id1, id2, w);

            break;

        case 6:
            cout << "Delete Edge Operation -" << endl;
            cout << "Enter ID of Source Vertex: ";
            cin >> id1;
            cout << "Enter ID of Destination Vertex: ";
            cin >> id2;
            g.deleteEdgeByID(id1, id2);

            break;

        case 7:
            cout << "Check if 2 Vertices are Neigbors -" << endl;
            cout << "Enter ID of Source Vertex: ";
            cin >> id1;
            cout << "Enter ID of Destination Vertex: ";
            cin >> id2;
            check = g.checkIfEdgeExistByID(id1, id2);
            if (check == true)
            {
                cout << "Vertices are Neigbors (Edge exist)";
            }
            else
            {
                cout << "Vertices are NOT Neigbors (Edge does NOT exist)";
            }

            break;

        case 8:
            cout << "Print All Neigbors of a Vertex -" << endl;
            cout << "Enter ID of Vertex to fetch all Neigbors : ";
            cin >> id1;
            g.getAllNeighboursByID(id1);
            break;

        case 9:
            cout << "Print Graph Operation -" << endl;
            g.printGraph();

            break;
        case 10:
            system("clear");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
        cout << endl;

    } while (option != 0);
    return 0;
}