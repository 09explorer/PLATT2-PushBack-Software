#include "main.h"
#include "platt2/MatchController.hpp"

platt2::MatchController matchController{};

void initialize() {
	matchController.init();
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	matchController.driveControl();
}
