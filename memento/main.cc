#include "memento.h"


int main()
{
	CareTaker careTaker;

	Role *role = new Magician(500, 103, 45, "ljy");
	Memento* memento = role->saveMemento();
	careTaker.saveMemento(memento);
	
	role = new Magician(600, 140, 65, "ljy");
	memento = role->saveMemento();
	careTaker.saveMemento(memento);

	role = new Warrior(800, 75, 55, "wb");
	memento = role->saveMemento();
	careTaker.saveMemento(memento);

	role = new Magician(800, 180, 75, "ljy");
	cout << "current role status" << endl;
	role->showStatus();

	memento = careTaker.getPreMemento();
	memento->show();
	//role->restoreFromMemento(memento);
	role = memento->role;
	cout << "rollback role status to warrior wb level 55" << endl;
	role->showStatus();

	memento = careTaker.getPreMemento();
	memento->show();
	role = memento->role;
	//role->restoreFromMemento(memento);
	cout << "rollback role status to magician ljy level 65" << endl;
	role->showStatus();

	memento = careTaker.getPreMemento();
	memento->show();
	role = memento->role;
	//role->restoreFromMemento(memento);
	cout << "rollback role status to magician ljy level 45" << endl;
	role->showStatus();
	return 0;
}
