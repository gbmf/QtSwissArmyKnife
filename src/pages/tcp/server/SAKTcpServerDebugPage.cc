﻿/*
 * Copyright 2018-2020 Qter(qsaker@qq.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 */
#include <QDebug>
#include <QWidget>
#include <QHBoxLayout>

#include "SAKGlobal.hh"
#include "SAKDataStruct.hh"
#include "SAKTcpServerDevice.hh"
#include "SAKTcpServerDebugPage.hh"
#include "SAKTcpServerDeviceController.hh"

SAKTcpServerDebugPage::SAKTcpServerDebugPage(QWidget *parent)
    :SAKDebugPage (SAKDataStruct::DebugPageTypeTCPServer, parent)
{
    mDeviceController = new SAKTcpServerDeviceController(this);
    setWindowTitle(SAKGlobal::debugPageNameFromType(SAKDataStruct::DebugPageTypeTCPServer));
    initializingPage();
}

SAKDebugPageController *SAKTcpServerDebugPage::deviceController()
{
    return mDeviceController;
}

SAKDebugPageDevice* SAKTcpServerDebugPage::device()
{
    SAKTcpServerDevice *device = new SAKTcpServerDevice(this);
    return device;
}
