#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;
class Unit
{
protected:
    int health;
public:
    int attackForce;

    Unit(int start_health, int _attackForce)
        :health(start_health), attackForce(_attackForce)
    {}
    void getDamage(int damage)
    {
        health -= damage;
    }
    int getHealth() const
    {
        return health;
    }
    bool isAlive() const
    {
        return (health > 0);
    }
};

class Dragon: public Unit
{
protected:
    int my_answer;
    string my_color;
public:
    static const int c_killScores = 100;

    Dragon(string color, int start_health, int _attackForce)
        :Unit(start_health, _attackForce), my_color(color)
    {}
    string getQuest()
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        stringstream question;
        question << left << " + " << right << ": ";
        my_answer = left + right;
        return question.str();
    }
    bool checkAnswer(int answer) const
    {
        return answer == my_answer;
    }
    string color() const
    {
        return my_color;
    }
};

class Hero: public Unit
{
    int scores;
public:
    static const int default_health = 100;
    static const int default_attackForce = 20;

    Hero(int health = default_health, int aForce = default_attackForce)
        :Unit(health, aForce), scores(0)
    {}
    void attack (Dragon &drago)
    {
        string q = drago.getQuest();
        cout << q;
        int answer;
        cin >> answer;
        if (drago.checkAnswer(answer))
        {
            drago.getDamage(attackForce);
            cout << "Hit you, dragon!" << endl;
        }
        else
        {
            getDamage(drago.attackForce);
            cout << "Hero suffers..." << endl;
        }
    }
    void addScores(int _scores)
    {
        scores += _scores;
    }
    int getScores()
    {
        return scores;
    }
};

void showHealth(const Hero &hero, const Dragon &dragon)
{
    cout << "Hero health: " << hero.getHealth()
        << ", Dragon health: " << dragon.getHealth() << endl;
}

void playGame()
{
    Hero hero;
    bool gameOver = false;
    for (int round = 0; round < 3; round++)
    {
        Dragon dragon("Green", 100, 10);
        cout << "You have met a new " << dragon.color() << " dragon. Fight!" << endl;

        while (dragon.isAlive() && hero.isAlive())
        {
            hero.attack(dragon);
        }
        if (!hero.isAlive())
        {
            gameOver = true;
            break;
        }
        else // dragon was killed!
        {
            hero.addScores(Dragon::c_killScores);
            cout << "Ough! You have killed a dragon!" << endl;
        }
    }
    if (gameOver)
    {
        cout << "Game over! Your score is: " << hero.getScores() << endl;
    }
    else
    {
        cout << "You win! Your score is: " << hero.getScores() << endl;
    }
}


int main()
{
    playGame();
    return 0;
}
