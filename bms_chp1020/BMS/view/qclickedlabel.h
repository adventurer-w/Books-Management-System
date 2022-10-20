#ifndef QCLICKEDLABEL_H
#define QCLICKEDLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
class QClickedLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QClickedLabel(QWidget *parent = nullptr);

signals:
    void clicked();
private:
    void mouseReleaseEvent(QMouseEvent* ev)
    {
        if (ev != nullptr && ev->button() == Qt::LeftButton)
        {
            emit clicked();    //emit signal
        }
    }
    void enterEvent(QEvent*)
    {
        setCursor(QCursor(Qt::PointingHandCursor));
    }
    void leaveEvent(QEvent*)
    {
        setCursor(QCursor(Qt::ArrowCursor));
    }

};

#endif // QCLICKEDLABEL_H
