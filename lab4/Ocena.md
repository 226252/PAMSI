# Quicksort

- Uwagi do projektu obiektowego - funkcja `measures` może znajdować się "na zewnątrz" i działać na obiekcie implementującym iRunnable. Wydaje się jednak sensowne żeby to implementacja iRunnable czyniła odpowiednie kroki związane z wypełnianiem odpowiednich tablic, losowaniem danych itd itp. Funkcja `measure` powinna wtedy jedynie wywoływać metody z interfejsu `iRunnable`, a nie je implementować. Wtedy również ta część kodu (`measure`) pozostaje de facto niezmienna, a jedyną zmieniającą się częścią `main()` jest linijka `Quick_sort testowanyObiekt`, `Tablica testowanyObiekt` itd itp.

+ poprawne sprawozdanie

Ocena: 4,5
