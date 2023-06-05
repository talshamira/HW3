#ifndef HEALTHPOINTS_H_
#define HEALTHPOINTS_H_
#include <iostream>
class HealthPoints
{
    public:
        /*
         * constuctor for HealthPoints
         * @param  maxPoints is the max health points allowed
         */
        HealthPoints(const int maxPoints = DEFAULT_MAX_HEALTH);
        
        /*
         * Exception to throw for invalid argument
         */
        class InvalidArgument{};

        /*
         * operator -= subtracts from current health the given health 
         * and makes sure current health doesnt go bellow zero
         * @param health given health to subtract
         */
        HealthPoints& operator-=(const int health);

        /*
         * binary operator - subtracts from current healthpoints the health given and returns the result
         * @param health an int specifing the amount to be subtracted shouldnt be <= 0
         */
        HealthPoints operator-(const int health);

         /*
         * operator += adds to current health the given health 
         * and makes sure current health doesnt go above m_maxHealthPoints
         * @param health given health to add
         */
        HealthPoints& operator+=(const int health);

         /*
         * operator + adds to current health the given health 
         * and makes sure current health doesnt go above m_maxHealthPoints
         * @param health given health to add
         */
        HealthPoints& operator+(const int health);
// --------------------------------- Default Functions------------------------------------------------------------------
        /*
         * Copy Constructor
         */
        HealthPoints(const HealthPoints& old) = default;

        /*
         * operator =
         */
        HealthPoints& operator=(const HealthPoints& old) = default;

        /*
         *Destructor
         */
        ~HealthPoints() = default;
    private:
//--------------------------------- Friend Functions -------------------------------------------------------------------
        /*
         * operator < checks if the a has more health than b
         * @param a first parameter to check
         * @param b second parameter to check
         */
        friend bool operator<(const HealthPoints& a, const HealthPoints& b);
        
        /*
         * operator << used to print the object in the given format <m_healthPoints>(<m_maxHealthPoints>)
         * @param os the out stream
         * @param health the object needed to be printed
         */
        friend std::ostream& operator<<(std::ostream& os,HealthPoints health);

//------------------------------- Fields -------------------------------------------------------------------------------
        /*
         * @param m_healthPoints - holds the current number of health points
         * @param m_maxHealthPoints - holds the max amount of health points
         * the default max health points is 100
         */
        int m_healthPoints;
        int m_maxHealthPoints;  
        static const int DEFAULT_MAX_HEALTH = 100;  
};

/*
 * binary operator + adds to current healthpoints the health given and returns the result 
 * makes sure the new health points <= max health points
 * @param health an int specifing the amount to be added shouldnt be <= 0
 * @param current is the healthPoints object to wich we add the health
 */
HealthPoints operator+(const int health, const HealthPoints& current);


/*
 * operator == checks if a has the same amount of health as b 
 * @param a first parameter to check
 * @param b second parameter to check
 */
bool operator==(const HealthPoints& a, const HealthPoints& b);

/*
 * operator != checks if a has a diffrent amount of health as b
 * @param a first given parameter to check
 * @param b second given parameter to check
 */
bool operator!=(const HealthPoints& a, const HealthPoints& b);

/*
 * operator <= checks if a has less health than or equall to b 
 * @param a first given parameter to check
 * @param b second given paramater to check
 */
bool operator<=(const HealthPoints& a, const HealthPoints& b);

/*
 * operator >= checks if a has more health than or equall to b 
 * @param a first given parameter to check
 * @param b second given paramater to check
 */
bool operator>=(const HealthPoints& a, const HealthPoints& b);

/*
 * operator > checks if a has more health than b 
 * @param a first given parameter to check
 * @param b second given paramater to check
 */
bool operator>(const HealthPoints& a, const HealthPoints& b);

#endif