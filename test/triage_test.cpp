#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "triage.h"

using namespace std;

TEST_CASE("Basic triage")
{
	vector<Patient> patients = {
		{1, 16, 70, 1.5, true, true},
		{2, 15, 65, 1.8, true, false},
		{3, 16, 70, 1.5, true, true},
		{4, 0, 0, 0, false, false},
		{5, 32, 72, 1.7, true, true},
		{6, 15, 71, 1.9, true, true},
		{7, 12, 66, 1.86, false, true},
		{8, 19, 75, 1.25, true, true},
	};

	HospitalER er(patients);
	REQUIRE(er.treatPatient().getTag() == Patient::BLACK);
	REQUIRE(er.treatPatient().getTag() == Patient::RED);
	REQUIRE(er.treatPatient().getTag() == Patient::RED);
	REQUIRE(er.treatPatient().getTag() == Patient::YELLOW);
	REQUIRE(er.treatPatient().getTag() == Patient::GREEN);
	REQUIRE(er.treatPatient().getTag() == Patient::GREEN);
	REQUIRE(er.treatPatient().getTag() == Patient::GREEN);
	REQUIRE(er.treatPatient().getTag() == Patient::GREEN);
}
