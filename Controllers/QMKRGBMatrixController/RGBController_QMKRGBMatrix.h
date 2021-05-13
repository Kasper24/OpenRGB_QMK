/*-------------------------------------------------------------------*\
|  RGBController_QMKRGBMatrix.h                                       |
|                                                                     |
|  Driver for QMK keybaords using RGB Matrix                          |
|                                                                     |
|  Kasper24         11th November 2020                                |
|                                                                     |
\*-------------------------------------------------------------------*/

#pragma once

#include "RGBController.h"
#include "QMKRGBMatrixController.h"
#include <map>
#include <set>

class RGBController_QMKRGBMatrix : public RGBController
{
public:
    RGBController_QMKRGBMatrix(QMKRGBMatrixController* qmk_rgb_matrix_ptr, unsigned int protocol_version);
    ~RGBController_QMKRGBMatrix();

    void        SetupZones();
    void        ResizeZone(int zone, int new_size);

    void        DeviceUpdateLEDs();
    void        UpdateZoneLEDs(int zone);
    void        UpdateSingleLED(int led);

    void        SetCustomMode();
    void        DeviceUpdateMode();
private:
    QMKRGBMatrixController* qmk_rgb_matrix;
    std::vector<unsigned int> openrgb_idx_to_qmk_idx;
    std::vector<unsigned int> flat_matrix_map;
    std::vector<unsigned int> flat_underglow_map;

    void            InitializeMode
                    (
                    std::string name,
                    unsigned int &current_mode,
                    unsigned int flags,
                    unsigned int color_mode
                    );

    unsigned int    CalculateDivisor
                    (
                    std::vector<point_t> led_points,
                    std::set<int> rows,
                    std::set<int> columns
                    );

    void            GetInitialLEDColors();

    std::vector<unsigned int>   OpenRGBIdxToQMKIdx
                                (
                                std::vector<unsigned int> led_flags
                                );
    std::pair<unsigned int, unsigned int>   CountKeyTypes
                                            (
                                            std::vector<unsigned int> led_points,
                                            unsigned int total_led_count
                                            );
    std::pair<std::vector<std::vector<unsigned int>>, std::vector<std::vector<unsigned int>>>   PlaceLEDsInMaps
                                                                                                (
                                                                                                (std::set<int> unique_rows,
                                                                                                std::set<int> unique_cols,
                                                                                                unsigned int divisor,
                                                                                                std::vector<point_t> led_points,
                                                                                                st)d::vector<unsigned int> led_flags
                                                                                                );
    std::vector<std::vector<unsigned int>> MakeEmptyMatrixMap
                                            (
                                            unsigned int height,
                                            unsigned int width
                                            );
    std::pair<std::vector<std::vector<unsigned int>>, std::vector<std::vector<unsigned int>>>   CleanMatrixMaps
                                                                                                (
                                                                                                std::vector<std::vector<unsigned int> > matrix_map,
                                                                                                std::vector<std::vector<unsigned int> > underglow_map,
                                                                                                unsigned int height
                                                                                                );
    std::vector<unsigned int>   FlattenMatrixMap
                                (
                                std::vector<std::vector<unsigned int>> matrix_map
                                );
};