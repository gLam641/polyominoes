#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QComboBox;
class QPushButton;
class QGroupBox;
class QLabel;

#include "drawpolycanvas.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

private:
    void createGroupBoxInput();
    void createGroupBoxResults();
    void createGroupBoxAction();

    QGroupBox *hGroupBoxInputs;
    QGroupBox *hGroupBoxActions;
    QGroupBox *hGroupBoxResults;

    QComboBox *cBoxNSquares;  // combo box to choose number of squares
    QPushButton *btnComputePoly;
    QPushButton *btnQuit;
    QLabel *nPolyResult;

    DrawPolyCanvas drawPolyCanvas;

signals:

private slots:
    void slotComputeButton();
};

#endif // WINDOW_H
