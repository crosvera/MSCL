/*******************************************************************************
Copyright(c) 2015-2016 LORD Corporation. All rights reserved.

MIT Licensed. See the included LICENSE.txt for a copy of the full MIT License.
*******************************************************************************/
#include "stdafx.h"
#include "InertialChannel.h"
#include "InertialNode.h"
#include "mscl/Utils.h"

namespace mscl
{
    InertialChannel::InertialChannel():
        m_channelField(static_cast<InertialTypes::ChannelField>(0))
    {}

    InertialChannel::InertialChannel(InertialTypes::ChannelField channelId, const SampleRate& sampleRate) :
        m_channelField(channelId),
        m_sampleRate(sampleRate)
    {}

    InertialTypes::ChannelField InertialChannel::channelField() const
    {
        return m_channelField;
    }

    const SampleRate& InertialChannel::sampleRate() const
    {
        return m_sampleRate;
    }

    uint16 InertialChannel::rateDecimation(uint16 sampleRateBase) const
    {
        return static_cast<uint16>(sampleRateBase / m_sampleRate.samplesPerSecond());
    }

    const SampleRate& InertialChannel::validateSampleRate(uint16 sampleRateBase)
    {
        //the lowest sample rate allowed by an InertialChannel is currently 1hz
        static const SampleRate RATE_1HZ = SampleRate::Hertz(1);
        if(m_sampleRate < RATE_1HZ)
        {
            m_sampleRate = RATE_1HZ;
        }
        //only allow up to the sample rate base rate
        else if(m_sampleRate.samples() > sampleRateBase)
        {
            m_sampleRate = SampleRate::Hertz(sampleRateBase);
        }

        //while the current sample rate isn't an even multiple of the sample rate base
        while(sampleRateBase % m_sampleRate.samples() != 0)
        {
            //increment the sample rate by 1 sample per second
            m_sampleRate += 1;
        }

        return m_sampleRate;
    }

    const SampleRate& InertialChannel::validateSampleRate(InertialNode& node)
    {
        //get the sample rate base for this channel and call validateSampleRate
        return validateSampleRate(node.getDataRateBase(InertialTypes::channelFieldToCategory(m_channelField)));
    }

    uint8 InertialChannel::fieldDescriptor() const
    {
        return Utils::lsb(static_cast<uint16>(m_channelField));
    }

    uint8 InertialChannel::descriptorSet() const
    {
        return Utils::msb(static_cast<uint16>(m_channelField));
    }
}