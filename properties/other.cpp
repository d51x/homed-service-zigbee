#include <QtEndian>
#include "other.h"

void PropertiesOther::KonkeButtonAction::parseAttribte(quint16 attributeId, const QByteArray &data)
{
    if (attributeId != 0x0000)
        return;

    switch (static_cast <quint8> (data.at(0)))
    {
        case 0x80: m_value = "singleClick"; break;
        case 0x81: m_value = "doubleClick"; break;
        case 0x82: m_value = "hold"; break;
    }
}

void PropertiesOther::SonoffButtonAction::parseCommand(quint8 commandId, const QByteArray &)
{
    switch (commandId)
    {
        case 0x00: m_value = "hold"; break;
        case 0x01: m_value = "doubleClick"; break;
        case 0x02: m_value = "singleClick"; break;
    }
}

void PropertiesOther::ModkamButtonAction::parseAttribte(quint16 attributeId, const QByteArray &data)
{
    if (attributeId != 0x0055)
        return;

    switch (static_cast <quint8> (data.at(0)))
    {
        case 0x00: m_value = "hold"; break;
        case 0x01: m_value = "singleClick"; break;
        case 0x02: m_value = "doubleClick"; break;
        case 0x03: m_value = "tripleClick"; break;
        case 0x04: m_value = "quadrupleClick"; break;
        case 0xFF: m_value = "release"; break;
        default:   m_value = "multipleClick"; break;
    }
}

void PropertiesOther::LifeControlAirQuality::parseAttribte(quint16 attributeId, const QByteArray &data)
{
    QMap <QString, QVariant> map = m_value.toMap();
    qint16 value = 0;

    if (static_cast <size_t> (data.length()) > sizeof(value))
        return;

    memcpy(&value, data.constData(), data.length());

    switch (attributeId)
    {
        case 0x0000: map.insert("temperature", qFromLittleEndian(value) / 100.0 + option("temperatureOffset").toDouble()); break;
        case 0x0001: map.insert("humidity", qFromLittleEndian(value) / 100.0 + option("humidityOffset").toDouble()); break;
        case 0x0002: map.insert("eco2", qFromLittleEndian(value)); break;
        case 0x0003: map.insert("voc", qFromLittleEndian(value)); break;
    }

    m_value = map.isEmpty() ? QVariant() : map;
}

void PropertiesOther::PerenioSmartPlug::parseAttribte(quint16 attributeId, const QByteArray &data)
{
    QMap <QString, QVariant> map = m_value.toMap();

    switch (attributeId)
    {
        case 0x0000:
        {
            switch (static_cast <quint8> (data.at(0)))
            {
                case 0x00: map.insert("powerOnStatus", "off"); break;
                case 0x01: map.insert("powerOnStatus", "on"); break;
                case 0x02: map.insert("powerOnStatus", "prevoious"); break;
            }

            break;
        }

        case 0x0001:
        {
            map.insert("alarmVoltateMin",  data.at(0) & 0x01 ? true : false);
            map.insert("alarmVoltateMax",  data.at(0) & 0x02 ? true : false);
            map.insert("alarmPowerMax",    data.at(0) & 0x04 ? true : false);
            map.insert("alarmEnergyLimit", data.at(0) & 0x08 ? true : false);
            break;
        }

        case 0x000E:
        {
            quint32 value = 0;

            if (static_cast <size_t> (data.length()) > sizeof(value))
                break;

            memcpy(&value, data.constData(), data.length());
            map.insert("energy", static_cast <double> (qFromLittleEndian(value)) / 1000);
            break;
        }

        default:
        {
            quint16 value = 0;

            if (static_cast <size_t> (data.length()) > sizeof(value))
                break;

            memcpy(&value, data.constData(), data.length());
            value = qFromLittleEndian(value);

            switch (attributeId)
            {
                case 0x0003: map.insert("voltage", value); break;
                case 0x0004: map.insert("voltageMin", value); break;
                case 0x0005: map.insert("voltageMax", value); break;
                case 0x000A: map.insert("power", value); break;
                case 0x000B: map.insert("powerMax", value); break;
                case 0x000F: map.insert("energyLimit", value); break;
            }

            break;
        }
    }

    m_value = map.isEmpty() ? QVariant() : map;
}
