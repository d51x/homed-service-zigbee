#include "properties/common.h"
#include "properties/efekta.h"
#include "properties/ias.h"
#include "properties/lumi.h"
#include "properties/other.h"
#include "properties/ptvo.h"
#include "properties/tuya.h"

void PropertyObject::registerMetaTypes(void)
{
    qRegisterMetaType <Properties::BatteryVoltage>                  ("batteryVoltageProperty");
    qRegisterMetaType <Properties::BatteryPercentage>               ("batteryPercentageProperty");
    qRegisterMetaType <Properties::DeviceTemperature>               ("deviceTemperatureProperty");
    qRegisterMetaType <Properties::Status>                          ("statusProperty");
    qRegisterMetaType <Properties::PowerOnStatus>                   ("powerOnStatusProperty");
    qRegisterMetaType <Properties::SwitchType>                      ("switchTypeProperty");
    qRegisterMetaType <Properties::SwitchMode>                      ("switchModeProperty");
    qRegisterMetaType <Properties::Level>                           ("levelProperty");
    qRegisterMetaType <Properties::CoverStatus>                     ("coverStatusProperty");
    qRegisterMetaType <Properties::CoverPosition>                   ("coverPositionProperty");
    qRegisterMetaType <Properties::CoverTilt>                       ("coverTiltProperty");
    qRegisterMetaType <Properties::ColorHS>                         ("colorHSProperty");
    qRegisterMetaType <Properties::ColorXY>                         ("colorXYProperty");
    qRegisterMetaType <Properties::ColorTemperature>                ("colorTemperatureProperty");
    qRegisterMetaType <Properties::Illuminance>                     ("illuminanceProperty");
    qRegisterMetaType <Properties::Temperature>                     ("temperatureProperty");
    qRegisterMetaType <Properties::Pressure>                        ("pressureProperty");
    qRegisterMetaType <Properties::Humidity>                        ("humidityProperty");
    qRegisterMetaType <Properties::Occupancy>                       ("occupancyProperty");
    qRegisterMetaType <Properties::Moisture>                        ("moistureProperty");
    qRegisterMetaType <Properties::Energy>                          ("energyProperty");
    qRegisterMetaType <Properties::Voltage>                         ("voltageProperty");
    qRegisterMetaType <Properties::Current>                         ("currentProperty");
    qRegisterMetaType <Properties::Power>                           ("powerProperty");
    qRegisterMetaType <Properties::Scene>                           ("sceneProperty");
    qRegisterMetaType <Properties::StatusAction>                    ("statusActionProperty");
    qRegisterMetaType <Properties::LevelAction>                     ("levelActionProperty");
    qRegisterMetaType <Properties::ColorAction>                     ("colorActionProperty");

    qRegisterMetaType <PropertiesIAS::Contact>                      ("iasContactProperty");
    qRegisterMetaType <PropertiesIAS::Gas>                          ("iasGasProperty");
    qRegisterMetaType <PropertiesIAS::Occupancy>                    ("iasOccupancyProperty");
    qRegisterMetaType <PropertiesIAS::Smoke>                        ("iasSmokeProperty");
    qRegisterMetaType <PropertiesIAS::WaterLeak>                    ("iasWaterLeakProperty");

    qRegisterMetaType <PropertiesLUMI::Data>                        ("lumiDataProperty");
    qRegisterMetaType <PropertiesLUMI::Basic>                       ("lumiBasicProperty");
    qRegisterMetaType <PropertiesLUMI::ButtonMode>                  ("lumiButtonModeProperty");
    qRegisterMetaType <PropertiesLUMI::SwitchType>                  ("lumiSwitchTypeProperty");
    qRegisterMetaType <PropertiesLUMI::Contact>                     ("lumiContactProperty");
    qRegisterMetaType <PropertiesLUMI::Power>                       ("lumiPowerProperty");
    qRegisterMetaType <PropertiesLUMI::Cover>                       ("lumiCoverProperty");
    qRegisterMetaType <PropertiesLUMI::Interlock>                   ("lumiInterlockProperty");
    qRegisterMetaType <PropertiesLUMI::Illuminance>                 ("lumiIlluminanceProperty");
    qRegisterMetaType <PropertiesLUMI::ButtonAction>                ("lumiButtonActionProperty");
    qRegisterMetaType <PropertiesLUMI::SwitchAction>                ("lumiSwitchActionProperty");
    qRegisterMetaType <PropertiesLUMI::CubeRotation>                ("lumiCubeRotationProperty");
    qRegisterMetaType <PropertiesLUMI::CubeMovement>                ("lumiCubeMovementProperty");
    qRegisterMetaType <PropertiesLUMI::Vibration>                   ("lumiVibrationProperty");

    qRegisterMetaType <PropertiesTUYA::DataPoints>                  ("tuyaDataPointsProperty");
    qRegisterMetaType <PropertiesTUYA::WeekdayThermostatProgram>    ("tuyaWeekdayThermostatProgramProperty");
    qRegisterMetaType <PropertiesTUYA::HolidayThermostatProgram>    ("tuyaHolidayThermostatProgramProperty");
    qRegisterMetaType <PropertiesTUYA::MoesThermostatProgram>       ("tuyaMoesThermostatProgramProperty");
    qRegisterMetaType <PropertiesTUYA::CoverMotor>                  ("tuyaCoverMotorProperty");
    qRegisterMetaType <PropertiesTUYA::CoverSwitch>                 ("tuyaCoverSwitchProperty");
    qRegisterMetaType <PropertiesTUYA::ChildLock>                   ("tuyaChildLockProperty");
    qRegisterMetaType <PropertiesTUYA::OperationMode>               ("tuyaOperationModeProperty");
    qRegisterMetaType <PropertiesTUYA::IndicatorMode>               ("tuyaIndicatorModeProperty");
    qRegisterMetaType <PropertiesTUYA::SwitchType>                  ("tuyaSwitchTypeProperty");
    qRegisterMetaType <PropertiesTUYA::PowerOnStatus>               ("tuyaPowerOnStatusProperty");
    qRegisterMetaType <PropertiesTUYA::ButtonAction>                ("tuyaButtonActionProperty");

    qRegisterMetaType <PropertiesEfekta::ReportingDelay>            ("efektaReportingDelayProperty");
    qRegisterMetaType <PropertiesEfekta::TemperatureSettings>       ("efektaTemperatureSettingsProperty");
    qRegisterMetaType <PropertiesEfekta::HumiditySettings>          ("efektaHumiditySettingsProperty");
    qRegisterMetaType <PropertiesEfekta::CO2Sensor>                 ("efektaCO2SensorProperty");
    qRegisterMetaType <PropertiesEfekta::VOCSensor>                 ("efektaVOCSensorProperty");

    qRegisterMetaType <PropertiesPTVO::ChangePattern>               ("ptvoChangePatternProperty");
    qRegisterMetaType <PropertiesPTVO::Contact>                     ("ptvoContactProperty");
    qRegisterMetaType <PropertiesPTVO::Occupancy>                   ("ptvoOccupancyProperty");
    qRegisterMetaType <PropertiesPTVO::WaterLeak>                   ("ptvoWaterLeakProperty");
    qRegisterMetaType <PropertiesPTVO::CO2>                         ("ptvoCO2Property");
    qRegisterMetaType <PropertiesPTVO::Temperature>                 ("ptvoTemperatureProperty");
    qRegisterMetaType <PropertiesPTVO::Humidity>                    ("ptvoHumidityProperty");
    qRegisterMetaType <PropertiesPTVO::Count>                       ("ptvoCountProperty");
    qRegisterMetaType <PropertiesPTVO::Pattern>                     ("ptvoPatternProperty");
    qRegisterMetaType <PropertiesPTVO::ButtonAction>                ("ptvoButtonActionProperty");
    qRegisterMetaType <PropertiesPTVO::SwitchAction>                ("ptvoSwitchActionProperty");

    qRegisterMetaType <PropertiesOther::KonkeButtonAction>          ("konkeButtonActionProperty");
    qRegisterMetaType <PropertiesOther::SonoffButtonAction>         ("sonoffButtonActionProperty");
    qRegisterMetaType <PropertiesOther::ModkamButtonAction>         ("modkamButtonActionProperty");
    qRegisterMetaType <PropertiesOther::LifeControlAirQuality>      ("lifeControlAirQualityProperty");
    qRegisterMetaType <PropertiesOther::PerenioSmartPlug>           ("perenioSmartPlugProperty");
}

quint8 PropertyObject::percentage(double min, double max, double value)
{
    if (value < min)
        value = min;

    if (value > max)
        value = max;

    return static_cast <quint8> ((value - min) / (max - min) * 100);
}
