// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <QApplication>
#include <QCheckBox>
#include <QDir>
#include <QDockWidget>
#include <QFileInfoList>
#include <QGraphicsBlurEffect>
#include <QHeaderView>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QXmlStreamReader>

#include "common/types.h"
#include "core/file_format/trp.h"

class TrophyViewer : public QMainWindow {
    Q_OBJECT
public:
    explicit TrophyViewer(QString trophyPath, QString gameTrpPath);

    void updateTrophyInfo();

    void updateTableFilters();
    void onDockClosed();
    void reopenLeftDock();

private:
    void PopulateTrophyWidget(QString title);
    void SetTableItem(QTableWidget* parent, int row, int column, QString str);

    QTabWidget* tabWidget = nullptr;
    QStringList headers;
    QString gameTrpPath_;
    TRP trp;
    QLabel* trophyInfoLabel;
    QCheckBox* showEarnedCheck;
    QCheckBox* showNotEarnedCheck;
    QCheckBox* showHiddenCheck;
    QPushButton* expandButton;
    QDockWidget* trophyInfoDock;
    QPushButton* reopenButton;

    std::string GetTrpType(const QChar trp_) {
        switch (trp_.toLatin1()) {
        case 'B':
            return "bronze.png";
        case 'S':
            return "silver.png";
        case 'G':
            return "gold.png";
        case 'P':
            return "platinum.png";
        }
        return "Unknown";
    }
};
