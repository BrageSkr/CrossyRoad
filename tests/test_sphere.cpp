
#include "sphere.hpp"

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>


TEST_CASE("Sphere Movement") {
    sphere s(0);
   keyInput inputTest{false, false, false, false, false};
   int hexColor = 0x0000FF;
   bool hasCollision = false;

 SECTION("Sphere moves forwards test") {
       inputTest.up = true;
       s.update(1.0f, inputTest, hexColor, hasCollision);
       CHECK(s.mesh()->position.x == Approx(6.f));
   }

   SECTION("Sphere moves backwards test") {
       inputTest.down = true;
       s.update(1.0f, inputTest, hexColor, hasCollision);
       CHECK(s.mesh()->position.x == Approx(-6.f));
   }

   SECTION("Sphere moves right test") {
       inputTest.right = true;
       s.update(1.0f, inputTest, hexColor, hasCollision);
       CHECK(s.mesh()->position.z == Approx(6.f));
   }

   SECTION("Sphere moves left test") {
       inputTest.left = true;
       s.update(1.0f, inputTest, hexColor, hasCollision);
       CHECK(s.mesh()->position.z == Approx(-6.f));
   }

   SECTION("Sphere is reset when the reset function should be called") {
       inputTest.reset = true;
       s.update(1.0f, inputTest, hexColor, hasCollision);
       CHECK(s.mesh()->position.x == Approx(0.0f));
       CHECK(s.mesh()->position.z == Approx(0.0f));
   }

   SECTION("Sphere is reset when hasCollision is true") {
       hasCollision = true;
       s.update(1.0f, inputTest, hexColor, hasCollision);
       CHECK(s.mesh()->position.x == Approx(0.0f));
       CHECK(s.mesh()->position.z == Approx(0.0f));
   }


}