// [WriteFile Name=IdentifyGraphics, Category=DisplayInformation]
// [Legal]
// Copyright 2015 Esri.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// [Legal]

#ifndef IDENTIFY_GRAPHICS_H
#define IDENTIFY_GRAPHICS_H

namespace Esri
{
    namespace ArcGISRuntime
    {
        class Map;
        class MapQuickView;
        class GraphicsOverlay;
    }
}

#include <QQuickItem>

class IdentifyGraphics : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int identifiedGraphicsCount READ identifiedGraphicsCount NOTIFY identifiedGraphicsCountChanged)

public:
    IdentifyGraphics(QQuickItem* parent = 0);
    ~IdentifyGraphics();

    void componentComplete() Q_DECL_OVERRIDE;

signals:
    void identifiedGraphicsCountChanged();

private:
    void addPolygonGraphic();
    void connectSignals();
    int identifiedGraphicsCount();

private:
    Esri::ArcGISRuntime::Map* m_map;
    Esri::ArcGISRuntime::MapQuickView* m_mapView;
    Esri::ArcGISRuntime::GraphicsOverlay* m_graphicsOverlay;
    int m_identifiedGraphicsCount;
};

#endif // IDENTIFY_GRAPHICS_H

