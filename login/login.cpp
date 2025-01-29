#include "login.h"
#include "./ui_login.h"
#include <string>
#include <QHBoxLayout>
#include <QVBoxLayout>
// #include "methodes"
using namespace std;

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    ui->main_login->setFixedSize(550,570);
    // 1. Get the central widget (created by Qt Designer)
    QWidget *centralWidget = this->centralWidget();

    // 2. Create layouts with stretch to push the frame to the center
    QVBoxLayout *verticalLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *horizontalLayout = new QHBoxLayout();

    // 3. Add stretchable space around the frame
    verticalLayout->addStretch(); // Top stretch
    horizontalLayout->addStretch(); // Left stretch
    horizontalLayout->addWidget(ui->main_login); // Your frame
    horizontalLayout->addStretch(); // Right stretch
    verticalLayout->addLayout(horizontalLayout);
    verticalLayout->addStretch(); // Bottom stretch

    // 4. Set the layout on the central widget
    centralWidget->setLayout(verticalLayout);
}

login::~login()
{
    delete ui;
}

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}


void login::on_pushButton_clicked()
{
    // use methodes here
    string email = ui->email_in->text().toStdString();
    string password = ui->password_in->text().toStdString();
    // validate email for format : x.@ensia.edu.dz
    // hash password
    // check for (email,pwd.hash()) in database
    // else no ? show_failed in UI
}
