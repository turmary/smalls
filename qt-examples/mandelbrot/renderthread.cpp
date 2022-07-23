/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "renderthread.h"

#include <QtWidgets>
#include <cmath>

//! [0]
RenderThread::RenderThread(QObject *parent)
    : QThread(parent)
{
    restart = false;
    abort = false;

    for (int i = 0; i < ColormapSize; ++i)
        colormap[i] = rgbFromWaveLength(380.0 + (i * 400.0 / ColormapSize));
}
//! [0]

//! [1]
RenderThread::~RenderThread()
{
    mutex.lock();
    abort = true;
    condition.wakeOne();
    mutex.unlock();

    wait();
}
//! [1]

//! [2]
void RenderThread::render(double centerX, double centerY, double scaleFactor,
                          QSize resultSize)
{
    QMutexLocker locker(&mutex);

    this->centerX = centerX;
    this->centerY = centerY;
    this->scaleFactor = scaleFactor;
    this->resultSize = resultSize;

    if (!isRunning()) {
        start(NormalPriority);
    } else {
        restart = true;
        condition.wakeOne();
    }
}
//! [2]

#define USING_THREAD 1

#if USING_THREAD
#include <deque>
#include <vector>
#include <thread>
#include <mutex>
#include <functional>
#include <iostream>
using namespace std;

deque<int> potentials;
std::mutex poten_mtx;

struct line_render {
    RenderThread* parent;
    deque<int>* q;
    QImage* image;
    QSize resultSize;
    double scaleFactor;
    double centerX, centerY;
    int MaxIterations, Limit;
    deque<int> valid;
};

int task_render(line_render& lr) {
    int halfWidth = lr.resultSize.width() / 2;
    int halfHeight = lr.resultSize.height() / 2;

    for (;;){
        poten_mtx.lock();

        if (lr.q->empty()) {
            poten_mtx.unlock();
            break;
        }

        int y = lr.q->front();
        lr.q->pop_front();
        poten_mtx.unlock();

        if (lr.parent->restart)
            break;
        if (lr.parent->abort)
            return -1;

        uint *scanLine =
        //  (uint *)(lr.image->bits() + (y + halfHeight) * lr.image->bytesPerLine());
            reinterpret_cast<uint *>(lr.image->scanLine(y + halfHeight));
        double ay = lr.centerY + (y * lr.scaleFactor);
        // std::cout <<*scanLine <<' ' <<qRgb(0,0,0) <<std::endl;

        for (int x = -halfWidth; x < halfWidth; ++x) {
            if (*scanLine != qRgba(0, 0, 0, 0)) {
                scanLine++;
                continue;
            }
            double ax = lr.centerX + (x * lr.scaleFactor);
            double a1 = ax;
            double b1 = ay;
            int numIterations = 0;

            do {
                ++numIterations;
                double a2 = (a1 * a1) - (b1 * b1) + ax;
                double b2 = (2 * a1 * b1) + ay;
                if ((a2 * a2) + (b2 * b2) > lr.Limit)
                    break;

                ++numIterations;
                a1 = (a2 * a2) - (b2 * b2) + ax;
                b1 = (2 * a2 * b2) + ay;
                if ((a1 * a1) + (b1 * b1) > lr.Limit)
                    break;
            } while (numIterations < lr.MaxIterations);

            if (numIterations < lr.MaxIterations) {
                *scanLine++ = lr.parent->colormap[numIterations % lr.parent->ColormapSize];
                // allBlack = false;
            } else {
                *scanLine++ = qRgba(0, 0, 0, 0);
            }
        }
        lr.valid.push_back(y);
    }
    return 0;
}
#endif

