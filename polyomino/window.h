#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QComboBox;
class QPushButton;
class QGroupBox;

#include "drawpolycanvas.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

private:
    void createGroupBoxInput();
    void createGroupBoxAction();

    QGroupBox *hGroupBoxInputs;
    QGroupBox *hGroupBoxActions;

    QComboBox *cBoxNSquares;  // combo box to choose number of squares
    QPushButton *btnComputePoly;
    QPushButton *btnQuit;

    DrawPolyCanvas drawPolyCanvas;

signals:

private slots:
    void slotComputeButton();
};

#endif // WINDOW_H
