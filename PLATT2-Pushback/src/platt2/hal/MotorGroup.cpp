#include "platt2/hal/MotorGroup.hpp"
#include <memory>

namespace platt2{

namespace hal{

void MotorGroup::setVoltage(double voltage){
    for (auto &motor : motors)
        if (motor) motor->move_voltage(voltage);
}

void MotorGroup::setVelocity(double velocity){
    for(auto &motor: motors)
        if(motor) motor->move_velocity(velocity);
}

void MotorGroup::addMotor(std::unique_ptr<pros::Motor> motor){
    motors.push_back(std::move(motor));
}

void MotorGroup::setMotorGearing(pros::MotorGears gears){
    for(auto &motor : motors)
        if(motor) motor->set_gearing(gears);
}

void MotorGroup::setZeroPostion(){
    for(auto &motor : motors)
        if(motor) motor->tare_position();
}

MotorGroup &MotorGroup::operator=(MotorGroup &rhs) {
    motors.clear();
    for (uint8_t i{0}; i < rhs.motors.size(); ++i)
      motors.push_back(std::move(rhs.motors.at(i)));
    rhs.motors.clear();
    return *this;
}

} // namespace hal
} // namespace platt2