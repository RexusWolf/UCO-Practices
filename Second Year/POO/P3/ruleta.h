#include "jugador.h"
#include "crupier.h"


class Ruleta{
    private:
      int banca_; // Cantidad de dinero de la banca.
      int bola_; // Entre 0 y 36, número que sale en la ruleta.
      list<Jugador> jugadores_;
      Crupier crupier_;
    public:

      int getBanca() const {return banca_;}
      int getBola() const {return bola_;}
      Crupier getCrupier() const {return crupier_;}
      list<Jugador> getJugadores() const {return jugadores_;}
      bool setBanca(const int banca);
      bool setBola(const int bola);
      bool addJugador(Jugador &j);
      int deleteJugador(Jugador &j);
      int deleteJugador(int j.dni);
      void escribeJugadores();
      void leeJugadores();
      void giraRuleta();
      void getPremios();

      Ruleta(Crupier &c); // Constructor
};
