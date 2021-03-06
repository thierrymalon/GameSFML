#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "State.hpp"
#include "Sort.hpp"

class Personnage : public sf::Drawable
{
    public:
        Personnage();
        Personnage(std::string const& path);

        sf::Vector2f getOrigin();

        void startClock();

        bool manageEvent(sf::Event const& event, sf::Packet& packet, std::vector<Sort> & sortsIcons, std::vector<std::pair<sf::Clock, Sort>>& sortsAttente);

        void regenStep();

        void networkOrientedNextStep();
        void nextStep();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

//    private:
        /* Apparence du personnage */
        sf::Sprite m_spritePerso;
        sf::Texture m_texturePerso;
        sf::Vector2f m_dimensions;
        unsigned int m_frameNumber;
        unsigned int m_animationNumber;
        sf::Clock m_tempsDepuisDebutAnimation;

        /* Positionnement du personnage */
        // Positions x, y et z du personnage
        sf::Vector3f m_position;
        // Vitesse de déplacement de base
        float m_vitesse;
        // Rayon du personnage
        float m_rayon;
        // Direction du personnage
        unsigned int m_direction;
        // Vecteur de projection
        sf::Vector3f m_projection;
        // Current moving state
        State m_state;

        /* Leveling du personnage */
        // Niveau du personnage
        unsigned int m_level;
        // Expérience totale
        std::uint64_t m_xpTotale;
        // Expérience pour up
        std::uint64_t m_xpPourUp;
        // Expérience donnée si vaincu
        std::uint64_t m_xpDonnee;

        /* Argent et objets du personnage */
        // Argent possédé
        std::uint64_t m_money;
        // Argent donné si vaincu
        std::uint64_t m_moneyDonnee;

        /* Stats du perso */
        // Points de vie maximum du personnage
        unsigned int m_pvMax;
        // Points de vie actuels du personnage
        unsigned int m_pvActuels;
        // Degats = Degats de l'attaque * (100 + m_puissance de la cible - m_resistance de soi) / 100
        // Puissance du personnage
        unsigned int m_puissance;
        // Resistance du personnage
        unsigned int m_resistance;

        // Points d'action, de mouvement et de special
        unsigned short m_PAmax;
        unsigned short m_PMmax;
        unsigned short m_PWmax;
        unsigned short m_PA;
        unsigned short m_PM;
        unsigned short m_PW;

        // Régénérateurs et vitesses de régénération
        float m_regenPV;
        float m_regenPA;
        float m_regenPM;
        float m_regenPW;
        float m_speedRegenPV;
        float m_speedRegenPA;
        float m_speedRegenPM;
        float m_speedRegenPW;

        sf::Time m_tempsIncantation;
        sf::Clock m_tempsIncante;
};

#endif // PERSONNAGE_HPP
