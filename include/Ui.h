#ifndef UI_H
#define UI_H

#include <QApplication>
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() {};

    void createTable();
    void drowWindow();

private:
    QPushButton* deleteButton;
    QPushButton* addButton;
    QTableWidget* table;
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
    FileModel fm;
};

#endif // UI_H