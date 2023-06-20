#include <iostream>
#include "polygon.h"
#include "ray.h"

using namespace std;

void printPolygon(const vector<Point>& polygon) {
    for (Point p : polygon) {
        cout << "(" << p.x() <<" "<< p.y() << ")  ";
    }
}

int main()
{
    vector<Polygon> polygons{
                    Polygon(vector<Point> {
                        Point(0, 0),
                        Point(0, 2),
                        Point(2, 2),
                        Point(2, 0)
                    })
                    ,Polygon(vector<Point> {
                        Point(1, 1),
                        Point(1, 3),
                        Point(3, 3),
                        Point(3, 1)
                    })
                    ,Polygon(vector<Point> {
                        Point(3, 3),
                        Point(3, 4),
                        Point(4, 4),
                        Point(4, 3)
                    })
                    ,Polygon(vector<Point> {
                        Point(.5, .5),
                        Point(.5, 1),
                        Point(1, 1),
                        Point(1, .5)
                    })

    };
    vector<Ray> rays {
        Ray (Point(-1,.5),Point(-.5,.5)) ,
        Ray (Point(-1,.5),Point(2,.5)) ,
        Ray (Point(-1,4),Point(-.5,4)),
        Ray (Point(1,1),Point(2,1))
    };

    for (int i = 0; i < rays.size(); ++i) {
        auto rayCrossings = polygons[0].segmentPolygonCrossings(rays[i]);
        cout << "ray " << i << " intersection poinst ";
        for (Point p : rayCrossings) {
            cout << "(" << p.x() <<" "<< p.y() << ")  ";
        }
        if (rayCrossings.empty()) {
            cout << "abscent";
        }
        cout << endl;
    }

    for (int i = 1; i < polygons.size(); ++i) {
        Polygon pol = polygons[0].polygonCollision(polygons[i]);
        cout << "пересечения полигонов c вершинами"  << endl;
        printPolygon(polygons[0].getPoints());
        cout << "  и " << endl;
        printPolygon(polygons[i].getPoints());
        cout <<  endl;
        printPolygon(pol.getPoints());
        if (pol.getPoints().empty()) {
            cout << "отсутствуют";
        }
        cout <<  endl;
    }

    return 0;
}
