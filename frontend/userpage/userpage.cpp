#include "userpage.h"
#include "./ui_userpage.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

userpage::userpage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userpage)
{
    ui->setupUi(this);
    // i freaking hate GUI making ....

    // 1. Ensure your main window has a central widget with a vertical layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);  // Crucial for full width

    // 2. Configure your existing QFrame "epic"
    ui->header_search->setParent(centralWidget);  // Ensure proper parent
    ui->header_search->setFixedHeight(80);        // Set your desired height
    ui->header_search->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // 3. Create layout for centering content INSIDE the frame
    QHBoxLayout *frameInnerLayout = new QHBoxLayout(ui->header_search);

    frameInnerLayout->addStretch();
    // Add your existing content here (what should be centered)
    frameInnerLayout->addWidget(ui->search_in);
    frameInnerLayout->addWidget(ui->search_but);
    frameInnerLayout->addStretch();

    // 4. Add to main layout (FIRST item to keep at top)
    mainLayout->addWidget(ui->header_search);
    mainLayout->addStretch(1);  // Push everything else below


    setupsearch();
    displaybooks();



}


void userpage::setupsearch(){
    ui->search_in->setPlaceholderText("Search for book");
};

// this thing will resevce somthing from the server and display it here
void displaybooks(){
    // gets the first 5 books in the database of the books
    return;
}

userpage::~userpage()
{
    delete ui;
}
