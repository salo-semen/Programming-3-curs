#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Realty.h"
#include "Apartment.h"
#include "VillageHouse.h"
#include "FileModel.h"
#include "Ui.h"

int main(int argc, char *argv[]) {
    FileModel r("1.txt");

    QApplication app(argc, argv);

    MainWindow window;

    window.createTable();
    window.drowWindow();
    
    window.show();

    return app.exec();
}