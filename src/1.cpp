#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Realty.h"
#include "Apartment.h"
#include "VillageHouse.h"
#include <QApplication>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>

class Realization {
public:
    Realization() {};
    Realization(std::string nameFile) {init(nameFile);};
    ~Realization() {
        for (auto& it : allRealty) {
            delete it;
        }
    };
    QTableWidget* createTable();

private:
    std::vector<Realty*> allRealty;
    void init(std::string nameFile);
};

QTableWidget* Realization::createTable() {
    QTableWidget* table = new QTableWidget(allRealty.size(), 6);
    table->setHorizontalHeaderLabels({"Type", "Owner", "Date", "Price", "House/Village", "Number"});

    for (int row = 0; row < table->rowCount(); ++row) {
        std::string line = allRealty[row]->getAll();
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

    return table;
}

void Realization::init(std::string nameFile) {
    std::string line;
    std::ifstream in(nameFile);
    if (in.is_open()) {
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            Realty* ob;
            std::string word;
            iss >> word;
            if (word == "Apartment") {
                ob = new Apartment;
                ob->read(iss);
            } else if (word == "VillageHouse") {
                ob = new VillageHouse;
                ob->read(iss);
            } 
            if (ob != nullptr)
                allRealty.push_back(ob);
        }
    } else {
        std::cout << "File is not exist";
    }
}

int main(int argc, char *argv[]) {
    Realization r("1.txt");

    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("It's your BD");
    window.resize(670, 350);
    
    QVBoxLayout* layout = new QVBoxLayout(&window);
    layout->addWidget(r.createTable());
    window.setLayout(layout);
    
    window.show();

    return app.exec();
}