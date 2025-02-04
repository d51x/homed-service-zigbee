#include "reporting.h"

void ReportingObject::registerMetaTypes(void)
{
    qRegisterMetaType <Reportings::BatteryVoltage>      ("batteryVoltageReporting");
    qRegisterMetaType <Reportings::BatteryPercentage>   ("batteryPercentageReporting");
    qRegisterMetaType <Reportings::DeviceTemperature>   ("deviceTemperatureReporting");
    qRegisterMetaType <Reportings::Status>              ("statusReporting");
    qRegisterMetaType <Reportings::Level>               ("levelReporting");
    qRegisterMetaType <Reportings::ColorHS>             ("colorHSReporting");
    qRegisterMetaType <Reportings::ColorXY>             ("colorXYReporting");
    qRegisterMetaType <Reportings::ColorTemperature>    ("colorTemperatureReporting");
    qRegisterMetaType <Reportings::Illuminance>         ("illuminanceReporting");
    qRegisterMetaType <Reportings::Temperature>         ("temperatureReporting");
    qRegisterMetaType <Reportings::Pressure>            ("pressureReporting");
    qRegisterMetaType <Reportings::Humidity>            ("humidityReporting");
    qRegisterMetaType <Reportings::Moisture>            ("moistureReporting");
    qRegisterMetaType <Reportings::Energy>              ("energyReporting");
    qRegisterMetaType <Reportings::Voltage>             ("voltageReporting");
    qRegisterMetaType <Reportings::Current>             ("currentReporting");
    qRegisterMetaType <Reportings::Power>               ("powerReporting");

    qRegisterMetaType <ReportingsPerenio::Voltage>      ("perenioVoltageReporting");
    qRegisterMetaType <ReportingsPerenio::Power>        ("perenioPowerReporting");
    qRegisterMetaType <ReportingsPerenio::Energy>       ("perenioEnergyReporting");
}
