﻿/*
 * Copyright 2018-2020 Qter(qsak@foxmail.com). All rights reserved.
 *
 * The file is encoding with utf-8 (with BOM). It is a part of QtSwissArmyKnife
 * project(https://www.qsak.pro). The project is an open source project. You can
 * get the source of the project from: "https://github.com/qsak/QtSwissArmyKnife"
 * or "https://gitee.com/qsak/QtSwissArmyKnife". Also, you can join in the QQ
 * group which number is 952218522 to have a communication.
 */
#include "SAKDebugPage.hh"
#include "SAKChartsManager.hh"
#include "SAKChartsXYSerialWidget.hh"
#include "SAKChartsThroughputWidget.hh"

#include "ui_SAKChartsManager.h"

SAKChartsManager::SAKChartsManager(SAKDebugPage *page, QWidget *parent)
    :QWidget (parent)
    ,mDebugPage (page)
    ,mUi (new Ui::SAKChartsManager)
{
    mUi->setupUi(this);
    mTabWidget = mUi->tabWidget;
    Q_ASSERT_X(page, __FUNCTION__, "The parameter(page) can not be null!");

#if 0
    setAttribute(Qt::WA_DeleteOnClose, true);
#endif

    mThroughputWidget = new SAKChartsThroughputWidget(mDebugPage);
    mTabWidget->addTab(mThroughputWidget, tr("吞吐量"));

    mXYSerialWidget = new SAKChartsXYSerialWidget;
    mTabWidget->addTab(mXYSerialWidget, tr("波形图"));
}

SAKChartsManager::~SAKChartsManager()
{
    delete mUi;
}
