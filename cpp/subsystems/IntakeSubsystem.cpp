// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IntakeSubsystem.h"

using namespace IntakeConstants;

Intake::Intake()
    : intakeMotor{kIntakeMotorPort}
       {}

void Intake::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Intake::Swallow() {
    intakeMotor.Set(swallowSpeed);
}

void Intake::SpitOut() {
    intakeMotor.Set(-SpitOutSpeed);
}

void Intake::StopIntake(){
    intakeMotor.Set(0);
}