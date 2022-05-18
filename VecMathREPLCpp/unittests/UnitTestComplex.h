#pragma once
#include "VecMathListener.h"

TEST_CASE("Complex tests", "[complex_operations]") {
	VecMathListener vm;
	SECTION("Complex multiplication") {
		vm.exec("z1=[1,(3)]");
		check2DVector(vm, "z1", 1, 3);
		vm.exec("z2=[3,(4)]");
		check2DVector(vm, "z2", 3,4);
		vm.exec("z3=z1.z2");
		check2DVector(vm, "z3", -9, 13);
	}

	SECTION("Inverse") {
		vm.exec("z1=[-3,(8.2)]");
		vm.exec("z2=inv(z1)");
		check2DVector(vm, "z2", -0.03935, -0.10756);
		vm.exec("z3=z1.z2");
		check2DVector(vm, "z3", 1, 0);

		vm.exec("z1norm=|z1|");
		checkScalar(vm, "z1norm", 8.73155);
	}

	SECTION("Conjugate") {
		vm.exec("z1=[-3,(8.2)]");
		vm.exec("z2=con(z1)");
		check2DVector(vm, "z2", -3, -8.2);
		
	}
}