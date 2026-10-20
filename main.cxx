/** Use this main to test exercises. See the example with 'as1.0' below.
 *  You can add all the exercise tests inside the same main.
 *  Don't forget to add includes properly.
 * */

#include "as1.hpp"
#include "as2.hpp"
#include <iostream>
#include <memory>
#include <string>

using namespace homework;

int failures = 0;

void check(const std::string &name, bool ok) {
  std::cout << (ok ? "[PASS] " : "[FAIL] ") << name << '\n';
  if (!ok) {
    ++failures;
  }
}

int main() {
  int a = 1;
  int b = 2;
  int c = 3;
  swap_ptr(&a, &b, &c);
  check("1.1 a gets value of b", a == 2);
  check("1.1 b gets value of c", b == 3);
  check("1.1 c gets value of a", c == 1);

  UniqueData data(5);
  check("1.2 get() after constructor is 5", data.get() == 5);
  data.set(10);
  check("1.2 get() after set(10) is 10", data.get() == 10);

  Knight knight("Arthur");
  knight.setWeapon("sword");
  knight.attack();
  std::unique_ptr<Entity> knightCopy = knight.clone();
  check("2.1 clone has name Arthur", knightCopy->getName() == "Arthur");
  knight.setWeapon("axe");
  knight.attack();
  knightCopy->attack();

  Sorcerer sorcerer("Merlin");
  sorcerer.setAbility("fireball");
  sorcerer.attack();
  std::unique_ptr<Entity> sorcererCopy = sorcerer.clone();
  check("2.2 clone has name Merlin", sorcererCopy->getName() == "Merlin");
  sorcerer.setAbility("lightning");
  sorcerer.attack();
  sorcererCopy->attack();

  if (failures == 0) {
    std::cout << "All checks passed\n";
  } else {
    std::cout << failures << " check(s) FAILED\n";
  }
  return failures == 0 ? 0 : 1;
}