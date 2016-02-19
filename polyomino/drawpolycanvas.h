#ifndef DRAWPOLYCANVAS_H
#define DRAWPOLYCANVAS_H

#include <QWidget>
#include "polyominos.h"

class DrawPolyCanvas : public QWidget {
    Q_OBJECT

public:
    DrawPolyCanvas(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    std::vector<Polyomino> getVPolyN(int nSquares){ return vPolyAll[nSquares - 1]; }

public slots:
    void updatePolynomino(const unsigned int nSquares);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    std::vector<std::vector<Polyomino>> vPolyAll;

};

#endif // DRAWPOLYCANVAS_H
