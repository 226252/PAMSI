# Lista, stos, kolejka

- interfejs IRunnable narusza zasadę budowania wyspecjalizowanych interfejsów - zawiera elementy listy jak i elementy runnable
- intefejs IList - niepotrzebnie dziedzicy po interfejsie IRunnable, powinien zawierać tylko metody dla Listy
↑ to klasa List powinna dziedziczyc IRunnable i IList, co spowoduje konieczność zaimplementowania w tej klasie metod interfejsów IRunnable i IList

+ poprawnie wykonane pomiary, wykres mało czytelny, powinien pokazywać również wykresy dla O(n), O(n^2) itd aby łatwiej pokazać do której klasy należy dana implementacja
- we wnioskach brak wskazania jaka jest złożoność danej implementacji - O(n)

Ocena: 4
