#include "audiocontroller.h"

AudioController::AudioController(QObject *parent)
    : QObject{parent}
    , m_volumeLevel(2)
{}

int AudioController::volumeLevel() const
{
    return m_volumeLevel;
}

void AudioController::changeVolume(const int &value)
{
    int newVolume = m_volumeLevel + value;

    if (newVolume < 0)
    {
        newVolume = 0;
    }

    if (newVolume > 100)
    {
        newVolume = 100;
    }

    setVolumeLevel(newVolume);
}

void AudioController::setVolumeLevel(int newVolumeLevel)
{
    if (m_volumeLevel == newVolumeLevel)
        return;
    m_volumeLevel = newVolumeLevel;
    emit volumeLevelChanged();
}
