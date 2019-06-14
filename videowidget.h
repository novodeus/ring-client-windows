/***************************************************************************
 * Copyright (C) 2015-2019 by Savoir-faire Linux                           *
 * Author: Edric Ladent Milaret <edric.ladent-milaret@savoirfairelinux.com>*
 * Author: Andreas Traczyk <andreas.traczyk@savoirfairelinux.com>          *
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation; either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 **************************************************************************/

#pragma once

#include <QWidget>
#include <QPainter>
#include <QMutex>

#include <memory>
#include <array>

#include "lrcinstance.h"

using namespace lrc::api;

class VideoWidget : public QWidget
{
    Q_OBJECT;

public:
    explicit VideoWidget(QWidget* parent = 0);
    ~VideoWidget();
    void connectRendering();
    void setPreviewDisplay(bool display);
    void setIsFullPreview(bool full);
    inline void setResetPreview(bool reset) { resetPreview_ = reset; hasFrame_=false; }
    void setPhotoMode(bool isPhotoMode);
    QImage takePhoto();

protected:
    void paintEvent(QPaintEvent* e);

public slots:
    void slotRendererStarted(const std::string& id);
    void renderFrame(const std::string& id);
    inline QRect& getPreviewRect(){ return previewGeometry_; }

private:
    struct rendererConnections {
        QMetaObject::Connection started, stopped, updated;
    } rendererConnections_;

    video::Renderer* previewRenderer_;
    video::Frame previewFrame_;
    std::unique_ptr<QImage> previewImage_;
    std::vector<uint8_t> framePreview_;

    video::Renderer* distantRenderer_;
    video::Frame distantFrame_;
    std::unique_ptr<QImage> distantImage_;
    std::vector<uint8_t> frameDistant_;

    QMutex mutex_;

    bool isPreviewDisplayed_;
    bool fullPreview_;
    QRect previewGeometry_;
    bool resetPreview_ = false;
    bool photoMode_ = false;
    bool hasFrame_ = false;

    constexpr static int previewMargin_ = 15;

private:
    void paintBackgroundColor(QPainter* painter, QColor color);
};
