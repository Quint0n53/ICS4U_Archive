// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClimberSubSystem.h"

using namespace ClimbConstants;

// This method will be called once per scheduler run
ClimberSubSystem::ClimberSubSystem()
    :leftArmMotor{kLeftArmMotorPort},
    rightArmMotor{kLeftArmMotorPort},
    leftHookMotor{kLeftHookMotorPort},
    rightHookMotor{kRightHookMotorPort} 
    {}
void ClimberSubSystem::Periodic(){
    
}
void ClimberSubSystem::ArmsUp(double ArmSpeed){
    leftArmMotor.Set(ArmSpeed);
    rightArmMotor.Set(-ArmSpeed);
}

void ClimberSubSystem::ArmsDown(double ArmSpeed){
    leftArmMotor.Set(ArmSpeed);
    rightArmMotor.Set(-ArmSpeed);
}

void ClimberSubSystem::StopArms(){
    leftArmMotor.Set(0);
    rightArmMotor.Set(0);

}

void ClimberSubSystem::HooksUp(){
    leftHookMotor.Set(HookSpeed);
    rightHookMotor.Set(-HookSpeed);
}

void ClimberSubSystem::StopHooks(){
    leftHookMotor.Set(0);
    rightHookMotor.Set(0);
}
