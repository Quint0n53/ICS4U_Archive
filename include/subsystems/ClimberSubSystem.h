// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class ClimberSubSystem : public frc2::SubsystemBase {
 public:
  ClimberSubSystem();

  void Periodic() override;

  void ArmsUp(double ArmSpeed);

  void ArmsDown(double ArmSpeed);

  void StopArms();

  void HooksUp();

  void StopHooks();

 private:
  WPI_TalonFX leftArmMotor;
  WPI_TalonFX rightArmMotor;
  WPI_VictorSPX leftHookMotor;
  WPI_VictorSPX rightHookMotor;
};
