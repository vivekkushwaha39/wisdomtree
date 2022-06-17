#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>

using namespace std;
class PointComparator;

class Point
{
    int x;
    int y;
    friend class PointComparator;
public:
    Point(int _x, int _y):x(_x), y(_y)
    {}
    bool operator < (const Point& p1)
    {
        return (p1.x + p1.y) > (x + y);
    }
    void print() 
    {
        cout << " " << x << ", " << y << "\n";
    }
};

class PointComparator 
{
    public:
        bool operator()(const Point &p1, const Point &p2)
        {
            return (p1.x + p1.y) < (p2.x + p2.y);
        }
};



int main(int argc, char const *argv[])
{
    std::vector<Point> vecP1{{1, 5}, {2, 3}};
    std::sort(vecP1.begin(), vecP1.end(), PointComparator());
    std::for_each(vecP1.begin(), vecP1.end(), [](Point &p)
                  { p.print(); });

    return 0;
}
