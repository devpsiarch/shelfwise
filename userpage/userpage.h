#ifndef USERPAGE_H
#define USERPAGE_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class userpage;
}
QT_END_NAMESPACE

class userpage : public QMainWindow
{
    Q_OBJECT

public:
    userpage(QWidget *parent = nullptr);
    void setupsearch();
    void centerframe();
    void displaybooks();
    ~userpage();

private:
    Ui::userpage *ui;
};
#endif // USERPAGE_H
