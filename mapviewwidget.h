#ifndef MAPVIEWWIDGET_H
#define MAPVIEWWIDGET_H


#include <QWidget>
#include <QGLWidget>
#include "map.h"
#include <opencv2/opencv.hpp>
#include "rt_local_rcv.h"
#include <QMetaType>
#include <QMutex>
using cv::Mat;

class MapViewWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MapViewWidget(QWidget *parent = 0);
    ~MapViewWidget();
    void localChangedFun(const cv::Mat RT_local_);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void drawFrame(const std::vector<cv::Point3f>& points, const cv::Point3f &rgb);

public slots:
    // slots for xyz-rotation
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);


    // open map file
    void open();

signals:
    // signaling rotation from mouse movement, currently not used.
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);


private:
    void draw();

    Map* map;

    int xRot;
    int yRot;
    int zRot;

    float xTrans;
    float yTrans;

    QPoint lastPos;
    RT_local_Rcv local_rcv;
    cv::Mat RT_local;
    volatile bool local_changed;
    QMutex local_Mutex;
};

#endif // MAPVIEWWIDGET_H
