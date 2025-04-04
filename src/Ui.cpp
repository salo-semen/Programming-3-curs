#include "include/Ui.h"

MainWindow::MainWindow(QWidget *parent, FileModel* f) : QWidget(parent) {
        setWindowTitle("It's your BD");
        fm = f;
}

 MainWindow::~MainWindow() {}

 void MainWindow::remove_selected() {
    int selectedRow = table->currentRow();
    if (selectedRow >= 0) {
        table->removeRow(selectedRow);
        fm->removeSelectedRow(selectedRow);
    }
 }

void MainWindow::drowWindow() {
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(table);

    buttonLayout = new QHBoxLayout(this);

    deleteButton = new QPushButton("Delete Selected Row", this);
    QObject::connect(deleteButton, SIGNAL(clicked()), SLOT(remove_selected()));
    buttonLayout->addWidget(deleteButton);


    addButton = new QPushButton("Add New Row");
    QObject::connect(addButton, &QPushButton::clicked, [this]() {
        int newRow = table->rowCount();
        table->insertRow(newRow);
        for (int col = 0; col < table->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem("New");
            table->setItem(newRow, col, item);
            fm->addNewRow();
        }
    });

    buttonLayout->addWidget(addButton);

    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void MainWindow::createTable() {
    std::vector<Realty*> allRealty = fm->getAllRealy();
    table = new QTableWidget(allRealty.size(), 6);
    table->setHorizontalHeaderLabels({"Type", "Owner", "Date", "Price", "House/Village", "Number"});
    for (int row = 0; row < allRealty.size(); ++row) {
        std::string line = "asdf asdf asdf asdf asd fasd asdg asdf asdfasdfasdfas fasfa s";
        std::cout << line;
        if (row < allRealty.size() && allRealty[row] != nullptr)
            line = allRealty[row]->getAll();

        std::istringstream iss(line);
        for (int col = 0; col < table->columnCount(); ++col) {
            std::string word;
            iss >> word;
            if (word == "Village") {
                std::string t;
                iss >> t;
                word += " " + t;
            }
            QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(word));
            table->setItem(row, col, item);
        }
    }

    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);

}