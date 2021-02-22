#pragma once
#include "obiekt.hh"
#include "hexagon.hh"

/*!
 * \brief Modeluje pojęcie drona
 * Klasa opisuje drona złożonego z obiektu i dwóch graniastosłupów sześciokątnych, który może się poruszać
 * i obracać wokół własnej osi.
 */
class dron {
private:
    /*! \brief body drona */
    obiekt body;
    /*! \brief Prawa śruba drona */
    hexagon right_motor;
    /*! Lewa śruba drona */
    hexagon left_motor;
    /*! \brief Łączny kąt obrotu obiektu */
    double laczny_kat_obrotu;
    /*! \brief przesunięcie obiektu względem wspolrzednych lokalnych */
    TVector<double, 3> przesuniecie;

    /*!
     * \brief Wylicza wektor translacji.
     * Metoda wylicza wektor translacji na podstawie zadanych parametrów
     * \param[in] wek - wektor który będzie zapisany
     * \param[in] kat_wznoszenia - kąt o jaki ma być odchylony wektor
     * \param[in] odleglosc - długość wektora
     */
    void wylicz_translacje(TVector<double, 3>& wek, double kat_wznoszenia, double odleglosc) const;
    /*!
     * \brief Wylicza macierz obrotu.
     * Metoda wylicza macierz obrotu wokół osi OZ na podstawie zadanych parametrów.
     * \param[in] obrot - wypełniana macierz obrotu
     * \param[in] kat_obrotu - kąt dla jakiego ma zostać wyliczona macierz
     */
    void wylicz_macierz_obrotu(TMatrix<double, 3>& obrot, double kat_obrotu) const;

    /*!
     * \brief Powoduje ruch sruby lewej
     * Metoda powoduje ruch lewej śruby o wektor przesunięcie i obrót o zadaną macierz.
     * \param[in] obrot - macierz z zapisanym obrotem
     */
    void left_motor_ruch(const TMatrix<double, 3>& obrot);
    /*!
     * \brief Powoduje ruch sruby prawej
     * Metoda powoduje ruch prawej śruby o wektor przesunięcie i obrót o zadaną macierz.
     * \param[in] obrot - macierz z zapisanym obrotem
     */
    void right_motor_ruch(const TMatrix<double, 3>& obrot);
    /*!
     * \brief Powoduje ruch bodyu
     * Metoda powoduje ruch bodyu o wektor przesunięcie i obrót o zadaną macierz.
     * \param[in] obrot - macierz z zapisanym obrotem
     */
    void body_ruch(const TMatrix<double, 3>& obrot);

public:
    /*!
     * \brief Konstruktor
     * Zeruje wektor przesunięcie i laczny_kat_obrotu
     */
    dron();
    /*!
     * \brief Inicjaizuje drona
     * Metoda inicjalizuje body i śruby oraz przesuwa śruby względem bodyu.
     */
    void inicjalizuj_drona();
    /*!
     * \brief Dodaje pliki bodyu
     * Metoda dodaje plik lokalny i globalny, które zawierają punkty tworzące body.
     * \param[in] nazwa_lok - plik ze współrzędnymi lokalnymi
     * \param[in] nazwa_glob - plik ze współrzędnymi globalnymi
     */
    void dodaj_pliki_body(const std::string& nazwa_lok, const std::string& nazwa_glob);
    /*!
     * \brief Dodaje pliki lewej śruby
     * Metoda dodaje plik lokalny i globalny, które zawierają punkty tworzące lewą śrubę.
     * \param[in] nazwa_lok - plik ze współrzędnymi lokalnymi
     * \param[in] nazwa_glob - plik ze współrzędnymi globalnymi
     */
    void dodaj_pliki_sruby_lewej(const std::string& nazwa_lok, const std::string& nazwa_glob);
    /*!
     * \brief Dodaje pliki prawej śruby
     * Metoda dodaje plik lokalny i globalny, które zawierają punkty tworzące prawą śrubę.
     * \param[in] nazwa_lok - plik ze współrzędnymi lokalnymi
     * \param[in] nazwa_glob - plik ze współrzędnymi globalnymi
     */
    void dodaj_pliki_sruby_prawej(const std::string& nazwa_lok, const std::string& nazwa_glob);

    /*!
     * \brief Powoduje ruch drona po prostej
     * Metoda powoduje przesunięcie drona o zadany kąt i zadaną odległość
     * \param[in] kat_wznoszenia - kąt o jaki ma wznieść się dron
     * \param[in] odleglosc - odległość na jaką ma przesunąć się dron
     */
    void ruch_na_wprost(double kat_wznoszenia, double odleglosc);
    /*!
     * \brief Powoduje obrót drona
     * Metoda powoduje obrót drona o zadany kąt obrotu
     * \param[in] kat_obrotu - kąt o jaki ma obrócić się dron w osi OZ
     */
    void obrot(double kat_obrotu);

    /*!
     * \brief Zwraca położenie drona
     * Metoda zwraca aktualne położenie drona
     * \return wektor z zapisanymi współrzędnymi kartezjańskimi drona
     */
    TVector<double, 3> zwroc_polozenie() const;
    /*!
     * \brief Zwraca wymiary drona
     * Metoda zwraca odległości środka drona od jego ścian.
     * \return wektor z zapisanymi długościami
     */
    TVector<double, 3> zwroc_dlugosci() const;
};
