#pragma once

#include <vector>

#include "TMatrix.hh"
#include "TVector.hh"
#include "surface.hh"

/*!
 * \brief Modeluje pojęcie obiektu
 * Klasa opisuje obiekt geometryczny, który może się poruszać
 * i obracać wokół własnej osi.
 */
class obiekt : public surface {
protected:
    /*! \brief Przechowuje współrzędne punktów tworzących obiekt */
    std::vector<TVector<double, 3>> wspolrzedne;
    /*! \brief Łączny kąt rotationu obiektu */
    double all_angle;
    /*! \brief przesunięcie obiektu względem wspolrzednych lokalnych */
    TVector<double, 3> translation;
    /*! \brief odległości środka obiektu od ścian */
    TVector<double, 3> polowa_dl;
    /*! \brief Środek wspolrzednych lokalnych obiektu */
    TVector<double, 3> srodek_lok;

    /*!
     * \brief Wczytuje wspolrzedne z pliku
     * Wczytuje dane z pliku i zapisuje je do pola współrzędne
     * \param[in] nazwa_pliku - nazwa pliku z którego będą odczytywane dane
     */
    void wczytaj_wspolrz(const std::string& nazwa_pliku);

public:
    /*!
     * \brief Konstruktor
     * Zeruje vector przesunięcia i łączny kąt rotationu.
     */
    obiekt();
    /*! \brief Destruktor wirtualny */
    virtual ~obiekt() {}

    /*!
     * \brief Inicjalizuje pola klasy
     * Wylicza srodek_lok oraz polowa_wysokosci, wpisuje plik lokalny do pliku z punktami
     * metoda powinna być wywołana przed wykonaniem ruchów przez obiekt
     */
    void inicjalizuj_obiekt();

    /*!
     * \brief Wczytuje wspolrzedne lokalne
     * Wczytuje współrzędne z pliku z współrzędnymi lokalnymi
     * i zapisuje je do pola współrzędne.
     */
    void wczytaj_wspolrzedne_lok();

    /*!
     * \brief Wpisuje współrzędne do pliku_z_punktami
     * Zapisuje współrzędne z pola współrzędne do pliku globalnego
     */
    void wpisz_wspolrzedne_glob();

    /*!
     * \brief Przeprowadza ruch na wprost
     * Powoduje ruch obiektu po prostej o zadany vector translacji
     * \param[in] przesun - zadany vector
     */
    void move_ahead(const TVector<double, 3>& przesun);

    /*!
     * \brief Powoduje obrót obiektu
     * Metoda powoduje obrót obiektu wokół własnej osi o zadaną macierz rotationu
     * \param[in] mac_rotationu - zadana macierz rotationu
     */
    void rotation(const TMatrix<double, 3>& mac_rotationu);

    /*!
     * \brief Zwraca środek drona
     * Metoda zwraca wartość współrzędnych środka drona
     * \return Współrzędna środka drona
     */
    TVector<double, 3> polozenie() const;

    /*!
     * \brief Zwraca vector z polowami dlugości obiektu
     * Metoda zwraca połowę wysokości obiektu
     * \retval polowa_wysokosci - pole klasy
     */
    TVector<double, 3> zwroc_polowy_dlugosci() const { return polowa_dl; }
};
