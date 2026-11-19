#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // تنظیم جدول لیفتراک‌ها برای مانیتور لمسی بزرگ
    ui->tblFleet->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblFleet->verticalHeader()->setDefaultSectionSize(45); // ارتفاع ردیف مناسب لمس
    ui->tblFleet->setRowCount(8);

    QStringList units = {"FL-101", "FL-102", "FL-103", "FL-104", "FL-105", "FL-106", "FL-107", "FL-108"};
    QStringList zones = {"Warehouse A", "Dock 3", "Paint Shop", "Assembly Line", "E-Coating Bay", "Dock 1", "Yard B", "Cold Store"};
    QStringList bats  = {"94%", "78%", "82%", "45%", "99%", "63%", "31%", "88%"};
    QStringList states = {"Active", "Active", "Charging", "Active", "Active", "Idle", "Warning", "Active"};
    QStringList csqs   = {"-65 dBm", "-70 dBm", "-62 dBm", "-80 dBm", "-59 dBm", "-72 dBm", "-85 dBm", "-68 dBm"};

    for (int i = 0; i < 8; ++i) {
        ui->tblFleet->setItem(i, 0, new QTableWidgetItem(units[i]));
        ui->tblFleet->setItem(i, 1, new QTableWidgetItem(zones[i]));
        ui->tblFleet->setItem(i, 2, new QTableWidgetItem(bats[i]));
        ui->tblFleet->setItem(i, 3, new QTableWidgetItem(states[i]));
        ui->tblFleet->setItem(i, 4, new QTableWidgetItem(csqs[i]));
    }

    // متغیر شمارنده تست لمس
    static int touchCount = 0;
    connect(ui->btnTestTouch, &QPushButton::clicked, this, [this]() {
        touchCount++;
        ui->btnTestTouch->setText(QString("TOUCH DETECTED! Count: %1").arg(touchCount));
        ui->lblTouchStatus->setText(QString("✅ Capacitive Touch Event #%1 Registered!").arg(touchCount));
    });

    connect(ui->btnEmergency, &QPushButton::clicked, this, [this]() {
        ui->lblTouchStatus->setText("⚠️ FLEET HALT BROADCAST SENT VIA MQTT!");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