//! [3]
void RenderThread::run()
{
    forever {
        mutex.lock();
        QSize resultSize = this->resultSize;
        double scaleFactor = this->scaleFactor;
        double centerX = this->centerX;
        double centerY = this->centerY;
        mutex.unlock();
//! [3]

//! [4]
#if !USING_THREAD
        int halfWidth = resultSize.width() / 2;
#endif
//! [4]//! [5]
        int halfHeight = resultSize.height() / 2;
        QImage image(resultSize, QImage::Format_RGB32);
        memset(image.bits(), '\0', image.sizeInBytes());

        const int NumPasses = 8;
        int pass = 0;
        while (pass < NumPasses) {
            const int MaxIterations = (1 << (2 * pass + 6)) + 32;
            const int Limit = 4;
            bool allBlack = true;

#if USING_THREAD
            poten_mtx.lock();
            potentials.clear();
            for (int y = -halfHeight; y < halfHeight; ++y) {
                potentials.push_back(y);
            }
            poten_mtx.unlock();

            const int cpus = 7;
            std::vector<std::thread> threads;

            line_render line;

            line.parent = this;
            line.q = &potentials;
            line.image = &image;
            line.resultSize = resultSize;
            line.scaleFactor = scaleFactor;
            line.centerX = centerX;
            line.centerY = centerY;
            line.MaxIterations = MaxIterations;
            line.Limit = Limit;

            line_render lines[cpus];
            for (int c = 0; c < cpus; c++) {
                lines[c] = line;
                lines[c].image = new QImage(image);
                threads.push_back(std::thread(task_render, ref(lines[c])));
            }
            for (auto& th: threads) th.join();
            if (restart)
                break;
            if (abort)
                return;

            for (int c = 0; c < cpus; c++) {
                while (!lines[c].valid.empty()) {
                    int yl = lines[c].valid.front();
                    lines[c].valid.pop_front();
                    uint *dest = (uint *)image.scanLine(yl + halfHeight);
                    uint *src  = (uint *)lines[c].image->scanLine(yl + halfHeight);
                    memcpy(dest, src, image.bytesPerLine());
                }
                delete lines[c].image;
            }

            allBlack = false;
#else
            for (int y = -halfHeight; y < halfHeight; ++y) {
                if (restart)
                    break;
                if (abort)
                    return;

                uint *scanLine =
                        reinterpret_cast<uint *>(image.scanLine(y + halfHeight));
                double ay = centerY + (y * scaleFactor);

                for (int x = -halfWidth; x < halfWidth; ++x) {
                    double ax = centerX + (x * scaleFactor);
                    double a1 = ax;
                    double b1 = ay;
                    int numIterations = 0;

                    do {
                        ++numIterations;
                        double a2 = (a1 * a1) - (b1 * b1) + ax;
                        double b2 = (2 * a1 * b1) + ay;
                        if ((a2 * a2) + (b2 * b2) > Limit)
                            break;

                        ++numIterations;
                        a1 = (a2 * a2) - (b2 * b2) + ax;
                        b1 = (2 * a2 * b2) + ay;
                        if ((a1 * a1) + (b1 * b1) > Limit)
                            break;
                    } while (numIterations < MaxIterations);

                    if (numIterations < MaxIterations) {
                        *scanLine++ = colormap[numIterations % ColormapSize];
                        allBlack = false;
                    } else {
                        *scanLine++ = qRgb(0, 0, 0);
                    }
                }
            }
#endif//USING_THREAD

            if (allBlack && pass == 0) {
                pass = 4;
            } else {
                if (!restart)
                    emit renderedImage(image, scaleFactor);
                else
                    break;
//! [5] //! [6]
                ++pass;
            }
//! [6] //! [7]
        }
//! [7]

//! [8]
        mutex.lock();
//! [8] //! [9]
        if (!restart)
            condition.wait(&mutex);
        restart = false;
        mutex.unlock();
    }
}
//! [9]

//! [10]
uint RenderThread::rgbFromWaveLength(double wave)
{
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;

    if (wave >= 380.0 && wave <= 400.0) {
        r = g = b = 1.0;
    } else
    if (wave >= 380.0 && wave <= 440.0) {
        r = -1.0 * (wave - 440.0) / (440.0 - 380.0);
        b = 1.0;
    } else if (wave >= 440.0 && wave <= 490.0) {
        g = (wave - 440.0) / (490.0 - 440.0);
        b = 1.0;
    } else if (wave >= 490.0 && wave <= 510.0) {
        g = 1.0;
        b = -1.0 * (wave - 510.0) / (510.0 - 490.0);
    } else if (wave >= 510.0 && wave <= 580.0) {
        r = (wave - 510.0) / (580.0 - 510.0);
        g = 1.0;
    } else if (wave >= 580.0 && wave <= 645.0) {
        r = 1.0;
        g = -1.0 * (wave - 645.0) / (645.0 - 580.0);
    } else if (wave >= 645.0 && wave <= 780.0) {
        r = 1.0;
    }

    double s = 1.0;
    if (wave > 700.0)
        s = 0.3 + 0.7 * (780.0 - wave) / (780.0 - 700.0);
    else if (wave <  420.0)
        s = 0.3 + 0.7 * (wave - 380.0) / (420.0 - 380.0);

    r = std::pow(r * s, 0.8);
    g = std::pow(g * s, 0.8);
    b = std::pow(b * s, 0.8);
    return qRgb(int(r * 255), int(g * 255), int(b * 255));
}
//! [10]
