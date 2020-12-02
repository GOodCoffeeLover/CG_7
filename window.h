#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <vector>
#include <QPainter>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();


private:
    void mousePressEvent(QMouseEvent* m);
    void mouseReleaseEvent(QMouseEvent* m);
    void mouseMoveEvent(QMouseEvent* m);
    void paintEvent(QPaintEvent*);
    void drawBezie(QPainter& , unsigned int);
    QPointF Bezie(double);

    double scale=600.0, xpos=0.0, ypos=0.0;

    QCheckBox *box;
    QSpinBox *aprox;
    QLabel *l_aprox;


    class point{
    public:
        point(int e, double x, double y);
        point(double x, double y);
        point(QPointF);

        ~point();
        void draw(QPainter&);
        bool pressed(QPointF);
        void move(QPointF);
        void set_scale(int e);
        QPointF pos();
    private:
        double x=0, y=0;
        int edge=7;
    };

    std::vector<point> points;
    int pressed_point=-1;
private slots:
    void changed(bool);
    void changed(int);
};
#endif // WINDOW_H
