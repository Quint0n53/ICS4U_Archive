// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IndexSubSystem.h"

using namespace IndexConstants;

IndexSubSystem::IndexSubSystem()
    :indexTop{kIndexMotorTopPort},
    indexBottom{kIndexMotorBottomPort},
    pesensor{kpesensorPort}
    {}

// This method will be called once per scheduler run
void IndexSubSystem::Periodic() {}

void IndexSubSystem::Uptake(){
    indexTop.Set(uptakeSpeed);
    indexBottom.Set(-uptakeSpeed);
}
void IndexSubSystem::Downtake(){
    indexTop.Set(-downtakeSpeed);
    indexBottom.Set(downtakeSpeed);
}
void IndexSubSystem::Stoptake(){
    indexTop.Set(0);
    indexBottom.Set(0);
}

