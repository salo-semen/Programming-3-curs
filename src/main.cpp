#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Realty.h"
#include "Apartment.h"
#include "VillageHouse.h"
#include "Realization.h"

#include <QApplication>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>




int main(int argc, char *argv[]) {
    Realization r("1.txt");

    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("It's your BD");
    window.resize(670, 400);
    
    QVBoxLayout* mainLayout = new QVBoxLayout(&window);
    QTableWidget* table = r.createTable();
    mainLayout->addWidget(table);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    
    QPushButton* deleteButton = new QPushButton("Delete Selected Row");
    QObject::connect(deleteButton, &QPushButton::clicked, [&r, table]() {
        r.removeSelectedRow(table);
    });
    buttonLayout->addWidget(deleteButton);

    QPushButton* addButton = new QPushButton("Add New Row");
    QObject::connect(addButton, &QPushButton::clicked, [&r, table]() {
        r.addNewRow(table);
    });
    buttonLayout->addWidget(addButton);

    mainLayout->addLayout(buttonLayout);

    window.setLayout(mainLayout);
    
    window.show();

    return app.exec();
}