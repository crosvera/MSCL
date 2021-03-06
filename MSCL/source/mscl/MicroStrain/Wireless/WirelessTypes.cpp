/*******************************************************************************
Copyright(c) 2015-2016 LORD Corporation. All rights reserved.

MIT Licensed. See the included LICENSE.txt for a copy of the full MIT License.
*******************************************************************************/
#include "stdafx.h"
#include "WirelessTypes.h"

namespace mscl
{
    uint16 WirelessTypes::dataTypeSize(DataType type)
    {
        switch(type)
        {
            case dataType_uint16_12bitRes:
            case dataType_uint16:
            case dataType_uint16_shifted:
            case dataType_uint16_18bitTrunc:
                return 2;

            case dataType_float32:
            case dataType_float32_noCals:
            case dataType_uint32:
                return 4;

            case dataType_uint24:
                return 3;

            default:
                assert(false);    //need to add support for a new DataType if this assert is hit
                return 2;
        }
    }

    ValueType WirelessTypes::dataTypeToValueType(DataType type)
    {
        //check the DataType
        switch(type)
        {
            //data types that are unsigned shorts
            case dataType_uint16_12bitRes:
            case dataType_uint16:
            case dataType_uint16_shifted:
                return valueType_uint16;

            case dataType_uint32:
            case dataType_uint24:               //uint24 is stored as a uint32 in mscl
            case dataType_uint16_18bitTrunc:    //uint16 from 18-bit node is stored as a uint32 in mscl
                return valueType_uint32;

            //data types that are floats
            case dataType_float32:
            case dataType_float32_noCals:
                return valueType_float;

            default:
                assert(false);    //need to add support for a new DataType if this assert is hit
                return valueType_uint16;
        }
    }

    uint8 WirelessTypes::dataFormatSize(DataFormat dataFormat)
    {
        switch(dataFormat)
        {
        case dataFormat_cal_float:
            return 4;

        case dataFormat_raw_uint24:
            return 3;

        case dataFormat_raw_uint16:
        default:
            return 2;
        }
    }

    uint16 WirelessTypes::settlingTime(SettlingTime time)
    {
        switch(time)
        {
            case settling_4ms:            return 4;
            case settling_8ms:            return 8;        
            case settling_16ms:            return 16;
            case settling_32ms:            return 32;        
            case settling_40ms:            return 40;
            case settling_48ms:            return 50;
            case settling_60ms:            return 60;
            case settling_101ms_90db:    return 101;
            case settling_120ms_80db:    return 120;
            case settling_120ms_65db:    return 120;
            case settling_160ms_69db:    return 160;
            case settling_200ms:        return 200;
                    
            default:                        return 0;
        }
    }

    WirelessTypes::WirelessSampleRate WirelessTypes::dataloggingRateToSampleRate(uint16 eepromValue)
    {
        //build the map of datalogging eeprom values to sample rates
        static const std::map<uint16, WirelessTypes::WirelessSampleRate> dataloggingMap = {
                {0, WirelessTypes::sampleRate_4096Hz},
                {1, WirelessTypes::sampleRate_2048Hz},
                {2, WirelessTypes::sampleRate_1024Hz},
                {3, WirelessTypes::sampleRate_512Hz},
                {4, WirelessTypes::sampleRate_256Hz},
                {5, WirelessTypes::sampleRate_128Hz},
                {6, WirelessTypes::sampleRate_64Hz},
                {7, WirelessTypes::sampleRate_32Hz}};

        //try to find the eeprom value in the map
        std::map<uint16, WirelessTypes::WirelessSampleRate>::const_iterator itr = dataloggingMap.find(eepromValue);

        //if we found the value
        if(itr != dataloggingMap.end())
        {
            //return the rate
            return itr->second;
        }
        else
        {
            //just cast and return the value
            return static_cast<WirelessTypes::WirelessSampleRate>(eepromValue);
        }
    }

    uint16 WirelessTypes::sampleRateToDataloggingRate(WirelessTypes::WirelessSampleRate rate)
    {
        //build the map of sample rates to datalogging eeprom values
        static const std::map<WirelessTypes::WirelessSampleRate, uint16> dataloggingMap = {
                {WirelessTypes::sampleRate_4096Hz, 0},
                {WirelessTypes::sampleRate_2048Hz, 1},
                {WirelessTypes::sampleRate_1024Hz, 2},
                {WirelessTypes::sampleRate_512Hz, 3},
                {WirelessTypes::sampleRate_256Hz, 4},
                {WirelessTypes::sampleRate_128Hz, 5},
                {WirelessTypes::sampleRate_64Hz, 6},
                {WirelessTypes::sampleRate_32Hz, 7}};

        //try to find the sample rate in the map
        std::map<WirelessTypes::WirelessSampleRate, uint16>::const_iterator itr = dataloggingMap.find(rate);

        //if we found the value
        if(itr != dataloggingMap.end())
        {
            //return the rate
            return itr->second;
        }
        else
        {
            //just cast and return the value
            return static_cast<uint16>(rate);
        }
    }

    WirelessTypes::TransmitPower WirelessTypes::maxTransmitPower(WirelessTypes::RegionCode region)
    {
        //determine the max power based on the region code
        switch(region)
        {
            case WirelessTypes::region_japan:
                return WirelessTypes::power_5dBm;

            case WirelessTypes::region_europe:
            case WirelessTypes::region_other:
                return WirelessTypes::power_10dBm;

            case WirelessTypes::region_usa:
            case WirelessTypes::region_brazil:
            default:
                return WirelessTypes::power_20dBm;
        }
    }

    WirelessTypes::TransmitPower WirelessTypes::legacyToTransmitPower(WirelessTypes::LegacyTransmitPower legacyVal)
    {
        switch(legacyVal)
        {
            case WirelessTypes::legacyPower_5dBm:
                return WirelessTypes::power_5dBm;

            case WirelessTypes::legacyPower_0dBm:
                return WirelessTypes::power_0dBm;

            case WirelessTypes::legacyPower_10dBm:
                return WirelessTypes::power_10dBm;

            case WirelessTypes::legacyPower_16dBm:
                return WirelessTypes::power_16dBm;

            default:
                return static_cast<WirelessTypes::TransmitPower>(legacyVal);
        }
    }

    WirelessTypes::LegacyTransmitPower WirelessTypes::transmitPowerToLegacy(WirelessTypes::TransmitPower power)
    {
        switch(power)
        {
            case WirelessTypes::power_5dBm:
                return WirelessTypes::legacyPower_5dBm;

            case WirelessTypes::power_0dBm:
                return WirelessTypes::legacyPower_0dBm;

            case WirelessTypes::power_10dBm:
                return WirelessTypes::legacyPower_10dBm;

            case WirelessTypes::power_16dBm:
                return WirelessTypes::legacyPower_16dBm;

            default:
                throw Error("Attempting to convert a transmit power (" + Utils::toStr(power) + ") without a legacy equivalent.");
        }
    }
}