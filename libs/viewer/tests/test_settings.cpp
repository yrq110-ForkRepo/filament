/*
 * Copyright 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <viewer/Settings.h>

#include <gtest/gtest.h>

using namespace filament::viewer;

class ViewSettingsTest : public testing::Test {};

static const char* JSON_TEST_DEFAULTS = R"TXT(
{
    "view": {
        "sampleCount": 1,
        "antiAliasing": "FXAA",
        "taa": {
            "enabled": false,
            "filterWidth": 1.0,
            "feedback": 0.04
        },
        "colorGrading": {
            "enabled": true,
            "quality": "MEDIUM",
            "toneMapping": "ACES_LEGACY",
            "temperature": 0,
            "tint": 0,
            "outRed": [1.0, 0.0, 0.0],
            "outGreen": [0.0, 1.0, 0.0],
            "outBlue": [0.0, 0.0, 1.0],
            "shadows": [1.0, 1.0, 1.0, 0.0],
            "midtones": [1.0, 1.0, 1.0, 0.0],
            "highlights": [1.0, 1.0, 1.0, 0.0],
            "ranges": [0.0, 0.333, 0.550, 1.0],
            "contrast": 1.0,
            "vibrance": 1.0,
            "saturation": 1.0,
            "slope": [1.0, 1.0, 1.0],
            "offset": [0.0, 0.0, 0.0],
            "power": [1.0, 1.0, 1.0],
            "gamma": [1.0, 1.0, 1.0],
            "midPoint": [1.0, 1.0, 1.0],
            "scale": [1.0, 1.0, 1.0],
            "linkedCurves": false
        },
        "ssao": {
            "enabled": false,
            "radius": 0.3,
            "power": 1.0,
            "bias": 0.0005,
            "resolution": 0.5,
            "intensity": 1.0,
            "quality": "LOW",
            "upsampling": "LOW",
            "minHorizonAngleRad": 0.0
        },
        "bloom": {
            "enabled": false,
            "strength": 0.10,
            "resolution": 360,
            "anamorphism": 1.0,
            "levels": 6,
            "blendMode": "ADD",
            "threshold": true,
            "highlight": 1000.0
        },
        "fog": {
            "enabled": false,
            "distance": 0.0,
            "maximumOpacity": 1.0,
            "height": 0.0,
            "heightFalloff": 1.0,
            "color": [0.5, 0.5, 0.5],
            "density": 0.1,
            "inScatteringStart": 0.0,
            "inScatteringSize": -1.0,
            "fogColorFromIbl": false
        },
        "dof": {
            "enabled": false,
            "focusDistance": 10.0,
            "cocScale": 1.0,
            "maxApertureDiameter": 0.01
        },
        "vignette": {
            "enabled": false,
            "midPoint": 0.5,
            "roundness": 0.5,
            "feather": 0.5,
            "color": [0, 0, 0, 1]
        },
        "dithering": "TEMPORAL",
        "renderQuality": {
            "hdrColorBuffer": "HIGH"
        },
        "dynamicLighting": {
            "zLightNear": 5,
            "zLightFar": 100,
        },
        "shadowType": "PCF",
        "postProcessingEnabled": true
    }
}
)TXT";

TEST_F(ViewSettingsTest, JsonTestDefaults) {
    Settings settings1 = {0};
    ASSERT_TRUE(readJson(JSON_TEST_DEFAULTS, strlen(JSON_TEST_DEFAULTS), &settings1));

    ASSERT_TRUE(settings1.view.bloom.threshold);

    Settings settings2;
    ASSERT_TRUE(readJson("{}", strlen("{}"), &settings2));
    ASSERT_EQ(writeJson(settings1), writeJson(settings2));

    Settings settings3;
    ASSERT_EQ(writeJson(settings1), writeJson(settings3));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
