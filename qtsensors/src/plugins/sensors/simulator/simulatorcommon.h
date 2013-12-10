/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSensors module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef SIMULATORCOMMON_H
#define SIMULATORCOMMON_H

#include <qsensorbackend.h>
#include "qsensordata_simulator_p.h"

class QTimer;

class SimulatorAsyncConnection;

class SensorsConnection : public QObject
{
    Q_OBJECT
public:
    explicit SensorsConnection(QObject *parent = 0);
    virtual ~SensorsConnection();

    static SensorsConnection *instance();
    bool safe() const { return mInitialDataSent; }
    bool connectionFailed() const { return mConnectionFailed; }

signals:
    void setAvailableFeatures(quint32 features);

public slots:
    void setAmbientLightData(const QtMobility::QAmbientLightReadingData &);
    void setLightData(const QtMobility::QLightReadingData &);
    void setAccelerometerData(const QtMobility::QAccelerometerReadingData &);
    void setMagnetometerData(const QtMobility::QMagnetometerReadingData &);
    void setCompassData(const QtMobility::QCompassReadingData &);
    void setProximityData(const QtMobility::QProximityReadingData &);
    void setIRProximityData(const QtMobility::QIRProximityReadingData &);
    void initialSensorsDataSent();
    void slotConnectionFailed();

private:
    SimulatorAsyncConnection *mConnection;
    bool mInitialDataSent;
    bool mConnectionFailed;

public:
    QtMobility::QAmbientLightReadingData qtAmbientLightData;
    QtMobility::QLightReadingData qtLightData;
    QtMobility::QAccelerometerReadingData qtAccelerometerData;
    QtMobility::QMagnetometerReadingData qtMagnetometerData;
    QtMobility::QCompassReadingData qtCompassData;
    QtMobility::QProximityReadingData qtProximityData;
    QtMobility::QIRProximityReadingData qtIRProximityData;
};

class SimulatorCommon : public QSensorBackend
{
public:
    SimulatorCommon(QSensor *sensor);

    void start();
    void stop();
    virtual void poll() = 0;
    void timerEvent(QTimerEvent * /*event*/);

private:
    int m_timerid;
};

#endif

