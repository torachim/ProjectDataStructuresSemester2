Projekt 1 abgeschlossen. Alle Datentypen liegen auf dem main Branch in ihren Ordnern.
Kommentare zu den Projekten.
Torge:
Die Hashende Menge verfügt über alle notwendigen Funktionen und ist voll ausführbar. Ausnahmen wurden eingebunden, für den Fall, dass ein Element doppelt engefuegt werden soll und für den Fall, dass ein Element entfernt werden soll, welches nicht existiert.
Google Tests wurden für die Funktionen insert, remove und find entworfen und implementiert.

Die PriorityQueue verfügt über alle notwendigen Funktionen und ist voll ausführbar. Ausnahme wurde implementiert für den Fall, dass ein Element aus einer leeren PQ entfernt werden soll.
Google Tests wurden für die Funktionen insert und remove entworfen und implementiert.
Laufzeittests im Vergleich zum C++-Standard wurden auf 2 arten durchgeführt. Einmal wurde immer nur ein Wert genommen pro neuer Anzahl an Elementen und im zweiten Versuch wurden die Durchschnitte von vielen Durchlaufen genommen. 

Bei der geordneten Menge könnte man ebenfalls die Funktionen find, insert und remove mit Google Tests testen und über eine size Funktion auf Richtigkeit überprüfen.

Queue wurde implementiert und besitzt die Funktionen enqueue,dequeue und size. Zudem wurden Ausnahmen beim Entfernen eines Elementes aus einer leeren Liste implementiert. Außerdem wurden alle 3 funktionen durch Google Tests geprüft.

Stack besteht aus den Funktionen push, pop und size. Hier wurden ebenfalls Ausnahmen beim Entfernen eines Elementes aus einer leeren Liste implementiert und zu den 3 Funktionen wurden Google Tests implementiert. Zudem wurden für diese 3 Funktionen Laufzeittests behoben und diese mit der Standardbibothek vergliechen. Die Ergebnis wurden bildlich dargestellt.
