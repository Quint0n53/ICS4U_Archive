// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSubSystem.h"

using namespace FlywheelConstants;

ShooterSubSystem::ShooterSubSystem()
    :frontFlywheel{kFrontFlywheelPort},
    backFlywheel{kBackFlywheelPort}
    {
        frontFlywheel.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
        backFlywheel.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
    }

// This method will be called once per scheduler run
void ShooterSubSystem::Periodic() {}

void ShooterSubSystem::HighShot(){
    frontFlywheel.Set(HighFlywheelSpeed);
    backFlywheel.Set(-HighFlywheelSpeed);
}

void ShooterSubSystem::LowShot(){
    frontFlywheel.Set(LowFlywheelSpeed);
    backFlywheel.Set(-LowFlywheelSpeed);
}

void ShooterSubSystem::StopShot(){
    frontFlywheel.Set(0);
    backFlywheel.Set(0);
}

int ShooterSubSystem::FlywheelVelocity(){
    return (frontFlywheel.GetSelectedSensorPosition(0) 
    + backFlywheel.GetSelectedSensorPosition(0))/2;
}


