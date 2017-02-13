#include "widget.h"
#include "map.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include <QString>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
    //return 0;
}


//#ifdef this_function_is_for_simplifying_map_file
//int main(int argc, char *argv[])
//{
//    using namespace  cv;
//    using namespace std;

//    Map* map = new Map();
//    map->loadFromFile("E:/SourceCode/odoslam_old.map");

//    FileStorage file("E:/SourceCode/MapViewer/MapViewer/odoslam.map", FileStorage::WRITE);

//    file << "KeyFrames" << "[";
//    for(Mat& pose: map->Poses) {
//        file << "{";
//        file << "Pose" << pose;
//        file << "}";
//    }
//    file << "]";
//    file << "MapPoints" << "[";
//    for(Point3f& pt : map->Points) {
//        file << "{";
//        file << "Pos" << pt;
//        file << "}";
//    }
//    file << "]";

//    file.release();

//    delete map;
//    return 0;
//}
//#endif
