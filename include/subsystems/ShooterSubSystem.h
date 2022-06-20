// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class ShooterSubSystem : public frc2::SubsystemBase {
 public:
  ShooterSubSystem();

  void Periodic() override;

  void HighShot();

  void LowShot();

  void StopShot();

  int FlywheelVelocity();

 private:
  WPI_TalonFX frontFlywheel;
  WPI_TalonFX backFlywheel;
};
