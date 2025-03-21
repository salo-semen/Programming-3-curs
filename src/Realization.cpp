#include "Realization.h"

Realization::~Realization() {
    for (auto& it : allRealty) {
        delete it;
    }
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

void Realization::removeSelectedRow(QTableWidget* table) {
    int selectedRow = table->currentRow();
    if (selectedRow >= 0) {
        table->removeRow(selectedRow);
        allRealty.erase(allRealty.begin() + selectedRow);
    }
}

void Realization::addNewRow(QTableWidget* table) {
    int newRow = table->rowCount();
    table->insertRow(newRow);
    for (int col = 0; col < table->columnCount(); ++col) {
        QTableWidgetItem* item = new QTableWidgetItem("New");
        table->setItem(newRow, col, item);
    }
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