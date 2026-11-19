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

    QStringList units = {"DEMO-01", "DEMO-02", "DEMO-03", "DEMO-04", "DEMO-05", "DEMO-06", "DEMO-07", "DEMO-08"};
    QStringList zones = {"Zone A", "Zone B", "Zone C", "Zone D", "Zone E", "Zone F", "Zone G", "Zone H"};
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

    // Demo-only interaction counter; this is not a hardware multi-touch test.
    static int touchCount = 0;
    connect(ui->btnTestTouch, &QPushButton::clicked, this, [this]() {
        touchCount++;
        ui->btnTestTouch->setText(QString("DEMO INTERACTION (Count: %1)").arg(touchCount));
        ui->lblTouchStatus->setText(QString("Demo UI interaction #%1; no hardware test is performed.").arg(touchCount));
    });

    connect(ui->btnEmergency, &QPushButton::clicked, this, [this]() {
        ui->lblTouchStatus->setText("DEMO ONLY: no MQTT command was sent and no vehicle was stopped.");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
