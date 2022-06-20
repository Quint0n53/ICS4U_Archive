// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
    : m_left1{kLeftMotor1Port},
      m_left2{kLeftMotor2Port},
      m_left3{kLeftMotor3Port},
      m_right1{kRightMotor1Port},
      m_right2{kRightMotor2Port},
      m_right3{kRightMotor3Port}
       {
         m_left1.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
         m_left2.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
         m_left3.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
         m_right1.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
         m_right2.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
         m_right3.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,10);
        m_rightMotors.SetInverted(true);
}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  m_drive.ArcadeDrive(fwd, rot);
}

void DriveSubsystem::ResetEncoders() {
  m_left1.SetSelectedSensorPosition(0,0,10);
  m_left2.SetSelectedSensorPosition(0,0,10);
  m_left3.SetSelectedSensorPosition(0,0,10);
  m_right1.SetSelectedSensorPosition(0,0,10);
  m_right2.SetSelectedSensorPosition(0,0,10);
  m_right3.SetSelectedSensorPosition(0,0,10);
}

double DriveSubsystem::GetAverageEncoderDistance() {
  return (m_left1.GetSelectedSensorPosition(0) + m_right1.GetSelectedSensorPosition(0) +
          m_left2.GetSelectedSensorPosition(0) + m_right2.GetSelectedSensorPosition(0) +
          m_left3.GetSelectedSensorPosition(0) + m_right3.GetSelectedSensorPosition(0)) / 6.0;
}

void DriveSubsystem::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}
