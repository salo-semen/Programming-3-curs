#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>

#include "FileModel.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent, FileModel* f);
    ~MainWindow();

    void createTable();
    void drowWindow();

private slots:
    void remove_selected();

private:
    QPushButton* deleteButton;
    QPushButton* addButton;
    QTableWidget* table;
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
    FileModel* fm;
    // void deleteRow();
};

// void MainWindow::deleteRow() {
//     int selectedRow = table->currentRow();
//     if (selectedRow >= 0) {
//         table->removeRow(selectedRow);
//         fm.removeSelectedRow(selectedRow);
//     }
// }

#endif // UI_H