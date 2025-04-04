#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "include/Realty.h"
#include "include/Apartment.h"
#include "include/VillageHouse.h"
#include "include/FileModel.h"
#include "include/Ui.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FileModel* r = new FileModel("1.txt");

    MainWindow window(nullptr, r); 

    window.resize(670, 400);
    std::cout << "asdfasdf";
    window.createTable();
    window.drowWindow();
    
    window.show();

    return app.exec();
}