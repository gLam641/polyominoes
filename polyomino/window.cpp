#include "window.h"
//#include "polyominocontroller.h"
#include <QApplication>
#include <QPushButton>
#include <QGroupBox>
#include <QBoxLayout>
#include <QLabel>
#include <QComboBox>
#include "drawpolycanvas.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    //drawPolyCanvas = new DrawPolyCanvas(parent);

    createGroupBoxInput();
    createGroupBoxAction();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(hGroupBoxInputs);
    mainLayout->addWidget(hGroupBoxActions);

    setLayout(mainLayout);
    setWindowTitle("Polyomino Generator");
}

void Window::createGroupBoxInput(){
    hGroupBoxInputs = new QGroupBox(tr("Inputs"));
    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(new QLabel(tr("Enter the number of Squares: "), this));

    cBoxNSquares = new QComboBox(this);
    //connect(btnQuit, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
    for(int i = 1; i < 9; ++i){
        cBoxNSquares->addItem(QString::number(i));
    }
    layout->addWidget(cBoxNSquares, 0);

    hGroupBoxInputs->setLayout(layout);
}

void Window::createGroupBoxAction(){
    hGroupBoxActions = new QGroupBox(tr("Actions"));
    QHBoxLayout *layout = new QHBoxLayout;

    btnComputePoly = new QPushButton("Compute", this);
    connect(btnComputePoly, SIGNAL(released()), this, SLOT(slotComputeButton()));
    layout->addWidget(btnComputePoly);

    btnQuit = new QPushButton("Quit", this);
    connect(btnQuit, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
    layout->addWidget(btnQuit);

    hGroupBoxActions->setLayout(layout);
}

void Window::slotComputeButton(){
    unsigned int nSquares = cBoxNSquares->currentIndex() + 1;
    drawPolyCanvas.updatePolynomino(nSquares);
    btnComputePoly->setText(QString::number(drawPolyCanvas.getVPolyN(nSquares).size()));
}
